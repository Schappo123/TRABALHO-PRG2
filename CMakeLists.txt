cmake_minimum_required(VERSION 4.1.2)
project(TRABALHO-PRG2 C)

set(CMAKE_C_STANDARD 23)

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
        libprg
        GIT_REPOSITORY https://github.com/Schappo123/libprg.git
        GIT_TAG        main
)
FetchContent_MakeAvailable(libprg)

add_executable(TRABALHO-PRG2 main.c
        src/interface.c
        src/sistema.c
        include/sistema.h
        include/interface.h
)


target_link_libraries(TRABALHO-PRG2 PUBLIC libprg)