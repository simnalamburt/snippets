const direction =
  left  :37
  up    :38
  right :39
  down  :40

cmd = direction.down

getc = switch cmd
       | direction.left  => (it, i) -> grid[it][i]
       | direction.right => (it, i) -> grid[it][3-i]
       | direction.up    => (it, i) -> grid[i][it]
       | direction.down  => (it, i) -> grid[3-i][it]

setc = switch cmd
       | direction.left  => (it, i, val) !-> grid[it][i] = val
       | direction.right => (it, i, val) !-> grid[it][3-i] = val
       | direction.up    => (it, i, val) !-> grid[i][it] = val
       | direction.down  => (it, i, val) !-> grid[3-i][it] = val
