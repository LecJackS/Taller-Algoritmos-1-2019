#include "../../src/ej2/puntaje.h"
#include "../../lib/gtest/gtest.h"

/* Gana puntos según la cantidad de bolitas con las siguientes
reglas:

Si la cantidad de bolitas es menor que 10, gana dos puntos por cada bolita
que sacó.

Si no, un punto por cada una.

Además, si la cantidad de bolitas que sacó es múltiplo de 3, gana 10
puntos. Si no, pierde 10 puntos.

Cuántos puntos ganó Sofı́a?
 *
 * */

// Escribir tests aca:
TEST(PuntajeTest, MenorA10Bolitas) {
    ASSERT_EQ(10, puntaje(0));
    ASSERT_EQ(2-10, puntaje(1));
    ASSERT_EQ(2*3+10, puntaje(3));
    ASSERT_EQ(2*5-10, puntaje(5));
    ASSERT_EQ(2*9+10, puntaje(9));
}

TEST(PuntajeTest, MayorA10Bolitas) {
    ASSERT_EQ(10*1 - 10, puntaje(10));
    ASSERT_EQ(12*1 + 10, puntaje(12));
}
// mas de 15 bolitas no va a sacar con una mano(?