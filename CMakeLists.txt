# CMakeList.txt : CMake project for opengl-slingshot, include source and define
# project specific logic here.
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required (VERSION 3.8)

project ("opengl-slingshot")

# Add source to this project's executable.
add_executable (opengl-slingshot 
	"opengl-slingshot.cpp" 
	"opengl-slingshot.h" "src/App.cpp" "src/App.h" "src/SampleApp.cpp" "src/SampleApp.h")

add_subdirectory(third_party/glad)
add_subdirectory(third_party/glfw)
add_subdirectory(third_party/glm)

include_directories(third_party/header_only)

target_link_libraries(opengl-slingshot glad glfw glm::glm)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET opengl-slingshot PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
