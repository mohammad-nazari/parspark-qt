#ifndef ANAR_DATABASE_FACTORY_HPP
#define ANAR_DATABASE_FACTORY_HPP

#include "anar/model/database-model.hpp"
#include "i-database.hpp"

namespace anar::database {
   class DatabaseFactory {
     public:
      static DatabasePtr Create(const std::string& engineName, const model::DataBaseModel& dataBaseModel);

     private:
      static const std::map<std::string, std::function<DatabasePtr(const model::DataBaseModel& dataBaseModel)>> _databases;
   };
}  // namespace anar::database
#endif  // ANAR_DATABASE_FACTORY_HPP
