#ifndef ANAR_MODEL_DATABASE_HPP
#define ANAR_MODEL_DATABASE_HPP

#include "anar/model.hpp"

namespace anar::common::model {
    class DataBaseModel : public Model {
       public:
        DataBaseModel()
            : Model("DataBase", "Database") {
        }

        bool Accept(interfaces::IModelBindingVisitor &visitor) final {
            return visitor.Visit(*this);
        }

        std::string EngineName{};
        std::string HostAddress{"localhost"};
        std::string DBUserName{"parspark"};
        std::string DBPassWord{"123456"};
        uint16_t Port{3306};  // Mysql default port
        std::string DatabaseName{"parspark"};
    };
    using DataBaseModelPtr = std::shared_ptr<DataBaseModel>;
}  // namespace anar::common::model
#endif  // ANAR_MODEL_DATABASE_HPP
