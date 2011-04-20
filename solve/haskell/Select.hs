import Common 

select :: [a] -> [(a, [a])]
select [x] = [(x, [])]
select (x:xs) = (x, xs) : [(y, x:ys) | (y, ys) <- select xs]

permute :: [a] -> [[a]]
permute [x] = [[x]]
permute xs = [y:zs | (y, ys) <- select xs, zs <- permute ys]

main = do skeleton "unordered" permute
