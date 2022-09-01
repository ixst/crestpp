#include "crestpp/header/content_length.hh"


namespace crestpp {
namespace header {

ContentLength::ContentLength(int value) noexcept 
    : Header("Content-Length"),
      value(value)
{}

std::string ContentLength::serialized_value() const noexcept {
  return std::to_string(value);
}

}
}
