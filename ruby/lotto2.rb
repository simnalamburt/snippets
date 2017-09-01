# frozen_string_literal: true
ball = 1..45
count = 7

######
counter = Hash.new
ball.each do |n|
  counter[n] = 0
end

parent = ball.to_a
num = 0
loop do
  parent.sample(count).each do |n|
    counter[n] += 1
  end

  if num == 1000
    num = 0

    result = counter.sort_by { |k, v| -v }
    result[0...7].each do |row|
      print '%2d ' % row[0]
    end
    puts ''
  else
    num += 1
  end
end
