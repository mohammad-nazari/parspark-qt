#include "common-view.hpp"

#include "service/qt-std-converter.hpp"

namespace anar::view {
   CommonViewPtr CommonView::Create() {
      return std::make_shared<CommonView>();
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
}  // namespace anar::view
