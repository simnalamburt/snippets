# frozen_string_literal: true
Session = 'bkground'

class String
  def black;          "\033[30m#{self}\033[0m" end
  def red;            "\033[31m#{self}\033[0m" end
  def green;          "\033[32m#{self}\033[0m" end
  def brown;          "\033[33m#{self}\033[0m" end
  def blue;           "\033[34m#{self}\033[0m" end
  def magenta;        "\033[35m#{self}\033[0m" end
  def cyan;           "\033[36m#{self}\033[0m" end
  def gray;           "\033[37m#{self}\033[0m" end
  def bold;           "\033[1m#{self}\033[22m" end
end

puts ''
puts ' tmux 세션 생성이 완료되었습니다.'.brown
puts ' 아래의 커맨드를 입력해주세요.'
puts ''
puts '   $'.brown + " tmux attach -t #{Session}".bold
puts ''
