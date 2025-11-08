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








    deleteTemperatureData(data);
    return 0;
}