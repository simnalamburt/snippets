#!/usr/bin/env ruby
File.readlines('/etc/passwd').each do |line|
  user = line.chomp.split(':')[0]
  next if user.nil?
  output = `crontab -u #{user} -l 2>/dev/null`
  next unless $?.success?
  puts "For \x1b[33m#{user}\x1b[0m ..", output, ''
end
