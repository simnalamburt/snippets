def hanoi(n, a, b, stack):
  print(stack)

  if n == 1:
    print(stack+"!")
  else:
    temp = 6 - a - b
    hanoi(n-1, a, temp, "*"+stack)
    hanoi(n-1, temp, b, "*"+stack)

  print(stack)

n = int(input("Type total count of disks : "))
hanoi(n, 1, 2, "")
