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

    int countInRange(const TemperatureData* data, bool (*inRange)(float)) {
        if (!data  data->count <= 0) return 0;  // Проверка на валидность данных
        int cnt = 0;
        for (int i = 0; i < data->count; ++i) {
            if (inRange(data->temperatures[i])) ++cnt;  // Счётчик для значений, удовлетворяющих условию
        }
        return cnt;
    }

    bool above_20(float t) {
        return t > 20.0f;  // Проверка на значение выше 20°C
    }

    float aggregate(const TemperatureData* data, float (*operation)(float, float)) {
        if (!data  data->count <= 0) return 0.0f;  // Проверка на валидность данных
        float result = data->temperatures[0];  // Начальное значение
        for (int i = 1; i < data->count; ++i) {
            result = operation(result, data->temperatures[i]);  // Применение операции к аккумулятору
        }
        return result;
    }

    float min_op(float a, float b) {
        return (a < b) ? a : b;  // Выбор меньшего значения
    }

    float max_op(float a, float b) {
        return (a > b) ? a : b;  // Выбор большего значения
    }

    float sum_op(float a, float b) {
        return a + b;  // Сложение двух значений
    }

}