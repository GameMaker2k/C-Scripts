local start = 0
local finish = 0
local step = 1
local file

if #arg >= 1 then
    finish = tonumber(arg[1])
end
if #arg >= 2 then
    start = tonumber(arg[2])
end
if #arg >= 3 then
    step = tonumber(arg[3])
end
if #arg >= 4 then
    file = io.open(arg[4], "w")
end

print("Executing with arguments " .. finish .. ", " .. start .. ", " .. step)
if file then
    file:write("Executing with arguments " .. finish .. ", " .. start .. ", " .. step .. "\n")
    print("Writing output to file " .. arg[4])
    file:write("Writing output to file " .. arg[4] .. "\n")
end

if step == 0 then
    step = 1
end

local tstart = os.time()

if finish <= start then
    for i = start, finish, -step do
        print(i)
        if file then
            file:write(i .. "\n")
        end
    end
else
    for i = start, finish, step do
        print(i)
        if file then
            file:write(i .. "\n")
        end
    end
end

local tend = os.time()
local tcheck = os.difftime(tend, tstart)

print("Executed in " .. tcheck .. " seconds")
if file then
    file:write("Executed in " .. tcheck .. " seconds\n")
    file:close()
end
