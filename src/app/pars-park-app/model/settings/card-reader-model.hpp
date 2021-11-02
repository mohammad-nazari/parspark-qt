#ifndef ANAR_PARS_PARK_MODEL_CARD_READER_HPP
#define ANAR_PARS_PARK_MODEL_CARD_READER_HPP

#include "comport-model.hpp"

namespace anar::parspark::model {
   class CardReaderModel;
   using CardReaderModelPtr = std::shared_ptr<CardReaderModel>;
   class CardReaderModel : public anar::model::Model {
     public:
      CardReaderModel()
          : anar::model::Model("CardReader") {
      }

      ComPortModel Enter;
      ComPortModel Exit;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_CARD_READER_HPP
