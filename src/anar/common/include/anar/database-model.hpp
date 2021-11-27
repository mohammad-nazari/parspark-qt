#ifndef ANAR_MODEL_DATABASE_HPP
#define ANAR_MODEL_DATABASE_HPP

#include "anar/model.hpp"

namespace anar::model {
   class DataBaseModel : public Model {
     public:
      DataBaseModel()
          : Model("DataBase", "Database") {
      }

      bool Accept(service::AFromJsonVisitor *visitor) final {
         return visitor->Visit(this);
      }

      std::string EngineName{};
      std::string HostAddress{"localhost"};
      std::string DBUserName{"root"};
      std::string DBPassWord{"root"};
      uint16_t Port{3306};  // Mysql default port
      std::string DatabaseName{"parspark"};
   };
   using DataBaseModelPtr = std::shared_ptr<DataBaseModel>;
}  // namespace anar::model
#endif  // ANAR_MODEL_DATABASE_HPP