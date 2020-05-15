#ifndef MODEL_CARDREADER_HPP
#define MODEL_CARDREADER_HPP

#include "comport.hpp"

namespace parspark::model {
   class CardReader;
   using CardReaderPtr = std::shared_ptr<CardReader>;
   class CardReader : public BaseModel {
    public:
      static CardReaderPtr Create();
      CardReader();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      ComPortPtr Enter() const {
         return m_enter;
      }
      void Enter(const ComPortPtr& enter) {
         m_enter = enter;
      }
      ComPortPtr Exit() const {
         return m_exit;
      }
      void Exit(const ComPortPtr& exit) {
         m_exit = exit;
      }

    private:
      ComPortPtr m_enter{new ComPort};
      ComPortPtr m_exit{new ComPort};
   };
} // namespace parspark::model
#endif // MODEL_CARDREADER_HPP
