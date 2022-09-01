#include "crestpp/header.hh"


namespace crestpp {

Header::Header(std::string name) noexcept 
    : name(std::move(name))
{}

}
