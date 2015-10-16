let rec makelist1 (num: int) a b : int * int * int=
  if num > 0 then
    makelist1 (num - 1) a b
  else
    100, a, b

let rec makelist2 (num: int) a b: int * int * int =
  let ret, _, _ = if num > 0 then
    makelist1 (num - 1) a b
  else
    100, a, b
  in
  ret, a, b
