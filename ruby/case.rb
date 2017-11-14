# frozen_string_literal: true
puts begin
  case 'lion'
  when /io/i, /eo/
    "사자"
  when /bla/
    "블라"
  else
    "ㅇㅂㅇ"
  end
end
