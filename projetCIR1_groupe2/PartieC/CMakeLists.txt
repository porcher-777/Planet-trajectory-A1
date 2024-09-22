cmake_minimum_required(VERSION 3.18)
project(projetCIR1_groupe2 C)

set(CMAKE_C_STANDARD 99)

add_executable(projetCIR1_groupe2 main.c init.c methode.c opeVect.c dessin_SDL.c)

target_link_libraries(projetCIR1_groupe2 SDL2 m)