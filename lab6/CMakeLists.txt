cmake_minimum_required(VERSION 3.10)
project(zoo_polymorphism)

set(CMAKE_CXX_STANDARD 20)

add_executable(zoo_polymorphism
        main.cpp
        manager.cpp
        menu.cpp
        livingbeing.h
        animal.h
        predator.h
        human.h
        visitor.h
        worker.h
        manager.h
        ticket.h
        resourcebox.h
        zoo.h
        idescribable.h
        zoo_objects.h
        zoo_storage.h
        file_io.h
        menu.h
)
