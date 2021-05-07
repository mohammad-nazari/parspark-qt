#ifndef PARSPARK_ERROR_HPP
#define PARSPARK_ERROR_HPP

#include "model.hpp"

namespace anar::model {
   class Error : public Model {
     public:
      Error();
      ~Error() override;

      [[nodiscard]] uint64_t Code() const {
         return m_code;
      }
      void Code(uint64_t code) {
         m_code = code;
      }
      [[nodiscard]] const std::string& Message() const {
         return m_message;
      }
      void Message(const std::string& message) {
         m_message = message;
      }
      [[nodiscard]] const std::vector<Error>& SubErrors() const {
         return m_subErrors;
      }
      void SubErrors(const std::vector<Error>& subErrors) {
         m_subErrors = subErrors;
      }

     private:
      uint64_t m_code{0};
      std::string m_message;
      std::vector<Error> m_subErrors{};
   };
}  // namespace anar::model
#endif  // PARSPARK_ERROR_HPP
