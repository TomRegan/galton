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


#include <iostream>
#include <string>

#include "matrix.h"
#include "application.h"
#include "histogram.h"

namespace application {

using core::Matrix;
using core::Histogram;

int Application::main() {
  Matrix *matrix = Matrix::createMatrix(8);
  for (int i = 0; i < 0xFF; ++i) {
    Ball ball;
    matrix->drop(ball);
  }
  auto histogram = Histogram(matrix->get_buckets());
  std::cout << histogram;
  return 0;
}

}  // application
