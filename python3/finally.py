def func():
    for i in range(0, 5):
        try:
            return i
        finally:
            if i != 3:
                # SyntaxError: 'continue' not supported inside 'finally' clause
                continue

print(func())
