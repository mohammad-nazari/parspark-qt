#ifndef ANAR_I_DATABASE_HPP
#define ANAR_I_DATABASE_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "anar/error-manager.hpp"
#include "database-model.hpp"
#include "odb/database.hxx"

namespace anar::common::database {
    class IDatabase;
    using DatabasePtr = std::shared_ptr<IDatabase>;
    class IDatabase {
       public:
        static DatabasePtr Create(const model::DataBaseModel& dataBaseModel);
        IDatabase(model::DataBaseModel dataBaseModel);
        virtual ~IDatabase();

        bool Initialize();
        bool Connect();
        bool Insert(const std::map<std::string, std::string>& dataInfos);
        template <typename TableTemp>
        bool Select(const odb::query<TableTemp>& query, std::vector<TableTemp>& resultList) {
            service::ErrorManager::ResetError(m_error);
            try {
                resultList.clear();
                odb::core::transaction transaction(m_dataBaseHandler->begin());
                odb::result<TableTemp> result(m_dataBaseHandler->query<TableTemp>(query));
                if (!result.empty()) {
                    for (const auto& resultValue : result) {
                        resultList.emplace_back(resultValue);
                    }
                }
                transaction.commit();
            } catch (std::exception& exception) {
                m_error = service::ErrorManager::GenerateError(1, constant::ErrorLevel::ANAR_FATAL, std::string("Database error: ") + exception.what());
            }
            return service::ErrorManager::HaveNoError(m_error);
        }
        bool Update(const std::string& conditions, const std::string& rowValues);
        bool Delete(const std::string& conditions);
        bool Disconnect();

        const model::ErrorModel& Error() const {
            return m_error;
        }

       protected:
        model::DataBaseModel m_dataBaseModel;
        std::shared_ptr<odb::database> m_dataBaseHandler;
        model::ErrorModel m_error;
    };
}  // namespace anar::common::database

#endif  // ANAR_I_DATABASE_HPP
