#include <iostream>
#include <climits>
#include <locale>

// Функция для поиска минимального элемента и его индекса
int findMinElementIndex(int arr[], int n) {
    int minIndex = 0;
    int minElement = arr[minIndex];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для вычисления суммы элементов после минимального элемента
int sumElementsAfterMin(int arr[], int n) {
    int minIndex = findMinElementIndex(arr, n);
    int sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void runTest(int arr[], int n, int expectedSum) {
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом." << std::endl;
    }
    else {

        int actualSum = sumElementsAfterMin(arr, n);
        if (actualSum == expectedSum) {
            std::cout << "Тест пройден." << std::endl;
        }
        else {
            std::cout << "Тест не пройден. Ожидаемая сумма: " << expectedSum
                << ", Фактическая сумма: " << actualSum << std::endl;
        }

    }
}

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    int arr1[] = { 10, 20, 30, 40, 50 };
    int n1 = 5;
    int expectedSum1 = 140;
    runTest(arr1, n1, expectedSum1);

    int arr2[] = { -30, -5, -10, -15, -20, -25 };
    int n2 = 6;
    int expectedSum2 = -75;
    runTest(arr2, n2, expectedSum2);

    int arr3[] = { 0, 0, 0, 0 };
    int n3 = 4;
    int expectedSum3 = 0;
    runTest(arr3, n3, expectedSum3);

    int arr4[] = { };
    int n4 = 0;
    int expectedSum4 = 0;
    runTest(arr4, n4, expectedSum4);

    return 0;
}
