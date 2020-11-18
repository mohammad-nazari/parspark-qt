#ifndef ANAR_FILEABLE_HPP
#define ANAR_FILEABLE_HPP

#include <string>

namespace anar::interfaces {
   class IFileable {
     public:
      IFileable();
      virtual ~IFileable();

      virtual bool FromFile(const std::string& filePath) = 0;
      bool FromFile(const std::string& fileName, const std::string& directory);

      virtual bool ToFile(const std::string& filePath) = 0;
      bool ToFile(const std::string& fileName, const std::string& directory);
   };
}  // namespace anar::interface

#endif  // ANAR_FILEABLE_HPP
