#ifndef ANAR_PARS_PARK_VIEW_HPP
#define ANAR_PARS_PARK_VIEW_HPP

#include <QObject>
#include <QQmlEngine>
#include <memory>

namespace anar::parspark::view {
   class View;
   using ViewPtr = std::shared_ptr<View>;
   class View : public QObject {
      Q_OBJECT
      Q_PROPERTY(QString error MEMBER m_error NOTIFY errorRaised)

     public:
      static ViewPtr Create();
      explicit View(QObject* parent = nullptr);

      [[nodiscard]] QString error() const {
         return m_error;
      }
      void setError(const QString& error) {
         m_error = error;
      }

     signals:
      void errorRaised(QString error);

     protected:
      QString m_error;
   };
}  // namespace anar::parspark::view

#endif  // ANAR_PARS_PARK_VIEW_HPP
