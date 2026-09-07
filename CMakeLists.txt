cmake_minimum_required(VERSION 3.10)

project(cutievanilla LANGUAGES C)

set(CMAKE_C_STANDARD 11)


# Adiciona dependências internas
add_subdirectory(libs/filecore)
add_subdirectory(libs/utils)

# Adiciona o executável principal
set(LIB_SOURCES
    src/cutievanilla.c
    
    src/io/image_io.c

    src/matrix/matrix.c


    # Formats implementations
    src/io/bmp/bmp_io.c
    src/io/jpeg/jpeg_io.c
    src/io/jpg/jpg_io.c
    src/io/png/png_io.c
    src/io/tiff/tiff_io.c
    
)

# Cria lib static
add_library(${PROJECT_NAME} STATIC
    ${LIB_SOURCES}
)

# Linkagem
target_link_libraries(${PROJECT_NAME} PRIVATE
    # packet
    # minisocket
    utils
    filecore
)

# Header público exposto para quem linka com a lib
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Headers privados dentro de src/ (visíveis apenas pelos .c da própria lib)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io
)


# Linka as dependências internas à biblioteca estática
target_link_libraries(${PROJECT_NAME} PRIVATE
    utils
    filecore
)