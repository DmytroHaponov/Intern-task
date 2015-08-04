cmake_minimum_required(VERSION 2.8.12)
project (lux4)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_PREFIX_PATH "E:\\Qt\\Qt5.5\\msvc2013_64\\")
INCLUDE_DIRECTORIES(E:\\Qt\\5.5\\msvc2013_64\\lib\\cmake\\)
INCLUDE_DIRECTORIES(E:\\Qt\\5.5\\msvc2013_64\\include\\QtSql\\)

INCLUDE_DIRECTORIES(E:\\Qt\\5.5\\msvc2013_64\\lib\\cmake\\Qt5Widgets\\)

INCLUDE(E:\\Qt\\5.5\\msvc2013_64\\lib\\cmake\\Qt5Widgets\\Qt5WidgetsConfig.cmake)

#NCLUDE_DIRECTORIES(D:\\temp\\lux4\\QtSql\\)
#INCLUDE(D:\\temp\\lux4\\Qt5Sql.lib)

find_package(Qt5Widgets REQUIRED)

add_executable (lux4 main.cpp opendialog.cpp createdialog.cpp showdbdialog.cpp widget.cpp)

qt5_use_modules(lux4 Widgets)

target_link_libraries(lux4 ${Qt5Widgets_LIBRARIES})