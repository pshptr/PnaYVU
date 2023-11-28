cmake_minimum_required(VERSION 3.23)
project(LB4_LinkedList_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LB4_LinkedList_
        CaseCheck.h
        CheckCaseInput.h
        CheckOnInt.h
        CheckString.h
        Exception.h
        isEmpty.h
        LinkedList.h
        main.cpp
        notThisIndex.h)
