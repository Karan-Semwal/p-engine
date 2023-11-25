cmake_minimum_required(VERSION 3.0)

project(p-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")

# Add the source files to your project
file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/pengine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Player/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Map/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Collision/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AssetManager/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Animation/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameStates/*cpp
)

# Add the executable target
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# Set the include directories
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system 
    sfml-window 
    sfml-graphics
    sfml-audio
)
