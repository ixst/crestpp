file(GLOB_RECURSE SOURCES *.cc)

add_executable(app ${SOURCES})

target_link_libraries(app chttpp)
