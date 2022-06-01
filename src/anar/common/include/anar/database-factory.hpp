#ifndef ANAR_DATABASE_FACTORY_HPP
#define ANAR_DATABASE_FACTORY_HPP

#include "database-model.hpp"
#include "i-database.hpp"

namespace anar::common::database {
    class DatabaseFactory {
       public:
        static DatabasePtr Create(const std::string& engineName, const model::DataBaseModel& dataBaseModel);

       private:
        static const std::map<std::string, std::function<DatabasePtr(const model::DataBaseModel& dataBaseModel)>> _databases;
    };
}  // namespace anar::common::database
#endif  // ANAR_DATABASE_FACTORY_HPP
