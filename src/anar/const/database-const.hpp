#ifndef ANAR_CONST_DATABASE_HPP
#define ANAR_CONST_DATABASE_HPP

#include "anar/model/constant-model.hpp"

namespace anar::constant {
   namespace DatabaseEngines {
      const model::ConstantModel ANAR_MYSQL{0, "mysql", "Mysql database"};
      const model::ConstantModel ANAR_POSTGRESQL{1, "postgresql", "Postgresql database"};
      const model::ConstantModel ANAR_ORACLE{2, "oracle", "Oracle database"};
      const model::ConstantModel ANAR_SQLSERVER{3, "sqlserver", "Sqlserver database"};
      const model::ConstantModel ANAR_DB2{4, "db2", "Db2 database"};
      const model::ConstantModel ANAR_SQLITE{5, "sqlite", "Sqlite database"};
      const model::ConstantModel ANAR_MONGODB{6, "mongodb", "Mongodb database"};
   }  // namespace DatabaseEngines
}  // namespace anar::constant
#endif  // ANAR_CONST_DATABASE_HPP
