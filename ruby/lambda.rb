# TL;DR
#
# 1.  Proc.new 와 proc 은 완전히 같음
# 2.  lambda와 `->` 도 완전히 같음
# 3.  proc과 람다는 인자 처리와 return문 처리하는부분에 있어서 다르다.

a = Proc.new  { |a, b| puts "#{a.inspect}, #{b.inspect}" }
b = proc      { |a, b| puts "#{a.inspect}, #{b.inspect}" }
c = lambda    { |a, b| puts "#{a.inspect}, #{b.inspect}" }
d = -> (a, b) { puts "#{a.inspect}, #{b.inspect}" }

a.call(3, 4)
b.call(3, 4)
c.call(3, 4)
d.call(3, 4)
puts

puts "\e[33m인자를 주지 않았을때의 동작 비교\e[0m"
begin a.call(3); rescue ArgumentError => e; puts e end
begin b.call(3); rescue ArgumentError => e; puts e end
begin c.call(3); rescue ArgumentError => e; puts e end
begin d.call(3); rescue ArgumentError => e; puts e end
puts

puts "\e[33m\"return\"문 처리하는 방법 비교\e[0m"
def func
  Proc.new { return "안쪽 return문이 바깥쪽 함수를 종료시켰음!!" }.call
  return "정상"
end
puts func
def func
  proc { return "안쪽 return문이 바깥쪽 함수를 종료시켰음!!" }.call
  return "정상"
end
puts func
def func
  lambda { return "안쪽 return문이 바깥쪽 함수를 종료시켰음!!" }.call
  return "정상"
end
puts func
def func
  -> { return "안쪽 return문이 바깥쪽 함수를 종료시켰음!!" }.call
  return "정상"
end
puts func

# Reference:
#   http://culttt.com/2015/05/13/what-are-lambdas-in-ruby/
