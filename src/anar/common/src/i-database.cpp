#include "anar/i-database.hpp"

namespace anar::common::database {
    DatabasePtr IDatabase::Create(const model::DataBaseModel& dataBaseModel) {
        return std::make_shared<IDatabase>(dataBaseModel);
    }
    IDatabase::IDatabase(model::DataBaseModel dataBaseModel)
        : m_dataBaseModel(std::move(dataBaseModel)) {
    }
    IDatabase::~IDatabase() = default;

    bool IDatabase::Initialize() {
        return m_isConnected;
    }
    bool IDatabase::Connect() {
        return m_isConnected;
    }
    bool IDatabase::Insert(const std::map<std::string, std::string>& dataInfos) {
        return false;
    }
    bool IDatabase::Update(const std::string& conditions, const std::string& rowValues) {
        return false;
    }
    bool IDatabase::Delete(const std::string& conditions) {
        return false;
    }
    bool IDatabase::Disconnect() {
        return false;
    }
}  // namespace anar::common::database
