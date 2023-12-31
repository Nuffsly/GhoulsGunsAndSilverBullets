cmake_minimum_required(VERSION 3.17)
project(project_ghost)

# Använd C++ 17.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#[[# På skolans Linux-system finns två versioner av GCC. Se vilken som används:
if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)

    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif()
endif()

if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/7.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-7.1.0/bin/g++)

    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif()
endif()]]

# Välj vilka delar av SFML som ska användas.
set(SFML_MODULES audio network graphics window system)

# Försök att hitta SFML genom att anropa 'FindSFML.cmake'.
find_package(SFML 2 COMPONENTS ${SFML_MODULES})
include_directories(${SFML_INCLUDE_DIR})

# Om det inte gick hoppas vi att det är installerat i alla fall.
if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
    set(SFML_LIBRARIES "")
    foreach(i ${SFML_MODULES})
        list(APPEND SFML_LIBRARIES "sfml-${i}")
    endforeach(i)
endif()

# Ange källfiler, lägg till de filer som ni behöver!
set(SOURCE_FILES main.cpp game_objects/Game_Object.cpp game_objects/Game_Object.h game_objects/Textured_Object.cpp game_objects/Textured_Object.h game_objects/Player.cpp game_objects/Player.h managers/World.cpp managers/World.h managers/Texture_Manager.cpp managers/Texture_Manager.h game_objects/Enemy.cpp game_objects/Weapon.cpp game_objects/Weapon.h states/State.cpp states/State.h game_objects/Projectile.cpp game_objects/Projectile.h states/Game_State.cpp states/Game_State.h containers/Upgrade.cpp containers/Upgrade.h containers/Player_Info.cpp containers/Player_Info.h game_objects/Money.cpp game_objects/Weapon.cpp managers/Sound_Manager.cpp managers/Sound_Manager.h game_objects/Upgrade_Pillar.cpp game_objects/Upgrade_Pillar.h game_objects/Door.cpp game_objects/Door.h game_objects/Hud.cpp game_objects/Hud.h states/Menu_State.cpp states/Menu_State.h)

# Säg till CMake att skapa en körbar fil som heter 'project_ghost'.
add_executable(project_ghost ${SOURCE_FILES})

# Länka med biblioteken som vi hittade tidigare.
target_link_libraries(project_ghost ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
