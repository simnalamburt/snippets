# frozen_string_literal: true
path = '/opt/nforge/var/svnroot'

class String
  def red;   "\033[31m#{self}\033[0m" end
  def brown; "\033[33m#{self}\033[0m" end
end

errors = []
Dir.foreach path do |item|
  next if item == '.' or item == '..'

  puts "cloning #{item}...".brown
  `git svn clone file://#{path}/#{item}`

  unless $?.success?
    errors.push 'Error: '.red + item.brown + ", #{$?.exitstatus}".red
  end
end

puts '--------------'
puts ''
puts errors
