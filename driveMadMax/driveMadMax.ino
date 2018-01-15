// Drive MadMax
#include <MadMax.h>

MadMax madmax;

void setup() {
  madmax.breakk();
  delay(2000);
}

int i = 0;
void loop() {
  
  if (i % 2 == 0) {
    madmax.forward();
  }
  else {
    madmax.backward();
  }
  
  delay(1000);
  madmax.breakk();
  delay(1000);

  i++;
  
}
