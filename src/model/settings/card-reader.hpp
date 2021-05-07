#ifndef ANAR_CARD_READER_HPP
#define ANAR_CARD_READER_HPP

#include "comport.hpp"

namespace anar::model {
   class CardReader;
   using CardReaderPtr = std::shared_ptr<CardReader>;
   class CardReader : public Model {
     public:
      static CardReaderPtr Create();
      CardReader();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const ComPortPtr& Enter() const {
         return m_enter;
      }
      void Enter(const ComPortPtr& enter) {
         m_enter = enter;
      }
      [[nodiscard]] const ComPortPtr& Exit() const {
         return m_exit;
      }
      void Exit(const ComPortPtr& exit) {
         m_exit = exit;
      }

     private:
      ComPortPtr m_enter{new ComPort};
      ComPortPtr m_exit{new ComPort};
   };
}  // namespace anar::model
#endif  // ANAR_CARD_READER_HPP
