#include "i-fileable.hpp"
namespace anar::interfaces {
   IFileable::IFileable() = default;
   IFileable::~IFileable() = default;

   bool IFileable::FromFile(const std::string& fileName, const std::string& directory) {
      return FromFile(directory + "/" + fileName);
   }
   bool IFileable::ToFile(const std::string& fileName, const std::string& directory) {
      return ToFile(directory + "/" + fileName);
   }
}  // namespace anar::interface
