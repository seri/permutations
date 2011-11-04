#! /usr/bin/lua

require "common"

function recurse(k)
    if k == 1 then
        output()
    else
        if k % 2 == 0 then
            for i = 1, k - 1 do
                recurse(k - 1)
                swap(i, k)
            end
        else
            for i = 1, k - 1 do
                recurse(k - 1)
                swap(1, k) 
            end
        end
        recurse(k - 1)
    end
end

skeleton(UNORDERED, function ()
    recurse(n) 
end)
