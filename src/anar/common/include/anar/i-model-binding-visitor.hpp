#ifndef ANAR_INTERFACE_VISITOR_HPP
#define ANAR_INTERFACE_VISITOR_HPP

#include <memory>

namespace anar::common::model {
    class Model;
    class ConstantModel;
    class ErrorModel;
    class DataBaseModel;
}  // namespace anar::common::model

namespace anar::common::interfaces {
    class IModelBindingVisitor {
       public:
        virtual bool Visit(model::Model &model) = 0;
        virtual bool visit(model::ConstantModel &constant) = 0;
        virtual bool visit(model::ErrorModel &error) = 0;
        virtual bool Visit(model::DataBaseModel &dataBase) = 0;

        [[nodiscard]] std::shared_ptr<model::ErrorModel> Error() const {
            return m_error;
        }

       protected:
        std::shared_ptr<model::ErrorModel> m_error;
    };
}  // namespace anar::common::interfaces

#endif  // ANAR_INTERFACE_VISITOR_HPP
