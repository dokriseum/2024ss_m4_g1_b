# Setzt die minimale Version von CMake, die erforderlich ist
cmake_minimum_required(VERSION 3.26)

# Definiert den Namen des Projekts und die verwendete Sprache
project(ReversiGame LANGUAGES CXX)

# Setzt den C++-Standard, der vom Projekt verwendet wird
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fügt Compiler-Warnungen hinzu
add_compile_options(-Wall -Wextra)

# Definiert die Quelldateien für das Projekt
set(SOURCE_FILES
    Board.cpp
    GameManager.cpp
    Menu.cpp
    Player.cpp
    main.cpp
)

# Erstellt ein ausführbares Programm mit dem angegebenen Namen und den Quelldateien
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Linkt die Standard C++ Bibliothek
target_link_libraries(${PROJECT_NAME} stdc++)
