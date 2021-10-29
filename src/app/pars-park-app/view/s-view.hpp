#ifndef ANAR_S_VIEW_HPP
#define ANAR_S_VIEW_HPP

#include <QObject>
#include <memory>

namespace anar::parspark::view {
   class SView;
   using SViewUPtr = std::unique_ptr<SView>;
   class SView {};
}  // namespace anar::view

#endif  // ANAR_S_VIEW_HPP
