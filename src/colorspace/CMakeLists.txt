

add_library(colorspace STATIC
    colorspace.c

    colorspace_internal.c

    converters/from_bgr.c
    converters/from_bgra.c
    converters/from_bin.c
    converters/from_cmyk.c
    converters/from_gray.c
    converters/from_hsl.c
    converters/from_hsv.c
    converters/from_rgb.c
    converters/from_rgba.c

)

target_include_directories(colorspace
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)