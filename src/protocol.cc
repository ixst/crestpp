#include "crestpp/protocol.hh"


namespace crestpp {

const Protocol Protocol::h1(Impl::h1);
const Protocol Protocol::h2(Impl::h2);
const Protocol Protocol::h3(Impl::h3);

Protocol::Protocol(const Impl& impl) noexcept 
    : name(impl.name),
      impl_(impl)
{}

bool Protocol::operator==(const Protocol& protocol) const noexcept {
  return &impl_ == &protocol.impl_;
}



const Protocol::Impl Protocol::Impl::h1("h1");
const Protocol::Impl Protocol::Impl::h2("h2");
const Protocol::Impl Protocol::Impl::h3("h3");

Protocol::Impl::Impl(std::string name) noexcept 
    : name(std::move(name))
{}

}
