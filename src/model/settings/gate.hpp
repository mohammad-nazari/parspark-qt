#ifndef MODEL_GATE_HPP
#define MODEL_GATE_HPP

#include "comport.hpp"

namespace parspark::model {
   class GateInfo;
   using GateInfoPtr = std::shared_ptr<GateInfo>;
   class GateInfo : public BaseModel {
    public:
      static GateInfoPtr Create();
      GateInfo();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      ComPortPtr Address() const {
         return m_address;
      }
      void Address(const ComPortPtr& address) {
         m_address = address;
      }
      bool OpenAuto() const {
         return m_openAuto;
      }
      void OpenAuto(bool openAuto) {
         m_openAuto = openAuto;
      }
      bool CloseAuto() const {
         return m_closeAuto;
      }
      void CloseAuto(bool closeAuto) {
         m_closeAuto = closeAuto;
      }
      uint16_t CloseAfter() const {
         return m_closeAfter;
      }
      void CloseAfter(const uint16_t& closeAfter) {
         m_closeAfter = closeAfter;
      }

    private:
      bool m_enable{false};
      ComPortPtr m_address{new ComPort};
      bool m_openAuto{true};
      bool m_closeAuto{true};
      uint16_t m_closeAfter{15};
   };

   class Gate;
   using GatePtr = std::shared_ptr<Gate>;
   class Gate : public BaseModel {
    public:
      static GatePtr Create();
      Gate();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      GateInfoPtr Enter() const {
         return m_enter;
      }
      void Enter(const GateInfoPtr& enter) {
         m_enter = enter;
      }
      GateInfoPtr Exit() const {
         return m_exit;
      }
      void Exit(const GateInfoPtr& exit) {
         m_exit = exit;
      }

    private:
      GateInfoPtr m_enter{new GateInfo};
      GateInfoPtr m_exit{new GateInfo};
   };
} // namespace parspark::model
#endif // MODEL_GATE_HPP
