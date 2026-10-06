
# add_subdirectory(libs/filecore)

add_library(histogram

    ${CMAKE_CURRENT_SOURCE_DIR}/histogram.c
    
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_arithmetic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_compare.c
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_filter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_image.c
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_internal.c    
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_matrix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_search.c
    ${CMAKE_CURRENT_SOURCE_DIR}/histogram_stats.c

    # HISTOGRAMS Formats implementations
    ${CMAKE_CURRENT_SOURCE_DIR}/io/histogram_io.c
    ${CMAKE_CURRENT_SOURCE_DIR}/io/csv/csv_io.c
    ${CMAKE_CURRENT_SOURCE_DIR}/io/txt/txt_io.c
    ${CMAKE_CURRENT_SOURCE_DIR}/io/xlsx/xlsx_io.c

)

target_link_libraries(histogram PRIVATE filecore)

target_include_directories(histogram
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
    PRIVATE
        # ${PROJECT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)