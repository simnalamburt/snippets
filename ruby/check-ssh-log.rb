# 아래와 같이 액세스로그를 얻고
#
#     journalctl -u ssh | rg -i '^(...............) .* (failed|accepted) password for (?:invalid user )?(.*) from (.*) port.*$' -r '$1,$2,$3,$4'
#
# 아래와 같이 접근패턴을 보면 됨
#
#     ruby check-ssh-log.rb | rg -B1 '^000+1'

data = open('a').each_line.map { |line| line.chomp.split(',') }
dict = {}

for entry in data
  time = entry[0]
  accepted = entry[1] == 'Accepted'
  username = entry[2]
  ip = entry[3]
  val = dict[ip]

  if val.nil?
    dict[ip] = [[accepted, time, username]]
  else
    dict[ip] += [[accepted, time, username]]
  end
end

for key, value in dict
  next if value.length == 1
  next if value.all? { |e| e[0] }

  puts key
  puts value.map { |e| e[0] ? '1' : '0' } .join()
  puts
end
