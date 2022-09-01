#ifndef CRESTPP_HEADER_CONTENT_ENCODING_HH__
#define CRESTPP_HEADER_CONTENT_ENCODING_HH__

#include <string>

#include "../header.hh"
#include "../encoding.hh"


namespace crestpp {
namespace header {

class ContentEncoding : public Header {
public:
  const Encoding encoding;

public:
  ContentEncoding(Encoding encoding) noexcept;

public:
  std::string serialized_value() const noexcept override;

};

}
}


#endif
