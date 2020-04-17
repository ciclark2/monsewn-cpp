set(include_list
	Downloader.h
	)

set(source_list
	Downloader.cpp
	)

add_library(mon ${source_list} ${include_list})
target_link_libraries(mon ${CONAN_LIBS})

add_executable(monsewn main.cpp)
target_link_libraries(monsewn ${CONAN_LIBS} mon)