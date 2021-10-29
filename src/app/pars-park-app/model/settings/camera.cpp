#include "camera.hpp"

namespace anar::model {
   CameraInfoPtr CameraInfo::Create() {
      return std::make_shared<CameraInfo>();
   }
   CameraInfo::CameraInfo()
       : Model("Camera") {
   }

   bool CameraInfo::FromJson(const json_nlohmann& json) {

      m_enable = json["enable"];
      m_address = json["address"];
      return true;
   }
   json_nlohmann CameraInfo::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["address"] = m_address;
      return json;
   }

   CameraPtr Camera::Create() {
      return std::make_shared<Camera>();
   }
   Camera::Camera()
       : Model("Camera") {
   }

   bool Camera::FromJson(const json_nlohmann& json) {

      m_enter->FromJson(json["enterAddress"]);
      m_exit->FromJson(json["exitAddress"]);
      return true;
   }
   json_nlohmann Camera::ToJson() {
      json_nlohmann json;
      json["enterAddress"] = m_enter->ToJson();
      json["exitAddress"] = m_exit->ToJson();
      return json;
   }
}  // namespace anar::model
