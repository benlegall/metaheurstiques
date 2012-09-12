project (metaheuristique)

set(
  SOURCES_META
  source/metaheuristique.cpp
  source/circuit.cpp
  source/main.cpp
  )


set(CMAKE_CXX_FLAGS "-W -Wall -std=c++0x")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(/usr/local/lib)


add_executable(
  meta
  ${SOURCES_META}
  )

# add a target to generate API documentation with Doxygen
# find_package(Doxygen)
# if(DOXYGEN_FOUND)

#   configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

#   add_custom_target(doc
#     ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Generating API documentation with Doxygen" VERBATIM
#     )

# endif(DOXYGEN_FOUND)
