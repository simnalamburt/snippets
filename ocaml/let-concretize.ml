let _ =
  let
    f = ref (fun x -> x)
  in
    f := fun x -> x + 1;
    (!f) true
