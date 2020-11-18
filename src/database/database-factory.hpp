#ifndef ANAR_DATABASE_FACTORY_HPP
#define ANAR_DATABASE_FACTORY_HPP

#include "database/mysql/mysql-database.hpp"

namespace anar::database {
   class DatabaseFactory {
     public:
      static DatabasePtr Create(const std::string& engineName, const model::DataBasePtr& dataBase);

     private:
      static const std::map<std::string, std::function<DatabasePtr(const model::DataBasePtr& dataBase)>> _databases;
   };
}  // namespace anar::database
#endif  // ANAR_DATABASE_FACTORY_HPP
