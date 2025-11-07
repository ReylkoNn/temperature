#pragma once

namespace temp {

    struct TemperatureData {
        float* temperatures;
        int count;
        char* unit;  // "C", "F" или "K"
    };

    TemperatureData* createTemperatureData(int count, const char* unit);  // Создать структуру данных
    void deleteTemperatureData(TemperatureData* data);  // Удалить структуру данных

}  // namespace temp