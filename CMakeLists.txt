CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project (main)

set (EXECUTABLE_OUTPUT_PATH ${PRODECT_SOURCE_DIR}/bin)

aux_source_directory (src SRC_LIST)

include_directories (inc)

add_executable(main ${SRC_LIST})