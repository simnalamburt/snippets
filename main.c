#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//
// If ch is upper-case letter: return lower-case of ch
//          otherwise        : return ch
//
// Homemade tolower() function
//
char _tolower(char ch) {
  return 'A' <= ch && ch <= 'Z' ?
    ch - 'A' + 'a' :
    ch;
}

//
// Compare (*left) and (*right), ignoring case
//
int cmp(const void* left, const void* right) {
  const unsigned char
    *s1 = *(const unsigned char **) left,
    *s2 = *(const unsigned char **) right;

  for (; _tolower(*s1) == _tolower(*s2); ++s1, ++s2) {
    if (*s1 == '\0') { return 0; }
  }

  return _tolower(*s1) - _tolower(*s2);
}

//
// main()
//
int main(void) {
  int i, j;

  //
  // input, delims 초기화
  //
  char input[1001] = {}, delims[101] = {};
  fgets(delims, sizeof delims, stdin);
  fgets(input, sizeof input, stdin);

  //
  // 문자열 input 안의 delimeter들을 전부 NULL로 치환
  // fgets 쓰기때문에 delims 엔 자동으로 '\n'이 들어있음
  //
  for (i = 0; input[i]; ++i) {
    for (j = 0; delims[j]; ++j) {
      if (input[i] != delims[j]) continue;

      input[i] = '\0';
    }
  }
  const int input_size = i - 1; // '\n' 제외

  //
  // NULL로 구분된 입력들의 각 시작점을 tokens[]에 저장
  // 이때 빈 토큰은 제외
  //
  char* tokens[501];
  int _count = 0;
  bool _last_state = false; // 마지막으로 읽은 글자가 NULL이었을경우 false
                            //                otherwise              true
  for (i = 0; i < input_size; ++i) {
    bool _current_state = !!input[i]; // 현재 글자가 NULL일 경우 false
                                      //        otherwise        true

    if (!_last_state && _current_state) {
      tokens[_count++] = &input[i];
    }

    _last_state = _current_state;
  }
  const int tokens_count = _count;

  //
  // 할 연산이 없을경우 빠른 return
  //
  if (tokens_count < 1) return 0;

  //
  // tokens 퀵소트
  //
  qsort(tokens, tokens_count, sizeof tokens[0], cmp);

  //
  // 출력
  //
  for (i = 0; i < 1; ++i) {
    printf("%s", tokens[i]);
  }
  for (; i < tokens_count; ++i) {
    printf(" %s", tokens[i]);
  }
  putchar('\n');

  return 0;
}
