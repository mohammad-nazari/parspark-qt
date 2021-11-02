#ifndef ANAR_MODEL_HPP
#define ANAR_MODEL_HPP

#include <Poco/UUIDGenerator.h>

#include <memory>
#include <string>

namespace anar::model {
   class Model {
     public:
      Model(std::string name, std::string description = "")
          : Name(std::move(name))
          , Description(std::move(description)) {
      }
      virtual ~Model() = default;

      uint64_t Id{0};
      std::string UUId{Poco::UUIDGenerator::defaultGenerator().create().toString()};
      std::string Name;
      std::string Description;
   };

   using ModelPtr = std::shared_ptr<Model>;
}  // namespace anar::model
#endif  // ANAR_MODEL_HPP
