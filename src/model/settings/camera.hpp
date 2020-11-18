#ifndef ANAR_CAMERA_HPP
#define ANAR_CAMERA_HPP

#include "model/base-model.hpp"

namespace anar::model {
   class CameraInfo;
   using CameraInfoPtr = std::shared_ptr<CameraInfo>;
   class CameraInfo : public BaseModel {
     public:
      static CameraInfoPtr Create();
      CameraInfo();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      [[nodiscard]] const std::string& Address() const {
         return m_address;
      }
      void Address(const std::string& address) {
         m_address = address;
      }

     private:
      bool m_enable{false};
      std::string m_address;
   };

   class Camera;
   using CameraPtr = std::shared_ptr<Camera>;
   class Camera : public BaseModel {
     public:
      static CameraPtr Create();
      Camera();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const CameraInfoPtr& Enter() const {
         return m_enter;
      }
      void Enter(const CameraInfoPtr& enter) {
         m_enter = enter;
      }
      [[nodiscard]] const CameraInfoPtr& Exit() const {
         return m_exit;
      }
      void Exit(const CameraInfoPtr& exit) {
         m_exit = exit;
      }

     private:
      CameraInfoPtr m_enter{new CameraInfo};
      CameraInfoPtr m_exit{new CameraInfo};
   };
}  // namespace anar::model
#endif  // ANAR_CAMERA_HPP
