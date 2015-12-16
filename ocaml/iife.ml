let new_var = begin
  let counter = ref (-1) in
  (fun () -> begin
    counter := !counter + 1;
    "α" ^ (string_of_int !counter)
  end)
end
