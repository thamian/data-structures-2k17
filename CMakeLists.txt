cmake_minimum_required(VERSION 2.6)
project(data-structures-2k17)

set(CMAKE_CXX_STANDARD 11)

add_executable(data-structures-2k17 main.cpp ui.cpp structures/list.cpp structures/arraylist.cpp structures/arraylist-add.cpp structures/arraylist-remove.cpp structures/linkedlist.cpp structures/linkedlist-add.cpp structures/linkedlist-remove.cpp structures/node.cpp structures/multiple-add.cpp structures/multiple-remove.cpp structures/heap.cpp)

#install(TARGETS data-structures-2k17 RUNTIME DESTINATION bin)
