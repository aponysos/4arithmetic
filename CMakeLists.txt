#
# Nicholas Yue nicholas_yue@users.sourceforge.net
#
# Note:
# (1) A dummy file include/config.h is required (remance from configure)
# (2) Default installation directory is /usr/local, override with -DCMAKE_INSTALL_PREFIX="" during cmake
#     invocation
# (3) Do the usual "make clean all" to build the library
# (4) To install either "make install" or "make install DESTDIR=<your directory>"
# (5) Need to include changes in include/log4cpp/Portability.hh for OSX to build

PROJECT ( 4ARITHMATIC )

INCLUDE_DIRECTORIES ( include )
INCLUDE_DIRECTORIES ( . )

IF (WIN32)
  ADD_DEFINITIONS ( -D_CRT_SECURE_NO_WARNINGS )
  ADD_DEFINITIONS ( -Wall )
ENDIF (WIN32)

IF ( CMAKE_BUILD_TYPE MATCHES "Debug" )
  SET ( 4ARITHMATIC_LIBRARY_NAME "4arithmaticD" )
ELSE ( CMAKE_BUILD_TYPE MATCHES "Debug" )
  SET ( 4ARITHMATIC_LIBRARY_NAME "4arithmatic" )
ENDIF ( CMAKE_BUILD_TYPE MATCHES "Debug" )

ADD_LIBRARY ( ${4ARITHMATIC_LIBRARY_NAME}
#  src/4arithmetic.cpp
  src/Combination.cpp
  src/Expression.cpp
  src/FourArithmeticProblem.cpp
  src/Fraction.cpp
  src/Util.cpp
)

IF (WIN32)
  TARGET_LINK_LIBRARIES (${4ARITHMATIC_LIBRARY_NAME} kernel32 user32 ws2_32 advapi32 liblog4cppD.a)
  SET_TARGET_PROPERTIES(${4ARITHMATIC_LIBRARY_NAME} PROPERTIES LINK_FLAGS /NODEFAULTLIB:msvcrt )
ENDIF (WIN32)
