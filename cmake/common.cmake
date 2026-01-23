function(add_exec2 EXEC_NAME)
    # message("CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_LIST_DIR}")
    cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH parent1)
    cmake_path(GET parent1 PARENT_PATH parent2)

    cmake_path(GET parent2 FILENAME first_prefix)
    cmake_path(GET parent1 FILENAME second_prefix)
    cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME filename)

    set(${EXEC_NAME} "${first_prefix}_${second_prefix}_${filename}" PARENT_SCOPE)
    add_executable(${first_prefix}_${second_prefix}_${filename} main.cpp)
endfunction()

function(add_exec1 EXEC_NAME)
    cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH parent1)

    cmake_path(GET parent1 FILENAME prefix)
    cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME filename)

    set(${EXEC_NAME} "${prefix}_${filename}" PARENT_SCOPE)
    add_executable(${prefix}_${filename} main.cpp)
endfunction()