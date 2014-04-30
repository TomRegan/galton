#import "bucket.h"

namespace core {

void Bucket::receive() {
  count++;
}

int Bucket::get_count() const {
  return count;
}

}  // core
