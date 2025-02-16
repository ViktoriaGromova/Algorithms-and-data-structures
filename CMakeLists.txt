cmake_minimum_required(VERSION 3.2)

project(AlogorithmsAndDataStructure
        VERSION 1.0.0
        DESCRIPTION "Project for learning basic algorithms and data structures"
        LANGUAGES CXX)

add_subdirectory(external/googletest)

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)       
endif()