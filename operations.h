#pragma once

#include "data.h"

namespace temp {

    void convertTemperatures(TemperatureData* data, float (*converter)(float));  // Преобразовать все температуры




    // Вспомогательные функции-конвертеры (твои)
    float c_to_f(float c);  // Из Цельсия в Фаренгейт
    float c_to_k(float c);  // Из Цельсия в Кельвин



}