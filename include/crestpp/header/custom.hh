#ifndef CREASTPP_HEADER_CUSTOM_HH__
#define CREASTPP_HEADER_CUSTOM_HH__

#include <string>

#include "../header.hh"


namespace crestpp {
namespace header {

class Custom : public Header {
public:
  const std::string value;

public:
  Custom(std::string name, std::string value) noexcept;

public:
  std::string serialized_value() const noexcept override;

};

}
}


#endif
