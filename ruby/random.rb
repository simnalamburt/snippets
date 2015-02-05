10.times do
  puts (5.times.map { ('a'..'z').to_a[rand(26)] } + 3.times.map { rand(10) }).join
end
