#include "binary.hpp"

namespace anar::common {
   uint64_t Binary::Reverse(const uint64_t& value, const uint8_t& byteLen) {
      if (byteLen > 8) {
         return value;
      }
      uint64_t rvalue = 0;
      uint64_t temp = 0;
      uint64_t one = 1;
      uint8_t bits = byteLen * 8;
      for (uint8_t index = bits; index > 0; --index) {
         //            temp = value >> (index - 1);
         //            temp = temp & one;
         //            temp = temp << (bits - (index - 1) - 1);
         //            rvalue |= temp;
         rvalue |= ((value >> (index - 1)) & one) << (bits - (index - 1) - 1);
      }
      return rvalue;
   }
}  // namespace anar::common
