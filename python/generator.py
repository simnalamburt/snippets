def foo(input):
    index = 0
    i = 1
    while index < len(input):
        yield input[index : index+i]
        index += i
        i += 1

def bar():
    yield from ((i, i) for i in range(5))

print(list(foo('....................................+++++')))
print(list(bar()))
