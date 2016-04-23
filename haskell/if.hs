import System.Directory

main = do
  exist <- doesFileExist "a"
  putStrLn $ if exist then "Yes!" else "No!"
