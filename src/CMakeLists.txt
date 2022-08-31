if(CMAKE_BUILD_TYPE STREQUAL Coverage) 
  add_compile_options(--coverage)
endif()

file(GLOB_RECURSE SOURCES *.cc)

add_library(chttpp SHARED ${SOURCES})

target_link_libraries(chttpp gcov)
