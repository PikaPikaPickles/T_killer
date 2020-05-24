cmake_minimum_required(VERSION 3.17)
project(T_killer)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(T_killer main.cpp YourKletka.cpp YourKletka.h Entity.cpp Entity.h Animation.cpp Animation.h Enemy.cpp Enemy.h AntyBody.cpp AntyBody.h Virus.cpp Virus.h)

target_link_libraries(T_killer sfml-graphics sfml-audio)