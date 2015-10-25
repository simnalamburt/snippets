type exp = Num of int
         | Nil

let exp = Num 30;;

match exp with
| Num(x) when x > 100 -> true
| _ -> false
