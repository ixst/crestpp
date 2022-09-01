#include "crestpp/header/custom.hh"


namespace crestpp {
namespace header {

Custom::Custom(std::string name, std::string value) noexcept 
    : Header(std::move(name)),
      value(std::move(value))
{}

std::string Custom::serialized_value() const noexcept {
  return value;
}

}
}
