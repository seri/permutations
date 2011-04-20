#! /usr/bin/lua

require "common"

function recurse(k)
	if k == 1 then
		output()
	else
		for i = 1, k do
			swap(i, k)
			recurse(k - 1)
			swap(i, k)
		end
	end
end

skeleton(UNORDERED, function ()
	recurse(n)
end)

