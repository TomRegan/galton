#include <iomanip>

#include "histogram.h"

namespace core {

std::ostream& operator<<(std::ostream& os, const Histogram& obj) {
  int msf = 0;
  for (auto bucket : obj.buckets) {
    auto height = bucket->get_count();
    if (height > msf) {
      msf = height;
    }
  }
  const auto max_height = 18;
  auto div = msf / max_height;
  bool toggle = false;
  for (uint32_t line = max_height; line > 0; --line) {
    if (toggle) {
      os << "  ";
    } else {
      os << std::setw(2) << div * line;
    }
    toggle = !toggle;
    os << " ┤";
    for (auto bucket : obj.buckets) {
      auto height = bucket->get_count() / div;
      if (height >= line) {
	os << " ██ ";
      } else {
	os << "    ";
      }
    }
    os << '\n';
  }
  os << " 0 ┴";
  for (auto i = 0; i < obj.buckets.size(); ++i) {
    os << "────";
  }
  os << '\n';
  return os;
}

}  // core
