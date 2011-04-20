#! /usr/bin/lua

require "common"

d = {}

function trotter()
    while true do
        output()

        local k = n + 2
        for i = 1, n do
            if a[i] > a[i + d[i]] and a[i] > a[k] then
                k = i
            end
        end
        if k == n + 2 then
            break
        end

        local j = a[k]
        local k2 = k + d[k]
        a[k], a[k2] = a[k2], a[k]
        d[k], d[k2] = d[k2], d[k]
        for i = 1, n do
            if a[i] > j then
                d[i] = d[i] * (-1)
            end
        end
    end
end

skeleton(UNORDERED, function ()
    a[0] = n + 97
    a[n + 1] = n + 97
    a[n + 2] = 0

    for i = 1, n do
        d[i] = -1
    end

    trotter()
end)
