#include <stdio.h>
#include <python2.7/Python.h>
int main(int argc, char * argv[])

{

   Py_Initialize();
  // evaluate some code
  PyRun_SimpleString("import sys\n");
PyRun_SimpleString("sys.path.insert(0,\"/home/pi/hexapod\")\n");
PyRun_SimpleString("from Adafruit_PWM_Servo_Driver import PWM\n");
 printf("oh oh!!!\n");
    Py_Finalize();
    return 0;
}
