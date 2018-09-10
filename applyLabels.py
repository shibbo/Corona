# a small script for updating symbols from symbols/symbols-us.txt

with open("symbols/symbols-us.txt", "rb") as f:
    data = f.readlines()

for line in data:
    splitAddr = line.split("=")
    addr = splitAddr[1]
    name = splitAddr[0]

    set_name(int(addr, 0), name)