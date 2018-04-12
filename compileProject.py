# Super Mario Sunshine Project Compiler v0.1
# by shibboleet

# This project aims to compile projects using a YAML file to define where to inject, and what to output

# 3/26/18 -- Add a bunch of stuff, and fix some wording, and add nice exits

import os, subprocess, sys

projectName = ""
codeFiles = []
cwFlags = "-i . -I- -i ../include -Cpp_exceptions off -enum int -Os -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0"
cwLocation = "CodeWarrior/mwcceppc.exe"
kamekLocation = "Kamek/Kamek.exe"

# first we check to see if we have the basic library installed for YAML, PyYAML
try:
	import yaml
except ImportError:
	raise RuntimeError("Error: Module for YAML not found / malfunctioning. Try using pip to (re)install PyYAML.")

# make sure we have our compiler as well
if not os.path.exists(cwLocation):
	raise RuntimeError("Error: Missing compiler. Be sure to have the compiler (mwcceppc) in your CodeWarrior folder.")
	
# now we need to make sure we have Kamek
if not os.path.exists(kamekLocation):
	raise RuntimeError("Error: Missing Kamek program. Be sure to have Kamek in the Kamek folder.")

# if we do, we continue with getting our input project
# now we get our input project name so we know which folder to look for

# we may be missing an arg, let's see...
if len(sys.argv) < 2:
	raise RuntimeError("Error: Missing project name.\nSyntax: compileProject.py <ProjectName> <inputDOL> <outputDOL>")

# we are not, so we get our project name
projectName = sys.argv[1]

if not os.path.exists(f"Projects/{projectName}"):
	raise RuntimeError("Error: Missing project folder. Be sure that the project folder is placed in the same directory as this script.")

# change our current working directory to the project's directory
os.chdir(f"Projects/{projectName}")

# now we check for our YAML
if os.path.exists(f"Projects/{projectName}/{projectName}.yaml"):
	raise RuntimeError("Error: Missing project YAML. Be sure there's a YAML placed in the project directory.")

# and now we open it right up and get the data
with open(f"{projectName}.yaml", "rb") as f:
	data = f.read()

# load our yaml
yamlData = yaml.load(data)

# now we have access to the entire yaml, this is important
# first thing we need are all of our source files, and our destination address
codeFiles = yamlData['source_filenames']

# change our directory to use CodeWarrior
os.chdir("../../CodeWarrior")

for name in codeFiles:
	print(f"Compiling {name}...")
	
	if not os.path.isdir(f"../Projects/{projectName}/bin"):
		os.mkdir(f"../Projects/{projectName}/bin")
	
	# 3/26/18 -- Use subprocess to get a proper error return if the compile fails
	if subprocess.call(f"mwcceppc.exe {cwFlags} -c -o ../Projects/{projectName}/bin/{name}.o ../Projects/{projectName}/source/{name}.cpp") == 1:
		raise RuntimeError("Compile failed. Fix the above errors and attempt to run the program again.")

# our code is now compiled and we have our compile .o files
# our next step is the kamek step. this tool does whatever we ask it to
# but for now we need to get all of our YAML information to see what kamek will do
outputDOL = yamlData['outputDOL']
outputGekko = yamlData['outputGekko']
outputBinary = yamlData['outputBinary']
baseAddress = hex(yamlData['baseAddress'])

# 3/26/18 -- Make the input and output dol names command line enterable, and error if we don't have them
if len(sys.argv) < 3 and outputDOL == True:
	raise RuntimeError("This project is set to import and export a DOL, but no DOL was specified!")
	
inputDOLStr = sys.argv[2]
outputDOLStr = sys.argv[3]

# make our current directory Kamek so we can run the next command
os.chdir("../Kamek")

# start the command string, which is the program name
kamekCommand = []
kamekCommand.append("Kamek.exe")

# we add all of our .o files to the command for compiling
for name in codeFiles:
	kamekCommand.append(f"../Projects/{projectName}/bin/{name}.o")
	
# we now add the static address
# TODO -- implement -dynamic
kamekCommand.append(f"-static={baseAddress}")

# if they want a binary file of the compiled code, we add that and point to our bin dir
if outputBinary:
	kamekCommand.append(f"-output-code=../Projects/{projectName}/bin/{projectName}.bin")
	
# if they want a Gekko code of the compiled code, we add that and point to our bin dir
if outputGekko:
	kamekCommand.append(f"-output-gecko=../Projects/{projectName}/bin/{projectName}.txt")
	
# we add our path for external symbols the code may use
# TODO -- regional stuff
kamekCommand.append(f"-externals=../symbols/symbols-us.txt")

# 3/26/18 -- Add in CLI arguments rather than asking
# now if they want to patch the DOL, we get our CLI arguments
if outputDOL:
	kamekCommand.append(f"-input-dol=../{inputDOLStr}.dol")
	kamekCommand.append(f"-output-dol=../{outputDOLStr}.dol")

# run the command, and see what result we get
# 3/26/18 make it better by seeing if it actually worked or not
if subprocess.call(kamekCommand) == 1:
	raise RuntimeError("Kamek failed to execute the command specified.")
else:
	print("Done.")