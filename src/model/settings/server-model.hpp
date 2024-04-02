#ifndef ANAR_PARS_PARK_MODEL_SERVER_HPP
#define ANAR_PARS_PARK_MODEL_SERVER_HPP

#include "model/pars-park-model.hpp"

namespace anar::parspark::model {
   class ServerModel;
   using ServerModelPtr = std::shared_ptr<ServerModel>;
   class ServerModel : public ParsParkModel {
     public:
      ServerModel()
          : ParsParkModel("Server", "Server") {
      }
      ~ServerModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      std::string Address{"localhost"};
      uint16_t Port{50001};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_SERVER_HPP
