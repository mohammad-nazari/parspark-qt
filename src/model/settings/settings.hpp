#ifndef MODEL_SETTING_HPP
#define MODEL_SETTING_HPP

#include "alpr.hpp"
#include "board.hpp"
#include "camera.hpp"
#include "card-reader.hpp"
#include "database.hpp"
#include "gate.hpp"
#include "parking.hpp"
#include "payment.hpp"
#include "printer.hpp"
#include "software.hpp"

namespace parspark::model {
   class Settings;
   using SettingsPtr = std::shared_ptr<Settings>;
   class Settings : public BaseModel {
    public:
      static SettingsPtr Create();
      Settings();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      AlprPtr SettingAlpr() const {
         return m_settingAlpr;
      }
      void SettingAlpr(const AlprPtr& settingAlpr) {
         m_settingAlpr = settingAlpr;
      }
      BoardPtr SettingBoard() const {
         return m_settingBoard;
      }
      void SettingBoard(const BoardPtr& settingBoard) {
         m_settingBoard = settingBoard;
      }
      CameraPtr SettingCamera() const {
         return m_settingCamera;
      }
      void SettingCamera(const CameraPtr& settingCamera) {
         m_settingCamera = settingCamera;
      }
      CardReaderPtr SettingCardReader() const {
         return m_settingCardReader;
      }
      void SettingCardReader(const CardReaderPtr& settingCardReader) {
         m_settingCardReader = settingCardReader;
      }
      DataBasePtr SettingDataBase() const {
         return m_settingDataBase;
      }
      void SettingDataBase(const DataBasePtr& settingDataBase) {
         m_settingDataBase = settingDataBase;
      }
      GatePtr SettingGate() const {
         return m_settingGate;
      }
      void SettingGate(const GatePtr& settingGate) {
         m_settingGate = settingGate;
      }
      ParkingPtr SettingParking() const {
         return m_settingParking;
      }
      void SettingParking(const ParkingPtr& settingParking) {
         m_settingParking = settingParking;
      }
      PaymentPtr SettingPayment() const {
         return m_settingPayment;
      }
      void SettingPayment(const PaymentPtr& settingPayment) {
         m_settingPayment = settingPayment;
      }
      SoftwarePtr SettingSoftware() const {
         return m_settingSoftware;
      }
      void SettingSoftware(const SoftwarePtr& settingSoftware) {
         m_settingSoftware = settingSoftware;
      }
      PrinterPtr SettingPrinter() const {
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
      DataBasePtr m_settingDataBase{new DataBase};
      GatePtr m_settingGate{new Gate};
      ParkingPtr m_settingParking{new Parking};
      PaymentPtr m_settingPayment{new Payment};
      SoftwarePtr m_settingSoftware{new Software};
      PrinterPtr m_settingPrinter{new Printer};
   };
} // namespace parspark::model
#endif // MODEL_SETTING_HPP
