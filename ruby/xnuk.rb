# frozen_string_literal: true
loop do
  begin
    result = gets.force_encoding('CP949').encode('UTF-8').strip
  rescue
    result = "\e[31mError"
  end

  puts "\e[33m#{result}\e[0m"
  puts ''
end
