project(glfw-simple-window CXX C)
cmake_minimum_required(VERSION 2.8)

find_package(PkgConfig)
pkg_check_modules(EGL REQUIRED egl)
pkg_check_modules(GLES2 REQUIRED glesv2)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

include_directories(
    include
)

add_executable(glfw-simple-window
    src/main.c
)

target_link_libraries(glfw-simple-window
    ${EGL_LIBRARIES}
    ${GLES2_LIBRARIES}
    ${GLFW_LIBRARIES}
    glfw
    GLEW
)
