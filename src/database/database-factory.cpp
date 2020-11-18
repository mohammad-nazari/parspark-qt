#include "database-factory.hpp"

#include "const/database-const.hpp"

namespace anar::database {
   const std::map<std::string, std::function<DatabasePtr(const model::DataBasePtr& dataBase)>> DatabaseFactory::_databases = {
       {constant::DatabaseEngines::AN_MYSQL, [](const model::DataBasePtr& dataBase) {
           return MysqlDataBase::Create(dataBase);
        }}};

   DatabasePtr DatabaseFactory::Create(const std::string& engineName, const model::DataBasePtr& dataBase) {
      if (_databases.find(engineName) != _databases.end()) {
         return nullptr;
      }
      return _databases.at(engineName)(dataBase);
   }
}  // namespace anar::database