def foo(input):
    index = 0
    i = 1
    while index < len(input):
        yield input[index : index+i]
        index += i
        i += 1

breakpoint()
