#include <stdio.h>
#include <stdbool.h>

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

      input[i] = 0;
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
  // tokens 들 사전순으로 배열
  //
  for (i = 0; i < tokens_count - 2; ++i) {
    for (j = i+1; j < tokens_count - 1; ++j) {
      int q = 0;
      char* temp = 0;
      while (true) {
        if (*tokens[i] > *tokens[j] && *tokens[i] - *tokens[j] != 32) { temp = tokens[i]; tokens[i] = tokens[j]; tokens[j] = temp; break; }
        else if (*tokens[i] < *tokens[j] && *tokens[j] - *tokens[i] != 32) { break; }
        else if (*tokens[i] == 0 && *tokens[j] != 0) { break; }
        else if (*tokens[j] == 0 && *tokens[i] != 0) { temp = tokens[i]; tokens[i] = tokens[j]; tokens[j] = temp; break; }
        else if (i == j) { break; }
        else { tokens[i] = tokens[i] + 1; tokens[j] = tokens[j] + 1; ++q; }
      }
      tokens[i] = tokens[i] - q; tokens[j] = tokens[j] - q;
    }
  }

  //
  // 출력
  //
  for (i = 0; i < tokens_count; ++i) {
    printf(" %s", tokens[i]);
  }

  return 0;
}
