# Corona
A toolkit designed for custom C++ code injection in Super Mario Sunshine. This kit can be used to create new enemies, objects, bosses, items, anything you can imagine.

# Setting Up
Corona needs a few things to successfully run. First you need Python 3.6 to run the script that compiles your code. Make sure thar you install the Python YAML library as well. 

Another thing that is required for use is CodeWarrior. You have the option of searching for one and praying that it works, or message me on Discord (shibboleet#1010) and I will give you the version that Nintendo used. This is preferred over other compilers because of how CodeWarrior deals with inheritance and other factors. Once you have CodeWarrior, please it in the CodeWarrior folder. The binary in CodeWarrior that compiles your code should be named "mwcceppc".

You will also need Ninji's program that injects the actual code into a DOL file, but this is supplied in the "Kamek" folder. The source to Kamek can be found [here.](https://github.com/Treeki/Kamek)

The last thing you will need to use this program is a symbols file. Sadly, only the NUS version is supported with symbols, with no intention of adding PAL or JAP until somebody generates a symbols text file in the same format for the region. The symbols used can be found in "symbols/symbols-us.txt". To generate this file, convertMap.py takes an IDA map file and converts it for use with Kamek. This also needs Python 3.6.

The last thing you will need is an actual project. I have supplied two in the "Projects" folder to use for example. Each project has a YAML that defines what source files to compile, where to inject the code into, and the output you wish to have. These parameters will be explained below.

# Compiling
To compile a project, you simply run the compileProject script. The syntax it uses is:

```
compileProject.py <ProjectName> [optional] <inputDOL> <outputDOL>
```
As noted, the input DOL and output DOL names are optional if you are not injecting into the DOL.

If your code fails to compile, read the error and attempt to fix it, and if you can't seem to get something to compile, contact me.

# YAML
As said above, the library uses a YAML file to determine what to do with your code. The comments next to each variable explains how it works.
```yaml
source_filenames:  // the filenames in "src" that you want to compile. It can be as many as you want, with respect to limits to where you can put your code.
    - "SpawnCoin"

baseAddress: 0x80001810 // the address the code will be injected at. Be careful with this one.
outputBinary: true // this will output the raw binary of your code.
outputGekko: false // this will output a Gekko code for use with cheats, etc
outputDOL: true // this will output a DOL file to use. If you have this set to true, you HAVE to specify the DOL names in the compile script!
```

# Bugs
If there's any bugs or errors that are spotted, open a Issue in the "Issues" tab and I'll try my best to resolve the error.

# Credits
Ninji -- Creating Kamek and helping me with setup
Yoshi2 -- Misc Reverse Engineering
MasterF0x -- Misc Reverse Engineering
Miluaces -- Misc Reverse Engineering

Have fun.