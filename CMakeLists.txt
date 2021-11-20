cmake_minimum_required(VERSION 3.20)
project(Kursach_OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Kursach_OOP main.cpp Classes/People/Person.cpp Classes/People/Person.h Classes/People/Worker.cpp Classes/People/Worker.h Classes/Speciefic/Task.cpp Classes/Speciefic/Task.h Classes/Enums/TaskState.cpp Classes/Enums/TaskState.h Classes/Managers/EmployerManager.cpp Classes/Managers/EmployerManager.h Classes/Managers/Singleton.cpp Classes/Managers/Singleton.h Classes/Managers/FileWriter.h Classes/Speciefic/AdminMenu.cpp Classes/Speciefic/AdminMenu.h Classes/Managers/Labor.cpp Classes/Managers/Labor.h)
