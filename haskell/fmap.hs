import Data.Char (ord)

main :: IO ()
main = do
  print (fmap ord "Hello, world!")
