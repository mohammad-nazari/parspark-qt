#ifndef ANAR_PARS_PARK_VIEW_COMMON_HPP
#define ANAR_PARS_PARK_VIEW_COMMON_HPP

#include "anar/common-controller.hpp"
#include "view.hpp"

namespace anar::parspark::view {
   class CommonView;
   using CommonViewPtr = std::shared_ptr<CommonView>;
   class CommonView : public View {
      Q_OBJECT
      Q_DISABLE_COPY(CommonView)
      Q_PROPERTY(QStringList serialPorts MEMBER m_serialPorts NOTIFY serialPortsChanged)
      Q_PROPERTY(QStringList baudRates MEMBER m_baudRates NOTIFY baudRatesChanged)
      Q_PROPERTY(QStringList printers MEMBER m_printers NOTIFY printersChanged)

     public:
      static CommonView* QmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine);

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
      static CommonView* m_instance;
      QStringList m_serialPorts;
      QStringList m_baudRates;
      QStringList m_printers;
      anar::common::controller::CommonControllerPtr m_commonController{new anar::common::controller::CommonController};
   };
}  // namespace anar::view

#endif  // ANAR_PARS_PARK_VIEW_COMMON_HPP
