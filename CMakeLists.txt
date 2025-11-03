cmake_minimum_required(VERSION 3.16)

project(RPG2D)

# Configuration C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#! ! ! ! ! ! !
# Set this to true to ship the game!
# This will change the RESOURCES_PATH to be the local path
#! ! ! ! ! ! !
option(PRODUCTION_BUILD "Make this a production build!" OFF)

# Configuration MSVC Runtime
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:>")
    add_compile_options(/arch:AVX2) # SIMD optimizations
    # Désactiver les avertissements de sécurité CRT
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# Link Time Optimization
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

# =============================================================================
# SFML Configuration avec FetchContent (téléchargement automatique)
# =============================================================================
include(FetchContent)

# Configurer SFML comme bibliothèque statique
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
set(SFML_BUILD_AUDIO ON CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK ON CACHE BOOL "" FORCE)

# Télécharger SFML 3.0.0
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW TRUE
)

message(STATUS "Téléchargement de SFML... (cela peut prendre quelques minutes la première fois)")
FetchContent_MakeAvailable(SFML)

# =============================================================================
# Configuration du projet RPG2D
# =============================================================================

# Récupérer tous les fichiers sources
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Créer l'exécutable
add_executable(${PROJECT_NAME} ${MY_SOURCES} "src/Systems/PhysicsSystem.cpp")

# Configuration du standard C++
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Définir le chemin des ressources
if(PRODUCTION_BUILD)
    target_compile_definitions(${PROJECT_NAME} PUBLIC 
        RESOURCES_PATH="./assets/"
        PRODUCTION_BUILD=1
    )
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC 
        RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/"
        PRODUCTION_BUILD=0
    )
endif()

# Ajouter les répertoires d'include
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

# Lier les bibliothèques SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
)

# Configuration Windows (supprimer la console en production)
if(MSVC AND PRODUCTION_BUILD)
    set_target_properties(${PROJECT_NAME} PROPERTIES 
        LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
    )
endif()

# Copier les DLLs SFML sur Windows (si compilation en shared)
if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::Graphics>
            $<TARGET_FILE:SFML::Window>
            $<TARGET_FILE:SFML::System>
            $<TARGET_FILE:SFML::Audio>
            $<TARGET_FILE:SFML::Network>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# Message de fin
message(STATUS "==============================================")
message(STATUS "Configuration CMake terminée pour RPG2D")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Production build: ${PRODUCTION_BUILD}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "SFML: Enabled (FetchContent)")
message(STATUS "ImGui: Disabled (not needed for now)")
message(STATUS "==============================================")
