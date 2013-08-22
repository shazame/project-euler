import Data.List (sort, nub)

syrastep :: Integer -> Integer
syrastep n | n `rem` 2 == 0 = n `quot`2
syrastep n                  = 3*n+1

syraflight n = syrafreq n [] where
	syrafreq k len | k <= m = (k,len)
	syrafreq k len = etc.



fly :: (Num a, Eq a) => a -> a
fly 1 = 0
fly x = 1 + (if (even x) then (fly (div x 2)) else (fly (x * 3 + 1)))

main = do
	putStrLn (show (fly 13))
