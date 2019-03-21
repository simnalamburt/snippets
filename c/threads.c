#include <stdio.h>
#include <threads.h>

typedef struct {
  int a, b;
} thread_param;

int thread(void *arg) {
  thread_param *param_handle = arg;
  return param_handle->a + param_handle->b;
}

int main() {
  int ret;

  thread_param param;
  scanf("%d%d", &param.a, &param.b);

  thrd_t thread_handle;
  ret = thrd_create(&thread_handle, thread, &param);
  if (ret != thrd_success) { goto error; }

  int result;
  ret = thrd_join(thread_handle, &result);
  if (ret != thrd_success) { goto error; }

  printf("%d\n", result);
  return 0;

error:
  fputs("An error occurred while using the thread.\n", stderr);
  return -1;
}
