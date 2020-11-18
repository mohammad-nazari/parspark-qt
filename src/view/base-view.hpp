#ifndef VIEW_BASE_VIEW_HPP
#define VIEW_BASE_VIEW_HPP

#include <QObject>
#include <memory>

namespace anar::view {
   class BaseView;
   using BaseViewPtr = std::shared_ptr<BaseView>;
   class BaseView : public QObject {
      Q_OBJECT
      Q_PROPERTY(QString error MEMBER m_error NOTIFY errorChanged)
      Q_PROPERTY(bool done MEMBER m_done NOTIFY doneChanged)

    public:
      static BaseViewPtr Create();
      explicit BaseView(QObject* parent = nullptr);

      QString error() const {
         return m_error;
      }
      void setError(const QString& error) {
         m_error = error;
      }

      bool done() const {
         return m_done;
      }
      void setDone(bool done) {
         m_done = done;
      }

  signals:
      void errorChanged(QString error);
      void doneChanged(bool done);

    protected:
      QString m_error;
      bool m_done{false};
   };
} // namespace anar::view

#endif // VIEW_BASE_VIEW_HPP
