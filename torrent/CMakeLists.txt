set(include_list
	Downloader.h
	)

set(source_list
	Downloader.cpp
	)

add_library(torr ${source_list} ${include_list})
target_link_libraries(torr ${CONAN_LIBS})