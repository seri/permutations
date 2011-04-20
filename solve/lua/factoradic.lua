#! /usr/bin/lua

require "common"

f = {}

function permute(k)
	for i = 1, n - 1 do
		local pos = math.floor(k / f[n - i]) + i
		local tmp = a[pos] 
		for j = pos, i + 1, -1 do 
			a[j] = a[j - 1]
		end 
		a[i] = tmp
		k = k % f[n - i]
	end
end

skeleton(ORDERED, function ()
	f[0] = 1
	for i = 1, n do
		f[i] = f[i - 1] * i
	end

	local top = f[n]
	for k = 0, top - 1 do
		undo()
		permute(k)
		output()
	end
end)
