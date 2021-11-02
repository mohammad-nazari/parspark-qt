#ifndef ANAR_PARS_PARK_MODEL_PAYMENT_HPP
#define ANAR_PARS_PARK_MODEL_PAYMENT_HPP

#include "comport-model.hpp"

namespace anar::parspark::model {
   class PaymentInfoModel;
   using PaymentInfoModelPtr = std::shared_ptr<PaymentInfoModel>;
   class PaymentInfoModel : public anar::model::Model {
     public:
      PaymentInfoModel()
          : anar::model::Model("PaymentInfo") {
      }

      bool Enable{false};
      ComPortModel Address;
      bool SendDirect{false};
   };

   class PaymentModel;
   using PaymentModelPtr = std::shared_ptr<PaymentModel>;
   class PaymentModel : public anar::model::Model {
     public:
      PaymentModel()
          : anar::model::Model("Payment") {
      }

      PaymentInfoModel CitizenDevice;
      PaymentInfoModel PosDevice;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_PAYMENT_HPP
