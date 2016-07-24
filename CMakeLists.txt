cmake_minimum_required(VERSION 3.5)
project(gumbopp)

set(GUMBOPP_MAJOR_VERSION 0)
set(GUMBOPP_MINOR_VERSION 0)
set(GUMBOPP_PATCH_VERSION 0)
set(GUMBOPP_VERSION ${GUMBOPP_MAJOR_VERSION}.${GUMBOPP_MINOR_VERSION}.${GUMBOPP_PATCH_VERSION})

set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for library files")
set(INSTALL_CMAKE_DIR lib/cmake/gumbopp CACHE PATH "Installation directory for CMake files")

foreach(p INCLUDE CMAKE LIB)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# Platform checks
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("#include <string_view> int main(int argc, char* argv[]) { return 0; }" GUMBOPP_HAS_NONEXP_STRINGVIEW)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/Config.hpp)

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

include_directories(${CMAKE_CURRENT_BINARY_DIR}/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/3rdParty/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(gumbopp_sources
  src/Document.cpp
  src/Node.cpp
  src/Parser.cpp
  src/Exceptions.cpp
  src/NodeIterator.cpp
  src/Attributes.cpp
  src/AttributeIterator.cpp
  src/Attribute.cpp
)

add_library(gumbopp ${gumbopp_sources})
add_dependencies(gumbopp gumbo-parser)
target_compile_features(gumbopp PUBLIC cxx_generic_lambdas)
target_link_libraries(gumbopp ${CMAKE_CURRENT_BINARY_DIR}/3rdParty/lib/libgumbo.a)

enable_testing()
add_boost_test(tests/document/document.cpp)
add_boost_test(tests/node/node.cpp)

export(PACKAGE gumbpp)

file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(gumboppConfig.cmake.in "${PROJECT_BINARY_DIR}/gumboppConfig.cmake" @ONLY)

set(CONF_INCLUDE_DIRS "\${gumbopp_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(gumboppConfig.cmake.in "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/gumboppConfig.cmake" @ONLY)
configure_file(gumboppConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/gumboppConfigVersion.cmake" @ONLY)

install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/gumboppConfig.cmake"
  "${PROJECT_BINARY_DIR}/gumboppConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}")

install(TARGETS gumbopp EXPORT gumbopp DESTINATION ${INSTALL_LIB_DIR} )
install(EXPORT gumbopp DESTINATION "${INSTALL_CMAKE_DIR}")
install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/Attribute.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/AttributeIterator.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/Attributes.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/Document.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/Exceptions.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/Node.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/NodeIterator.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gumbopp/Parser.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/Config.hpp
  DESTINATION include/gumbopp)