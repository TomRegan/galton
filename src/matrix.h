#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>
#include <deque>
#include <vector>
#include <memory>

#include "ball.h"
#include "pin.h"
#include "bucket.h"

namespace core {

class Matrix {
 public:
  static Matrix* createMatrix(size_t levels);
  void drop(const Ball& ball);
  std::vector<Bucket*> get_buckets() const;
 private:
  Matrix(Pin *&, std::vector<Bucket*>&);
  static void add_row(uint32_t, std::deque<Pin*>&);
  static void add_first_pin(std::deque<Pin*>&);
  static void add_last_pin(std::deque<Pin*>&);
  static void add_middle_pin(std::deque<Pin*>&);
  std::unique_ptr<Pin> first_pin_;
  std::vector<Bucket*> buckets_;
};

}  // core

#endif
