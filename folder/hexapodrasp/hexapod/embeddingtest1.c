#include <stdio.h>
#include <python2.7/Python.h>
int main(int argc, char * argv[])
{
  Py_Initialize();
  // evaluate some code
  PyRun_SimpleString("import sys\n");
   PyRun_SimpleString("sys.path.insert(0,\"/home/pi/pytest3/Adafruit-Raspberry-Pi-Python-Code/testdir/mod2\")\n");
  // PyRun_SimpleString("import mod2\n");
  
  PyRun_SimpleString("sys.stdout.write('Hello from an embedded Python Script\\n')\n");
    // shut down the interpreter
  printf("oh oh!!!\n");
    Py_Finalize();
    return 0;
}
