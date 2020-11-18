#ifndef ANAR_I_DATABASE_HPP
#define ANAR_I_DATABASE_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "model/settings/database.hpp"
#include "odb/database.hxx"

namespace anar::database {
   class IDatabase;
   using DatabasePtr = std::shared_ptr<IDatabase>;
   class IDatabase {
     public:
      static DatabasePtr Create(const model::DataBasePtr& dataBase);
      IDatabase(model::DataBasePtr dataBase);
      virtual ~IDatabase();

      bool Connect();
      bool Initialize();
      bool Insert(const std::map<std::string, std::string>& dataInfos);
      template <typename TableTemp>
      std::vector<TableTemp> Select(const odb::query<TableTemp>& query) {
         std::vector<TableTemp> resultList;
         odb::core::transaction transaction(m_dataBaseHandler->begin());

         odb::result<TableTemp> result(m_dataBaseHandler->query<TableTemp>(query));
         if (!result.empty()) {
            for (const auto& resultValue : result) {
               resultList.emplace_back(resultValue);
            }
         }
         transaction.commit();

         return resultList;
      }
      bool Update(const std::string& conditions, const std::string& rowValues);
      bool Delete(const std::string& conditions);
      bool Disconnect();

     protected:
      model::DataBasePtr m_dataBase;
      std::shared_ptr<odb::core::database> m_dataBaseHandler;
   };
}  // namespace anar::database

#endif  // ANAR_I_DATABASE_HPP
