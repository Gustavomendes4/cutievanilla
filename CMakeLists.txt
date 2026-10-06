cmake_minimum_required(VERSION 3.10)

project(cutievanilla LANGUAGES C)

set(CMAKE_C_STANDARD 11)


# Adiciona dependências externas
add_subdirectory(libs/filecore)
add_subdirectory(libs/utils)
add_subdirectory(libs/raylib)


# Adiciona dependências internas
add_subdirectory(src/type)
add_subdirectory(src/histogram)
add_subdirectory(src/matrix)
add_subdirectory(src/image)

# Adiciona o executável principal
set(LIB_SOURCES
    src/cutievanilla.c    
)

# Cria lib static
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

# Cria lib com INTERFACE
# add_library(${PROJECT_NAME} INTERFACE)

# Linkagem
target_link_libraries(${PROJECT_NAME} PRIVATE

    # Adiciona dependências externas
    utils
    filecore
    # packet
    # minisocket

    # Adiciona dependências internas
    type
    histogram
    matrix
    image
)

# Header público exposto para quem linka com a lib
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Headers privados dentro de src/ (visíveis apenas pelos .c da própria lib)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    
)
