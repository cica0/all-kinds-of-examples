#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

int main () {
  std::string foo = "foo-string";
  std::string bar = "bar-string";
  std::vector<std::string> myvector;

  myvector.push_back (foo);                    // copies
  myvector.push_back (std::move(bar));         // moves


  std::cout << "myvector contains:";
  for (std::string& x:myvector) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "foo:" << foo << std::endl;		//拷贝之后foo里面仍然有内容
  std::cout << "bar:" << bar << std::endl;		//转移之后bar里面没有内容
  return 0;
}
