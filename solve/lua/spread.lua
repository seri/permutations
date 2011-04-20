#! /usr/bin/lua

require "common"

used = {}

function recurse(k)
	for i = 1, n do
		if not used[i] then
			a[k] = 96 + i
			if k == n then
				output()
			else
				used[k] = true
				recurse(k + 1)
				used[k] = false
			end
		end
	end
end

skeleton(ORDERED, function ()
	for i = 1, n do
		used[i] = false
	end 
	recurse(1)
end)
