set(include_list
	imgui_impl_glfw.h
	imgui_impl_opengl3.h
	)

set(source_list
	imgui_impl_glfw.cpp
	imgui_impl_opengl3.cpp
	)

add_library(window ${source_list} ${include_list})
target_link_libraries(window ${CONAN_LIBS})