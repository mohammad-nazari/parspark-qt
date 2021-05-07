#ifndef ANAR_COMPORT_HPP
#define ANAR_COMPORT_HPP

#include "model/model.hpp"

namespace anar::model {
   class ComPort;
   using ComPortPtr = std::shared_ptr<ComPort>;
   class ComPort : public Model {
     public:
      static ComPortPtr Create();
      ComPort();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const std::string& PortName() const {
         return m_portName;
      }
      void PortName(const std::string& portName) {
         m_portName = portName;
      }
      [[nodiscard]] uint16_t BaudRate() const {
         return m_baudRate;
      }
      void BaudRate(uint16_t baudRate) {
         m_baudRate = baudRate;
      }

     private:
      std::string m_portName;
      uint16_t m_baudRate{19200};
   };
}  // namespace anar::model
#endif  // ANAR_COMPORT_HPP
