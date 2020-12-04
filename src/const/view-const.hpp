#ifndef PARSPARK_VIEW_CONST_HPP
#define PARSPARK_VIEW_CONST_HPP

#include <cstdint>
namespace anar::constant {
   namespace RegisterPackets {
      constexpr char PARS_PARK_PACKAGE_NAME[]{"ParsPark.View"};
      constexpr uint8_t PARS_PARK_PACKAGE_MAJOR_VERSION{1};
      constexpr uint8_t PARS_PARK_PACKAGE_MINOR_VERSION{0};
   }  // namespace RegisterPackets
}  // namespace anar::constant

#endif  // PARSPARK_VIEW_CONST_HPP
