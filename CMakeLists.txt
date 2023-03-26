cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 11) # or 14, 17, etc.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(vulkan_example_1)

# Add MoltenVK library
find_library(
  MOLTENVK_LIB MoltenVK
  PATHS ${CMAKE_SOURCE_DIR}/external/MoltenVK/MoltenVK.xcframework/MacOS)

# Add GLFW library
find_package(glfw3 REQUIRED)

# Add Vulkan library
find_package(Vulkan REQUIRED)

# Add source files
set(SOURCES src/main.cpp src/lve_window.cpp src/first_app.cpp src/lve_pipeline.cpp)
# Create executable
add_executable(vulkan_example_1 ${SOURCES})

# Link libraries
target_link_libraries(vulkan_example_1 ${MOLTENVK_LIB} glfw Vulkan::Vulkan)
