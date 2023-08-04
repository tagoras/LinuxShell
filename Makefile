shell.out: main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o \
	Cd.o Ln.o Mv.o Rm.o Umount.o ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o Chmod.o Time.o Suicide.o \
	Sleep.o Ls.o SignalHandler.o Kill.o Pid.o Signals.o Run.o CommandLogger.o Find.o
	g++ -g -L lrt -L pthread main.o ApplicationRunner.o CommandParser.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o \
	Ln.o Mv.o Rm.o Umount.o ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o Chmod.o Time.o Suicide.o \
	Sleep.o Ls.o SignalHandler.o Kill.o Pid.o Signals.o Run.o CommandLogger.o Find.o -o shell.out

main.o: ./Cpps/main.cpp
	g++  -c -g ./Cpps/main.cpp

ApplicationRunner.o: ./Cpps/ApplicationRunner.cpp
	g++ -c -g ./Cpps/ApplicationRunner.cpp

CommandParser.o: ./Cpps/CommandParser.cpp
	g++ -c -g ./Cpps/CommandParser.cpp

Echo.o: ./Cpps/CommandImplementations/Echo.cpp
	g++ -c -g ./Cpps/CommandImplementations/Echo.cpp

CommandManager.o: ./Cpps/CommandManager.cpp
	g++ -c -g ./Cpps/CommandManager.cpp

CommandPicker.o: ./Cpps/CommandPicker.cpp
	g++ -c -g ./Cpps/CommandPicker.cpp

Cat.o: ./Cpps/CommandImplementations/Cat.cpp
	g++ -c -g ./Cpps/CommandImplementations/Cat.cpp

Cp.o: ./Cpps/CommandImplementations/Cp.cpp
	g++ -c -g ./Cpps/CommandImplementations/Cp.cpp

UtilityFunctions.o: ./Cpps/UtilityFunctions.cpp
	g++ -c -g ./Cpps/UtilityFunctions.cpp

Cd.o: ./Cpps/CommandImplementations/Cd.cpp
	g++ -c -g ./Cpps/CommandImplementations/Cd.cpp

Ln.o: ./Cpps/CommandImplementations/Ln.cpp
	g++ -c -g ./Cpps/CommandImplementations/Ln.cpp

Mv.o: ./Cpps/CommandImplementations/Mv.cpp
	g++ -c -g ./Cpps/CommandImplementations/Mv.cpp

Rm.o: ./Cpps/CommandImplementations/Rm.cpp
	g++ -c -g ./Cpps/CommandImplementations/Rm.cpp

Umount.o: ./Cpps/CommandImplementations/Umount.cpp
	g++ -c -g ./Cpps/CommandImplementations/Umount.cpp

ErrorManager.o: ./Cpps/ErrorManager.cpp
	g++ -c -g ./Cpps/ErrorManager.cpp

Mount.o: ./Cpps/CommandImplementations/Mount.cpp
	g++ -c -g ./Cpps/CommandImplementations/Mount.cpp

Mkdir.o: ./Cpps/CommandImplementations/Mkdir.cpp
	g++ -c -g ./Cpps/CommandImplementations/Mkdir.cpp

Id.o: ./Cpps/CommandImplementations/Id.cpp
	g++ -c -g ./Cpps/CommandImplementations/Id.cpp

Setid.o: ./Cpps/CommandImplementations/Setid.cpp
	g++ -c -g ./Cpps/CommandImplementations/Setid.cpp

Stat.o: ./Cpps/CommandImplementations/Stat.cpp
	g++ -c -g ./Cpps/CommandImplementations/Stat.cpp

Chown.o: ./Cpps/CommandImplementations/Chown.cpp
	g++ -c -g ./Cpps/CommandImplementations/Chown.cpp

Chgrp.o: ./Cpps/CommandImplementations/Chgrp.cpp
	g++ -c -g ./Cpps/CommandImplementations/Chgrp.cpp

Chmod.o: ./Cpps/CommandImplementations/Chmod.cpp
	g++ -c -g ./Cpps/CommandImplementations/Chmod.cpp

Time.o: ./Cpps/CommandImplementations/Time.cpp
	g++ -c -g ./Cpps/CommandImplementations/Time.cpp

Suicide.o: ./Cpps/CommandImplementations/Suicide.cpp
	g++ -c -g ./Cpps/CommandImplementations/Suicide.cpp

Sleep.o: ./Cpps/CommandImplementations/Sleep.cpp
	g++ -c -g ./Cpps/CommandImplementations/Sleep.cpp

Ls.o: ./Cpps/CommandImplementations/Ls.cpp
	g++ -c -g ./Cpps/CommandImplementations/Ls.cpp

SignalHandler.o: ./Cpps/SignalHandler.cpp
	g++ -c -g ./Cpps/SignalHandler.cpp

Kill.o: ./Cpps/CommandImplementations/Kill.cpp
	g++ -c -g ./Cpps/CommandImplementations/Kill.cpp	

Pid.o: ./Cpps/CommandImplementations/Pid.cpp
	g++ -c -g ./Cpps/CommandImplementations/Pid.cpp

Signals.o: ./Cpps/CommandImplementations/Signals.cpp
	g++ -c -g ./Cpps/CommandImplementations/Signals.cpp

Run.o: ./Cpps/CommandImplementations/Run.cpp
	g++ -c -g ./Cpps/CommandImplementations/Run.cpp

Find.o: ./Cpps/CommandImplementations/Find.cpp
	g++ -c -g ./Cpps/CommandImplementations/Find.cpp

CommandLogger.o: ./Cpps/CommandLogger.cpp
	g++ -c -g ./Cpps/CommandLogger.cpp

clean:
	rm -f ApplicationRunner.o CommandParser.o main.o Echo.o CommandManager.o CommandPicker.o Cat.o Cp.o UtilityFunctions.o Cd.o Ln.o Mv.o Rm.o Umount.o \
	ErrorManager.o Mount.o Mkdir.o Id.o Setid.o Stat.o Chown.o Chgrp.o Chmod.o Time.o Suicide.o Sleep.o Ls.o SignalHandler.o Kill.o Pid.o Signals.o Run.o \
	CommandLogger. Find.o CommandLogger.o log.txt