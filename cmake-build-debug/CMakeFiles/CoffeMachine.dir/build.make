# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /cygdrive/c/Users/leog/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/leog/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CoffeMachine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CoffeMachine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CoffeMachine.dir/flags.make

CMakeFiles/CoffeMachine.dir/main.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CoffeMachine.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/main.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/main.cpp

CMakeFiles/CoffeMachine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/main.cpp > CMakeFiles/CoffeMachine.dir/main.cpp.i

CMakeFiles/CoffeMachine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/main.cpp -o CMakeFiles/CoffeMachine.dir/main.cpp.s

CMakeFiles/CoffeMachine.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/main.cpp.o.requires

CMakeFiles/CoffeMachine.dir/main.cpp.o.provides: CMakeFiles/CoffeMachine.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/main.cpp.o.provides

CMakeFiles/CoffeMachine.dir/main.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/main.cpp.o


CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o: ../DataProcessor/Stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/Stack.cpp

CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/Stack.cpp > CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.i

CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/Stack.cpp -o CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.s

CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.requires

CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.provides: CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.provides

CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o


CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o: ../DataProcessor/DataProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/DataProcessor.cpp

CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/DataProcessor.cpp > CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.i

CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/DataProcessor.cpp -o CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.s

CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.requires

CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.provides: CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.provides

CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o


CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o: ../ExecutionProcessor/ExecutionProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ExecutionProcessor/ExecutionProcessor.cpp

CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ExecutionProcessor/ExecutionProcessor.cpp > CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.i

CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ExecutionProcessor/ExecutionProcessor.cpp -o CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.s

CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.requires

CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.provides: CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.provides

CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o


CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o: ../CommandProcessor/CommandProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/CommandProcessor/CommandProcessor.cpp

CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/CommandProcessor/CommandProcessor.cpp > CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.i

CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/CommandProcessor/CommandProcessor.cpp -o CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.s

CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.requires

CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.provides: CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.provides

CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o


CMakeFiles/CoffeMachine.dir/Processor.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/Processor.cpp.o: ../Processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CoffeMachine.dir/Processor.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/Processor.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/Processor.cpp

CMakeFiles/CoffeMachine.dir/Processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/Processor.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/Processor.cpp > CMakeFiles/CoffeMachine.dir/Processor.cpp.i

CMakeFiles/CoffeMachine.dir/Processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/Processor.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/Processor.cpp -o CMakeFiles/CoffeMachine.dir/Processor.cpp.s

CMakeFiles/CoffeMachine.dir/Processor.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/Processor.cpp.o.requires

CMakeFiles/CoffeMachine.dir/Processor.cpp.o.provides: CMakeFiles/CoffeMachine.dir/Processor.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/Processor.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/Processor.cpp.o.provides

CMakeFiles/CoffeMachine.dir/Processor.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/Processor.cpp.o


CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o: ../CommandProcessor/Commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/CommandProcessor/Commands.cpp

CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/CommandProcessor/Commands.cpp > CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.i

CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/CommandProcessor/Commands.cpp -o CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.s

CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.requires

CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.provides: CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.provides

CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o


CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o: ../DataProcessor/Dictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/Dictionary.cpp

CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/Dictionary.cpp > CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.i

CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/DataProcessor/Dictionary.cpp -o CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.s

CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.requires

CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.provides: CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.provides

CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o


CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o: ../InputProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/InputProcessor.cpp

CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/InputProcessor.cpp > CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.i

CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/InputProcessor.cpp -o CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.s

CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.requires

CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.provides: CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.provides

CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o


CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o: ../TinyXML2/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/TinyXML2/tinyxml2.cpp

CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/TinyXML2/tinyxml2.cpp > CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.i

CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/TinyXML2/tinyxml2.cpp -o CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.s

CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.requires

CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.provides: CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.provides

CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o


CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o: ../ModuleSupport/ModulesInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/ModulesInterface.cpp

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/ModulesInterface.cpp > CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.i

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/ModulesInterface.cpp -o CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.s

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.requires

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.provides: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.provides

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o


CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o: ../ModuleSupport/UniversalModuleInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/UniversalModuleInterface.cpp

CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/UniversalModuleInterface.cpp > CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.i

CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/UniversalModuleInterface.cpp -o CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.s

CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.requires

CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.provides: CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.provides

CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o


CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o: CMakeFiles/CoffeMachine.dir/flags.make
CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o: ../ModuleSupport/ModuleContainer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o -c /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/ModuleContainer.cpp

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/ModuleContainer.cpp > CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.i

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/ModuleSupport/ModuleContainer.cpp -o CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.s

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.requires:

.PHONY : CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.requires

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.provides: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.requires
	$(MAKE) -f CMakeFiles/CoffeMachine.dir/build.make CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.provides.build
.PHONY : CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.provides

CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.provides.build: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o


# Object files for target CoffeMachine
CoffeMachine_OBJECTS = \
"CMakeFiles/CoffeMachine.dir/main.cpp.o" \
"CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o" \
"CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o" \
"CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o" \
"CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o" \
"CMakeFiles/CoffeMachine.dir/Processor.cpp.o" \
"CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o" \
"CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o" \
"CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o" \
"CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o" \
"CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o" \
"CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o" \
"CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o"

# External object files for target CoffeMachine
CoffeMachine_EXTERNAL_OBJECTS =

CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/main.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/Processor.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/build.make
CoffeMachine.exe: CMakeFiles/CoffeMachine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable CoffeMachine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CoffeMachine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CoffeMachine.dir/build: CoffeMachine.exe

.PHONY : CMakeFiles/CoffeMachine.dir/build

CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/main.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/DataProcessor/Stack.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/DataProcessor/DataProcessor.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/ExecutionProcessor/ExecutionProcessor.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/CommandProcessor/CommandProcessor.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/Processor.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/CommandProcessor/Commands.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/DataProcessor/Dictionary.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/InputProcessor.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/TinyXML2/tinyxml2.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModulesInterface.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/ModuleSupport/UniversalModuleInterface.cpp.o.requires
CMakeFiles/CoffeMachine.dir/requires: CMakeFiles/CoffeMachine.dir/ModuleSupport/ModuleContainer.cpp.o.requires

.PHONY : CMakeFiles/CoffeMachine.dir/requires

CMakeFiles/CoffeMachine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CoffeMachine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CoffeMachine.dir/clean

CMakeFiles/CoffeMachine.dir/depend:
	cd /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug /cygdrive/c/Users/leog/Documents/GitHub/CoffeMachine/cmake-build-debug/CMakeFiles/CoffeMachine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CoffeMachine.dir/depend

