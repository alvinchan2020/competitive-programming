import Control.Monad
import Data.Int

solve :: Int64 -> Int64
solve n
  | n `mod` 2050 /= 0 = -1
  | otherwise = bitsSum $ quot n 2050
  where
    bitsSum i = sum $ read <$> (\c -> [c]) <$> show i

solveIO :: IO ()
solveIO = do
  l <- getLine
  let t = read l :: Int64
  putStr $ show (solve t) ++ "\n"

main :: IO ()
main = do
  l <- getLine
  let t = read l :: Int
  replicateM_ t solveIO
