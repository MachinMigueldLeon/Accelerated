# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build

# Include any dependencies generated for this target.
include CMakeFiles/MyExe2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyExe2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyExe2.dir/flags.make

CMakeFiles/MyExe2.dir/app/main2.cpp.o: CMakeFiles/MyExe2.dir/flags.make
CMakeFiles/MyExe2.dir/app/main2.cpp.o: ../app/main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyExe2.dir/app/main2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyExe2.dir/app/main2.cpp.o -c /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/app/main2.cpp

CMakeFiles/MyExe2.dir/app/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyExe2.dir/app/main2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/app/main2.cpp > CMakeFiles/MyExe2.dir/app/main2.cpp.i

CMakeFiles/MyExe2.dir/app/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyExe2.dir/app/main2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/app/main2.cpp -o CMakeFiles/MyExe2.dir/app/main2.cpp.s

# Object files for target MyExe2
MyExe2_OBJECTS = \
"CMakeFiles/MyExe2.dir/app/main2.cpp.o"

# External object files for target MyExe2
MyExe2_EXTERNAL_OBJECTS =

MyExe2: CMakeFiles/MyExe2.dir/app/main2.cpp.o
MyExe2: CMakeFiles/MyExe2.dir/build.make
MyExe2: libNotas.so
MyExe2: CMakeFiles/MyExe2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyExe2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyExe2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyExe2.dir/build: MyExe2

.PHONY : CMakeFiles/MyExe2.dir/build

CMakeFiles/MyExe2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyExe2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyExe2.dir/clean

CMakeFiles/MyExe2.dir/depend:
	cd /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4 /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4 /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build /home/mmachin/projects/Computer_Simulator/AcceleratedCpp/Chapter_4/build/CMakeFiles/MyExe2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyExe2.dir/depend

