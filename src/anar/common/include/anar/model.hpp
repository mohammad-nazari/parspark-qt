#ifndef ANAR_MODEL_HPP
#define ANAR_MODEL_HPP

#include <Poco/UUIDGenerator.h>

#include <memory>
#include <string>

#include "a-from-json-visitor.hpp"
#include "a-to-json-visitor.hpp"

namespace anar::model {
   class Model {
     public:
      Model(std::string name, std::string description = "")
          : Name(std::move(name))
          , Description(std::move(description)) {
      }
      virtual ~Model() = default;

      virtual bool Accept(interfaces::IModelBindingVisitor &visitor) {
         return visitor.Visit(*this);
      }

      uint64_t Id{0};                                                                 // This is for database mapping and is unique
      std::string UUId{Poco::UUIDGenerator::defaultGenerator().create().toString()};  // This is a unique UUID
      std::string Name;
      std::string Description;
   };

   using ModelPtr = std::shared_ptr<Model>;
}  // namespace anar::model
#endif  // ANAR_MODEL_HPP
