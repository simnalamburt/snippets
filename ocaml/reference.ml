type tyvar = TyVar of string | NIL

let new_variable: unit -> tyvar =
  let counter = ref 0 in
  fun () -> begin
    let str = Printf.sprintf "__%d" !counter in
    counter := !counter + 1;
    TyVar str
  end

let alpha1 = new_variable ()
let alpha2 = new_variable ()
let alpha3 = new_variable ()
