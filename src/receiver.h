#ifndef RECEIVER_H_
#define RECEIVER_H_

namespace event {

class Receiver {
 public:
  virtual ~Receiver() {}
  virtual void receive() {}
};

}  // event

#endif
