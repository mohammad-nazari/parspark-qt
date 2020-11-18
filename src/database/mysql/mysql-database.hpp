#ifndef ANAR_MYSQL_DATABASE_HPP
#define ANAR_MYSQL_DATABASE_HPP

#include "database/i-database.hpp"
#include "odb/mysql/database.hxx"

namespace anar::database {
   class MysqlDataBase;
   using MysqlDataBasePtr = std::shared_ptr<MysqlDataBase>;
   class MysqlDataBase : public IDatabase {
     public:
      static MysqlDataBasePtr Create(const model::DataBasePtr & dataBase);
      MysqlDataBase(const model::DataBasePtr & dataBase);
      ~MysqlDataBase() override;
   };
}  // namespace anar::database
#endif  // ANAR_MYSQL_DATABASE_HPP
