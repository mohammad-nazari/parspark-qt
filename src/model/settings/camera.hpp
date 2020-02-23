#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <model/base-model.hpp>

namespace parspark::model {
   class CameraInfo;
   using CameraInfoPtr = std::shared_ptr<CameraInfo>;
   class CameraInfo : public BaseModel {
    public:
      static CameraInfoPtr Create();
      CameraInfo();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      QString Address() const {
         return m_address;
      }
      void Address(const QString& address) {
         m_address = address;
      }

    private:
      bool m_enable{false};
      QString m_address;
   };

   class Camera;
   using CameraPtr = std::shared_ptr<Camera>;
   class Camera : public BaseModel {
    public:
      static CameraPtr Create();
      Camera();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      CameraInfoPtr Enter() const {
         return m_enter;
      }
      void Enter(const CameraInfoPtr& enter) {
         m_enter = enter;
      }
      CameraInfoPtr Exit() const {
         return m_exit;
      }
      void Exit(const CameraInfoPtr& exit) {
         m_exit = exit;
      }

    private:
      CameraInfoPtr m_enter{new CameraInfo};
      CameraInfoPtr m_exit{new CameraInfo};
   };
} // namespace parspark::model
#endif // CAMERA_HPP
