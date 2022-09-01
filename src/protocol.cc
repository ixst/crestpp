#include "crestpp/protocol.hh"


namespace crestpp {

const Protocol Protocol::h1c(Impl::h1c);
const Protocol Protocol::h1(Impl::h1);
const Protocol Protocol::h2c(Impl::h2c);
const Protocol Protocol::h2(Impl::h2);
const Protocol Protocol::h3(Impl::h3);

Protocol::Protocol(const Impl& impl) noexcept 
    : port(impl.port),
      impl_(impl)
{}

bool Protocol::operator==(const Protocol& protocol) const noexcept {
  return &impl_ == &protocol.impl_;
}



const Protocol::Impl Protocol::Impl::h1c(80);
const Protocol::Impl Protocol::Impl::h1(443);
const Protocol::Impl Protocol::Impl::h2c(80);
const Protocol::Impl Protocol::Impl::h2(443);
const Protocol::Impl Protocol::Impl::h3(443);

Protocol::Impl::Impl(int port) noexcept 
    : port(port)
{}

}
