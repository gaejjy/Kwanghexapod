from Adafruit_PWM_Servo_Driver import PWM
import time

servoMin = 150  # Min pulse length out of 4096
servoMax = 600  # Max pulse length out of 4096

def runServo1(PWM argpwm):
	while (True):
  # Change speed of continuous servo on channel O
  argpwm.setPWM(0, 0, servoMin)
  time.sleep(1)
  argpwm.setPWM(0, 0, servoMax)
  time.sleep(1)

