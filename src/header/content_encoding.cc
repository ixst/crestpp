#include <sstream>

#include "crestpp/header/content_encoding.hh"


namespace crestpp {
namespace header {

ContentEncoding::ContentEncoding(Encoding encoding) noexcept 
    : Header("Content-Encoding"),
      encoding(std::move(encoding))
{}

std::string ContentEncoding::serialized_value() const noexcept {
  return encoding.name;
}

}
}
