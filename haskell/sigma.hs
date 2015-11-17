sigma a b f =
  let inner c r =
        if c > b
        then r
        else inner (c+1) (f c+r)
  in
  inner a 0
