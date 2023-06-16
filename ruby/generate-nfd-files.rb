# frozen_string_literal: true
require 'fileutils'

count = ARGV[0]&.to_i
if count.nil?
  STDERR.puts "Usage: #{$PROGRAM_NAME} <count>"
  exit 1
end

FileUtils.remove_dir 'test', true
FileUtils.mkdir 'test'

alphabet = ('가'..'힣').to_a.map { |c| c.unicode_normalize(:nfd) } .freeze
for i in 0...count
  FileUtils.touch "test/#{alphabet.sample(20).join}.txt"
end
