# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtGameTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtGameTest_autogen.dir/ParseCache.txt"
  "QtGameTest_autogen"
  )
endif()
