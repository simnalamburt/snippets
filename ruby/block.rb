p [10, 11, 12, 13, 14, 15, 16, 17, 18].reduce(0) { |a, b|
  puts "#{a}, #{b}"
  next 100 if b == 13
  break 200 if b == 17
  a + b
}
