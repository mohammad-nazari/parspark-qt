#include "camera.hpp"

namespace parspark::model {
   CameraInfoPtr CameraInfo::Create() {
      return std::make_shared<CameraInfo>();
   }
   CameraInfo::CameraInfo()
       : BaseModel("Camera") {
   }

   bool CameraInfo::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_address = json["address"].toString();
      return true;
   }
   const QVariantMap CameraInfo::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enable"] = m_enable;
      json["address"] = m_address;
      return json;
   }

   CameraPtr Camera::Create() {
      return std::make_shared<Camera>();
   }
   Camera::Camera()
       : BaseModel("Camera") {
   }

   bool Camera::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enter->FromJson(json["enterAddress"].toMap());
      m_exit->FromJson(json["exitAddress"].toMap());
      return true;
   }
   const QVariantMap Camera::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enterAddress"] = m_enter->ToJson();
      json["exitAddress"] = m_exit->ToJson();
      return json;
   }
} // namespace parspark::model
