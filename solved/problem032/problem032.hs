import Data.List (sort, nub)

pandigital :: Show a => [a] -> Bool
pandigital x = sort (filter (/= ' ') (unwords (map show x))) == "123456789"

main = do
putStrLn (show (sum (nub[x*y | x <- [1..100], y <- [1..10000], x < y, x*y < 10000, x*y>1000, pandigital [x,y,x*y]])))
