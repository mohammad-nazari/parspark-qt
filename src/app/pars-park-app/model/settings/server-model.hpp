#ifndef ANAR_PARS_PARK_MODEL_SERVER_HPP
#define ANAR_PARS_PARK_MODEL_SERVER_HPP

#include "anar/model/model.hpp"

namespace anar::parspark::model {
   class ServerModel;
   using ServerModelPtr = std::shared_ptr<ServerModel>;
   class ServerModel : public anar::model::Model {
     public:
      ServerModel()
          : anar::model::Model("Server", "Server") {
      }

      std::string Address{"localhost"};
      uint16_t Port{50001};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_SERVER_HPP
