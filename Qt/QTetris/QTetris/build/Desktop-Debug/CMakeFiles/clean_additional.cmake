# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QTetris_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QTetris_autogen.dir/ParseCache.txt"
  "QTetris_autogen"
  )
endif()
