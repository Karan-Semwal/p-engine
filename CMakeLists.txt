cmake_minimum_required(VERSION 3.0)

project(game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(p-engine)

file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/game/Game/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game/GameStates/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game/main.cpp
)

include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/game/Game/include
    ${CMAKE_CURRENT_SOURCE_DIR}/game/GameStates/include
    ${CMAKE_CURRENT_SOURCE_DIR}/game/Levels/include
    ${CMAKE_CURRENT_SOURCE_DIR}/p-engine/include
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE p-engine)