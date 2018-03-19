# compile c_to_python.c

default:
		gcc -L/usr/lib/python2.7/config-arm-linux-gnueabihf -L/usr/include/python2.7 -L/usr/include/c++/4.9/tr1 -L/usr/include/arm-linux-gnueabihf/bits -L/usr/include -L/usr/include/python3.4m -L/usr/lib -lpython2.7 -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -o invoke_python projecttest2.c
