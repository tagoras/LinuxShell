shell.out: main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o \
	Cd.o Ln.o Mv.o Rm.o Umount.o ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o
	g++ main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o \
	Ln.o Mv.o Rm.o Umount.o ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o -o shell.out

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

Mount.o: ./Cpps/Mount.cpp
	g++ -c ./Cpps/Mount.cpp

Mkdir.o: ./Cpps/Mkdir.cpp
	g++ -c ./Cpps/Mkdir.cpp

Id.o: ./Cpps/Id.cpp
	g++ -c ./Cpps/Id.cpp

Setid.o: ./Cpps/Setid.cpp
	g++ -c ./Cpps/Setid.cpp

Stat.o: ./Cpps/Stat.cpp
	g++ -c ./Cpps/Stat.cpp

Chown.o: ./Cpps/Chown.cpp
	g++ -c ./Cpps/Chown.cpp

Chgrp.o: ./Cpps/Chgrp.cpp
	g++ -c ./Cpps/Chgrp.cpp

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o Ln.o Mv.o Rm.o Umount.o \
	ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o