#ifndef ANAR_PARS_PARK_MODEL_CARD_READER_HPP
#define ANAR_PARS_PARK_MODEL_CARD_READER_HPP

#include "comport-model.hpp"

namespace anar::parspark::model {
   class CardReaderModel;
   using CardReaderModelPtr = std::shared_ptr<CardReaderModel>;
   class CardReaderModel : public ParsParkModel {
     public:
      CardReaderModel()
          : ParsParkModel("CardReader", "CardReader") {
      }
      ~CardReaderModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      ComPortModel EnterCardReader;
      ComPortModel ExitCardReader;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_CARD_READER_HPP
