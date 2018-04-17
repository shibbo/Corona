# converts an IDA exported MAP to externals.txt for Kamek

# Example:
# 0001:802342C4       startPause__9RumbleMgrFv
# to
# startPause__9RumbleMgrFv=0x802342C4

import os, sys

if not os.path.exists(sys.argv[1]):
	raise RuntimeError(f"Error: Input file {sys.argv[1]} not found.")

newFile = []
numSymbols = 0
discardedSymbols = 0

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
        discardedSymbols += 1
        continue

    # so IDA does not allow symbols to start with "sub__", even though some functions do have this name.
    # so we replace "subtract__" with "sub__" here.
    if symbol.find("subtract__") != -1:
        # we get our right side, which is the class that holds this method
        symbolHolder = symbol.split("__")
        # now we create our symbol, with sub__ and our original class that had this method
        symbol = f"sub__{symbolHolder[1]}"

	# add our address to this list as well as add the symbol to it
    newFile.append(f"{symbol}=0x{lineAddress}\n")
    numSymbols += 1

with open("symbols/symbols-us.txt", "w") as f:
    for line in newFile:
        f.write(line)

print(f"Done. Wrote {numSymbols} symbols, and discarded {discardedSymbols}.")