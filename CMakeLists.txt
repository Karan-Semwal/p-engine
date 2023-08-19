cmake_minimum_required(VERSION 3.0)

project(sfml-testing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files to your project
file(GLOB SOURCE_FILES 
    src/*.cpp
    Player/*cpp
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Set the include directories
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Player/include
)

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    sfml-system 
    sfml-window 
    sfml-graphics
    sfml-audio
)
