#include "crestpp/path.hh"

#include <sstream>


namespace crestpp {

Path::Path(std::string path) noexcept 
    : Path(Parse(std::move(path)))
{}

Path::Path(std::list<std::string> nodes) noexcept
    : nodes_(std::move(nodes))
{}

std::string Path::str() const noexcept {
  std::stringstream sout;
  int i = nodes_.size();
  for(const auto& node : nodes_) {
    sout << node;
    if(--i || node.empty()) {
      sout << "/";
    }
  }
  return sout.str();
}

Path& Path::Append(const char* text) noexcept {
  return Append(std::string(text));
}

Path& Path::Append(std::string text) noexcept {
  return Append(Parse(std::move(text)));
}

Path& Path::Append(Path path) noexcept {
  nodes_.splice(nodes_.end(), path.nodes_);
  return *this;
}

bool Path::operator==(const Path& path) const noexcept {
  if(nodes_.size() != path.nodes_.size()) {
    return false;
  }
  auto i = nodes_.begin();
  auto j = path.nodes_.begin();
  for(; i != nodes_.end(); i++, j++) {
    if(*i != *j) {
      return false;
    }
  }
  return true;
}

bool Path::operator==(const std::string& text) const noexcept {
  return *this == Parse(text);
}

Path Path::Parse(std::string text) noexcept {
  std::list<std::string> nodes;

  if(text.back() == '/') {
    text.pop_back();
  } 

  decltype(text.find('/', 0)) left = 0;
  auto right = left;
  while(true) {
    right = text.find('/', left);
    if(right == std::string::npos) {
      break;
    }
    auto size = right - left;
    nodes.push_back(text.substr(left, size));
    left = right + 1;
  }
  nodes.push_back(text.substr(left));
  return { nodes };
}

}
