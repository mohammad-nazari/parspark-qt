#ifndef ANAR_PARS_PARK_MODEL_PAYMENT_HPP
#define ANAR_PARS_PARK_MODEL_PAYMENT_HPP

#include "comport-model.hpp"

namespace anar::parspark::model {
   class PaymentInfoModel;
   using PaymentInfoModelPtr = std::shared_ptr<PaymentInfoModel>;
   class PaymentInfoModel : public ParsParkModel {
     public:
      PaymentInfoModel()
          : ParsParkModel("PaymentInfo") {
      }
      ~PaymentInfoModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      bool Enable{false};
      ComPortModel Address;
      bool SendDirect{false};
   };

   class PaymentModel;
   using PaymentModelPtr = std::shared_ptr<PaymentModel>;
   class PaymentModel : public ParsParkModel {
     public:
      PaymentModel()
          : ParsParkModel("Payment") {
      }
      ~PaymentModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      PaymentInfoModel CitizenDevice;
      PaymentInfoModel PosDevice;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_PAYMENT_HPP
