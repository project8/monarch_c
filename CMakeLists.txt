cmake_minimum_required (VERSION 2.6)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
project (monarch)

# protocol buffers
find_package (Protobuf REQUIRED)
#set (PBUF_C_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../protobuf-c-0.15/src)
#include_directories(${PROTOBUF_INCLUDE_DIRS} ${PBUF_C_ROOT})
set (LIBS ${LIBS} ${PROTOBUF_LIBRARIES} protobuf-c)

# build shared libraries
set (BUILD_SHARED_LIBS ON)
set (CMAKE_BUILD_TYPE Debug)

# source subdirs
include_directories (
    ${PROJECT_SOURCE_DIR}/src
)

set (MONARCH_HDR_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/monarch.h
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set (MONARCH_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/monarch.c
)

protobuf_generate_c(
	GENERATED_PROTO_SOURCE_FILES 
	GENERATED_PROTO_HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/pbuf/MonarchHeader.proto
)

set (MONARCH_TEST_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test/monarch_test.c
)

add_library(monarch ${MONARCH_SRC_FILES} ${GENERATED_PROTO_SOURCE_FILES})
target_link_libraries(monarch ${LIBS})

add_executable(monarch_test ${MONARCH_TEST_SRC_FILES})
target_link_libraries(monarch_test monarch ${LIBS})
