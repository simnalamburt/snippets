# frozen_string_literal: true
`echo "returning 123..."`
puts "Failed: exit status is #{$?}" unless $?.success?

`exit 123`
puts "Failed: exit status is #{$?}" unless $?.success?

exit $?.exitstatus
