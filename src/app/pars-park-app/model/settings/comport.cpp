#include "comport.hpp"

namespace anar::model {
   ComPortPtr ComPort::Create() {
      return std::make_shared<ComPort>();
   }
   ComPort::ComPort()
       : Model("Comport", "Comport") {
   }

   bool ComPort::FromJson(const json_nlohmann& json) {

      m_portName = json["portName"];
      m_baudRate = json["baudRate"];
      return true;
   }
   json_nlohmann ComPort::ToJson() {
      json_nlohmann json;
      json["portName"] = m_portName;
      json["baudRate"] = m_baudRate;
      return json;
   }
}  // namespace anar::model
