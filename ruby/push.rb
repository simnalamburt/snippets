# frozen_string_literal: true
require 'rest_client'
require 'json'

token = '********************'

class String
  def green; "\033[32m#{self}\033[0m" end
  def white; "\033[37m#{self}\033[0m" end
end

Dir.foreach '.' do |project|
  next if project == '.' or project == '..'
  next unless File.directory? project
  next unless Dir.exist? File.join project, '.git'
  puts "#{project}:".white

  print "  Creating project..."
  response = JSON.parse RestClient.post \
    'http://git.upnl.org/api/v3/projects',
    {
      name: project,
      namespace_id: 38, # upnl-museum
      issues_enabled: false,
      merge_requests_enabled: false,
      wiki_enabled: false,
      snippets_enabled: false,
      visibility_level: 10, # internal
    },
    :'PRIVATE-TOKEN' => token
  puts " done!"

  puts "  Pushing..."
  Dir.chdir project
  `git remote add origin #{response['http_url_to_repo']}`
  loop do
    `git push -u origin master`
    break if $?.success?
  end
  Dir.chdir '..'
  puts "  done!"

  print "  Moving..."
  File.rename project, (File.join '..', 'nforge-done', project)

  puts " done!".green
end
