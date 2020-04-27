cmake_minimum_required(VERSION 3.15)
project(Qt_Tetris)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR  ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH D:/Qt5.14.1/5.14.1/mingw73_64)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

set(UI_FILES)
set(RC_FILES)
set(QRC_FILES)
set(SOUND_FILES)

set(SOURCE_FILES main.cpp)

add_executable(Qt_Tetris main.cpp
        Core/Tile.h
        Core/Board.cpp Core/Board.h
        Core/Tetris.cpp Core/Tetris.h
        Core/Game.cpp Core/Game.h
		Core/Observer.h 
		Core/Subject.cpp 
		Core/Subject.h
		
        GUI/LabelTile.cpp GUI/LabelTile.h
        GUI/ResetButton.cpp GUI/ResetButton.h
        GUI/GameOverWindow.cpp GUI/GameOverWindow.h
        GUI/GameBoard.cpp GUI/GameBoard.h
        GUI/MainWindow.cpp GUI/MainWindow.h
        )

target_link_libraries(Qt_Tetris Qt5::Widgets Qt5::Core Qt5::Gui)

qt5_use_modules(Qt_Tetris widgets core gui)
