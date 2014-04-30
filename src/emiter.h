#ifndef EMITER_H_
#define EMITER_H_

#include "receiver.h"

namespace event {

class Emiter {
 public:
  virtual void register_receiver(Receiver*) {}
};

}  // event

#endif
