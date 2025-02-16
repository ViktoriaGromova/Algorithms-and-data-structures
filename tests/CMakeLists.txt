add_executable(BinarySearchTest BinarySearchTest.cpp)

target_include_directories(BinarySearchTest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../BinarySearch/") 

find_package(GTest REQUIRED)
target_link_libraries(BinarySearchTest PRIVATE GTest::GTest GTest::Main )

add_test(NAME BinarySearch COMMAND BinarySearchTest)
