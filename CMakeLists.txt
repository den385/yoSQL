cmake_minimum_required(VERSION 3.12)
project(sql_engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(sql_engine main.cpp row/row.cpp row/row.h table/table.cpp table/table.h page/page.cpp page/page.h parser/parser.cpp parser/parser.h processor/processor.cpp processor/processor.h engine_instance.cpp engine_instance.h utils.h command/command.cpp command/command.h)

set(BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu/")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.65.0 REQUIRED COMPONENTS system thread filesystem)

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	target_link_libraries(sql_engine Boost::system Boost::thread)
endif()