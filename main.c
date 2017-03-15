// 이주헌 과제 도와주기
// ========
// Programming Practice, SNU 4190.103A
//
//     gcc main.c
//
// ### TODOs
// - [ ] 맨 앞에 뜨는 공백문자 삭제
// - [ ] 빈 토큰은 처리하지 않기

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
  // NULL로 치환하며, 동시에 tokens에 치환된 위치를 저장
  //
  char* tokens[501] = { input };
  int _count = 1;
  for (i = 0; input[i]; ++i) {
    for (j = 0; delims[j]; ++j) {
      if (input[i] == delims[j]) {
        input[i] = '\0';
        tokens[_count++] = &input[i + 1];
        break;
      }
    }
  }

  //
  // 빈 token 제외하기
  //
  for (i = 0; i < _count; ++i) {
    if (tokens[i][0] != '\0') continue;

    tokens[i--] = tokens[--_count];
  }
  const int tokens_count = _count;

  //
  // tokens 퀵소트
  //
  qsort(tokens, tokens_count, sizeof tokens[0], cmp);

  //
  // 출력
  //
  i = 0;
  for (; i < tokens_count && i < 1; ++i) {
    printf("%s", tokens[i]);
  }
  for (; i < tokens_count; ++i) {
    printf(" %s", tokens[i]);
  }
  putchar('\n');

  return 0;
}
