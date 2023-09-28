#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    if (a == 0) {
        // Это не квадратное уравнение, обработаем случай линейного уравнения
        if (b != 0) {
            double x = -c / b;
            cout << "Уравнение имеет один корень: x = " << x << endl;
        }
        else if (c == 0) {
            cout << "Уравнение имеет бесконечно много корней." << endl;
        }
        else {
            cout << "Уравнение не имеет корней." << endl;
        }
    }
    else {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Уравнение имеет два действительных корня: x1 = " << x1 << " и x2 = " << x2 << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "Уравнение имеет один действительный корень: x = " << x << endl;
        }
        else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Уравнение имеет два комплексных корня: ";
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i и x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
    return 0;
}
