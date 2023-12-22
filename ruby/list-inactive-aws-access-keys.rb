# frozen_string_literal: true
require 'json'
require 'date'

ractors = JSON.parse(`aws iam list-users`)['Users'].map do |user|
  Ractor.new(user) do |user|
    # Path, UserId, Arn, CreateDate, PasswordLastUsed
    name = user['UserName']

    for key in JSON.parse(`aws iam list-access-keys --user-name '#{name}'`)['AccessKeyMetadata']
      # AccessKeyId, Status, CreateDate
      key_id = key['AccessKeyId']
      lastinfo = JSON.parse(`aws iam get-access-key-last-used --access-key-id '#{key_id}'`)['AccessKeyLastUsed']
      # Region, ServiceName
      lastdate = lastinfo['LastUsedDate']
      if lastdate.nil?
        # Never used
        puts "#{key_id}\t#{name}\t\tNever used"
      elsif 90 < (delta = DateTime.now - DateTime.iso8601(lastdate))
        # Older than 90 days
        puts "#{key_id}\t#{name}\t#{lastdate}\t#{delta.to_i} days"
      end
    end
  end
end

# Wait for all ractors to finish
ractors.each(&:take)
