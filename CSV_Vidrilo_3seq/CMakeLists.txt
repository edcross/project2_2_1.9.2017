cmake_minimum_required (VERSION 2.8.3)
project (CSV_Vidrilo)

find_package(Boost REQUIRED COMPONENTS system)

#add_library(svm svm/svm.cpp)
add_library(files fileMethods/fileMethods.cpp)

set  (project_SOURCES ImageTags.cpp main.cpp )
set  (project_HEADERS ImageTags.h )

add_executable(csvVidrilo ${project_SOURCES} ${project_HEADERS})
target_link_libraries(csvVidrilo  files)