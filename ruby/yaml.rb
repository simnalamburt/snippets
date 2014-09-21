require 'yaml'

puts YAML.load <<YAML
bkground:
  snucheat:   cd ~/snucheat && ./app.py
  hyeonme:    cd ~/hyeon.me && ruby server.rb
irc:
  weechat:    cd ~ && TERM=screen-256color weechat-curses
YAML
