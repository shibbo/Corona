# converts an IDA exported MAP to externals.txt for Kamek

# Example:
# 0001:802342C4       startPause__9RumbleMgrFv
# to
# startPause__9RumbleMgrFv=0x802342C4

import os, sys

if not os.path.exists(sys.argv[1]):
	raise RuntimeError(f"Error: Input file {sys.argv[1]} not found.")

newFile = []

with open(sys.argv[1], "r") as f:
    data = f.readlines()

for line in data:
	# so first we need to split it based on spaces
    newLine = line.split(" ")

	# now we get the line that has our address
    newerLine = newLine[1]

	# now we get our address
    addressList = newerLine.split(":")

	# now we get our actual address from the gotten data
    lineAddress = addressList[1]
	# strip some stuff we don't care about
    symbol = newLine[-1].strip("\r\n")

	# do not include nullsubs and def_addr symbols as well as j_ stubs
    if symbol.find("nullsub") != -1 or symbol.find("def_") != -1 or symbol.find("j_") != -1:
        continue

	# add our address to this list as well as add the symbol to it
    newFile.append(f"{symbol}=0x{lineAddress}\n")

with open("symbols/symbols-us.txt", "w") as f:
    for line in newFile:
        f.write(line)