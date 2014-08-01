pattern = [
  'html',
  'css',
  'js',
  'erb',
  'svg',
  'Gemfile',
  'rb',
  'ru',
  'md',
  'README',
  'readme',
  'gitignore'
]
exclude = [
  'Gemfile.lock',
  'public/codemirror/',
  'public/filetree/',
  'public/lib/',
  'public/mode/',
  'public/theme/',
  'config/',
  'node_modules/',
  'vendor/assets/',
]

cmd = "git log --pretty=tformat: --numstat | egrep -h '%s' | egrep -v '%s'" % [pattern.join('|'), exclude.join('|')]

result = Array.new
ARGV.each do |arg|
  puts " * #{arg}"
  addsum = 0;
  delsum = 0;

  output = `cd #{arg} && #{cmd}`
  output.lines.each do |line|
    token = line.split("\t")
    add = token[0].to_i
    del = -token[1].to_i
    puts "%+10d%10d : %s" % [add, del, token[2]]
    addsum += add
    delsum += del
  end
  puts "----------------------"
  puts "%+10d%10d" % [addsum, delsum]
  puts ""

  result.push({ :name => arg, :add => addsum, :del => delsum })
end

if result.length > 1
  result.each do |entity|
    puts "%15s : %+d, %d" % [entity[:name], entity[:add], entity[:del]]
  end
end
