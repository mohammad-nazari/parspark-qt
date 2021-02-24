#include "i-database.hpp"

namespace anar::database {
   DatabasePtr IDatabase::Create(const model::DataBasePtr& dataBase) {
      return std::make_shared<IDatabase>(dataBase);
   }
   IDatabase::IDatabase(model::DataBasePtr dataBase)
       : m_dataBase(std::move(dataBase)) {
   }
   IDatabase::~IDatabase() = default;

   bool IDatabase::Initialize() {
      return true;
   }
   bool IDatabase::Connect() {
      return true;
   }
   bool IDatabase::Insert(const std::map<std::string, std::string>& dataInfos) {
      return false;
   }
   bool IDatabase::Update(const std::string& conditions, const std::string& rowValues) {
      return false;
   }
   bool IDatabase::Delete(const std::string& conditions) {
      return false;
   }
   bool IDatabase::Disconnect() {
      return false;
   }
}  // namespace anar::database
