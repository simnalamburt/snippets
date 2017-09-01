# frozen_string_literal: true
ball = 1..45
count = 7

lotto = ball.to_a.sample(count)

print ' ... '
for n in 0...count
  sleep 0.8
  print "#{lotto[n]} "
  $stdout.flush
end
puts ''

lotto.sort!
puts "Today's Lucky Numbers are #{lotto}!!"
