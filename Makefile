shell.out: main.o ApplicationRunner.o CommandParser.o
	g++ main.o ApplicationRunner.o CommandParser.o -o shell.out

main.o: ./Cpps/main.cpp
	g++ -c ./Cpps/main.cpp

ApplicationRunner.o: ./Cpps/ApplicationRunner.cpp
	g++ -c ./Cpps/ApplicationRunner.cpp

CommandParser.o: ./Cpps/CommandParser.cpp
	g++ -c ./Cpps/CommandParser.cpp

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o