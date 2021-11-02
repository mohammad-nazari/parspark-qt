#include "database-factory.hpp"

#include "anar/const/database-const.hpp"
#include "mysql/mysql-database.hpp"

namespace anar::database {
   const std::map<std::string, std::function<DatabasePtr(const model::DataBaseModel& dataBaseModel)>> DatabaseFactory::_databases = {
       {constant::DatabaseEngines::ANAR_MYSQL.Name, [](const model::DataBaseModel& dataBaseModel) {
           return MysqlDataBase::Create(dataBaseModel);
        }}};

   DatabasePtr DatabaseFactory::Create(const std::string& engineName, const model::DataBaseModel& dataBaseModel) {
      if (_databases.find(engineName) != _databases.end()) {
         return nullptr;
      }
      return _databases.at(engineName)(dataBaseModel);
   }
}  // namespace anar::database