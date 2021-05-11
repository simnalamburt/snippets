import numpy as np

#     |a|
#     |b|
# U = |c|
#     |d|
#     |e|
#     |f|
#
# MU = C
M = np.array([
    [-4.,  1.,  1.,  0.,  0.,  0.],
    [ 1., -4.,  0.,  1.,  0.,  0.],
    [ 1.,  0., -4.,  1.,  1.,  0.],
    [ 0.,  1.,  1., -4.,  0.,  1.],
    [ 0.,  0.,  2.,  0., -4.,  1.],
    [ 0.,  0.,  0.,  2.,  1., -4.],
])
C = np.array([
       2.,
      -4.,
       5.,
     -28.,
      -2.,
    -116.,
])

if not np.all(M.diagonal() == M[0,0]):
    print('행렬의 대각성분 값이 모두 같아야합니다.')
    exit(1)

# If M = X + kI:
#     MU = C
#  => XU + kU = C
#  => U = -1/k*XU + 1/k*C
#
# U = AU + B
#     where A = -1/k * X,
#           B =  1/k * C
k = M[0,0]

X = M.copy()
np.fill_diagonal(X, 0)

A = -1/k * X
B =  1/k * C

# Initial values
U = np.array([0., 0., 0., 0., 0., 0.])
print(f'''\
U = V = [u_11  u_12  u_21  u_22  u_31  u_32]

U = {U}''')

for i in range(5):
    U = A@U + B
    letter = 'V' if i % 2 == 0 else 'U'
    print(f'{letter} = {U}')

print(f'''
Result after 5 steps:
  u_11 = {U[0]}
  u_12 = {U[1]}
  u_21 = {U[2]}
  u_22 = {U[3]}
''')

for i in range(5, 20):
    U = A@U + B
    letter = 'V' if i % 2 == 0 else 'U'
    print(f'{letter} = {U}')

print(f'''
Result after 20 steps:
  u_11 = {U[0]}
  u_12 = {U[1]}
  u_21 = {U[2]}
  u_22 = {U[3]}
''')
