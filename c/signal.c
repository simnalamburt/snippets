#include <signal.h>
#include <bits/signum.h>
#include <string.h>
#include <stdio.h>

int main() {
  const int signals[] = {
    SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV, SIGPIPE,
    SIGALRM, SIGTERM, SIGUSR1, SIGUSR2, SIGCHLD, SIGCONT, SIGSTOP, SIGTSTP,
    SIGTTIN, SIGTTOU, SIGBUS, SIGPOLL, SIGPROF, SIGSYS, SIGTRAP, SIGURG,
    SIGVTALRM, SIGXCPU, SIGXFSZ, SIGIOT, SIGSTKFLT, SIGIO, SIGCLD, SIGPWR,
    SIGWINCH, SIGUNUSED,
    // SIGEMT, SIGINFO, SIGLOST,
  };
  const size_t count = sizeof signals/sizeof signals[0];

  for (size_t i = 0; i < count; ++i) {
    const int signal = signals[i];

    printf("%s\n", strsignal(signal));
    // printf("%s\n", sys_siglist[signal]);
    // psignal(signal, NULL);
  }
}
