#ifndef CRESTPP_HEADER_HH__
#define CRESTPP_HEADER_HH__

#include <string>


namespace crestpp {

class Header {
public:
  const std::string name;

public:
  virtual std::string serialized_value() const noexcept = 0;

protected:
  Header(std::string name) noexcept;

};

}


#endif
