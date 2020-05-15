#ifndef MODEL_COMPORT_HPP
#define MODEL_COMPORT_HPP

#include <model/base-model.hpp>

namespace parspark::model {
   class ComPort;
   using ComPortPtr = std::shared_ptr<ComPort>;
   class ComPort : public BaseModel {
    public:
      static ComPortPtr Create();
      ComPort();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      uint BaudRate() const {
         return m_baudRate;
      }
      void BaudRate(const uint& baudRate) {
         m_baudRate = baudRate;
      }
      QString PortName() const {
         return m_portName;
      }
      void PortName(const QString& portName) {
         m_portName = portName;
      }

    private:
      QString m_portName;
      uint m_baudRate{19200};
   };
} // namespace parspark::model
#endif // MODEL_COMPORT_HPP
