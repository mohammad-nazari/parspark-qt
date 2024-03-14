#ifndef ANAR_PARSPARK_NAZARI_TEST_HPP
#define ANAR_PARSPARK_NAZARI_TEST_HPP

namespace anar::test {
   class NazariTest {
     public:
      static void RunTest();
      static void TestPocoReadAndWrite();
      static void TestPocoMySQL();
      static void TestPocoSHA();
      static void TestODB();
      static void VisitorTest();
   };
}  // namespace anar::test

#endif  // ANAR_PARSPARK_NAZARI_TEST_HPP