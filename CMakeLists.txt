cmake_minimum_required(VERSION 3.16)

project(life)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_library(SfmlWrapp STATIC graph_wrapp/graph_wrapp.cc)

target_link_libraries(SfmlWrapp PRIVATE sfml-window sfml-system sfml-graphics)
target_compile_options(SfmlWrapp PUBLIC -Wall -Wextra -Wpedantic)
target_compile_features(SfmlWrapp PRIVATE cxx_std_17)

add_executable(${PROJECT_NAME} game/game_life.c main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE SfmlWrapp)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
#
target_include_directories(${PROJECT_NAME} PRIVATE game)
target_include_directories(${PROJECT_NAME} PRIVATE graph_wrapp)
