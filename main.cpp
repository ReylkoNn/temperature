#include <iostream>
#include "data.h"
#include "operations.h"

namespace temp {

    void print_temperatures(const TemperatureData* data) {
        if (!data || data->count <= 0) return;  // Проверка на валидность данных
        for (int i = 0; i < data->count; ++i) {
            std::cout << data->temperatures[i] << " ";  // Вывод каждой температуры
        }
        std::cout << std::endl;
    }

}  // namespace temp

int main() {
    using namespace temp;

    // Создание данных (в Цельсиях)
    TemperatureData* data = createTemperatureData(5, "C");

    // Заполнение значений (по указателю)
    data->temperatures[0] = 10.0f;
    data->temperatures[1] = 25.0f;
    data->temperatures[2] = 15.0f;
    data->temperatures[3] = 30.0f;
    data->temperatures[4] = 22.0f;

    std::cout << "Initial temperatures (C): ";
    print_temperatures(data);


    // Подсчет выше 20°C (используя вспомогательную функцию)
    int above = countInRange(data, above_20);
    std::cout << "Temperatures above 20°C: " << above << std::endl;

    // Лямбда для другого диапазона (ниже 100°F, но пока в C, для демонстрации)
    auto below_100f = [](float t) -> bool { return t < 100.0f; };  // Лямбда-выражение
    int below = countInRange(data, below_100f);
    std::cout << "Temperatures below 100°F (equivalent): " << below << std::endl;

    // Конвертация в Фаренгейты
    convertTemperatures(data, c_to_f);
    std::cout << "After conversion to F: ";
    print_temperatures(data);

    // Агрегаты (макс и среднее)
    float max_temp = aggregate(data, max_op);
    std::cout << "Maximum: " << max_temp << std::endl;

    float sum = aggregate(data, sum_op);
    float avg = sum / data->count;
    std::cout << "Average: " << avg << std::endl;

    // Демонстрация константной ссылки (лямбда с const ref для чтения)
    auto print_data = [](const TemperatureData& d) {  // Передача по константной ссылке
        std::cout << "Unit: " << d.unit << ", Count: " << d.count << std::endl;
        };




    deleteTemperatureData(data);
    return 0;
}