Instructions for compiling and running the code: 

*------------------------------------------------------------------------------------------*

for the stack simulator: 
	use: g++ -stdc++11 -o executablename programname.cpp

for the accumulator simulator: 
	use: g++ -std=c++11 -o executablename programname.cpp

for both the stack and accumulator based machines, make sure that you have the attached stackCode.txt or accumCode.txt 
in the same directory as the .cpp file and it's corresponding executable file.


i experienced extensive difficulty with every single aspect of this homework, particularly 
reading the data portion into memory. 


Biggest programming hurdle i was not able to overcome (so far): 

*------------------------------------------------------------------------------------------*

i wanted to iterate through the registers that were stored sequentially as string pointers and
dereference the address to get the variable name that was stored at that address. that way i could 
get the address of the correct destination via a for loop and not have to use a very long switch/if 
statement sequence. This was beyond my current capabilities as a programmer so i had to settle for 
the latter. (which line number did that start on.) 
	
The original copy of the MIPS assembly file is included in this repository for reference.