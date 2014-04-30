//   Copyright 2014 Tom Regan
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.


#include "gtest/gtest.h"

#include "matrix.h"

using core::Matrix;

class MatrixTest : public ::testing::Test {

 protected:
  Matrix *matrix = NULL;

  virtual void SetUp() {

  }

  virtual void TearDown() {
    if (matrix != NULL) {
      delete matrix;
    }
  }

};

TEST_F(MatrixTest, ShouldReturnZero) {
  EXPECT_TRUE(Matrix::createMatrix(0) == NULL);
}

TEST_F(MatrixTest, ShouldReturnObject) {
  EXPECT_FALSE(Matrix::createMatrix(1) == NULL);
}
