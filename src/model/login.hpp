#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "settings/database.hpp"
#include "user.hpp"

namespace parspark::model {
   class Login;
   using LoginPtr = std::shared_ptr<Login>;
   class Login : public User, public DataBase {
    public:
      static LoginPtr Create();
      Login();

      bool IsLoggedin() const {
         return m_isLoggedin;
      }
      void IsLoggedin(bool isLoggedin) {
         m_isLoggedin = isLoggedin;
      }
      QString Error() const {
         return m_error;
      }
      void Error(const QString& error) {
         m_error = error;
      }

    private:
      QString m_error;
      bool m_isLoggedin{false};
   };
} // namespace parspark::model
#endif // LOGIN_HPP
