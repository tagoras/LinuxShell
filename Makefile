shell.out: main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o
	g++ main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o -o shell.out

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

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o