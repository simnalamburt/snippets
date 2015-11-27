x = (lambda do
  for i in 0...5
    begin
      return i
    ensure
      next unless i == 3
    end
  end
end).call
puts x
