#ifndef MODEL_JSONABLE_HPP
#define MODEL_JSONABLE_HPP

#include "stringable.hpp"

#include <QVariantMap>

namespace parspark::model {
   class Jsonable : public Stringable {
    public:
      Jsonable();

      // Stringable interface
      bool FromString(const QString& jsonString) override;
      const QString ToString() const override;

      virtual bool FromJson(const QVariantMap& json) = 0;
      virtual const QVariantMap ToJson() const = 0;
   };
} // namespace parspark::model
#endif // MODEL_JSONABLE_HPP
