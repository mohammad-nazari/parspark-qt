#ifndef BASE_MODEL_HPP
#define BASE_MODEL_HPP

#include "jsonable.hpp"
#include <memory>
#include <qstring.h>

namespace parspark::model {
   class BaseModel;
   using BaseModelPtr = std::shared_ptr<BaseModel>;
   class BaseModel : public Jsonable {
    public:
      static BaseModelPtr Create(const QString& name);
      BaseModel(const QString& name);

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      QString Id() const;
      void Id(const QString& id);
      QString Name() const;
      void Name(const QString& name);

    protected:
      QString m_id;
      QString m_name;
   };
} // namespace parspark::model
#endif // BASE_MODEL_HPP
