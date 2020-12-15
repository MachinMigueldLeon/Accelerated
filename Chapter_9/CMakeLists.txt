cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Release)
set( PROJECT_APPLICATION_NAME Notas )
project(${PROJECT_APPLICATION_NAME})


SET(SRC   src/grade.cpp
            src/median.cpp
            src/student_info.cpp)

SET(HDR     include/grade.h
            include/median.h
            include/student_info.h)


add_library(${PROJECT_APPLICATION_NAME} SHARED ${SRC} ${HDR})
target_include_directories(${PROJECT_APPLICATION_NAME} PUBLIC include )

add_executable(MyExe app/main.cpp)
target_link_libraries( MyExe PUBLIC ${PROJECT_APPLICATION_NAME})