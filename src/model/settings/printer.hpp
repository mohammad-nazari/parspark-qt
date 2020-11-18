#ifndef ANAR_PRINTER_HPP
#define ANAR_PRINTER_HPP

#include <cstdint>
#include <memory>
#include <string>

#include "model/base-model.hpp"

namespace anar::model {
   class Printer;
   using PrinterPtr = std::shared_ptr<Printer>;
   class Printer : public BaseModel {
     public:
      static PrinterPtr Create();
      Printer();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      [[nodiscard]] const std::string& Title() const {
         return m_title;
      }
      void Title(const std::string& title) {
         m_title = title;
      }

     private:
      bool m_enable{false};
      std::string m_title{"In the name of GOD"};
   };
}  // namespace anar::model
#endif  // ANAR_PRINTER_HPP
