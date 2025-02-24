#include <gtest/gtest.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "../src/main.cpp"

using namespace boost::multiprecision;
using namespace std::chrono;





// Тест Ферма
TEST(FermatTest, PrimeNumbers) {
    EXPECT_TRUE(fermat_test(7, 10));
    EXPECT_TRUE(fermat_test(13, 10));
    EXPECT_TRUE(fermat_test(static_cast<cpp_int>("8683317618811886495518194401279999999"), 1000));
}

TEST(FermatTest, CompositeNumbers) {
    EXPECT_FALSE(fermat_test(9, 10));
    EXPECT_FALSE(fermat_test(15, 10));
    EXPECT_FALSE(fermat_test(static_cast<cpp_int>("8683317618811886495518194401279999999") * 7, 10));
}

// Тест Соловею-Штрассену
TEST(SolovayStrassenTest, PrimeNumbers) {
    EXPECT_TRUE(solovay_shtressen_test(7, 10));
    EXPECT_TRUE(solovay_shtressen_test(13, 10));
    EXPECT_TRUE(solovay_shtressen_test(static_cast<cpp_int>("8683317618811886495518194401279999999"), 10000));
}

TEST(SolovayStrassenTest, CompositeNumbers) {
    EXPECT_FALSE(solovay_shtressen_test(9, 10));
    EXPECT_FALSE(solovay_shtressen_test(15, 10));
    EXPECT_FALSE(solovay_shtressen_test(static_cast<cpp_int>("8683317618811886495518194401279999999") * 7, 10));
}

// Тест Миллера-Рабина
TEST(MillerRabinTest, PrimeNumbers) {
    EXPECT_TRUE(miller_rabin_test(7, 10));
    EXPECT_TRUE(miller_rabin_test(13, 10));
    EXPECT_TRUE(miller_rabin_test(static_cast<cpp_int>("8683317618811886495518194401279999999"), 1000));
}

TEST(MillerRabinTest, CompositeNumbers) {
    EXPECT_FALSE(miller_rabin_test(9, 10));
    EXPECT_FALSE(miller_rabin_test(15, 10));
    EXPECT_FALSE(miller_rabin_test(static_cast<cpp_int>("8683317618811886495518194401279999999") * 7, 10));
}

//AKS тест
TEST(AKS, PrimeNumbers) {
    EXPECT_TRUE(aks_test(7));
    EXPECT_TRUE(aks_test(13));
    EXPECT_TRUE(aks_test(109));
}

TEST(AKS, CompositeNumbers) {
    EXPECT_FALSE(aks_test(9));
    EXPECT_FALSE(aks_test(15));
    EXPECT_FALSE(aks_test(21));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
