cmake_minimum_required(VERSION 3.23)
project(LABI_5678_v_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LABI_5678_v_2
        Binary.dat
        Clock.cpp
        Clock.h
        Electronic.cpp
        Electronic.h
        Exp_cout.h
        Exp_file.h
        ExpVvod.h
        File.cpp
        File.h
        FitnesTracker.cpp
        FitnesTracker.h
        List.h
        Main.cpp
        Mechanic.cpp
        Mechanic.h
        menu.cpp
        menu.h
        MyException.h
        Source.cpp
        Text.txt
        WallClock.cpp
        WallClock.h
        Watch.cpp
        Watch.h)
