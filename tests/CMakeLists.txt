include_directories(../src)

include_directories(.)

add_executable(tests
        # test sources
        tests.cpp
        # task sources
        ../src/Sorter.h
        # gtest sources
        gtest/gtest-all.cc
        gtest/gtest_main.cc)

# add pthread for unix systems
if (UNIX)
    target_link_libraries(tests pthread)
endif ()