cmake_minimum_required(VERSION 3.7)
project(Numkinch)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-build-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(SDL2 REQUIRED)

if (APPLE)
    set(SDL2_IMAGE_INCLUDE_DIR /Library/Frameworks/SDL2_image.framework/Headers)
    set(SDL2_IMAGE_LIBRARY /Library/Frameworks/SDL2_image.framework)

    set(SDL2_TTF_INCLUDE_DIR /Library/Frameworks/SDL2_ttf.framework/Headers)
    set(SDL2_TTF_LIBRARY /Library/Frameworks/SDL2_ttf.framework)
endif (APPLE)

set(SOURCE_FILES Main.cpp Core/GameEngine.cpp Core/GameEngine.h Core/GameState.h Core/MainMenuState.cpp Core/MainMenuState.h Core/GameStateManager.cpp Core/GameStateManager.h GUI/Element.h GUI/Element.cpp GUI/Button.cpp GUI/Button.h GUI/MenuBackground.cpp GUI/MenuBackground.h GUI/ChooseCharacterMenu.h GUI/ChooseCharacterMenu.cpp Core/ChooseCharactersState.cpp Core/ChooseCharactersState.h)
add_executable(Numkinch ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(Numkinch ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
