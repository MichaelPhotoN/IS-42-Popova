#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для решения квадратного уравнения и проверки результатов
bool solveQuadraticEquation(double a, double b, double c, double expected_x1, double expected_x2) {
    cout << "Входные данные: a = " << a << ", b = " << b << ", c = " << c << endl;

    if (a == 0) {
        // Обработка линейного уравнения
        if (b != 0) {
            double x = -c / b;
            cout << "Ожидаемый результат: Уравнение имеет один корень: x = " << expected_x1 << endl;
            cout << "Фактический результат: Уравнение имеет один корень: x = " << x << endl;
            return x == expected_x1;
        }
        else if (c == 0) {
            cout << "Ожидаемый результат: Уравнение имеет бесконечно много корней." << endl;
            cout << "Фактический результат: Уравнение имеет бесконечно много корней." << endl;
            return true;
        }
        else {
            cout << "Ожидаемый результат: Уравнение не имеет корней." << endl;
            cout << "Фактический результат: Уравнение не имеет корней." << endl;
            return true;
        }
    }
    else {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Ожидаемый результат: Уравнение имеет два действительных корня: x1 = " << expected_x1 << " и x2 = " << expected_x2 << endl;
            cout << "Фактический результат: Уравнение имеет два действительных корня: x1 = " << x1 << " и x2 = " << x2 << endl;
            return x1 == expected_x1 && x2 == expected_x2;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "Ожидаемый результат: Уравнение имеет один действительный корень: x = " << expected_x1 << endl;
            cout << "Фактический результат: Уравнение имеет один действительный корень: x = " << x << endl;
            return x == expected_x1;
        }
        else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Ожидаемый результат: Уравнение имеет два комплексных корня: ";
            cout << "x1 = " << expected_x1 << " + " << expected_x2 << "i и x2 = " << expected_x1 << " - " << expected_x2 << "i" << endl;
            cout << "Фактический результат: Уравнение имеет два комплексных корня: ";
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i и x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
            return realPart == expected_x1 && imaginaryPart == expected_x2;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Тесты
    bool test1 = solveQuadraticEquation(1, 2, 1, -1, -1);
    bool test2 = solveQuadraticEquation(1, -3, 2, 2, 1);
    bool test3 = solveQuadraticEquation(1, 1, 1, -0.5, sqrt(3) / 2);
    bool test4 = solveQuadraticEquation(0, 3, -6, 2, 0);
    bool test5 = solveQuadraticEquation(0, 0, 5, 0, 0);

    // Проверка результатов тестов и вывод общего результата
    if (test1 && test2 && test3 && test4 && test5) {
        cout << "Все тесты пройдены успешно!" << endl;
    }
    else {
        cout << "Тест(ы) не пройден(ы). Проверьте результаты." << endl;
        if (!test1) {
            cout << "Тест 1 не пройден." << endl;
        }
        if (!test2) {
            cout << "Тест 2 не пройден." << endl;
        }
        if (!test3) {
            cout << "Тест 3 не пройден." << endl;
        }
        if (!test4) {
            cout << "Тест 4 не пройден." << endl;
        }
        if (!test5) {
            cout << "Тест 5 не пройден." << endl;
        }
    }

    return 0;
}
