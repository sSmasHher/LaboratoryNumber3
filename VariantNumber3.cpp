/***************************
* Автор: Полудинцев Никита *
* Вариант: 23              *
* Лабораторная номер 3     *
***************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double gasTemperature;
    double secondP;
    double molarMass;
    double adiabaticIndex;
    double coefficientA;
    double gasConstant;
    double betaBase;
    double criticalBeta;
    double firstP;
    double pressureRatio;
    double pressurePower;
    double speedSquared;
    double gasSpeed;

    double firstPValues[6] = {1.4, 1.5, 1.6, 2.4, 2.5, 2.6};

    int count;
    int i;

    gasTemperature = 900.0;
    secondP = 1.0;
    molarMass = 30.0;
    adiabaticIndex = 1.33;
    count = 6;

    coefficientA = adiabaticIndex / (adiabaticIndex - 1.0);
    gasConstant = 8314.0 / molarMass;

    betaBase = 2.0 / (adiabaticIndex + 1.0);
    criticalBeta = pow(betaBase, coefficientA);

    cout << fixed << setprecision(4);
    cout << "отношение давлений beta = "
         << criticalBeta << "\n\n";

    cout << "P1\tBeta\t\tW\n";

    for (i = 0; i < count; ++i) {
        firstP = firstPValues[i];
        pressureRatio = secondP / firstP;

        if (pressureRatio > criticalBeta) {
            pressurePower = pow(pressureRatio, 1.0 / coefficientA);

            speedSquared = 2.0 * coefficientA *
                           gasConstant * gasTemperature;

            speedSquared = speedSquared * (1.0 - pressurePower);
            gasSpeed = sqrt(speedSquared);
        } else {
            speedSquared = 2.0 * coefficientA *
                           gasConstant * gasTemperature;

            gasSpeed = sqrt(speedSquared);
        }

        cout << firstP << "\t\t"
             << pressureRatio << "\t\t"
             << gasSpeed << '\n';
    }
}
