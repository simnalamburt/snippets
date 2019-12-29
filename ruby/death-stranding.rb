# 데스스트랜딩 편하게 하려고 짬
#
# Reference:
#   https://docs.google.com/spreadsheets/d/1woGu0IdFka8EUI48KXO3e14ja6EPy-u60stHXn1yJjw

puts open('input').read.split("\r\n").map { |cell|
  lines = cell.split("\n")

  if lines[0][0] == '"' and lines[-1][-1] == '"'
    lines[0] = lines[0][1..-1]
    lines[-1] = lines[-1][0..-2]
  elsif lines[0][0] != '"' and lines[-1][-1] != '"'
    # Do nothing
  elsif
    raise ArgumentError.new("입력이 비일관적임")
  end

  join = []
  star_3 = []
  star_4 = []
  star_5 = []
  thank = []
  otherwise = []

  for line_unstripped in lines
    line = line_unstripped.strip
    if line.start_with?('【UCA 가입】'); join.push(line[8..-1].strip())
    elsif line.start_with?('【★3】'); star_3.push(line[4..-1].strip())
    elsif line.start_with?('【★4】'); star_4.push(line[4..-1].strip())
    elsif line.start_with?('【★5】'); star_5.push(line[4..-1].strip())
    elsif line.start_with?('【감사의 표시】'); thank.push(line[8..-1].strip())
    else                              otherwise.push(line)
    end
  end

  [join, star_3, star_4, star_5, thank, otherwise].map { |cell|
    '"' + cell.join("\n") + '"'
  }.join("\t")
}.join("\r\n")
