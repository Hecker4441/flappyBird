cmake_minimum_required(VERSION 3.16)
PROJECT(bird)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
add_executable(${PROJECT_NAME} main.cpp bird.cpp World.cpp game.cpp StateMachine.cpp MainMenu.cpp gameOver.cpp)

add_subdirectory(./SFML)

target_include_directories(${PROJECT_NAME} PUBLIC SFML/include/SFML)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_directories(${PROJECT_NAME} PRIVATE build/SFML/lib)

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system sfml-network)