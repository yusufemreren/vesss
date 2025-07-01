#include "..\include\pressure_sensor.hpp"

int32_t get_pressure() {
    return 60 + rand() % 15;
}

void pressure_sensor() {
    int32_t pressure = get_pressure();
    printf("[pressure sensor] pressure: %d\n", pressure);
}