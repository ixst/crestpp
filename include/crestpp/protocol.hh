#ifndef CRESTPP_PROTOCOL_HH__
#define CRESTPP_PROTOCOL_HH__

#include <string>


namespace crestpp {

class Protocol {
public:
  const std::string& name;

public:
  static const Protocol h1;
  static const Protocol h2;
  static const Protocol h3;

public:
  bool operator==(const Protocol& protocol) const noexcept;

private:
  class Impl {
  public:
    const std::string name;

  private:
    static const Impl h1;
    static const Impl h2;
    static const Impl h3;

  private:
    Impl(std::string name) noexcept;

  friend class Protocol;

  };

private:
  Protocol(const Impl& impl) noexcept;

private:
  const Impl& impl_;

};

}


#endif
