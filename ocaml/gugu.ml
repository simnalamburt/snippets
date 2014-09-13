open Printf;;

for a = 1 to 9 do
  for b = 2 to 5 do
    printf "%d * %d = %2d\t" b a (a*b)
  done;
  print_char '\n'
done;;

print_char '\n';;

for a = 1 to 9 do
  for b = 6 to 9 do
    printf "%d * %d = %2d\t" b a (a*b)
  done;
  print_char '\n'
done
