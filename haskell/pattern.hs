{-# LANGUAGE OverloadedStrings #-}

import qualified Data.ByteString.Char8 as B

spacedConcat :: [B.ByteString] -> B.ByteString
spacedConcat [] = B.empty
spacedConcat [b] = b
spacedConcat bs = do
  mconcat [head bs, " ", spacedConcat $ tail bs]

main :: IO ()
main = do
  B.putStrLn $ spacedConcat ["I", "am", "hungry"]
