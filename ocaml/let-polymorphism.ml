open Printf

let f = fun x -> x;;
printf "%d\n" (f(f) 2)
