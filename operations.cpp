#include "operations.h"

namespace temp {

    void convertTemperatures(TemperatureData* data, float (*converter)(float)) {
        if (!data || data->count <= 0) return;  // Проверка на валидность данных
        for (int i = 0; i < data->count; ++i) {
            data->temperatures[i] = converter(data->temperatures[i]);  // Применение конвертера к каждой температуре
        }
    }

    float c_to_f(float c) {
        return c * 9.0f / 5.0f + 32.0f;  // Формула: F = C * 9/5 + 32
    }

    float c_to_k(float c) {
        return c + 273.15f;  // Формула: K = C + 273.15
}



}