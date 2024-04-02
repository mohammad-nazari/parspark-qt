#ifndef ANAR_PARS_PARK_MODEL_HPP
#define ANAR_PARS_PARK_MODEL_HPP

#include "anar/model.hpp"
#include "interface/i-pars-park-model-binding-visitor.hpp"

namespace anar {
    namespace parspark {
        namespace model {
            class ParsParkModel : public anar::common::model::Model {
               public:
                ParsParkModel(const std::string &name, const std::string &description = "")
                    : anar::common::model::Model(name, description) {
                }
                virtual bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) {
                    return modelBindingVisitor.Visit(*this);
                }
            };
        }  // namespace model
    }      // namespace parspark
}  // namespace anar

#endif  // ANAR_PARS_PARK_MODEL_HPP
