#include "mysql-database.hpp"

namespace anar::database {
   MysqlDataBasePtr MysqlDataBase::Create(const model::DataBasePtr& dataBase) {
      return std::make_shared<MysqlDataBase>(dataBase);
   }
   MysqlDataBase::MysqlDataBase(const model::DataBasePtr& dataBase)
       : IDatabase(dataBase) {
      m_dataBaseHandler =
          std::shared_ptr<odb::core::database>(new odb::mysql::database(m_dataBase->UserName(), m_dataBase->PassWord(), m_dataBase->DatabaseName(), m_dataBase->HostAddress(), m_dataBase->Port()));
   }
   MysqlDataBase::~MysqlDataBase() = default;
}  // namespace anar::database
