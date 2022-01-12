#ifndef ANAR_SERVICE_PRINTER_HPP
#define ANAR_SERVICE_PRINTER_HPP

//#ifdef WIN32
//#    include <windows.h>
//#endif
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

//#ifdef WIN32
//        static PRINTER_INFO_2* GetList(DWORD& count);
//#endif
        static std::vector<std::string> GetListNames();
        //      static QPrinterInfo GetDefault();
        static std::string GetDefaultName();
        //      static QPrinterInfo GetInfo(const std::string& printerName);
    };
}  // namespace anar::service
#endif  // ANAR_SERVICE_PRINTER_HPP
