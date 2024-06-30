cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    raytracer-cpp
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare executable ----

add_executable(raytracer-cpp_exe source/main.cpp
        source/Riptracer.cpp
        source/Riptracer.h)
add_executable(raytracer-cpp::exe ALIAS raytracer-cpp_exe)

find_package(fmt 7.1.3 REQUIRED)
target_link_libraries(raytracer-cpp_exe PUBLIC fmt::fmt)

find_package(spdlog REQUIRED)
target_link_libraries(raytracer-cpp_exe PRIVATE spdlog::spdlog)

set_property(TARGET raytracer-cpp_exe PROPERTY OUTPUT_NAME raytracer-cpp)

target_compile_features(raytracer-cpp_exe PRIVATE cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT raytracer-cpp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of raytracer-cpp"
  )
endif()

include(cmake/dev-mode.cmake)
