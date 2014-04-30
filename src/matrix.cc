#include <vector>

#include "matrix.h"
#include "receiver.h"
#include "bucket.h"

using std::vector;
using event::Receiver;

namespace core {

Matrix::Matrix(Pin *&first_pin, std::vector<Bucket*> &buckets) {
  first_pin_ = std::unique_ptr<Pin>(first_pin);
  buckets_ = buckets;
}

Matrix* Matrix::createMatrix(size_t levels) {
  if (levels == 0) {
    return 0;
  }

  auto *first_pin = new Pin;
  auto queue = std::deque<Pin*>();
  queue.push_back(first_pin);
  for (uint32_t row_length = 0; --levels; row_length++) {
    add_row(row_length, queue);
  }
  auto buckets = vector<Bucket*>();
  for (auto pin : queue) {
    auto bucket = new Bucket;
    pin->register_receiver(bucket);
    buckets.push_back(bucket);
  }
  return new Matrix(first_pin, buckets);
}

std::vector<Bucket*> Matrix::get_buckets() const {
  return buckets_;
}

void Matrix::add_row(uint32_t row_length, std::deque<Pin*> &queue) {
  add_first_pin(queue);
  for (int n = 0; n < row_length; n++) {
    add_middle_pin(queue);
  }
  add_last_pin(queue);
}

void Matrix::add_first_pin(std::deque<Pin*> &queue) {
  auto pin = queue.front();
  auto left_child = new Pin;
  pin->left(left_child);
  queue.push_back(left_child);
}

void Matrix::add_last_pin(std::deque<Pin*> &queue) {
  auto pin = new Pin;
  auto left_parent = queue.front();
  queue.pop_front();
  left_parent->right(pin);
  queue.push_back(pin);
}

void Matrix::add_middle_pin(std::deque<Pin*> &queue) {
  auto left_parent = queue.front();
  queue.pop_front();
  auto child = new Pin;
  left_parent->right(child);
  auto right_parent = queue.front();
  right_parent->left(child);
  queue.push_back(child);
}

void Matrix::drop(const Ball& ball) {
  first_pin_->accept(ball);
}

}  // core
