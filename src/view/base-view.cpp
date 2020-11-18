#include "base-view.hpp"

namespace anar::view {
   BaseViewPtr BaseView::Create() {
      return std::make_shared<BaseView>();
   }
   BaseView::BaseView(QObject* parent)
       : QObject(parent) {
   }
} // namespace anar::view
