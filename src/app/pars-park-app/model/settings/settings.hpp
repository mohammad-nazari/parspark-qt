#ifndef ANAR_SETTING_HPP
#define ANAR_SETTING_HPP

#include "alpr.hpp"
#include "anar/interface/a-jsonable.hpp"
#include "anar/model/database-model.hpp"
#include "board.hpp"
#include "camera.hpp"
#include "card-reader.hpp"
#include "gate.hpp"
#include "parking.hpp"
#include "payment.hpp"
#include "printer.hpp"
#include "software.hpp"

namespace anar::model {
   class Settings;
   using SettingsPtr = std::shared_ptr<Settings>;
   class Settings : public Model {
     public:
      static SettingsPtr Create();
      Settings();

      bool FromJson(const json_nlohmann& json);
      json_nlohmann ToJson();

      [[nodiscard]] const AlprPtr& SettingAlpr() const {
         return m_settingAlpr;
      }
      void SettingAlpr(const AlprPtr& settingAlpr) {
         m_settingAlpr = settingAlpr;
      }
      [[nodiscard]] const BoardPtr& SettingBoard() const {
         return m_settingBoard;
      }
      void SettingBoard(const BoardPtr& settingBoard) {
         m_settingBoard = settingBoard;
      }
      [[nodiscard]] const CameraPtr& SettingCamera() const {
         return m_settingCamera;
      }
      void SettingCamera(const CameraPtr& settingCamera) {
         m_settingCamera = settingCamera;
      }
      [[nodiscard]] const CardReaderPtr& SettingCardReader() const {
         return m_settingCardReader;
      }
      void SettingCardReader(const CardReaderPtr& settingCardReader) {
         m_settingCardReader = settingCardReader;
      }
      [[nodiscard]] const DataBaseModelPtr& SettingDataBase() const {
         return m_settingDataBase;
      }
      void SettingDataBase(const DataBaseModelPtr& settingDataBase) {
         m_settingDataBase = settingDataBase;
      }
      [[nodiscard]] const GatePtr& SettingGate() const {
         return m_settingGate;
      }
      void SettingGate(const GatePtr& settingGate) {
         m_settingGate = settingGate;
      }
      [[nodiscard]] const ParkingPtr& SettingParking() const {
         return m_settingParking;
      }
      void SettingParking(const ParkingPtr& settingParking) {
         m_settingParking = settingParking;
      }
      [[nodiscard]] const PaymentPtr& SettingPayment() const {
         return m_settingPayment;
      }
      void SettingPayment(const PaymentPtr& settingPayment) {
         m_settingPayment = settingPayment;
      }
      [[nodiscard]] const SoftwarePtr& SettingSoftware() const {
         return m_settingSoftware;
      }
      void SettingSoftware(const SoftwarePtr& settingSoftware) {
         m_settingSoftware = settingSoftware;
      }
      [[nodiscard]] const PrinterPtr& SettingPrinter() const {
         return m_settingPrinter;
      }
      void SettingPrinter(const PrinterPtr& settingPrinter) {
         m_settingPrinter = settingPrinter;
      }

     private:
      AlprPtr m_settingAlpr{new Alpr};
      BoardPtr m_settingBoard{new Board};
      CameraPtr m_settingCamera{new Camera};
      CardReaderPtr m_settingCardReader{new CardReader};
      DataBaseModelPtr m_settingDataBase{new DataBaseModel};
      GatePtr m_settingGate{new Gate};
      ParkingPtr m_settingParking{new Parking};
      PaymentPtr m_settingPayment{new Payment};
      SoftwarePtr m_settingSoftware{new Software};
      PrinterPtr m_settingPrinter{new Printer};
   };
}  // namespace anar::model
#endif  // ANAR_SETTING_HPP
