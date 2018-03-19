from Adafruit_PWM_Servo_Driver import PWM
import time


pwm = PWM(0x40)
pwm2 = PWM(0x41)

def setServoPulse(channel, pulse):
  pulseLength = 1000000                   # 1,000,000 us per second
  pulseLength /= 60                       # 60 Hz
  print "%d us per period" % pulseLength
  pulseLength /= 4096                     # 12 bits of resolution
  print "%d us per bit" % pulseLength
  pulse *= 1000
  pulse /= pulseLength
  pwm.setPWM(channel, 0, pulse)


def setServoPulse2(channel, pulse):
  pulseLength = 1000000                   # 1,000,000 us per second
  pulseLength /= 60                       # 60 Hz
  print "%d us per period" % pulseLength
  pulseLength /= 4096                     # 12 bits of resolution
  print "%d us per bit" % pulseLength
  pulse *= 1000
  pulse /= pulseLength
  pwm2.setPWM(channel, 0, pulse)


pwm2.setPWMFreq(60)
pwm.setPWMFreq(60)
while(True):
	pwmnumber = input("input your pwmnumber: ")
	channel = input("input your mortor channel: ")
	valuenumber = input("input your valuenumber: ")
	if(pwmnumber == 1):# Change speed of continuous servo on channel O
		print("pwm1 mode...")
		pwm.setPWM(channel, 0, valuenumber)
	else:
		pass
	if(pwmnumber == 2):
		print("pwm2 mode....")
		pwm2.setPWM(channel, 0, valuenumber)
	else:
		pass
	if(pwmnumber == 5):
		print("standmode 1")
		pwm.setPWM(0,0,320)
		pwm.setPWM(1,0,350)
		pwm.setPWM(2,0,350)
		pwm.setPWM(3,0,430)
		pwm.setPWM(4,0,370)
		pwm.setPWM(5,0,370)
		pwm2.setPWM(0,0,360)
		pwm2.setPWM(1,0,370)
		pwm2.setPWM(2,0,354)
		pwm2.setPWM(3,0,435)
		pwm2.setPWM(4,0,392)
		pwm2.setPWM(5,0,402)
		pwm2.setPWM(6,0,290)
		pwm2.setPWM(7,0,280)
		pwm2.setPWM(8,0,300)
		pwm2.setPWM(9,0,450)
		pwm2.setPWM(10,0,490)
		pwm2.setPWM(11,0,480)
	else:
		pass
	if(pwmnumber == 6):
		print("robot stand mode 2")
		pwm.setPWM(0,0,380)
		pwm.setPWM(1,0,350)
		pwm.setPWM(2,0,290)
		pwm.setPWM(3,0,370)
		pwm.setPWM(4,0,370)
		pwm.setPWM(5,0,420)
		pwm2.setPWM(0,0,300)
		pwm2.setPWM(1,0,310)
		pwm2.setPWM(2,0,294)
		pwm2.setPWM(3,0,495)
		pwm2.setPWM(4,0,432)
		pwm2.setPWM(5,0,462)
		pwm2.setPWM(6,0,200)
		pwm2.setPWM(7,0,190)
		pwm2.setPWM(8,0,210)
		pwm2.setPWM(9,0,540)
		pwm2.setPWM(10,0,580)
		pwm2.setPWM(11,0,570)
	else:
		pass
	if(pwmnumber ==-1):
		print("robot sleep..")
		pwm.setPWM(0, 0, 0)
		pwm.setPWM(1, 0, 0)
		pwm.setPWM(2, 0, 0)
		pwm.setPWM(3, 0, 0)
		pwm.setPWM(4, 0, 0)
		pwm.setPWM(5, 0, 0)
		pwm2.setPWM(0, 0, 0)
		pwm2.setPWM(1, 0, 0)
		pwm2.setPWM(2, 0, 0)
		pwm2.setPWM(3, 0, 0)
		pwm2.setPWM(4, 0, 0)
		pwm2.setPWM(5, 0, 0)
		pwm2.setPWM(6, 0, 0)
		pwm2.setPWM(7, 0, 0)
		pwm2.setPWM(8, 0, 0)
		pwm2.setPWM(9, 0, 0)
		pwm2.setPWM(10, 0, 0)
		pwm2.setPWM(11, 0, 0)
		break;
	else:
		pass
