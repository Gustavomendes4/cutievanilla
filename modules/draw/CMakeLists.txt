
# add_subdirectory(libs/filecore)

add_library(draw

    ${CMAKE_CURRENT_SOURCE_DIR}/draw.c
    ${CMAKE_CURRENT_SOURCE_DIR}/draw.c

)

target_include_directories(draw
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
    PRIVATE
        # ${PROJECT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)