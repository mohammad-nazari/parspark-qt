#ifndef ANAR_PARS_PARK_CONST_VIEW_HPP
#define ANAR_PARS_PARK_CONST_VIEW_HPP

#include "anar/model/constant-model.hpp"

namespace anar::constant {
   namespace RegisterPackets {
      const model::ConstantModel PARS_PARK_PACKAGE_NAME{0, "ParsPark.View", "ParsPark view name"};
      const model::ConstantModel PARS_PARK_PACKAGE_MAJOR_VERSION{1, "ParsPark.View.Major.Version", "ParsPark view major version"};
      const model::ConstantModel PARS_PARK_PACKAGE_MINOR_VERSION{0, "ParsPark.View.Minor.Version", "ParsPark view minot version"};
   }  // namespace RegisterPackets
}  // namespace anar::parspark::constant

#endif  // ANAR_PARS_PARK_CONST_VIEW_HPP
