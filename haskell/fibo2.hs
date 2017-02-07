main :: IO ()
main = do
  print (let f = 0:1:((zipWith (+) =<< tail) f) in f)
