shell.out: main.o ApplicationRunner.o CommandParser.o
	g++ main.o ApplicationRunner.o CommandParser.o -o shell.out

main.o: main.cpp
	g++ -c main.cpp

ApplicationRunner.o: ApplicationRunner.cpp
	g++ -c ApplicationRunner.cpp

CommandParser.o: CommandParser.cpp
	g++ -c CommandParser.cpp

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o