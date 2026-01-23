add_exec(EXEC_NAME)

file(GLOB SRC_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
# message("SRC_FILES = ${SRC_FILES}")
# message("EXEC_NAME = ${EXEC_NAME}")

target_sources(${EXEC_NAME} PRIVATE ${SRC_FILES})
target_include_directories(${EXEC_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)