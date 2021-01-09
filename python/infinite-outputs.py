import signal
import time
import itertools

signal.signal(signal.SIGINT, lambda sig, frame: exit(0))

try:
    for i in itertools.count():
        print(i, flush=True)
        time.sleep(0.05)
except BrokenPipeError:
    ...
