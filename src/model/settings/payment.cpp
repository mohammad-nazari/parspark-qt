#include "payment.hpp"

namespace anar::model {
   PaymentInfoPtr PaymentInfo::Create() {
      return std::make_shared<PaymentInfo>();
   }
   PaymentInfo::PaymentInfo()
       : BaseModel("PaymentInfo") {
   }

   bool PaymentInfo::FromJson(const json_nlohmann& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"];
      m_address->FromJson(json["address"]);
      m_sendDirect = json["sendDirect"];
      return true;
   }
   json_nlohmann PaymentInfo::ToJson() {
      json_nlohmann json = BaseModel::ToJson();
      json["enable"] = m_enable;
      json["address"] = m_address->ToJson();
      json["sendDirect"] = m_sendDirect;
      return json;
   }

   PaymentPtr Payment::Create() {
      return std::make_shared<Payment>();
   }
   Payment::Payment()
       : BaseModel("Payment") {
   }

   bool Payment::FromJson(const json_nlohmann& json) {
      BaseModel::FromJson(json);
      m_citizenDevice->FromJson(json["citizenDevice"]);
      m_posDevice->FromJson(json["posDevice"]);
      return true;
   }
   json_nlohmann Payment::ToJson() {
      json_nlohmann json = BaseModel::ToJson();
      json["citizenDevice"] = m_citizenDevice->ToJson();
      json["posDevice"] = m_posDevice->ToJson();
      return json;
   }
}  // namespace anar::model
