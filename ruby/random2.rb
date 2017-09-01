# frozen_string_literal: true
o = [('a'..'z'), ('A'..'Z'), ('0'..'9')].map(&:to_a).flatten
str = (0...1000000).map { o[rand(o.length)] }.join
File.open('input', 'w') { |file| file.puts str }
