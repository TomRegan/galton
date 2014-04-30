################################
# Binaries and Libraries
################################
set(SOURCE_FILES
  application.cc
  bucket.cc
  histogram.cc
  matrix.cc
  pin.cc
)
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
add_executable(galton main.cc)
add_library(galton_lib ${SOURCE_FILES})
target_link_libraries(galton galton_lib)

################################
# Tests
################################
set(TEST_FILES
  test_application.cc
  test_matrix.cc
)
add_executable(TestSuite ${TEST_FILES})
target_link_libraries(TestSuite gtest gtest_main)
target_link_libraries(TestSuite galton_lib)
