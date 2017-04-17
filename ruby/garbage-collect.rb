# frozen_string_literal: true
Dir['**/*'].map do |x|
  next if File.directory?(x)

  name = File.basename(x)
  result = system("rg -qF '#{name}'")
  next if result
  puts x
end
