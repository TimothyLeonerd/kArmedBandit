cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
SET(projName kArmedBandit)
project (${projName})

include_directories("${PROJECT_SOURCE_DIR}/include")

message(STATUS "${PROJECT_SOURCE_DIR}") 

SET(SRC
  src/kArmedBandit.cpp
  src/kArmedBanditEnsemble.cpp
  src/lever.cpp
  src/leverSet.cpp
  src/main.cpp
)

SET(HEADERS
  include/kArmedBandit.h
  include/kArmedBanditEnsemble.h
  include/lever.h
  include/leverSet.h
)

add_executable (${projName}  ${SRC} ${HEADERS})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${projName})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)