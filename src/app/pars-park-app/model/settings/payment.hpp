#ifndef ANAR_PAYMENT_HPP
#define ANAR_PAYMENT_HPP

#include "anar/model/model.hpp"
#include "comport.hpp"

namespace anar::model {
   class PaymentInfo;
   using PaymentInfoPtr = std::shared_ptr<PaymentInfo>;
   class PaymentInfo : public Model {
     public:
      static PaymentInfoPtr Create();
      PaymentInfo();

      bool FromJson(const json_nlohmann& json);
      json_nlohmann ToJson();

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool active) {
         m_enable = active;
      }
      [[nodiscard]] ComPortPtr Address() const {
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
   class Payment : public Model {
     public:
      static PaymentPtr Create();
      Payment();

      bool FromJson(const json_nlohmann& json);
      json_nlohmann ToJson();

      [[nodiscard]] const PaymentInfoPtr& CitizenDevice() const {
         return m_citizenDevice;
      }
      void CitizenDevice(const PaymentInfoPtr& citizenDevice) {
         m_citizenDevice = citizenDevice;
      }
      [[nodiscard]] const PaymentInfoPtr& PosDevice() const {
         return m_posDevice;
      }
      void PosDevice(const PaymentInfoPtr& posDevice) {
         m_posDevice = posDevice;
      }

     private:
      PaymentInfoPtr m_citizenDevice{new PaymentInfo};
      PaymentInfoPtr m_posDevice{new PaymentInfo};
   };
}  // namespace anar::model
#endif  // ANAR_PAYMENT_HPP
