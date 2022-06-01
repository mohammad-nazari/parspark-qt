#include "gtest/gtest.h"

namespace anar::parspark::test {
    // The fixture for testing class Foo.
    class CalculatorTest : public ::testing::Test {
       protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.
        // You can do set-up work for each test here.
        CalculatorTest() = default;
        // You can do clean-up work that doesn't throw exceptions here.
        ~CalculatorTest() override = default;

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:
        // Code here will be called immediately after the constructor (right
        // before each test).
        void SetUp() override {
        }
        // Code here will be called immediately after each test (right
        // before the destructor).
        void TearDown() override {
        }

        // Class members declared here can be used by all tests in the test suite
        // for Foo.
        [[nodiscard]] const int Add(const int &first, const int &second) const {
            return first + second;
        }
        [[nodiscard]] const int Sub(const int &first, const int &second) const {
            return first - second;
        }
        [[nodiscard]] const int Mul(const int &first, const int &second) const {
            return first * second;
        }
        [[nodiscard]] const int Div(const int &first, const int &second) const {
            return first / second;
        }
    };

    TEST_F(CalculatorTest, CalculatorTest_Add_Test) {
        EXPECT_EQ(Add(4, 2), 6);
    }
    TEST_F(CalculatorTest, CalculatorTest_Sub_Test) {
        EXPECT_EQ(Sub(4, 2), 2);
    }
    TEST_F(CalculatorTest, CalculatorTest_Multi_Test) {
        EXPECT_EQ(Mul(4, 2), 8);
    }
    TEST_F(CalculatorTest, CalculatorTest_Divid_Test) {
        EXPECT_EQ(Div(4, 2), 2);
    }
}  // namespace anar::parspark::test

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}