
add_library(type
    type.c

    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/int8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/uint8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/int16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/uint16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/int32.c
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/uint32.c
    
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/float32.c
    ${CMAKE_CURRENT_SOURCE_DIR}/primitive/float64.c
)

target_include_directories(type
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)