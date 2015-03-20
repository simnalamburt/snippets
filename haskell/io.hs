{-# LANGUAGE OverloadedStrings #-}
-- 기본 문자열 아주 안좋으니 쓰지 않기

import qualified Data.ByteString.Char8 as Bytes
import System.IO

main :: IO()
main = do
  -- System.IO
  input <- openFile "input" ReadMode
  output <- openFile "a.out" WriteMode

  text <- Bytes.hGetContents input
  Bytes.hPut output text
  hClose input
  hClose output

-- <@즈눅> 참고로 func a b는 a `func` b랑 동치
