#include "data.h"
#include <cstring>

namespace temp {

    TemperatureData* createTemperatureData(int count, const char* unit) {
        if (count <= 0) return nullptr;  // Проверка на корректный размер
        TemperatureData* data = new TemperatureData;
        data->temperatures = new float[count];  // Выделение памяти для температур
        data->count = count;
        size_t len = std::strlen(unit);
        data->unit = new char[len + 1];  // Выделение памяти для единицы
        std::strcpy(data->unit, unit);
        // Инициализация нулями
        for (int i = 0; i < count; ++i) {
            data->temperatures[i] = 0.0f;
        }
        return data;
    }

    void deleteTemperatureData(TemperatureData* data) {
        if (!data) return;  // Проверка на nullptr
        delete[] data->temperatures;  // Освобождение массива температур
        delete[] data->unit;  // Освобождение строки единицы
        delete data;  // Освобождение структуры
    }

}  // namespace temp