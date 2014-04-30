#include <stdlib.h>

#include "pin.h"

using event::Receiver;

namespace core {

void Pin::accept(const Ball& ball) {
  const uint8_t max = 10;
  const uint8_t pivot = max / 2;
  sranddev();  // RAND(3) sez: initializes a seed using random number device
  uint8_t value = (rand() % max);
  if (left_ != NULL && right_ != NULL) {
    (value < pivot)
      ? left_->accept(ball)
      : right_->accept(ball);
  } else {
    drop(ball);
  }
}

void Pin::register_receiver(Receiver *receiver) {
  receiver_ = std::unique_ptr<Receiver>(receiver);
}

void Pin::drop(const Ball &ball) {
  if (receiver_ != NULL) {
    receiver_->receive();
  }
}

void Pin::left(Pin *&pin) {
  left_ = std::shared_ptr<Pin>(pin);
}

void Pin::right(Pin *&pin) {
  right_ = std::shared_ptr<Pin>(pin);
}

}  // core
