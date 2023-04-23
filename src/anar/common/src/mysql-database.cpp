#include "anar/mysql-database.hpp"
#include <iostream>

namespace anar::common::database {
    MysqlDataBasePtr MysqlDataBase::Create(const model::DataBaseModel &dataBaseModel) {
        return std::make_shared<MysqlDataBase>(dataBaseModel);
    }

    MysqlDataBase::MysqlDataBase(const model::DataBaseModel &dataBaseModel)
            : IDatabase(dataBaseModel) {
        try {
            m_dataBaseHandler =
                    std::make_shared<odb::mysql::database>(m_dataBaseModel.DBUserName, m_dataBaseModel.DBPassWord,
                                                           m_dataBaseModel.DatabaseName, m_dataBaseModel.HostAddress,
                                                           m_dataBaseModel.Port);
            m_isConnected = m_dataBaseHandler != nullptr;
        } catch (const std::exception &e) {
            m_isConnected = false;
            std::cerr << e.what() << '\n';
        }
    }

    MysqlDataBase::~MysqlDataBase() = default;
}  // namespace anar::common::database
