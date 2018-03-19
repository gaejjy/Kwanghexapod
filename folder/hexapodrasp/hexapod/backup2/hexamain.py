import time


from Adafruit_PWM_Servo_Driver import PWM

from hexadef import LeftShoulder, RightShoulder, LeftElbow, RightElbow, LeftWrist, RightWrist, Arm, Hexapod




pwm1 = PWM(0x40)
pwm1.setPWMFreq(60)

pwm2 = PWM(0x41)
pwm2.setPWMFreq(60)


shoulder_1 = LeftShoulder(pwm1, 0)
elbow_1 = LeftElbow(pwm2, 0)
wrist_1 = LeftWrist(pwm2, 6)
arm_1 = Arm(shoulder_1, elbow_1, wrist_1)

shoulder_2 = LeftShoulder(pwm1, 1)
elbow_2 = LeftElbow(pwm2, 1)
wrist_2 = LeftWrist(pwm2, 7)
arm_2 = Arm(shoulder_2, elbow_2, wrist_2)

shoulder_3 = LeftShoulder(pwm1, 2)
elbow_3 = LeftElbow(pwm2, 2)
wrist_3 = LeftWrist(pwm2, 8)
arm_3 = Arm(shoulder_3, elbow_3, wrist_3)

shoulder_4 = RightShoulder(pwm1, 3)
elbow_4 = RightElbow(pwm2, 3)
wrist_4 = RightWrist(pwm2, 9)
arm_4 = Arm(shoulder_4, elbow_4, wrist_4)

shoulder_5 = RightShoulder(pwm1, 4)
elbow_5 = RightElbow(pwm2, 4)
wrist_5 = RightWrist(pwm2, 10)
arm_5 = Arm(shoulder_5, elbow_5, wrist_5)

shoulder_6 = RightShoulder(pwm1, 5)
elbow_6 = RightElbow(pwm2, 5)
wrist_6 = RightWrist(pwm2, 11)
arm_6 = Arm(shoulder_6, elbow_6, wrist_6)

hexapod = Hexapod(arm_1, arm_2, arm_3, arm_4, arm_5, arm_6)

def left_shoulder_min():
    shoulder_1.move_min()
    shoulder_2.move_min()
    shoulder_3.move_min()
    
def left_shoulder_max():
    shoulder_1.move_max()
    shoulder_2.move_max()
    shoulder_3.move_max()

def left_elbow_min():
    elbow_1.move_min()
    elbow_2.move_min()
    elbow_3.move_min()

def left_elbow_max():
    elbow_1.move_max()
    elbow_2.move_max()
    elbow_3.move_max()

def left_wrist_min():
    wrist_1.move_min()
    wrist_2.move_min()
    wrist_3.move_min()

def left_wrist_max():
    wrist_1.move_max()
    wrist_2.move_max()
    wrist_3.move_max()

def right_shoulder_min():
    shoulder_4.move_min()
    shoulder_5.move_min()
    shoulder_6.move_min()
    
def right_shoulder_max():
    shoulder_4.move_max()
    shoulder_5.move_max()
    shoulder_6.move_max()

def right_elbow_min():
    elbow_4.move_min()
    elbow_5.move_min()
    elbow_6.move_min()

def right_elbow_max():
    elbow_4.move_max()
    elbow_5.move_max()
    elbow_6.move_max()

def right_wrist_min():
    wrist_4.move_min()
    wrist_5.move_min()
    wrist_6.move_min()

def right_wrist_max():
    wrist_4.move_max()
    wrist_5.move_max()
    wrist_6.move_max()

def left_forward():
    hexapod.forward('left')

def right_forward():
    hexapod.forward('right')


print("hexapod is start")


while(True):
	commandnum = input("input your command..")
	if(commandnum == 1):
		print("hexapod stand...")
		left_forward()
		right_forward()
	if(commandnum==2):
		print("hexapod wake up...")
		hexapod.wake_up()	
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
