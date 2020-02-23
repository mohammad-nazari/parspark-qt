#include "payment.hpp"

namespace parspark::model {
   PaymentInfoPtr PaymentInfo::Create() {
      return std::make_shared<PaymentInfo>();
   }
   PaymentInfo::PaymentInfo()
       : BaseModel("PaymentInfo") {
   }

   bool PaymentInfo::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_active = json["active"].toBool();
      m_address->FromJson(json["address"].toMap());
      m_sendDirect = json["sendDirect"].toBool();
      return true;
   }
   const QVariantMap PaymentInfo::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["active"] = m_active;
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

   bool Payment::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_citizenDevice->FromJson(json["citizenDevice"].toMap());
      m_citizenDevice->FromJson(json["citizenDevice"].toMap());
      return true;
   }
   const QVariantMap Payment::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["citizenDevice"] = m_citizenDevice->ToJson();
      json["posDevice"] = m_posDevice->ToJson();
      return json;
   }
} // namespace parspark::model
