#ifndef ANAR_CONTROLLER_HPP
#define ANAR_CONTROLLER_HPP

#include <memory>
#include <string>

#include "anar/model/error-model.hpp"

namespace anar::controller {
   class Controller;
   using ControllerPtr = std::shared_ptr<Controller>;
   class Controller {
     public:
      static ControllerPtr Create();
      explicit Controller();
      virtual ~Controller() = default;

      const model::ErrorModel& ErrorModel() const {
         return m_errorModel;
      }
      void ErrorModel(const model::ErrorModel& errorModel) {
         m_errorModel = errorModel;
      }

     protected:
      model::ErrorModel m_errorModel;
   };
}  // namespace anar::controller
#endif  // ANAR_CONTROLLER_HPP
