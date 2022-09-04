#include "crestpp/request.hh"


namespace crestpp {

Request::Request(Path path) noexcept 
    : path(std::move(path))
{}

}
