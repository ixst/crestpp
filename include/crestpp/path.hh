#ifndef CRESTPP_PATH_HH__
#define CRESTPP_PATH_HH__

#include <list>
#include <string>
#include <sstream>


namespace crestpp {

class Path {
public:
  Path(std::string path) noexcept;
  Path(std::list<std::string> nodes) noexcept;

public:
  std::string str() const noexcept;

public:
  Path& Append(const char* text) noexcept;
  Path& Append(std::string text) noexcept;
  Path& Append(Path path) noexcept;

  template <class T>
  Path& Append(T t) noexcept {
    std::stringstream sout;
    sout << t;
    return Append(sout.str());
  }

  template <class T>
  Path& operator<<(T t) noexcept {
    return Append(t);
  }

  bool operator==(const Path& path) const noexcept;
  bool operator==(const std::string& path) const noexcept;

private:
  std::list<std::string> nodes_;

private:
  static Path Parse(std::string text) noexcept;

};

}


#endif
