#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include <vector>
#include <iostream>

#include "bucket.h"

using core::Bucket;

namespace core {

class Histogram{
 public:
 Histogram(std::vector<Bucket*> buckets)
   : buckets(buckets)
  {}
  std::vector<Bucket*> buckets;
};

std::ostream& operator<<(std::ostream& os, const Histogram& obj);

}  // core

#endif  // HISTOGRAM_H_
