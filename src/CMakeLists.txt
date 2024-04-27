cmake_minimum_required (VERSION 3.24)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (Swimming  "main.cpp ""swim.cpp"" ${MY_INCLUDE_DIR}/swim.h")
target_include_directories(Swimming PUBLIC ${MY_INCLUDE_DIR})
