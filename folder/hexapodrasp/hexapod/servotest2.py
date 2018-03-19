from Adafruit_PWM_Servo_Driver import PWM
import time

# ===========================================================================
# Example Code
# ===========================================================================

# Initialise the PWM device using the default address
pwm = PWM(0x40)
#pwm2 = PWM(0x41)
# Note if you'd like more debug output you can instead run:
#pwm = PWM(0x40, debug=True)

servoMin = 150  # Min pulse length out of 4096
servoMax = 600  # Max pulse length out of 4096

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




while(True):
	number = input("input your number: ")
	pwm.setPWMFreq(60)
	#pwm2.setPWMFreq(60)
    # Set frequency to 60 Hz
	if (number == 1):
    # Change speed of continuous servo on channel O
		pwm.setPWM(0, 0, 290)  
		pwm.setPWM(1, 0, 200)
		pwm.setPWM(2, 0, 350)
		pwm.setPWM(3, 0, 512)
		pwm.setPWM(4, 0, 512)
		pwm.setPWM(5, 0, 512)
	if (number ==2):
		pwm.setPWM(0, 0, 0)
		pwm.setPWM(1, 0, 0)
		pwm.setPWM(2, 0, 0)
		pwm.setPWM(3, 0, 0)
		pwm.setPWM(4, 0, 0)
		pwm.setPWM(5, 0, 0)	
		
