#ifndef ANAR_PARS_PARK_CONST_VIEW_HPP
#define ANAR_PARS_PARK_CONST_VIEW_HPP

#include "anar/model/constant-model.hpp"

namespace anar::parspark::constant {
   namespace RegisterPackets {
      const model::ConstantModel PARS_PARK_COMMON_PACKAGE_NAME{0, "CommonApi", "ANAR.ParsPark.View"};
      const model::ConstantModel PARS_PARK_LOGIN_PACKAGE_NAME{0, "LoginApi", "ANAR.ParsPark.View"};
      const model::ConstantModel PARS_PARK_SETTINGS_PACKAGE_NAME{0, "SettingApi", "ANAR.ParsPark.View"};
      const model::ConstantModel PARS_PARK_PACKAGE_MAJOR_VERSION{1, "ANAR.ParsPark.View.Major.Version", "ParsPark view major version"};
      const model::ConstantModel PARS_PARK_PACKAGE_MINOR_VERSION{0, "ANAR.ParsPark.View.Minor.Version", "ParsPark view minot version"};
   }  // namespace RegisterPackets
}  // namespace anar::parspark::constant

#endif  // ANAR_PARS_PARK_CONST_VIEW_HPP
