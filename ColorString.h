//  Copyright 2021 Carlos Caminero (Carlosalpha1)

//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at

//      http://www.apache.org/licenses/LICENSE-2.0

//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.


#ifndef COLORSTRING_H_
#define COLORSTRING_H_

#include <string>
#include <map>


namespace ColorString
{

/**
 * A list of all possible colors
 */
enum {Not_color,
  Black,    Bold_Black,   High_Black,
  Red,      Bold_Red,     High_Red,
  Green,    Bold_Green,   High_Green,
  Yellow,   Bold_Yellow,  High_Yellow,
  Blue,     Bold_Blue,    High_Blue,
  Purple,   Bold_Purple,  High_Purple,
  Cyan,     Bold_Cyan,    High_Cyan,
  White,    Bold_White,   High_White,
};


/**
 * A table which associate each color
 * with a representation code
 */
std::map<int, std::string> colors = {
  {Not_color,     "\033[0m"   },
  {Black,         "\033[0;0m" },
  {Red,           "\033[0;31m"},
  {Green,         "\033[0;32m"},
  {Yellow,        "\033[0;33m"},
  {Blue,          "\033[0;34m"},
  {Purple,        "\033[0;35m"},
  {Cyan,          "\033[0;36m"},
  {White,         "\033[0;37m"},
  {Bold_Black,    "\033[1;30m"},
  {Bold_Red,      "\033[1;31m"},
  {Bold_Green,    "\033[1;32m"},
  {Bold_Yellow,   "\033[1;33m"},
  {Bold_Blue,     "\033[1;34m"},
  {Bold_Purple,   "\033[1;35m"},
  {Bold_Cyan,     "\033[1;36m"},
  {White,         "\033[1;37m"},
  {High_Black,    "\033[0;90m"},
  {High_Red,      "\033[0;91m"},
  {High_Green,    "\033[0;92m"},
  {High_Yellow,   "\033[0;93m"},
  {High_Blue,     "\033[0;94m"},
  {High_Purple,   "\033[0;95m"},
  {High_Cyan,     "\033[0;96m"},
  {High_White,    "\033[0;97m"},
};


/** 
 *  Class String (ColorString Namespace)
 *  It inherits all public methods from std::string class
 *  and adds the ability to have color defined in "colors"
 */
template <int color_id = White>
class String : public std::string
{
private:
  int color = color_id;

public:
  String()
    : std::string() {}
  String(const std::string & str)
    : std::string(str) {}
  String(const std::string & str, size_t pos, size_t len = npos)
    : std::string(str, pos, len) {}
  String(const char * s)
    : std::string(s) {}
  String(const char * s, size_t n)
    : std::string(s, n) {}
  template <class InputIterator>
  String(InputIterator first, InputIterator last)
    : std::string(first, last) {}


  ~String() {}


  // New Methods of ColorString Class
  int getColorId() const { return color; }
  void setColorId(int id) { color = id; }


  friend std::ostream & operator<<(std::ostream& os, const String & str)
  {
    os << colors[str.color] << (std::string) str << colors[Not_color];
    return os;
  }
};

};  // namespace ColorString

#endif  // COLORSTRING_H_
