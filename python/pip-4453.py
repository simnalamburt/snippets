# Python is neither call by value nor call by reference.
# This is cause of https://github.com/pypa/pip/issues/4453
#
#     $ python3 pip-4453.py
#     ['a', 'a', 'a', 'a', 'a']
#     []
#
# References:
#   https://gist.github.com/simnalamburt/4eba5ba8a881e473f17ebd70383f18ab
#   https://github.com/pypa/pip/blob/master/src/pip/_internal/req/req_install.py#L773
#   https://github.com/pypa/pip/blob/master/src/pip/_internal/req/req_set.py#L225

def foo(param):
    param += ['a']

def bar(param):
    param = param + ['a']

p1 = []
foo(p1)
foo(p1)
foo(p1)
foo(p1)
foo(p1)
print(p1)

p2 = []
bar(p2)
bar(p2)
bar(p2)
bar(p2)
bar(p2)
print(p2)
