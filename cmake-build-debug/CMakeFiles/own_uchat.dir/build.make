# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mburenko/Documents/own_uchat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mburenko/Documents/own_uchat/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/own_uchat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/own_uchat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/own_uchat.dir/flags.make

CMakeFiles/own_uchat.dir/main.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/own_uchat.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/main.c.o   -c /Users/mburenko/Documents/own_uchat/main.c

CMakeFiles/own_uchat.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/main.c > CMakeFiles/own_uchat.dir/main.c.i

CMakeFiles/own_uchat.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/main.c -o CMakeFiles/own_uchat.dir/main.c.s

CMakeFiles/own_uchat.dir/server/src/server.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/server/src/server.c.o: ../server/src/server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/own_uchat.dir/server/src/server.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/server/src/server.c.o   -c /Users/mburenko/Documents/own_uchat/server/src/server.c

CMakeFiles/own_uchat.dir/server/src/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/server/src/server.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/server/src/server.c > CMakeFiles/own_uchat.dir/server/src/server.c.i

CMakeFiles/own_uchat.dir/server/src/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/server/src/server.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/server/src/server.c -o CMakeFiles/own_uchat.dir/server/src/server.c.s

CMakeFiles/own_uchat.dir/client/src/client.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/client/src/client.c.o: ../client/src/client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/own_uchat.dir/client/src/client.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/client/src/client.c.o   -c /Users/mburenko/Documents/own_uchat/client/src/client.c

CMakeFiles/own_uchat.dir/client/src/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/client/src/client.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/client/src/client.c > CMakeFiles/own_uchat.dir/client/src/client.c.i

CMakeFiles/own_uchat.dir/client/src/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/client/src/client.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/client/src/client.c -o CMakeFiles/own_uchat.dir/client/src/client.c.s

CMakeFiles/own_uchat.dir/server/src/openDB.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/server/src/openDB.c.o: ../server/src/openDB.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/own_uchat.dir/server/src/openDB.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/server/src/openDB.c.o   -c /Users/mburenko/Documents/own_uchat/server/src/openDB.c

CMakeFiles/own_uchat.dir/server/src/openDB.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/server/src/openDB.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/server/src/openDB.c > CMakeFiles/own_uchat.dir/server/src/openDB.c.i

CMakeFiles/own_uchat.dir/server/src/openDB.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/server/src/openDB.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/server/src/openDB.c -o CMakeFiles/own_uchat.dir/server/src/openDB.c.s

CMakeFiles/own_uchat.dir/server/src/dbRequest.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/server/src/dbRequest.c.o: ../server/src/dbRequest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/own_uchat.dir/server/src/dbRequest.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/server/src/dbRequest.c.o   -c /Users/mburenko/Documents/own_uchat/server/src/dbRequest.c

CMakeFiles/own_uchat.dir/server/src/dbRequest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/server/src/dbRequest.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/server/src/dbRequest.c > CMakeFiles/own_uchat.dir/server/src/dbRequest.c.i

CMakeFiles/own_uchat.dir/server/src/dbRequest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/server/src/dbRequest.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/server/src/dbRequest.c -o CMakeFiles/own_uchat.dir/server/src/dbRequest.c.s

CMakeFiles/own_uchat.dir/client/src/string_api.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/client/src/string_api.c.o: ../client/src/string_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/own_uchat.dir/client/src/string_api.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/client/src/string_api.c.o   -c /Users/mburenko/Documents/own_uchat/client/src/string_api.c

CMakeFiles/own_uchat.dir/client/src/string_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/client/src/string_api.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/client/src/string_api.c > CMakeFiles/own_uchat.dir/client/src/string_api.c.i

CMakeFiles/own_uchat.dir/client/src/string_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/client/src/string_api.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/client/src/string_api.c -o CMakeFiles/own_uchat.dir/client/src/string_api.c.s

CMakeFiles/own_uchat.dir/client/src/command_api.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/client/src/command_api.c.o: ../client/src/command_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/own_uchat.dir/client/src/command_api.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/client/src/command_api.c.o   -c /Users/mburenko/Documents/own_uchat/client/src/command_api.c

CMakeFiles/own_uchat.dir/client/src/command_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/client/src/command_api.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/client/src/command_api.c > CMakeFiles/own_uchat.dir/client/src/command_api.c.i

