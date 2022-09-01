#ifndef CRESTPP_PROTOCOL_HH__
#define CRESTPP_PROTOCOL_HH__


namespace crestpp {

class Protocol {
public:
  const int& port;

public:
  static const Protocol h1c;
  static const Protocol h1;
  static const Protocol h2c;
  static const Protocol h2;
  static const Protocol h3;

public:
  bool operator==(const Protocol& protocol) const noexcept;

private:
  class Impl {
  public:
    const int port;

  private:
    static const Impl h1c;
    static const Impl h1;
    static const Impl h2c;
    static const Impl h2;
    static const Impl h3;

  private:
    Impl(int port) noexcept;

  friend class Protocol;

  };

private:
  Protocol(const Impl& impl) noexcept;

private:
  const Impl& impl_;

};

}


#endif
