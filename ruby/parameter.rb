def my_method(*args)
  p args
end

my_method(a: 10, b: 20)
my_method(10, 20)
my_method(10, b: 20)

my_method({ a: 10, b: 20 })

A = { a: 10 }
my_method(A)
my_method(A.merge(b: 20))
my_method(A)
my_method(A.merge!(b: 20))
my_method(A)
