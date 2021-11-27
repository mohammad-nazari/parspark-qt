#include "anar/i-visitor.hpp"

#include "anar/error-model.hpp"

namespace anar::interfaces {
   std::shared_ptr<model::ErrorModel> IVisitor::Error() const {
      return m_error;
   }
}