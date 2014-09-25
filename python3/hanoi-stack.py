job_stack = []

n = int(input('판이 총 몇개 있니? : '))
job_stack.append( (n, 1, 2) ) # 잡 스택에 제일 먼저 할 일 하나를 Push

while job_stack: # 잡 스택에 뭔가 '할일'이 남아있는한, 계속 반복함
  (n, a, b) = job_stack.pop() # 잡 스택에서 일 하나를 뽑아옴
  if n == 1:
    print('판 한개를 %d -> %d 으로 옮기셈' % (a, b))
  else:
    temp = 6 - a - b

    # 스택은 FILO라서, 원하는 실행순서의 반대로 잡 큐에 집어넣어야됨
    job_stack.append( (n-1, temp, b) )        # 3. '임시'로 옮겼던 판들을 '임시'에서 모두 b로 옮김
    job_stack.append( (1, a, b) )             # 2. 밑에 깔려있는 제일 큰 판을   a 에서 b로 옮김
    job_stack.append( (n-1, a, temp) )        # 1. 맨 밑에 깔려있는거 빼고 전부 a 에서 '임시'로 옮김
