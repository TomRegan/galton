#ifndef PIN_H_
#define PIN_H_

#include <memory>

#include "ball.h"
#include "emiter.h"
#include "receiver.h"

using event::Receiver;

namespace core {

class Pin : public event::Emiter {
 public:
  void register_receiver(Receiver*);
  void accept(const Ball& ball);
  void left(Pin*&);
  void right(Pin*&);
  void drop(const Ball &ball);
 private:
  std::shared_ptr<Pin> left_;
  std::shared_ptr<Pin> right_;
  std::unique_ptr<Receiver> receiver_;
};

}  // core

#endif  // PIN_H_
