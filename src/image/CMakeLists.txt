
add_library(image STATIC

    image.c

    # IO
    io/image_io.c

    # Formats implementations
    io/bmp/bmp_io.c
    io/jpeg/jpeg_io.c
    io/jpg/jpg_io.c
    io/png/png_io.c
    io/tiff/tiff_io.c

)

target_link_libraries(image
    PRIVATE
        filecore
        matrix
)

target_include_directories(image
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)