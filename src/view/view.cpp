#include "view.hpp"

namespace anar::view {
   ViewPtr View::Create() {
      return std::make_shared<View>();
   }
   View::View(QObject* parent)
       : QObject(parent) {
   }
} // namespace anar::view
