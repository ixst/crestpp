#ifndef CRESTPP_HEADER_CONTENT_LENGTH_HH__
#define CRESTPP_HEADER_CONTENT_LENGTH_HH__

#include <string>

#include "../header.hh"


namespace crestpp {
namespace header {

class ContentLength : public Header {
public:
  int value;

public:
  ContentLength(int value) noexcept;

public:
  std::string serialized_value() const noexcept override;

};

}
}


#endif
