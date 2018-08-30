# frozen_string_literal: true
loop do
  input = gets
  break if input.nil?
  puts input.force_encoding('UTF-8').encode('CP949').strip
end
