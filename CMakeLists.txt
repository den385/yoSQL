cmake_minimum_required(VERSION 3.12)
project(yoSQL)

set(CMAKE_CXX_STANDARD 17)


set(SHARED_DIR "${CMAKE_SOURCE_DIR}/../shared")
set(BOOST_LATEST_SOURCE_DIR "${SHARED_DIR}/boost_1_68_0")
set(BOOST_LATEST_BIN_DIR "${BOOST_LATEST_SOURCE_DIR}/stage/lib")
set(BOOST_LATEST_INCLUDE_DIR "${BOOST_LATEST_SOURCE_DIR}/boost")
set(BOOST_LATEST_LIBS "libboost_system.so" "libboost_filesystem.so" "libboost_thread.so")

set(HYRISE_SQL_PARSER_DIR "${SHARED_DIR}/hyrise_sql_parser")
set(HYRISE_SQL_PARSER_SOURCE_DIR ${HYRISE_SQL_PARSER_SOURCE_DIR})
set(HYRISE_SQL_PARSER_BIN_DIR "${SHARED_DIR}/hyrise_sql_parser")
set(HYRISE_SQL_PARSER_INCLUDE_DIR "${SHARED_DIR}/hyrise_sql_parser/src")
set(HYRISE_SQL_PARSER_LIBS "libsqlparser.so")


include_directories(${CMAKE_SOURCE_DIR} ${BOOST_LATEST_INCLUDE_DIR} ${HYRISE_SQL_PARSER_INCLUDE_DIR})

link_directories(${BOOST_LATEST_BIN_DIR} ${HYRISE_SQL_PARSER_BIN_DIR})

add_executable(yoSQL main.cpp row/row.cpp row/row.h table/table.cpp table/table.h page/page.cpp page/page.h
		processor/processor.cpp processor/processor.h engine_instance.cpp engine_instance.h utils.h
		meta_command.h)


target_link_libraries(yoSQL ${BOOST_LATEST_LIBS} ${HYRISE_SQL_PARSER_LIBS})
