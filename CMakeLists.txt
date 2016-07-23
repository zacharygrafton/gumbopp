cmake_minimum_required(VERSION 3.5)
project(gumbopp)

find_package(Boost REQUIRED)

set(CMAKE_MODULE_PATH $CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

include(ExternalProject)
include(BoostTestHelper)

ExternalProject_Add(
  gumbo-parser
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/gumbo-parser
  CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/gumbo-parser/autogen.sh COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/gumbo-parser/configure --prefix=${CMAKE_CURRENT_BINARY_DIR}/3rdParty
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/3rdParty
  BUILD_COMMAND make
  BUILD_IN_SOURCE 1
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/3rdParty/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(gumbopp_sources
  src/Document.cpp
)

add_library(gumbopp ${gumbopp_sources})
add_dependencies(gumbopp gumbo-parser)
target_compile_features(gumbopp PUBLIC cxx_generic_lambdas)
target_link_libraries(gumbopp ${CMAKE_CURRENT_BINARY_DIR}/3rdParty/lib/libgumbo.a)

enable_testing()
add_boost_test(tests/document/document.cpp)