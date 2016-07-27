# n : 옮겨야할 판의 갯수
# a : 출발지
# b : 도착지
def hanoi(n, a, b):
  if n == 1:
    print('판 한개를 %d -> %d 으로 옮기셈' % (a, b))
  else:
    temp = 6 - a - b
    hanoi(n-1, a, temp) # 1. 맨 밑에 깔려있는거 빼고 전부 a 에서 '임시'로 옮김
    hanoi(1, a, b)      # 2. 밑에 깔려있는 제일 큰 판을   a 에서 b로 옮김
    hanoi(n-1, temp, b) # 3. '임시'로 옮겼던 판들을 '임시'에서 모두 b로 옮김


n = int(input('판이 총 몇개 있니? : '))
hanoi(n, 1, 2)
