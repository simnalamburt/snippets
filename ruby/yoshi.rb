# frozen_string_literal: true

# http://i.imgur.com/kwnQ6Iy.png

class String
  def yoshi
    ([0xC3] + self.encode('CP949').unpack('C*') + [0xA4]).pack('C*').force_encoding('CP949').encode('UTF-8')
  end
end

puts '아그란도시즌'.yoshi   # 첸튿溜促돕쳅制
puts '요시초콜릿먹어'.yoshi # 첼鵝쳉珏賻뉨禿在
