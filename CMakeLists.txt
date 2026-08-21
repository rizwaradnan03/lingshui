cmake_minimum_required(VERSION 3.16)

project(lingshui
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================
# GLFW & OpenGL
# =========================
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# =========================
# Cari Semua File Source Secara Otomatis
# =========================
file(GLOB_RECURSE SOURCES 
    CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.c"
)

# =========================
# Executable
# =========================
add_executable(lingshui_window
    ${SOURCES}
)

# =========================
# Include directories
# =========================
target_include_directories(lingshui_window PRIVATE
    include
    include/external
)

# =========================
# Libraries
# =========================
target_link_libraries(lingshui_window PRIVATE
    glfw
    OpenGL::GL
    ${CMAKE_DL_LIBS}
)