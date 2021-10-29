#include "traffic.hpp"

namespace anar::model {
   TrafficSectionPtr TrafficSection::Create() {
      return std::make_shared<TrafficSection>();
   }
   TrafficSection::TrafficSection()
       : Model("TrafficSection") {
   }

   TrafficPtr Traffic::Create() {
      return std::make_shared<Traffic>();
   }
   Traffic::Traffic()
       : Model("Traffic") {
   }

} // namespace anar::model
