import Common 

permute :: [a] -> [[a]]
permute [] = [[]]
permute (x:xs) = concatMap (inject x) (permute xs)
				   
inject :: a -> [a] -> [[a]]
inject x [] = [[x]]
inject x (y:ys) = (x:y:ys) : map (y:) (inject x ys)

main = do skeleton "unordered" permute
