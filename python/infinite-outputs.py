import signal
import time
import itertools

# Ignore Ctrl-C
signal.signal(signal.SIGINT, lambda sig, frame: ...)

try:
    for i in itertools.count():
        print(i, flush=True)
        time.sleep(0.05)
except BrokenPipeError:
    ...
