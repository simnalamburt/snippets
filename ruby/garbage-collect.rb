# frozen_string_literal: true
puts (Dir['**/*'].flat_map do |x|
  next [] if File.directory?(x)

  # 여기서 정책 조정
  #name = File.basename(x)
  name = File.basename(x, '.*')

  result = system("rg -qF '#{name}'")
  next [] if result

  x
end).entries.sort
