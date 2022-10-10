cmake_minimum_required(VERSION 3.16)

project(life)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_library(SfmlWrapp STATIC graph_wrapp.cc)

target_link_libraries(SfmlWrapp PRIVATE sfml-window sfml-system sfml-graphics)
target_compile_options(SfmlWrapp PUBLIC -Wall -Wextra -Wpedantic)
target_compile_features(SfmlWrapp PRIVATE cxx_std_17)

add_executable(${PROJECT_NAME} game_life.cc main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE SfmlWrapp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)