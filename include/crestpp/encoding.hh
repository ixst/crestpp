#ifndef CRESTPP_ENCODING_HH__
#define CRESTPP_ENCODING_HH__

#include <string>


namespace crestpp {

class Encoding {
public:
  const std::string& name;

public:
  static const Encoding br;
  static const Encoding gzip;
  static const Encoding deflate;

public:
  bool operator==(const Encoding& encoding) const noexcept;

private:
  class Impl {
  public:
    const std::string name;

  private:
    static const Impl br;
    static const Impl gzip;
    static const Impl deflate;

  private:
    Impl(std::string name) noexcept;

  friend class Encoding;

  };

private:
  Encoding(const Impl& impl) noexcept;

private:
  const Impl& impl_;

};

}


#endif
