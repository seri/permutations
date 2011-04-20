#! /usr/bin/lua

require "common"

function recurse(k)
	for i = 1, n do
		if a[i] == 0 then
			a[i] = 96 + k
			if k == n then
				output()
			else
				recurse(k + 1)
			end
			a[i] = 0
		end
	end
end

skeleton(UNORDERED, function ()
	for i = 1, n do
		a[i] = 0
	end
	recurse(1)
end)
