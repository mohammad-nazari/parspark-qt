#ifndef ANAR_BASE_MODEL_HPP
#define ANAR_BASE_MODEL_HPP

#include <memory>
#include <string>

#include "interface/i-a-jsonable.hpp"

namespace anar::model {
   class BaseModel;
   using BaseModelPtr = std::shared_ptr<BaseModel>;
   class BaseModel : public interfaces::IAJsonable {
     public:
      static BaseModelPtr Create(const std::string& name);
      BaseModel(std::string name);

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const std::string& Id() const {
         return m_id;
      }
      void Id(const std::string& id) {
         m_id = id;
      }
      [[nodiscard]] const std::string& Name() const {
         return m_name;
      }
      void Name(const std::string& name) {
         m_name = name;
      }
      [[nodiscard]] const std::string& Error() const {
         return m_error;
      }
      void Error(const std::string& error) {
         m_error = error;
      }

     protected:
      std::string m_id;
      std::string m_name;
      std::string m_error;
   };
}  // namespace anar::model
#endif  // ANAR_BASE_MODEL_HPP
