#ifndef BUCKET_H_
#define BUCKET_H_

#include <cstddef>

#include "emiter.h"
#include "receiver.h"

namespace core {

class Bucket : public event::Receiver {
 public:
  virtual void receive();
  int get_count() const;
 private:
  int count = 0;
};

}  // core

#endif
