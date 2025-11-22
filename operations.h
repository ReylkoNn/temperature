#pragma once

#include "data.h"

namespace temp {

    void convertTemperatures(TemperatureData* data, float (*converter)(float));  // Преобразовать все температуры

    int countInRange(const TemperatureData* data, bool (*inRange)(float));  // Подсчитать значения в диапазоне (твоя)
    float aggregate(const TemperatureData* data, float (*operation)(float, float));  // Вычислить агрегат (твоя)


    // Вспомогательные функции-конвертеры
    float c_to_f(float c);  // Из Цельсия в Фаренгейт
    float c_to_k(float c);  // Из Цельсия в Кельвин

    // Вспомогательная функция для диапазона
    bool above_20(float t);  // Выше 20°C

    // Вспомогательные операции агрегации
    float min_op(float a, float b);  // Минимум
    float max_op(float a, float b);  // Максимум
    float sum_op(float a, float b);  // Сумма

}