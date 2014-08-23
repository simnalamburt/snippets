def line desc, value
  puts "%20s : #{value}" % desc
end

line 'ARGV', ARGV
puts ''

line 'ENV', ENV
line 'empty?', ENV.empty?
line 'to_h', ENV.to_h
