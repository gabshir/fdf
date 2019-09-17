cmake_minimum_required(VERSION 3.13)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "libft/srcs/*.c")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "libft/includes/*.h")
file(GLOB_RECURSE SOURCES2 RELATIVE ${CMAKE_SOURCE_DIR} "srcs/*.c")
file(GLOB_RECURSE HEADERS2 RELATIVE ${CMAKE_SOURCE_DIR} "includes/*.h")
project(fdf)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)
include_directories(libft)
include_directories(libft/includes)
include_directories(libft/sources)
include_directories(srcs)

add_executable(fdf
        ${SOURCES}
        ${HEADERS}
        ${HEADERS2}
        ${SOURCES2}
        )
target_link_libraries(fdf "-lmlx")
target_link_libraries(fdf "-framework OpenGl")
target_link_libraries(fdf "-framework Appkit")