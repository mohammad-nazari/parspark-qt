#ifndef ANAR_MODEL_HPP
#define ANAR_MODEL_HPP

#include <Poco/UUIDGenerator.h>

#include <memory>
#include <string>

#include "interface/a-jsonable.hpp"

namespace anar::model {
   class Model;
   using ModelPtr = std::shared_ptr<Model>;
   class Model : public interfaces::AJsonable {
     public:
      static ModelPtr CreatePtr(const std::string& name, const std::string& description);
      static Model Create(const std::string& name, const std::string& description);
      Model(std::string name, std::string description = "");

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
      [[nodiscard]] const std::string& Description() const {
         return m_description;
      }
      void Description(const std::string& description) {
         m_description = description;
      }
      [[nodiscard]] const std::string& Error() const {
         return m_error;
      }
      void Error(const std::string& error) {
         m_error = error;
      }

     protected:
      std::string m_id{Poco::UUIDGenerator::defaultGenerator().create().toString()};
      std::string m_name;
      std::string m_description;
      std::string m_error;
   };
}  // namespace anar::model
#endif  // ANAR_MODEL_HPP
