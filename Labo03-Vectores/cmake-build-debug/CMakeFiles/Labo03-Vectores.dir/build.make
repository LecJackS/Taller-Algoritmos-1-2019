# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.6/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.6/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labo03-Vectores.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Labo03-Vectores.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labo03-Vectores.dir/flags.make

CMakeFiles/Labo03-Vectores.dir/main.cpp.o: CMakeFiles/Labo03-Vectores.dir/flags.make
CMakeFiles/Labo03-Vectores.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Labo03-Vectores.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Labo03-Vectores.dir/main.cpp.o -c /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/main.cpp

CMakeFiles/Labo03-Vectores.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labo03-Vectores.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/main.cpp > CMakeFiles/Labo03-Vectores.dir/main.cpp.i

CMakeFiles/Labo03-Vectores.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labo03-Vectores.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/main.cpp -o CMakeFiles/Labo03-Vectores.dir/main.cpp.s

CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.o: CMakeFiles/Labo03-Vectores.dir/flags.make
CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.o: ../ejercicios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.o -c /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/ejercicios.cpp

CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/ejercicios.cpp > CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.i

CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/ejercicios.cpp -o CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.s

# Object files for target Labo03-Vectores
Labo03__Vectores_OBJECTS = \
"CMakeFiles/Labo03-Vectores.dir/main.cpp.o" \
"CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.o"

# External object files for target Labo03-Vectores
Labo03__Vectores_EXTERNAL_OBJECTS =

Labo03-Vectores: CMakeFiles/Labo03-Vectores.dir/main.cpp.o
Labo03-Vectores: CMakeFiles/Labo03-Vectores.dir/ejercicios.cpp.o
Labo03-Vectores: CMakeFiles/Labo03-Vectores.dir/build.make
Labo03-Vectores: CMakeFiles/Labo03-Vectores.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Labo03-Vectores"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Labo03-Vectores.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labo03-Vectores.dir/build: Labo03-Vectores

.PHONY : CMakeFiles/Labo03-Vectores.dir/build

CMakeFiles/Labo03-Vectores.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Labo03-Vectores.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Labo03-Vectores.dir/clean

CMakeFiles/Labo03-Vectores.dir/depend:
	cd /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug /home/lcarreira/Taller-Algoritmos-1-2019/Labo03-Vectores/cmake-build-debug/CMakeFiles/Labo03-Vectores.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labo03-Vectores.dir/depend

