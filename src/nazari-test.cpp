#include "nazari-test.hpp"

#include <iostream>

#include "Poco/FileStream.h"

namespace anar {
   void NazariTest::TestPocoReadAndWrite() {
      Poco::FileStream oFileStream;
      oFileStream.open("test.txt", std::ios::out);
      oFileStream.write("Test1\n", 6);
      oFileStream.write("Test2\n", 6);
      oFileStream.write("Test3\n", 6);
      oFileStream.close();
      char str[50];
      Poco::FileStream iFileStream;
      iFileStream.open("test.txt", std::ios::out);
      iFileStream.getline(str, sizeof(str));
      std::cout << str << std::endl;
      iFileStream.getline(str, sizeof(str));
      std::cout << str << std::endl;
      iFileStream.getline(str, sizeof(str));
      std::cout << str << std::endl;
      iFileStream.close();
   }
}  // namespace anar