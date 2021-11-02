#include "common-view.hpp"

#include "service/qt-std-converter.hpp"

namespace anar::parspark::view {
   CommonView* CommonView::m_instance = nullptr;
   CommonView* CommonView::QmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)
      if (!m_instance) {
         m_instance = new CommonView();
      }
      return m_instance;
   }
   CommonView::CommonView()
       : View() {
   }

   void CommonView::getSerialPorts() {
      m_serialPorts = service::QtStdConverter::VectorToQStringList(m_commonController->GetSerialPortListNames());
   }
   void CommonView::getSerialPortBaudRates() {
      m_baudRates = service::QtStdConverter::VectorToQStringList(m_commonController->GetSerialPortBaudRates());
   }
   void CommonView::getPrinters() {
      m_printers = service::QtStdConverter::VectorToQStringList(m_commonController->GetPrinterListNames());
   }
}  // namespace anar::parspark::view
