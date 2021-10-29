#ifndef ANAR_COMMON_VIEW_H
#define ANAR_COMMON_VIEW_H

#include "anar/controller/common-controller.hpp"
#include "view.hpp"

namespace anar::parspark::view {
   class CommonView;
   using CommonViewPtr = std::shared_ptr<CommonView>;
   class CommonView : public View {
      Q_OBJECT
      Q_PROPERTY(QStringList serialPorts MEMBER m_serialPorts NOTIFY serialPortsChanged)
      Q_PROPERTY(QStringList baudRates MEMBER m_baudRates NOTIFY baudRatesChanged)
      Q_PROPERTY(QStringList printers MEMBER m_printers NOTIFY printersChanged)

     public:
      static CommonViewPtr Create();
      CommonView();

     signals:
      void serialPortsChanged(QStringList serialPorts);
      void baudRatesChanged(QStringList serialPorts);
      void printersChanged(QStringList serialPorts);

     public slots:
      void getSerialPorts();
      void getSerialPortBaudRates();
      void getPrinters();

     private:
      QStringList m_serialPorts;
      QStringList m_baudRates;
      QStringList m_printers;
      controller::CommonControllerPtr m_commonController{new controller::CommonController};
   };
}  // namespace anar::view

#endif  // ANAR_COMMON_VIEW_H
