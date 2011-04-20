--- @section Struture

MAX = 12
n = 0
a = {}

UNORDERED = false
  ORDERED = true

function undo()
    for i = 1, n do
        a[i] = 96 + i
    end 
end

function optimize()
    size = 1
    for i = 1, n + 1 do
        size = size * i
    end     
    size = size + 20
    io.output():setvbuf("full", size)    
end 

function skeleton(ordered, body)
    if #arg < 1 then
        print("Usage: " .. arg[0] .. " <size> [filename]") 
        return 1
    end

    n = tonumber(arg[1])
    if n == nil or n < 1 or n > MAX then
        io.stderr:write("Constraint: 1 <= size <= " .. MAX 
                         .. " (got " .. n .. ")\n")
        return 1
    end 

    if #arg > 1 then
        io.output(arg[2])
    end 
    
    io.write(tostring(n) .. " ")
    if ordered then
        io.write("ordered")
    else
        io.write("unordered")
    end
    io.write("\n")

    undo()
    optimize()
    body()
    io.flush()
    io.close()

    return 0
end

function output()
    for i = 1, n do
        io.write(string.char(a[i]))
    end
    io.write("\n")
end

--- @section Helpers

function swap(i, j)
    a[i], a[j] = a[j], a[i]
end
