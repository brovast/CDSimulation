# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\IndSoftware\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\IndSoftware\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\XMH_PROJECT\QT\CDSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\XMH_PROJECT\QT\CDSimulation\build\cursor

# Utility rule file for qcustomplot_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/progress.make

qcustomplot_autogen_timestamp_deps: src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/build.make
.PHONY : qcustomplot_autogen_timestamp_deps

# Rule to build all files generated by this target.
src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/build: qcustomplot_autogen_timestamp_deps
.PHONY : src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/build

src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/clean:
	cd /d D:\XMH_PROJECT\QT\CDSimulation\build\cursor\src && $(CMAKE_COMMAND) -P CMakeFiles\qcustomplot_autogen_timestamp_deps.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/clean

src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\XMH_PROJECT\QT\CDSimulation D:\XMH_PROJECT\QT\CDSimulation\src D:\XMH_PROJECT\QT\CDSimulation\build\cursor D:\XMH_PROJECT\QT\CDSimulation\build\cursor\src D:\XMH_PROJECT\QT\CDSimulation\build\cursor\src\CMakeFiles\qcustomplot_autogen_timestamp_deps.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/qcustomplot_autogen_timestamp_deps.dir/depend
