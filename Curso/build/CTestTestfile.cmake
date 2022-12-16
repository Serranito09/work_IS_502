# CMake generated Testfile for 
# Source directory: /home/alvaro/Escritorio/is/Curso
# Build directory: /home/alvaro/Escritorio/is/Curso/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "runUnitTests")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/alvaro/Escritorio/is/Curso/CMakeLists.txt;13;add_test;/home/alvaro/Escritorio/is/Curso/CMakeLists.txt;0;")
subdirs("ext/googletest")
