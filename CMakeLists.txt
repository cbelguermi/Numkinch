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

set(SOURCE_FILES Main.cpp Core/GameEngine.cpp Core/GameEngine.h Core/GameState.h Core/MainMenuState.cpp Core/MainMenuState.h Core/GameStateManager.cpp Core/GameStateManager.h GUI/Element.h GUI/Element.cpp GUI/Button.cpp GUI/Button.h GUI/Background.cpp GUI/Background.h Core/ChooseCharactersState.cpp Core/ChooseCharactersState.h Logic/CharacterFactory.cpp Logic/CharacterFactory.h Logic/Race.cpp Logic/Race.h Logic/Class.cpp Logic/Class.h Logic/Elf.cpp Logic/Elf.h Logic/Skill.cpp Logic/Skill.h Logic/Dwarf.cpp Logic/Dwarf.h Logic/Assassin.cpp Logic/Assassin.h Logic/Paladin.cpp Logic/Paladin.h Core/PlayState.cpp Core/PlayState.h GUI/Sprite.cpp GUI/Sprite.h GUI/GUIConstants.h Logic/Races.h Logic/Classes.h Logic/LogicConstants.h)
add_executable(Numkinch ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(Numkinch ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
