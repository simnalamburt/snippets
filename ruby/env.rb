def line desc, value
  puts "%20s : #{value}" % desc
end

line "ENV", ENV
line "empty?", ENV.empty?
line "to_h", ENV.to_h
