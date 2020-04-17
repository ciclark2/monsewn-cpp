set(include_list
	downloader.h
	)

set(source_list
	downloader.cpp
	)

add_library(mon ${source_list} ${include_list})

add_executable(Monsewn main.cpp "downloader.cpp")

target_link_libraries(Monsewn ${CONAN_LIBS} mon)