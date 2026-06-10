#include "AppActions.h"

#include "../ui/Ui.h"

void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}

void appTwo() {
  loading("APP 2", "Running", 800);
  page("APP 2", "Sensor/rele", "placeholder");
}
