// Dumb liblzma tutorial

#include <stdio.h>
#include <unistd.h>
#include <lzma.h>

#define BUFFER_SIZE 4096

int main() {
  uint32_t version_no = lzma_version_number();
  const char* version_str = lzma_version_string();
  printf("liblzma version: %s (%d)\n", version_str, version_no);

  /*
  lzma_ret _ret;
  _ret = LZMA_OK;
  _ret = LZMA_STREAM_END;
  _ret = LZMA_NO_CHECK;
  _ret = LZMA_UNSUPPORTED_CHECK;
  _ret = LZMA_GET_CHECK;
  _ret = LZMA_MEM_ERROR;
  _ret = LZMA_MEMLIMIT_ERROR;
  _ret = LZMA_FORMAT_ERROR;
  _ret = LZMA_OPTIONS_ERROR;
  _ret = LZMA_DATA_ERROR;
  _ret = LZMA_BUF_ERROR;
  _ret = LZMA_PROG_ERROR;

  lzma_action _action;
  _action = LZMA_RUN;
  _action = LZMA_SYNC_FLUSH;
  _action = LZMA_FULL_FLUSH;
  _action = LZMA_FINISH;
  _action = LZMA_FULL_BARRIER;
  */

  lzma_ret ret;

  lzma_stream stream = LZMA_STREAM_INIT;
  ret = lzma_easy_encoder(&stream, 6, LZMA_CHECK_CRC64);
  if (ret == LZMA_OK) { puts("Initialization went successful"); }
  else { printf("Error on lzma_stream_encoder (result: %d)\n", ret); return 1; }

  uint8_t buffer_input[BUFFER_SIZE] = "Hello, world!";
  stream.next_in = buffer_input;
  stream.avail_in = 13;

  uint8_t buffer_output[BUFFER_SIZE] = {};
  stream.next_out = buffer_output;
  stream.avail_out = BUFFER_SIZE;

  ret = lzma_code(&stream, LZMA_RUN);
  if (ret == LZMA_OK) { puts("Encoding went successful"); }
  else { printf("Error on lzma_code (result: %d)\n", ret); return 1; }

  lzma_end(&stream);

  printf("Input: [");
  for (int i = 0; i < stream.total_in; ++i) {
    printf("%d, ", buffer_input[i]);
  }
  printf("\b\b] (%llu)\n", stream.total_in);

  printf("Output: [");
  for (int i = 0; i < stream.total_out; ++i) {
    printf("%d, ", buffer_output[i]);
  }
  printf("\b\b] (%llu)\n", stream.total_out);

  return 0;
}

// Reference: https://lists.samba.org/archive/linux/2013-November/032622.html
