all: HW3

HW3: main.o fightFunctions.o bossFunctions.o debugPrint.o
	gcc main.o fightFunctions.o bossFunctions.o debugPrint.o -o HW3

main.o: main.c
	gcc -g -c main.c

fightFunctions.o: fightFunctions.c
	gcc -g -c fightFunctions.c
	
bossFunctions.o: bossFunctions.c
	gcc -g -c bossFunctions.c
	
debugPrint.o: debugPrint.c
	gcc -g -c debugPrint.c
	
#Put your stuff ABOVE this line!
#If you have trouble, and you KNOW THAT YOU DID THE MAKEFILE CORRECTLY,
#then try the following things:
#	1. change "${OUTPUT_PATH}" in your run command to your actual executable name you made in this file, 
#	   adding .exe to the end, and putting it in the quotes
#	2. Hit the button to the left of the run button (the green arrow). Highlighted, it
#	   should be the one for build (you can try using clean and build, but you can only
#	   (use it if you have successfully compiled and ran once). Then run your code (that's what this clean 
#	   target is for!)
#The following things might make you do the above:
#	You run the program, and you get something saying your executable is not found
#	You change your code, but you see no change in the output, even though you should.

#For the debugger to work correctly, add -g to all your target commands (before your -c/-o in the command)

#A note on this clean command: HW3 is assuming that you are calling your executable "HW3"
#in your first target (using -o). If you are not using HW3 as the name, change your executable 
#name, or change the executable name in this clean command.
clean:
	rm -f *.o HW3.exe  