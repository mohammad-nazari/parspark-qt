#include "anar/exception.hpp"

namespace anar::common::exception {
    Exception::Exception(const char *message, const char *info)
        : m_message(message)
        , m_file(__FILE__)
        , m_function(__FUNCTION__)
        , m_line(__LINE__)
        , m_info(info) {
    }
}  // namespace anar::common::exception