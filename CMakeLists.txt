cmake_minimum_required(VERSION 3.12)

project(TradingEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
	main.cpp
	OrderBook.cpp
)

add_executable(engine ${SOURCE_FILES})

target_include_directories(engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

