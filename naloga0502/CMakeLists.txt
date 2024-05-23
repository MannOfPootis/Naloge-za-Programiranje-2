cmake_minimum_required(VERSION 3.27)
project(naloga0502)

set(CMAKE_CXX_STANDARD 17)

add_executable(naloga0502 main.cpp
        Person.cpp
        Person.h
        Account.cpp
        Account.h
        Bank.cpp
        Bank.h
        SavingsAccount.cpp
        SavingsAccount.h
        Date.cpp
        Date.h
        Transaction.cpp
        Transaction.h)
