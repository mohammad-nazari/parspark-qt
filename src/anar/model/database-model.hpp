#ifndef ANAR_MODEL_DATABASE_HPP
#define ANAR_MODEL_DATABASE_HPP

#include "anar/model/model.hpp"

namespace anar::model {
   class DataBaseModel;
   using DataBaseModelPtr = std::shared_ptr<DataBaseModel>;
   class DataBaseModel : virtual public Model {
     public:
      static DataBaseModelPtr Create() {
         return std::make_shared<DataBaseModel>();
      }
      DataBaseModel()
          : Model("DataBase", "Database") {
      }

     public:
      std::string EngineName{};
      std::string HostAddress{"localhost"};
      std::string DBUserName{"root"};
      std::string DBPassWord{"root"};
      uint16_t Port{3306};  // Mysql default port
      std::string DatabaseName{"parspark"};
   };
}  // namespace anar::model
#endif  // ANAR_MODEL_DATABASE_HPP
