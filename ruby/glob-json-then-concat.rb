# frozen_string_literal: true
require 'json'

results = []

Dir.glob('text*/**/*.json') do |path|
  obj = JSON.load(open(path))
  raise 'Unexpected format' if obj.class != Array
  for entry in obj
    raise 'Unexpected format' if entry.class != Hash
    raise 'Unexpected format' if entry.keys != ['identifier', 'text']
    text = entry['text']
    raise 'Unexpected format' if text.class != String
    results.append(text)
  end
end
puts JSON.pretty_generate(results)
