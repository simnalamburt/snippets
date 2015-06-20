// 2015년 IPSC
//
// 최대길이 96
// trivial(), solve() 함수의 리턴타입이 항상 number가 되게 하느라 오버헤드가 조금 있음


//
// 편의
//
function unique(arr) {
  var u = {}, a = [];
  for (var i = 0, l = arr.length; i < l; ++i) {
    if (u.hasOwnProperty(arr[i])) { continue; }
    a.push(arr[i]);
    u[arr[i]] = 1;
  }
  return a;
}

function assert(bool) {
  if (bool) { return; }
  var err = new Error();
  console.error(err.stack);
  process.exit(1);
}


//
// 풀이
//
function trivial(num) {
  var str = num.toString();
  var trivial = '+[[';
  for (var i = 0; i < str.length; ++i) {
    trivial += encode(str[i]) + ']+[';

    function encode(char) {
      switch(char) {
      case '0': return '+[]';
      case '1': return '+!+[]';
      case '2': return '!+[]+!+[]';
      case '3': return '!+[]+!+[]+!+[]';
      case '4': return '!+[]+!+[]+!+[]+!+[]';
      case '5': return '!+[]+!+[]+!+[]+!+[]+!+[]';
      case '6': return '!+[]+!+[]+!+[]+!+[]+!+[]+!+[]';
      case '7': return '[[+!+[]]+[+[]]]-!-[]-!-[]-!-[]';
      case '8': return '[[+!+[]]+[+[]]]-!-[]-!-[]';
      case '9': return '[[+!+[]]+[+[]]]-!-[]';
      }
    }
  }
  trivial += ']]';
  return trivial;
}


var table = [];
function solve(num) {
  // 메모이제이션
  if (table[num]) { return table[num]; }

  assert(num <= 1000);
  var str = num.toString();
  var options = [trivial(num)];

  // 무조건 자명해 반환할 숫자들
  switch (num) {
  case 0: case 1: case 10: case 11: case 100: case 101: case 110: case 111:
    return options[0];
  }

  // (1, 10, 11, 100, 101, 110, 101, 111 * N) 숫자들 처리
  +function() {
    if (str.length === 3) {
      var arr = unique(str.split(''));
      switch (arr.length) {
        case 1:
          options.push(solve(111) + '*' + solve(parseInt(str[0])));
          return;
        case 2:
          var _0 = str.split('').filter(function(v) { return v === arr[0]; }).length;
          var _1 = str.split('').filter(function(v) { return v === arr[1]; }).length;
          assert((_0 === 1 && _1 === 2) || (_0 === 2 && _1 === 1));

          // aab aba baa
          var A = _0 > _1 ? arr[0] : arr[1];
          var B = _0 > _1 ? arr[1] : arr[0];
          var a = parseInt(A), b = parseInt(B);

          // b00 제외
          if (a === 0) { return; }

          // aa0 a0a
          if (b === 0) {
            switch (str) {
              case A+A+B: options.push(solve(a) + '*' + solve(110)); break;
              case A+B+A: options.push(solve(a) + '*' + solve(101)); break;
              default: assert(false);
            }
            return;
          }

          // aaa + (b-a)
          var delta = b - a;
          assert(delta !== 0);
          var op = delta > 0 ? '-+-' : '+-';
          if (delta < 0) { delta *= -1; }
          switch (str) {
          case A+A+B: options.push(solve(a*111) + op + solve(delta*1)); break;
          case A+B+A: options.push(solve(a*111) + op + solve(delta*10)); break;
          case B+A+A: options.push(solve(a*111) + op + solve(delta*100)); break;
          default: assert(false);
          }
          return;
        case 3:
          // abc
          return;
      }
      assert(false);
    }
  }();

  // 678 = 700 - 22
  if (num < 1000 && num % 100 !== 0) {
    var upper = (parseInt(num/100) + 1)*100;
    var delta = upper - num;
    options.push(solve(upper) + '+-' + trivial(delta));
  }

  var ret = options.reduce(function(p,c) { return p.length > c.length ? c : p; }, { length: Infinity });
  table[num] = ret; return ret;
}
exports.solve = solve;


//
// 테스트
//
if (!module.parent) {
  var answer = [];

  for (var num = 0; num < 1000; ++num) {
    var result = solve(num);
    assert(num === eval(result));
    answer.push({ num: num, result: result });
  }

  answer.sort(function(a, b) { return a.result.length - b.result.length });

  answer.forEach(function(e) {
    console.log(e.num + ': (' + e.result.length + ') ' + e.result);
  });
}
