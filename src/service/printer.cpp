#include "printer.hpp"

namespace anar::service {
   PrinterPtr Printer::Create() {
      return std::make_shared<Printer>();
   }
   Printer::Printer() = default;

//   QList<QPrinterInfo> Printer::GetList() {
//      return QPrinterInfo::availablePrinters();
//   }

   std::vector<std::string> Printer::GetListNames() {
      return std::vector<std::string>();
   }

//   QPrinterInfo Printer::GetDefault() {
//      return QPrinterInfo::defaultPrinter();
//   }

   std::string Printer::GetDefaultName() {
      return std::string();
   }

//   QPrinterInfo Printer::GetInfo(const QString& printerName) {
//      return QPrinterInfo::printerInfo(printerName);
//   }
}  // namespace anar::service
