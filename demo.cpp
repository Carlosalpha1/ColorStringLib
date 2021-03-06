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


#include <iostream>
#include "ColorString.h"

using std::cout;
using std::endl;


int main()
{
  ColorString::String<ColorString::Red> str1 = "Hello";
  ColorString::String<ColorString::Green> str2 = "World!";
  cout << str1 << " " << str2 << endl;

  ColorString::String<ColorString::Yellow> str3 = str1 + ' ' + str2;
  cout << str3 << endl;
  str3.setColorId(ColorString::Blue);
  cout << str3 << endl;

  return 0;
}
