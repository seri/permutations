module Common where

import System (getArgs, getProgName)
import IO
import Data.Char

maxSize :: Int
maxSize = 12

skeleton :: String -> (String -> [String]) -> IO ()
skeleton ordered permutator = do 
    app <- getProgName
    arg <- getArgs
    if length arg < 1
        then error $ "Usage: " ++ app ++ " <size> [filename]\n"
        else do
    let n :: Int
        n = read $ head arg
    if n < 1 || n > maxSize
        then error $ "Constraint: 1 <= size <= " ++ show maxSize ++ 
                     "(got " ++ show n ++ ")"
        else do 
    hOut <- if length arg > 1
        then openFile (head $ tail arg) WriteMode
        else return stdout
    hPutStrLn hOut $ show n ++ " " ++ ordered
    hPutStrLn hOut $ unlines $ permutator ['a' .. chr(96 + n)]
    hClose hOut
