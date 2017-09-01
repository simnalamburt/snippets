# frozen_string_literal: true
class String
  def brown; "\033[33m#{self}\033[0m" end
  def green; "\033[32m#{self}\033[0m" end
  def white; "\033[37m#{self}\033[0m" end
end

Dir.foreach '.' do |project|
  next if project == '.' or project == '..'
  next unless File.directory? project
  Dir.chdir project

  entries = Dir.entries('.').reject { |e| %w(. .. .git).include? e }
  next unless entries.length == 1

  dir = entries.first
  puts "#{project.white}: #{dir.brown} only"

  Dir.entries(dir).reject { |e| %w(. ..).include? e }.each do |name|
    src = File.join dir, name
    dst = File.basename name

    puts "  Moving files: " + "#{src} => #{dst}".green
    File.rename src, dst
  end

  puts "  Removing #{dir.brown}..."
  Dir.rmdir dir

  print "  Saving..."
  `git add -A`
  `git commit -am "Remove redundant directory: #{dir}"`
  puts " Done!"

  # clean up
  Dir.chdir '..'
end
