

add_library(colorspace STATIC
    colorspace.c

)

target_include_directories(colorspace
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)