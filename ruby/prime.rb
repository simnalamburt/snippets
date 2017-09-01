# frozen_string_literal: true
require 'prime'

begin
  print "소수판별 프로그램입니다!\n\n"
  loop do
    print 'N을 입력하세요 : '
    input = gets.chomp
    break if input.empty?

    number = input.to_i
    next if number < 2

    if Prime.prime?(number)
      print "#{number}는 소수입니다!\n\n"
    else
      print "#{number}는 소수가 아닙니다.\n\n"
    end
  end
rescue Interrupt
  puts ''
end
puts 'Bye'
