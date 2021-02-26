#ifndef ANAR_DATABASE_CONST_HPP
#define ANAR_DATABASE_CONST_HPP

namespace anar::constant {
   namespace DatabaseEngines {
      constexpr char AN_MYSQL[]{"mysql"};
      constexpr char AN_POSTGRESQL[]{"postgresql"};
      constexpr char AN_ORACLE[]{"oracle"};
      constexpr char AN_SQLSERVER[]{"sqlserver"};
      constexpr char AN_DB2[]{"db2"};
      constexpr char AN_SQLITE[]{"sqlite"};
      constexpr char AN_MONGODB[]{"mongodb"};
   }  // namespace DatabaseEngines
}  // namespace anar::constant
#endif  // ANAR_DATABASE_CONST_HPP
