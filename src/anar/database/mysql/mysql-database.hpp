#ifndef ANAR_DATABASE_MYSQL_HPP
#define ANAR_DATABASE_MYSQL_HPP

#include <odb/mysql/database.hxx>

#include "anar/database/i-database.hpp"

namespace anar::database {
   class MysqlDataBase;
   using MysqlDataBasePtr = std::shared_ptr<MysqlDataBase>;
   class MysqlDataBase : public IDatabase {
     public:
      static MysqlDataBasePtr Create(const model::DataBaseModel& dataBaseModel);
      MysqlDataBase(const model::DataBaseModel& dataBaseModel);
      ~MysqlDataBase() override;
   };
}  // namespace anar::database
#endif  // ANAR_DATABASE_MYSQL_HPP
