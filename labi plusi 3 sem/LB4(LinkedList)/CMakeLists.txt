cmake_minimum_required(VERSION 3.23)
project(LB4_LinkedList_)

set(CMAKE_CXX_STANDARD 14)

include_directories("LB4(LinkedList)")

add_executable(LB4_LinkedList_
        "LB4(LinkedList)/CaseCheck.h"
        "LB4(LinkedList)/CheckOnInt.h"
        "LB4(LinkedList)/CheckString.h"
        "LB4(LinkedList)/Exception.h"
        "LB4(LinkedList)/LinkedList.h"
        "LB4(LinkedList)/main.cpp")
