cmake_minimum_required(VERSION 3.4...3.27 FATAL_ERROR) 

set(ENGINE_PROJECT_NAME EngineCore)

set(ENGINE_PUBLIC_INCLUDES
	includes/EngineCore/Application.hpp
	includes/EngineCore/Log.hpp
	includes/EngineCore/Event.hpp
	includes/EngineCore/Camera.hpp
	includes/EngineCore/Keys.hpp
	includes/EngineCore/Input.hpp
)

set(ENGINE_PRIVATE_INCLUDES
	src/EngineCore/Window.hpp
	src/EngineCore/Modules/UIModule.hpp
	src/EngineCore/Rendering/OpenGL/Renderer_OpenGL.hpp
	src/EngineCore/Rendering/OpenGL/ShaderProgram.hpp
	src/EngineCore/Rendering/OpenGL/VertexBuffer.hpp
	src/EngineCore/Rendering/OpenGL/VertexArray.hpp
	src/EngineCore/Rendering/OpenGL/IndexBuffer.hpp
	src/EngineCore/Rendering/OpenGL/Texture2D.hpp
)

set(ENGINE_PRIVATE_SOURCES
	src/EngineCore/Application.cpp
	src/EngineCore/Window.cpp
	src/EngineCore/Input.cpp
	src/EngineCore/Modules/UIModule.cpp
	src/EngineCore/Camera.cpp
	src/EngineCore/Rendering/OpenGL/Renderer_OpenGL.cpp
	src/EngineCore/Rendering/OpenGL/ShaderProgram.cpp
	src/EngineCore/Rendering/OpenGL/VertexBuffer.cpp
	src/EngineCore/Rendering/OpenGL/VertexArray.cpp
	src/EngineCore/Rendering/OpenGL/IndexBuffer.cpp
	src/EngineCore/Rendering/OpenGL/Texture2D.cpp
)
set(ENGINE_ALL_SOURCES
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
	${ENGINE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ENGINE_ALL_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)

set(IMGUI_INCLUDES
	../external/imgui/imgui.h
	../external/imgui/backends/imgui_impl_glfw.h
	../external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	../external/imgui/imgui.cpp
	../external/imgui/backends/imgui_impl_glfw.cpp
	../external/imgui/backends/imgui_impl_opengl3.cpp
	../external/imgui/imgui_demo.cpp
	../external/imgui/imgui_tables.cpp
	../external/imgui/imgui_widgets.cpp
	../external/imgui/imgui_draw.cpp
)

add_library(ImGui STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)
target_link_libraries(ImGui PRIVATE glad glfw)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE ImGui)