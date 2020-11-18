#include "traffic.hpp"

namespace anar::model {
   TrafficSectionPtr TrafficSection::Create() {
      return std::make_shared<TrafficSection>();
   }
   TrafficSection::TrafficSection()
       : BaseModel("TrafficSection") {
   }

   TrafficPtr Traffic::Create() {
      return std::make_shared<Traffic>();
   }
   Traffic::Traffic()
       : BaseModel("Traffic") {
   }

} // namespace anar::model
