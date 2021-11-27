#ifndef ANAR_INTERFACE_VISITOR_HPP
#define ANAR_INTERFACE_VISITOR_HPP

#include <memory>

namespace anar::model {
   class Model;
   class ConstantModel;
   class ErrorModel;
   class DataBaseModel;
}  // namespace anar::model

namespace anar::interfaces {
   class IVisitor {
     public:
      virtual bool Visit(model::Model *model) = 0;
      virtual bool visit(model::ConstantModel *constant) = 0;
      virtual bool visit(model::ErrorModel *error) = 0;
      virtual bool Visit(model::DataBaseModel *dataBase) = 0;

      [[nodiscard]] std::shared_ptr<model::ErrorModel> Error() const;

     protected:
      std::shared_ptr<model::ErrorModel> m_error{nullptr};
   };
}  // namespace anar::interfaces

#endif  // ANAR_INTERFACE_VISITOR_HPP
