{-# LANGUAGE OverloadedStrings #-}
import qualified Data.ByteString.Char8 as Bytes
import System.IO
import System.IO.Error
import Control.Monad

main :: IO()
main = do
  input <- openFile "input" ReadMode
  output <- openFile "a.out" WriteMode
  untilIOError $ process input output
  hClose input
  hClose output

process input output = do
  line <- Bytes.hGetLine input
  if Bytes.isPrefixOf "꾸" line
    then Bytes.hPutStrLn output line
    else return ()

untilIOError action = do
  catchIOError (forever action) (\_ -> return())
