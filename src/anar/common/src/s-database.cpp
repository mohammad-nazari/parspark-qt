#include "anar/s-database.hpp"

namespace anar::common::database {
    SDatabase::~SDatabase() = default;

    bool SDatabase::Connect() {
        return false;
    }
    bool SDatabase::Initialize() {
        return false;
    }
    bool SDatabase::Insert(const std::map<std::string, std::string>& dataInfos) {
        return false;
    }
    std::map<std::string, std::string> SDatabase::Select(const std::string& conditions) {
        return {};
    }
    bool SDatabase::Update(const std::string& conditions, const std::string& rowValues) {
        return false;
    }
    bool SDatabase::Delete(const std::string& conditions) {
        return false;
    }
    bool SDatabase::Disconnect() {
        return false;
    }
}  // namespace anar::common::database
