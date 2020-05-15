#include "base-view.hpp"

namespace parspark::view {
   BaseViewPtr BaseView::Create() {
      return std::make_shared<BaseView>();
   }
   BaseView::BaseView(QObject* parent)
       : QObject(parent) {
   }
} // namespace parspark::view
