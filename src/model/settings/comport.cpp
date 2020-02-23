#include "comport.hpp"

namespace parspark::model {
   ComPortPtr ComPort::Create() {
      return std::make_shared<ComPort>();
   }
   ComPort::ComPort()
       : BaseModel("Com1") {
   }

   bool ComPort::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_portName = json["portName"].toString();
      m_baudRate = json["baudRate"].toUInt();
      return true;
   }
   const QVariantMap ComPort::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["portName"] = m_portName;
      json["baudRate"] = m_baudRate;
      return json;
   }
} // namespace parspark::model
