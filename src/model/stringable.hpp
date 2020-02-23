#ifndef STRINGABLE_HPP
#define STRINGABLE_HPP

#include <QString>

namespace parspark::model {
   class Stringable {
    public:
      Stringable();

      virtual bool FromString(const QString& jsonString) = 0;
      virtual const QString ToString() const = 0;
   };
} // namespace parspark::model
#endif // STRINGABLE_HPP
