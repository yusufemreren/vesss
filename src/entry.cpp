#include <windows.h>
#include "..\include\scheduler.hpp"
#include "..\include\pressure_sensor.hpp"
#include "..\include\temp_sensor.hpp"

int main() {
    scheduler scheduler;

    scheduler.add_task(temp_sensor, 1000, 1);
    scheduler.add_task(pressure_sensor, 3000, 2);

    scheduler.run();

    return 1;
}