cmake_minimum_required(VERSION 3.0.0)
project(learn_opengl_project VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADER_FILES
	${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -Wextra -Wconversion -Wsign-conversion -Weffc++)

find_package(OpenGL REQUIRED)
find_library(GLFW3 "lib/libglfw3.a")

add_library(GLAD "lib/glad.c")
add_library(STB_IMAGE "lib/stb_image.c")

set(LIBS GLFW3 ${OPENGL_LIBRARY} GLAD STB_IMAGE)

include_directories(
	"${CMAKE_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/include/glad"
	"${CMAKE_SOURCE_DIR}/include/glm"
)

target_link_libraries(${PROJECT_NAME} ${LIBS})
