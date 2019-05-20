#include "../../src/ej1/esPrimo.h"
#include "../../lib/gtest/gtest.h"

TEST(EsPrimoTest, NumeroPrimo) {
	ASSERT_EQ(true, esPrimo(7));
	ASSERT_EQ(true, esPrimo(2));
}

TEST(EsPrimoTest, NumeroCompuesto) {
	ASSERT_EQ(false, esPrimo(6));
	ASSERT_EQ(false, esPrimo(10));
}

TEST(EsPrimoTest, CasosBorde) {
	ASSERT_EQ(false, esPrimo(1));
	ASSERT_EQ(false, esPrimo(0));
}
