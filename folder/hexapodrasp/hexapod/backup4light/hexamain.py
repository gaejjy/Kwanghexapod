import time


from Adafruit_PWM_Servo_Driver import PWM

from hexadef import Shoulder,Elbow,Wrist, Arm, Hexapod




pwm1 = PWM(0x40)
pwm1.setPWMFreq(60)

pwm2 = PWM(0x41)
pwm2.setPWMFreq(60)


shoulder_0 = Shoulder(pwm1, 0,450,310)
elbow_0 = Elbow(pwm2, 0,350,250)
wrist_0 = Wrist(pwm2, 6,120,280)
arm_0 = Arm(shoulder_0, elbow_0, wrist_0)

shoulder_1 = Shoulder(pwm1, 1,420,280)
elbow_1 = Elbow(pwm2, 1,360,260)
wrist_1 = Wrist(pwm2, 7,110,270)
arm_1 = Arm(shoulder_1, elbow_1, wrist_1)

shoulder_2 = Shoulder(pwm1, 2,360,220)
elbow_2 = Elbow(pwm2, 2,344,244)
wrist_2 = Wrist(pwm2, 8,130,290)
arm_2 = Arm(shoulder_2, elbow_2, wrist_2)

shoulder_3 = Shoulder(pwm1, 3,300,440)
elbow_3 = Elbow(pwm2, 3,415,515)
wrist_3 = Wrist(pwm2, 9,590,430)
arm_3 = Arm(shoulder_3, elbow_3, wrist_3)

shoulder_4 = Shoulder(pwm1, 4,300,440)
elbow_4 = Elbow(pwm2, 4,402,502)
wrist_4 = Wrist(pwm2, 10,660,500)
arm_4 = Arm(shoulder_4, elbow_4, wrist_4)

shoulder_5 = Shoulder(pwm1, 5,350,490)
elbow_5 = Elbow(pwm2, 5,400,500)
wrist_5 = Wrist(pwm2, 11,650,490)
arm_5 = Arm(shoulder_5, elbow_5, wrist_5)

hexapod = Hexapod(arm_0, arm_1, arm_2, arm_3, arm_4, arm_5)

print("hexapod is start")


while(True):
	commandnum = input("input your command..")
	if(commandnum == 1):
		print("hexapod stand...")
		
	if(commandnum==2):
		print("hexapod wake up...")
		
	if(commandnum==3):
		stand()
		print("hexapod stand up..")	
	if(commandnum == -1):
		pwm1.setPWM(0, 0, 0)
		pwm1.setPWM(1, 0, 0)
		pwm1.setPWM(2, 0, 0)
		pwm1.setPWM(3, 0, 0)
		pwm1.setPWM(4, 0, 0)
		pwm1.setPWM(5, 0, 0)
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
		print("hexapod exit..")
		break
