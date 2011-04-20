#! /usr/bin/lua

require "common"

function permute(k)
	for i = 2, n do
		swap(i, k % i + 1)
		k = math.floor(k / i)
	end
end

skeleton(UNORDERED, function ()
	local top = 1
	for i = 2, n do
		top = top * i
	end

	for k = 0, top - 1 do
        undo()
		permute(k)
		output()
	end
end)
