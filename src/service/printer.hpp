#ifndef ANAR_PRINTER_HPP
#define ANAR_PRINTER_HPP

#include <memory>
#include <string>
#include <vector>

namespace anar::service {
   class Printer;
   using PrinterPtr = std::shared_ptr<Printer>;
   class Printer {
     public:
      static PrinterPtr Create();
      Printer();

      //      static std::vector<QPrinterInfo> GetList();
      static std::vector<std::string> GetListNames();
//      static QPrinterInfo GetDefault();
      static std::string GetDefaultName();
//      static QPrinterInfo GetInfo(const std::string& printerName);
   };
}  // namespace anar::service
#endif  // ANAR_PRINTER_HPP
