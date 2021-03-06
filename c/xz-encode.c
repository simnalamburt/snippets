#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <lzma.h>

#define BUFFER_SIZE 4096

void error(char *msg)
{
  fputs(msg, stderr);
  exit(EXIT_FAILURE);
}

int main(void)
{
  uint8_t inbuf[BUFFER_SIZE];
  uint8_t outbuf[BUFFER_SIZE];

  FILE *infile = fopen("input", "r");
  FILE *outfile = fopen("input.xz", "w");

  lzma_stream strm = LZMA_STREAM_INIT;
  if (lzma_easy_encoder(&strm, 9, LZMA_CHECK_CRC64) != LZMA_OK)
    error("lzma_easy_encoder()");

  strm.avail_in = 0;
  strm.next_out = outbuf;
  strm.avail_out = sizeof(outbuf);

  do {
    /* input empty, read in more */
    if (strm.avail_in == 0) {
      strm.next_in = inbuf;
      strm.avail_in = fread(inbuf, 1, sizeof(inbuf), infile);
      if (ferror(infile))
        error("fread()");
    }

    if (lzma_code(&strm, LZMA_RUN) != LZMA_OK)
      error("lzma_code(,LZMA_RUN)");

    /* output buffer full, write to file */
    if (strm.avail_out == 0) {
      if (fwrite(outbuf, sizeof(outbuf), 1, outfile) == 0)
        error("fwrite()");
      strm.next_out = outbuf;
      strm.avail_out = sizeof(outbuf);
    }

  } while (feof(infile) == 0);

  /* now that input is exhausted, call lzma_code() with action
     LZMA_FINISH until it returns LZMA_STREAM_END */
  while (true) {

    lzma_ret ret = lzma_code(&strm, LZMA_FINISH);

    /* output buffer full, write to file */
    if (strm.avail_out == 0) {
      if (fwrite(outbuf, sizeof(outbuf), 1, outfile) == 0)
        error("fwrite()");
      strm.next_out = outbuf;
      strm.avail_out = sizeof(outbuf);
    }

    /* compress finished, write remainder of output buffer to file */
    if (ret == LZMA_STREAM_END) {
      size_t write_size = sizeof(outbuf) - strm.avail_out;
      if (fwrite(outbuf, write_size, 1, outfile) == 0)
        error("fwrite()");

      return EXIT_SUCCESS;
    }

    if (ret != LZMA_OK)
      error("lzma_code(,LZMA_FINISH)");
  }
}
