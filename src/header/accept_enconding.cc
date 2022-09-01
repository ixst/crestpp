#include <sstream>

#include "crestpp/header/accept_encoding.hh"


namespace crestpp {
namespace header {

AcceptEncoding::AcceptEncoding(std::vector<Encoding> encodings) noexcept 
    : Header("Accept-Encoding"),
      encodings(std::move(encodings))
{}

std::string AcceptEncoding::serialized_value() const noexcept {
  std::stringstream sout;
  auto size = encodings.size();
  for(size_t i = 0; i < size; i++) {
    if(i) {
      sout << ", ";
    }
    sout << encodings[i].name;
  }
  return sout.str();
}

}
}
