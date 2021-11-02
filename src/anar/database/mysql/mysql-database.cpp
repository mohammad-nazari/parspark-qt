#include "mysql-database.hpp"

namespace anar::database {
   MysqlDataBasePtr MysqlDataBase::Create(const model::DataBaseModel& dataBaseModel) {
      return std::make_shared<MysqlDataBase>(dataBaseModel);
   }
   MysqlDataBase::MysqlDataBase(const model::DataBaseModel& dataBaseModel)
       : IDatabase(dataBaseModel) {
      m_dataBaseHandler = std::shared_ptr<odb::core::database>(
          new odb::mysql::database(m_dataBaseModel.DBUserName, m_dataBaseModel.DBPassWord, m_dataBaseModel.DatabaseName, m_dataBaseModel.HostAddress, m_dataBaseModel.Port));
   }
   MysqlDataBase::~MysqlDataBase() = default;
}  // namespace anar::database
