shell.out: main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o \
	Cd.o Ln.o Mv.o Rm.o Umount.o ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o Chmod.o Time.o Suicide.o \
	Sleep.o Ls.o SignalHandler.o Kill.o Pid.o Signals.o
	g++ -L lrt main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o \
	Ln.o Mv.o Rm.o Umount.o ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o Chmod.o Time.o Suicide.o \
	Sleep.o Ls.o SignalHandler.o Kill.o Pid.o Signals.o -o shell.out

main.o: ./Cpps/main.cpp
	g++ -c ./Cpps/main.cpp

ApplicationRunner.o: ./Cpps/ApplicationRunner.cpp
	g++ -c ./Cpps/ApplicationRunner.cpp

CommandParser.o: ./Cpps/CommandParser.cpp
	g++ -c ./Cpps/CommandParser.cpp

Echo.o: ./Cpps/CommandImplementations/Echo.cpp
	g++ -c ./Cpps/CommandImplementations/Echo.cpp

CommandManager.o: ./Cpps/CommandManager.cpp
	g++ -c ./Cpps/CommandManager.cpp

CommandPicker.o: ./Cpps/CommandPicker.cpp
	g++ -c ./Cpps/CommandPicker.cpp

Cat.o: ./Cpps/CommandImplementations/Cat.cpp
	g++ -c ./Cpps/CommandImplementations/Cat.cpp

Cp.o: ./Cpps/CommandImplementations/Cp.cpp
	g++ -c ./Cpps/CommandImplementations/Cp.cpp

UtilityFunctions.o: ./Cpps/UtilityFunctions.cpp
	g++ -c ./Cpps/UtilityFunctions.cpp

Cd.o: ./Cpps/CommandImplementations/Cd.cpp
	g++ -c ./Cpps/CommandImplementations/Cd.cpp

Ln.o: ./Cpps/CommandImplementations/Ln.cpp
	g++ -c ./Cpps/CommandImplementations/Ln.cpp

Mv.o: ./Cpps/CommandImplementations/Mv.cpp
	g++ -c ./Cpps/CommandImplementations/Mv.cpp

Rm.o: ./Cpps/CommandImplementations/Rm.cpp
	g++ -c ./Cpps/CommandImplementations/Rm.cpp

Umount.o: ./Cpps/CommandImplementations/Umount.cpp
	g++ -c ./Cpps/CommandImplementations/Umount.cpp

ErrorManager.o: ./Cpps/ErrorManager.cpp
	g++ -c ./Cpps/ErrorManager.cpp

Mount.o: ./Cpps/CommandImplementations/Mount.cpp
	g++ -c ./Cpps/CommandImplementations/Mount.cpp

Mkdir.o: ./Cpps/CommandImplementations/Mkdir.cpp
	g++ -c ./Cpps/CommandImplementations/Mkdir.cpp

Id.o: ./Cpps/CommandImplementations/Id.cpp
	g++ -c ./Cpps/CommandImplementations/Id.cpp

Setid.o: ./Cpps/CommandImplementations/Setid.cpp
	g++ -c ./Cpps/CommandImplementations/Setid.cpp

Stat.o: ./Cpps/CommandImplementations/Stat.cpp
	g++ -c ./Cpps/CommandImplementations/Stat.cpp

Chown.o: ./Cpps/CommandImplementations/Chown.cpp
	g++ -c ./Cpps/CommandImplementations/Chown.cpp

Chgrp.o: ./Cpps/CommandImplementations/Chgrp.cpp
	g++ -c ./Cpps/CommandImplementations/Chgrp.cpp

Chmod.o: ./Cpps/CommandImplementations/Chmod.cpp
	g++ -c ./Cpps/CommandImplementations/Chmod.cpp

Time.o: ./Cpps/CommandImplementations/Time.cpp
	g++ -c ./Cpps/CommandImplementations/Time.cpp

Suicide.o: ./Cpps/CommandImplementations/Suicide.cpp
	g++ -c ./Cpps/CommandImplementations/Suicide.cpp

Sleep.o: ./Cpps/CommandImplementations/Sleep.cpp
	g++ -c ./Cpps/CommandImplementations/Sleep.cpp

Ls.o: ./Cpps/CommandImplementations/Ls.cpp
	g++ -c ./Cpps/CommandImplementations/Ls.cpp

SignalHandler.o: ./Cpps/SignalHandler.cpp
	g++ -c ./Cpps/SignalHandler.cpp

Kill.o: ./Cpps/CommandImplementations/Kill.cpp
	g++ -c ./Cpps/CommandImplementations/Kill.cpp	

Pid.o: ./Cpps/CommandImplementations/Pid.cpp
	g++ -c ./Cpps/CommandImplementations/Pid.cpp

Signals.o: ./Cpps/CommandImplementations/Signals.cpp
	g++ -c ./Cpps/CommandImplementations/Signals.cpp

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o Ln.o Mv.o Rm.o Umount.o \
	ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o Chmod.o Time.o Suicide.o Sleep.o Ls.o SignalHandler.o Kill.o Pid.o Signals.o