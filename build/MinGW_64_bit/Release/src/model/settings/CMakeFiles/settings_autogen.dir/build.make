# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Projects\ParsPark\QT\ParsPark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release

# Utility rule file for settings_autogen.

# Include the progress variables for this target.
include src/model/settings/CMakeFiles/settings_autogen.dir/progress.make

src/model/settings/CMakeFiles/settings_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target settings"
	cd /d E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release\src\model\settings && "C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen E:/Projects/ParsPark/QT/ParsPark/build/MinGW_64_bit/Release/src/model/settings/CMakeFiles/settings_autogen.dir/AutogenInfo.json Release

settings_autogen: src/model/settings/CMakeFiles/settings_autogen
settings_autogen: src/model/settings/CMakeFiles/settings_autogen.dir/build.make

.PHONY : settings_autogen

# Rule to build all files generated by this target.
src/model/settings/CMakeFiles/settings_autogen.dir/build: settings_autogen

.PHONY : src/model/settings/CMakeFiles/settings_autogen.dir/build

src/model/settings/CMakeFiles/settings_autogen.dir/clean:
	cd /d E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release\src\model\settings && $(CMAKE_COMMAND) -P CMakeFiles\settings_autogen.dir\cmake_clean.cmake
.PHONY : src/model/settings/CMakeFiles/settings_autogen.dir/clean

src/model/settings/CMakeFiles/settings_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projects\ParsPark\QT\ParsPark E:\Projects\ParsPark\QT\ParsPark\src\model\settings E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release\src\model\settings E:\Projects\ParsPark\QT\ParsPark\build\MinGW_64_bit\Release\src\model\settings\CMakeFiles\settings_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/model/settings/CMakeFiles/settings_autogen.dir/depend

