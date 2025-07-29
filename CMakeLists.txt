cmake_minimum_required(VERSION 3.11)
project(MyGameProject LANGUAGES CXX)

# ─── Global compiler settings ───────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Debug symbols for GCC/Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options($<$<CONFIG:Debug>:-g>)
endif()

# ─── Dependencies ───────────────────────────────────────────────────────────
include(FetchContent)

# --- Raylib 4.5.0 -----------------------------------------------------------
find_package(raylib 4.5 QUIET)

if (NOT raylib_FOUND)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES     OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
    FetchContent_MakeAvailable(raylib)
endif()

# --- ImGui ------------------------------------------------------------------
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        master          # pin a tag if you prefer
)
FetchContent_MakeAvailable(imgui)

# --- rlImGui ----------------------------------------------------------------
FetchContent_Declare(
    rlimgui
    GIT_REPOSITORY https://github.com/raylib-extras/rlImGui.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(rlimgui)

# ─── Sources ----------------------------------------------------------------
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp include/*.h)

list(APPEND SOURCES
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${rlimgui_SOURCE_DIR}/rlImGui.cpp
)

# ─── Executable -------------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES}
        src/Bird.cpp
        include/Bird.h
        include/Object.h
        include/Globals.h
        include/Physics.h
        src/Physics.cpp
        include/Pipe.h
        src/Pipe.cpp)

# Shim: rlImGui expects IsTextureValid → map to Raylib 4.5 IsTextureReady
target_compile_definitions(${PROJECT_NAME} PRIVATE IsTextureValid=IsTextureReady)

# Includes & linking
target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${imgui_SOURCE_DIR}
    ${rlimgui_SOURCE_DIR}
    ${rlimgui_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# ─── Windows DLL copy (Debug & Release) -------------------------------------
if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:raylib>
            $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

cmake_policy(SET CMP0135 NEW)
