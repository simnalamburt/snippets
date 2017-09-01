# frozen_string_literal: true
require 'curses'

Curses.init_screen

wins = (0..10).map do |i|
  Curses::Window.new(1, 0, 2 + i, 0)
end

1000.times do
  win = wins.sample
  win << '*'
  win.refresh

  sleep 0.001
end

msg = Curses::Window.new(1, 0, 0, 0)
msg << 'Done!'
msg.refresh
msg.getch
