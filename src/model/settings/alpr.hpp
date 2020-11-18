#ifndef ANAR_ALPR_HPP
#define ANAR_ALPR_HPP

#include <cstdint>
#include <memory>
#include <string>

#include "model/base-model.hpp"

namespace anar::model {
   class AlprByCamera;
   using AlprByCameraPtr = std::shared_ptr<AlprByCamera>;
   class AlprByCamera : public BaseModel {
     public:
      static AlprByCameraPtr Create();
      AlprByCamera();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      [[nodiscard]] bool SubmitWithoutEnterPlate() const {
         return m_submitWithoutEnterPlate;
      }
      void SubmitWithoutEnterPlate(bool submitWithoutEnterPlate) {
         m_submitWithoutEnterPlate = submitWithoutEnterPlate;
      }
      [[nodiscard]] bool SubmitWithoutExitPlate() const {
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

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      [[nodiscard]] const AlprByCameraPtr& ByCamera() const {
         return m_byCamera;
      }
      void ByCamera(const AlprByCameraPtr& byCamera) {
         m_byCamera = byCamera;
      }

     private:
      bool m_enable{false};
      AlprByCameraPtr m_byCamera{new AlprByCamera};
   };
}  // namespace anar::model
#endif  // ANAR_ALPR_HPP
