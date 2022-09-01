#include "crestpp/encoding.hh"


namespace crestpp {

const Encoding Encoding::br(Impl::br);
const Encoding Encoding::gzip(Impl::gzip);
const Encoding Encoding::deflate(Impl::deflate);

Encoding::Encoding(const Impl& impl) noexcept 
    : name(impl.name),
      impl_(impl)
{}

bool Encoding::operator==(const Encoding& encoding) const noexcept {
  return &impl_ == &encoding.impl_;
}



const Encoding::Impl Encoding::Impl::br("br");
const Encoding::Impl Encoding::Impl::gzip("gzip");
const Encoding::Impl Encoding::Impl::deflate("deflate");

Encoding::Impl::Impl(std::string name) noexcept 
    : name(std::move(name))
{}

}
