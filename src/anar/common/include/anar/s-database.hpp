#ifndef ANAR_S_DATABASE_HPP
#define ANAR_S_DATABASE_HPP

#include <map>
#include <memory>
#include <string>

namespace anar::common::database {
    class SDatabase;
    using SDatabasePtr = std::unique_ptr<SDatabase>;
    class SDatabase {
       public:
        SDatabase() = delete;
        ~SDatabase();

        static bool Connect();
        static bool Initialize();
        static bool Insert(const std::map<std::string, std::string>& dataInfos);
        static std::map<std::string, std::string> Select(const std::string& conditions);
        static bool Update(const std::string& conditions, const std::string& rowValues);
        static bool Delete(const std::string& conditions);
        static bool Disconnect();

       protected:
        std::string m_server;
        std::string m_user;
        std::string m_password;
        uint16_t m_port{0};
        std::string m_database;
    };
}  // namespace anar::common::database
#endif  // ANAR_S_DATABASE_HPP
