#include "../../src/ej2/llenarTaxis.h"
#include "../../lib/gtest/gtest.h"

// Escribir tests aca:
// La entrada son 3 n ́umeros:
//     la cantidad de grupos de un chico (n1), de dos (n2) y de tres (n3), respectivamente.
//     La salida es un numero: la m ́ınima cantidad de taxis que necesitan.

int res = -1;
TEST(TaxiTest, mismosDeCada) {
    llenarTaxis1(1,1,1, res);
    ASSERT_EQ(2, res); // < error
    llenarTaxis1(0,0,0, res);
    ASSERT_EQ(0, res);

}
TEST(TaxiTest, n2par) {
    llenarTaxis1(1,2,1, res);
    ASSERT_EQ(2, res); // < error
}
TEST(TaxiTest, n2ImparN1MinusN3Eq1o2) {
    llenarTaxis1(2,1,1, res);
    ASSERT_EQ(3, res);
}

TEST(TaxiTest, n2ImparN1MinusN3NotEq1o2) {
    llenarTaxis1(3,1,0, res);
    ASSERT_EQ(2, res); // < error
}