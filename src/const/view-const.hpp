#ifndef ANAR_PARS_PARK_CONST_VIEW_HPP
#define ANAR_PARS_PARK_CONST_VIEW_HPP

#include "anar/constant-model.hpp"

namespace anar::parspark::constant {
    namespace RegisterPackets {
        const anar::common::model::ConstantModel ANAR_COMMON_PACKAGE_NAME{"CommonApi", "ANAR.ParsPark.View", 0};
        const anar::common::model::ConstantModel ANAR_LOGIN_PACKAGE_NAME{"LoginApi", "ANAR.ParsPark.View", 0};
        const anar::common::model::ConstantModel ANAR_SETTINGS_PACKAGE_NAME{"SettingApi", "ANAR.ParsPark.View", 0};
        const anar::common::model::ConstantModel ANAR_PACKAGE_MAJOR_VERSION{"ANAR.ParsPark.View.Major.Version", "ParsPark view major version", 1};
        const anar::common::model::ConstantModel ANAR_PACKAGE_MINOR_VERSION{"ANAR.ParsPark.View.Minor.Version", "ParsPark view minot version", 0};
    }  // namespace RegisterPackets
}  // namespace anar::parspark::constant

#endif  // ANAR_PARS_PARK_CONST_VIEW_HPP
