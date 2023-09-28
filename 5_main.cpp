#include <iostream>
#include <climits>

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    // Запросить у пользователя размер массива
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом." << std::endl;
        return 1;
    }
    // Выделяем память под динамический массив
    int* arr = new int[n];
    // Заполнить массив элементами
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    // Находим минимальный элемент и его индекс
    int minElement = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }
    // Проверяем, что минимальный элемент был найден
    if (minIndex == -1) {
        std::cout << "Минимальный элемент не найден." << std::endl;
        delete[] arr; // Освобождаем выделенную память
        return 1;
    }
    // Вычисляем сумму элементов после минимального элемента
    int sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += arr[i];
    }
    // Выводим результат
    std::cout << "Сумма элементов после минимального элемента: " << sum << std::endl;

    // Освобождаем выделенную память
    delete[] arr;
    return 0;
}
