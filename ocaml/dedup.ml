(*
 * From Core.Std
 *)
(* returns list without adjacent duplicates *)
let dedup_without_sorting ?(compare=Pervasives.compare) list =
  let rec loop list accum = match list with
    | [] -> accum
    | hd :: [] -> hd :: accum
    | hd1 :: hd2 :: tl ->
        if compare hd1 hd2 = 0
        then loop (hd2 :: tl) accum
        else loop (hd2 :: tl) (hd1 :: accum)
  in
  loop list []

(** returns sorted version of list with duplicates removed *)
let dedup ?(compare=Pervasives.compare) list =
  let sorted = List.sort (fun x y -> compare y x) list in
  dedup_without_sorting ~compare sorted
