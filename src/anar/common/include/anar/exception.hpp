#ifndef ANAR_EXCEPTION_HPP
#define ANAR_EXCEPTION_HPP

#include <cstdint>
#include <exception>

namespace anar::exception {
   class Exception : public std::exception {
     public:
      Exception(const char* message, const char* info = "");

      [[nodiscard]] const char* File() const {
         return m_file;
      }
      [[nodiscard]] const char* Function() const {
         return m_function;
      }
      [[nodiscard]] uint32_t Line() const {
         return m_line;
      }
      [[nodiscard]] const char* Info() const {
         return m_info;
      }
      [[nodiscard]] const char* what() const noexcept override {
         return m_message;
      }

     private:
      const char* m_message;
      const char* m_file;
      const char* m_function;
      uint32_t m_line;
      const char* m_info;
   };
}  // namespace anar::exception
#endif  // ANAR_EXCEPTION_HPP
