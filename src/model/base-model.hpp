#ifndef MODEL_BASE_MODEL_HPP
#define MODEL_BASE_MODEL_HPP

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

      QString Id() const {
         return m_id;
      }
      void Id(const QString& id) {
         m_id = id;
      }
      QString Name() const {
          return m_name;
      }
      void Name(const QString& name) {
          m_name = name;
      }
      QString Error() const {
          return m_error;
      }
      void Error(const QString& error) {
          m_error = error;
      }

    protected:
      QString m_id;
      QString m_name;
      QString m_error;
   };
} // namespace parspark::model
#endif // MODEL_BASE_MODEL_HPP
