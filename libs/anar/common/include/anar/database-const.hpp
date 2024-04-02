#ifndef ANAR_CONST_DATABASE_HPP
#define ANAR_CONST_DATABASE_HPP

#include "constant-model.hpp"

namespace anar::common::constant {
    namespace DatabaseEngines {
        const model::ConstantModel ANAR_MYSQL{"mysql", "Mysql database", 0};
        const model::ConstantModel ANAR_POSTGRESQL{"postgresql", "Postgresql database", 1};
        const model::ConstantModel ANAR_ORACLE{"oracle", "Oracle database", 2};
        const model::ConstantModel ANAR_SQLSERVER{"sqlserver", "Sqlserver database", 3};
        const model::ConstantModel ANAR_DB2{"db2", "Db2 database", 4};
        const model::ConstantModel ANAR_SQLITE{"sqlite", "Sqlite database", 5};
        const model::ConstantModel ANAR_MONGODB{"mongodb", "Mongodb database", 6};
    }  // namespace DatabaseEngines
}  // namespace anar::common::constant
#endif  // ANAR_CONST_DATABASE_HPP
