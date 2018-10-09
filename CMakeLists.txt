cmake_minimum_required(VERSION 3.12)
project(yoSQL)

set(CMAKE_CXX_STANDARD 17)


set(SHARED_DIR "${CMAKE_SOURCE_DIR}/../shared")

set(BOOST_LATEST_DIR            "${SHARED_DIR}/boost_1_68_0")
set(BOOST_LATEST_BIN_DIR        "${BOOST_LATEST_DIR}/stage/lib")
set(BOOST_LATEST_INCLUDE_DIR    "${BOOST_LATEST_DIR}/boost")
set(BOOST_SYSTEM                "${BOOST_LATEST_BIN_DIR}/libboost_system.so")
set(BOOST_FS                    "${BOOST_LATEST_BIN_DIR}/libboost_filesystem.so")
set(BOOST_THREAD                "${BOOST_LATEST_BIN_DIR}/libboost_thread.so")

set(HYRISE_SQL_PARSER_DIR           "${SHARED_DIR}/hyrise_sql_parser")
set(HYRISE_SQL_PARSER_BIN_DIR       "${HYRISE_SQL_PARSER_DIR}")
set(HYRISE_SQL_PARSER_INCLUDE_DIR   "${HYRISE_SQL_PARSER_DIR}/src")
set(HYRISE_SQLPARSER                "${HYRISE_SQL_PARSER_BIN_DIR}/libsqlparser.so")


include_directories(${CMAKE_SOURCE_DIR} ${BOOST_LATEST_INCLUDE_DIR} ${HYRISE_SQL_PARSER_INCLUDE_DIR})

link_directories(${BOOST_LATEST_BIN_DIR} ${HYRISE_SQL_PARSER_BIN_DIR})

add_executable(yoSQL main.cpp row/row.cpp row/row.h table/table.cpp table/table.h page/page.cpp page/page.h
		processor/processor.cpp processor/processor.h engine_instance.cpp engine_instance.h utils.h
		meta_command.h terminal/terminal.cpp terminal/terminal.h)


target_link_libraries(yoSQL PUBLIC ${BOOST_SYSTEM} ${BOOST_FS} ${BOOST_THREAD} ${HYRISE_SQLPARSER})