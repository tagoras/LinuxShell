shell.out: main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o \
	Cd.o Ln.o Mv.o Rm.o Umount.o ErrorManager.o
	g++ main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o \
	Ln.o Mv.o Rm.o Umount.o ErrorManager.o -o shell.out

main.o: ./Cpps/main.cpp
	g++ -c ./Cpps/main.cpp

ApplicationRunner.o: ./Cpps/ApplicationRunner.cpp
	g++ -c ./Cpps/ApplicationRunner.cpp

CommandParser.o: ./Cpps/CommandParser.cpp
	g++ -c ./Cpps/CommandParser.cpp

Echo.o: ./Cpps/Echo.cpp
	g++ -c ./Cpps/Echo.cpp

CommandManager.o: ./Cpps/CommandManager.cpp
	g++ -c ./Cpps/CommandManager.cpp

CommandPicker.o: ./Cpps/CommandPicker.cpp
	g++ -c ./Cpps/CommandPicker.cpp

Cat.o: ./Cpps/Cat.cpp
	g++ -c ./Cpps/Cat.cpp

Cp.o: ./Cpps/Cp.cpp
	g++ -c ./Cpps/Cp.cpp

UtilityFunctions.o: ./Cpps/UtilityFunctions.cpp
	g++ -c ./Cpps/UtilityFunctions.cpp

Cd.o: ./Cpps/Cd.cpp
	g++ -c ./Cpps/Cd.cpp

Ln.o: ./Cpps/Ln.cpp
	g++ -c ./Cpps/Ln.cpp

Mv.o: ./Cpps/Mv.cpp
	g++ -c ./Cpps/Mv.cpp

Rm.o: ./Cpps/Rm.cpp
	g++ -c ./Cpps/Rm.cpp

Umount.o: ./Cpps/Umount.cpp
	g++ -c ./Cpps/Umount.cpp

ErrorManager.o: ./Cpps/ErrorManager.cpp
	g++ -c ./Cpps/ErrorManager.cpp

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o Ln.o Mv.o Umount.o \
	ErrorManager.o