import numpy as np

#     |a|
# U = |b|
#     |c|
#     |d|
#
# U = AU + B

A = np.array([
    [0., 1/4, 1/4, 0],
    [1/4, 0., 0., 1/4],
    [15/52, 0., 0., 17/52],
    [0., 15/52, 17/52, 0.],
])
B = np.array([-1/2, 1., 49/52, 443/26])

# Initial values
U = np.array([0., 0., 0., 0.])
print(f'''\
U = V = [u_11  u_12  u_21  u_22]

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