CMakeFiles/own_uchat.dir/client/src/command_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/client/src/command_api.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/client/src/command_api.c -o CMakeFiles/own_uchat.dir/client/src/command_api.c.s

CMakeFiles/own_uchat.dir/client/src/printer.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/client/src/printer.c.o: ../client/src/printer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/own_uchat.dir/client/src/printer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/client/src/printer.c.o   -c /Users/mburenko/Documents/own_uchat/client/src/printer.c

CMakeFiles/own_uchat.dir/client/src/printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/client/src/printer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/client/src/printer.c > CMakeFiles/own_uchat.dir/client/src/printer.c.i

CMakeFiles/own_uchat.dir/client/src/printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/client/src/printer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/client/src/printer.c -o CMakeFiles/own_uchat.dir/client/src/printer.c.s

CMakeFiles/own_uchat.dir/client/src/socked_api.c.o: CMakeFiles/own_uchat.dir/flags.make
CMakeFiles/own_uchat.dir/client/src/socked_api.c.o: ../client/src/socked_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/own_uchat.dir/client/src/socked_api.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/own_uchat.dir/client/src/socked_api.c.o   -c /Users/mburenko/Documents/own_uchat/client/src/socked_api.c

CMakeFiles/own_uchat.dir/client/src/socked_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/own_uchat.dir/client/src/socked_api.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mburenko/Documents/own_uchat/client/src/socked_api.c > CMakeFiles/own_uchat.dir/client/src/socked_api.c.i

CMakeFiles/own_uchat.dir/client/src/socked_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/own_uchat.dir/client/src/socked_api.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mburenko/Documents/own_uchat/client/src/socked_api.c -o CMakeFiles/own_uchat.dir/client/src/socked_api.c.s

# Object files for target own_uchat
own_uchat_OBJECTS = \
"CMakeFiles/own_uchat.dir/main.c.o" \
"CMakeFiles/own_uchat.dir/server/src/server.c.o" \
"CMakeFiles/own_uchat.dir/client/src/client.c.o" \
"CMakeFiles/own_uchat.dir/server/src/openDB.c.o" \
"CMakeFiles/own_uchat.dir/server/src/dbRequest.c.o" \
"CMakeFiles/own_uchat.dir/client/src/string_api.c.o" \
"CMakeFiles/own_uchat.dir/client/src/command_api.c.o" \
"CMakeFiles/own_uchat.dir/client/src/printer.c.o" \
"CMakeFiles/own_uchat.dir/client/src/socked_api.c.o"

# External object files for target own_uchat
own_uchat_EXTERNAL_OBJECTS =

own_uchat: CMakeFiles/own_uchat.dir/main.c.o
own_uchat: CMakeFiles/own_uchat.dir/server/src/server.c.o
own_uchat: CMakeFiles/own_uchat.dir/client/src/client.c.o
own_uchat: CMakeFiles/own_uchat.dir/server/src/openDB.c.o
own_uchat: CMakeFiles/own_uchat.dir/server/src/dbRequest.c.o
own_uchat: CMakeFiles/own_uchat.dir/client/src/string_api.c.o
own_uchat: CMakeFiles/own_uchat.dir/client/src/command_api.c.o
own_uchat: CMakeFiles/own_uchat.dir/client/src/printer.c.o
own_uchat: CMakeFiles/own_uchat.dir/client/src/socked_api.c.o
own_uchat: CMakeFiles/own_uchat.dir/build.make
own_uchat: CMakeFiles/own_uchat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable own_uchat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/own_uchat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/own_uchat.dir/build: own_uchat

.PHONY : CMakeFiles/own_uchat.dir/build

CMakeFiles/own_uchat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/own_uchat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/own_uchat.dir/clean

CMakeFiles/own_uchat.dir/depend:
	cd /Users/mburenko/Documents/own_uchat/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mburenko/Documents/own_uchat /Users/mburenko/Documents/own_uchat /Users/mburenko/Documents/own_uchat/cmake-build-debug /Users/mburenko/Documents/own_uchat/cmake-build-debug /Users/mburenko/Documents/own_uchat/cmake-build-debug/CMakeFiles/own_uchat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/own_uchat.dir/depend

