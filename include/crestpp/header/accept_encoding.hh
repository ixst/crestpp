#ifndef CRESTPP_HEADER_ACCEPT_ENCODING_HH__
#define CRESTPP_HEADER_ACCEPT_ENCODING_HH__

#include <vector>
#include <string>

#include "../header.hh"
#include "../encoding.hh"


namespace crestpp {
namespace header {

class AcceptEncoding : public Header {
public:
  const std::vector<Encoding> encodings;

public:
  AcceptEncoding(std::vector<Encoding> encodings) noexcept;

public:
  std::string serialized_value() const noexcept override;

};

}
}


#endif
