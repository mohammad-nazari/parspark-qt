#include "anar/printer.hpp"
#ifdef WIN32
#    include <windows.h>
#endif

namespace anar::service {
    PrinterPtr Printer::Create() {
        return std::make_shared<Printer>();
    }
    Printer::Printer() = default;

    //   QList<QPrinterInfo> Printer::GetList() {
    //      return QPrinterInfo::availablePrinters();
    //   }
//#ifdef WIN32
//    PRINTER_INFO_2* Printer::GetList(DWORD& count) {
//        PRINTER_INFO_2* printers;
//        DWORD sz = 0;
//        DWORD Level = 2;
//        int i;
//        int sl;
//
//        EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, Level, NULL, 0, &sz, &count);
//
//        if ((printers = (PRINTER_INFO_2*)malloc(sz)) == 0)
//            return {};
//
//        if (!EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, Level, (LPBYTE)printers, sz, &sz, &count)) {
//            free(printers);
//            return {};
//        }
//        return printers;
//    }
//#endif

    std::vector<std::string> Printer::GetListNames() {
        std::vector<std::string> printerNames;
#ifdef WIN32
        DWORD count = 0;
//        PRINTER_INFO_2* printers = GetList(count);
        PRINTER_INFO_2* printers;
        DWORD sz = 0;
        DWORD Level = 2;
        int i;
        int sl;

        EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, Level, NULL, 0, &sz, &count);

        if ((printers = (PRINTER_INFO_2*)malloc(sz)) == 0)
            return {};

        if (!EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, Level, (LPBYTE)printers, sz, &sz, &count)) {
            free(printers);
            return {};
        }
        for (size_t index = 0; index < (int)count; index++) {
            std::wstring wstr(printers[index].pPrinterName);
            printerNames.emplace_back(std::string(wstr.begin(), wstr.end()));
        }
#endif

        return printerNames;
    }

    //   QPrinterInfo Printer::GetDefault() {
    //      return QPrinterInfo::defaultPrinter();
    //   }

    std::string Printer::GetDefaultName() {
#ifdef WIN32
        DWORD count = 0;
//        PRINTER_INFO_2* printers = GetList(count);
//        for (size_t index = 0; index < (int)count; index++) {
//            std::wstring wstr(printers[index].pPrinterName);
//            return std::string(wstr.begin(), wstr.end());
//        }
#endif
        return "";
    }

    //   QPrinterInfo Printer::GetInfo(const QString& printerName) {
    //      return QPrinterInfo::printerInfo(printerName);
    //   }
}  // namespace anar::service
