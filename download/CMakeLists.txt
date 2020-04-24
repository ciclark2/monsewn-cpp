set(include_list
	Downloader.h
	)

set(source_list
	Downloader.cpp
	)

add_library(download ${source_list} ${include_list})
target_link_libraries(download ${CONAN_LIBS})