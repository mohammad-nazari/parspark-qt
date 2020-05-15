#ifndef MODEL_PAYMENT_HPP
#define MODEL_PAYMENT_HPP

#include "comport.hpp"
#include <model/base-model.hpp>

namespace parspark::model {
   class PaymentInfo;
   using PaymentInfoPtr = std::shared_ptr<PaymentInfo>;
   class PaymentInfo : public BaseModel {
    public:
      static PaymentInfoPtr Create();
      PaymentInfo();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool active) {
         m_enable = active;
      }
      ComPortPtr Address() const {
         return m_address;
      }
      void Address(const ComPortPtr& address) {
         m_address = address;
      }

    private:
      bool m_enable{false};
      ComPortPtr m_address{new ComPort};
      bool m_sendDirect{false};
   };
   class Payment;
   using PaymentPtr = std::shared_ptr<Payment>;
   class Payment : public BaseModel {
    public:
      static PaymentPtr Create();
      Payment();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      PaymentInfoPtr CitizenDevice() const {
         return m_citizenDevice;
      }
      void CitizenDevice(const PaymentInfoPtr& citizenDevice) {
         m_citizenDevice = citizenDevice;
      }
      PaymentInfoPtr PosDevice() const {
         return m_posDevice;
      }
      void PosDevice(const PaymentInfoPtr& posDevice) {
         m_posDevice = posDevice;
      }

    private:
      PaymentInfoPtr m_citizenDevice{new PaymentInfo};
      PaymentInfoPtr m_posDevice{new PaymentInfo};
   };
} // namespace parspark::model
#endif // MODEL_PAYMENT_HPP
