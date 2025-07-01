#include "..\include\temp_sensor.hpp"

int32_t get_temperature() {
    return 20 + rand() % 15;
}

void temp_sensor() {
    int32_t temp = get_temperature();
    printf("[temp sensor] temperature: %d\n", temp);
}