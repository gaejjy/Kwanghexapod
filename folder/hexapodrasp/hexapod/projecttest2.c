#include <stdio.h>
#include <python2.7/Python.h>
int main(int argc, char * argv[])

{

   Py_Initialize();
  // evaluate some code
  PyRun_SimpleString("import sys\n");
PyRun_SimpleString("sys.path.insert(0,\"/home/pi/hexapod\")\n");
PyRun_SimpleString("import Adafruit_PWM_Servo_Driver\n");
PyRun_SimpleString("from  Adafruit_PWM_Servo_Driver import PWM\n");

PyRun_SimpleString("import time\n");

printf("import work is completed..\n");


PyRun_SimpleString("pwm = PWM(0x40)");


PyRun_SimpleString("servoMin=150\n");
PyRun_SimpleString("servoMax = 600\n");


PyRun_SimpleString("pwm.setPWMFreq(60)\n");
printf("before while...\n");

PyRun_SimpleString("while (True):	\n");
//printf("after while...\n");
PyRun_SimpleString("pwm.setPWM(0,0,servoMin)\n");

PyRun_SimpleString("time.sleep(1)\n");

PyRun_SimpleString("pwm.setPWM(0,0,servoMax)\n");

PyRun_SimpleString("time.sleep(1)\n");





 printf("oh oh!!!\n");








    Py_Finalize();
    return 0;
}
