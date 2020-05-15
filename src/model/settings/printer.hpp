#ifndef MODEL_PRINTER_HPP
#define MODEL_PRINTER_HPP

#include <cstdint>
#include <memory>
#include <model/base-model.hpp>
#include <string>

namespace parspark::model {
   class Printer;
   using PrinterPtr = std::shared_ptr<Printer>;
   class Printer : public BaseModel {
    public:
      static PrinterPtr Create();
      Printer();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      QString Name() const {
         return m_name;
      }
      void Name(const QString& name) {
         m_name = name;
      }
      QString Title() const {
         return m_title;
      }
      void Title(const QString& title) {
         m_title = title;
      }

    private:
      bool m_enable{false};
      QString m_name{""};
      QString m_title{"In the name of GOD"};
   };
} // namespace parspark::model
#endif // MODEL_PRINTER_HPP
