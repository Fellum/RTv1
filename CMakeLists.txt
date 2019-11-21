cmake_minimum_required(VERSION 3.15)
project(RTv1 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/libft)
include_directories(lib/libft/include)

add_subdirectory(lib/SDL2-2.0.10)
include_directories(lib/SDL2-2.0.10/include)

aux_source_directory(src src)
include_directories(include)

add_executable(RTv1 ${src} include/rtv_structs.h)
target_link_libraries(RTv1 SDL2)
target_link_libraries(RTv1 libft)
target_link_libraries(RTv1 m)
