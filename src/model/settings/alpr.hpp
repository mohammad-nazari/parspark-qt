#ifndef MODEL_ALPR_HPP
#define MODEL_ALPR_HPP

#include <cstdint>
#include <memory>
#include <model/base-model.hpp>
#include <string>

namespace parspark::model {
   class AlprByCamera;
   using AlprByCameraPtr = std::shared_ptr<AlprByCamera>;
   class AlprByCamera : public BaseModel {
    public:
      static AlprByCameraPtr Create();
      AlprByCamera();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      bool SubmitWithoutEnterPlate() const {
         return m_submitWithoutEnterPlate;
      }
      void SubmitWithoutEnterPlate(bool submitWithoutEnterPlate) {
         m_submitWithoutEnterPlate = submitWithoutEnterPlate;
      }
      bool SubmitWithoutExitPlate() const {
         return m_submitWithoutExitPlate;
      }
      void SubmitWithoutExitPlate(bool submitWithoutExitPlate) {
         m_submitWithoutExitPlate = submitWithoutExitPlate;
      }

    private:
      bool m_enable{false};
      bool m_submitWithoutEnterPlate{false};
      bool m_submitWithoutExitPlate{false};
   };

   class Alpr;
   using AlprPtr = std::shared_ptr<Alpr>;
   class Alpr : public BaseModel {
    public:
      static AlprPtr Create();
      Alpr();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      AlprByCameraPtr ByCamera() const {
         return m_byCamera;
      }
      void ByCamera(const AlprByCameraPtr& byCamera) {
         m_byCamera = byCamera;
      }

    private:
      bool m_enable{false};
      AlprByCameraPtr m_byCamera{new AlprByCamera};
   };
} // namespace parspark::model
#endif // MODEL_ALPR_HPP
