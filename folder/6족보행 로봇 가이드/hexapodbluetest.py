from bluetooth import *

import time

from Adafruit_PWM_Servo_Driver import PWM

from hexadef import Shoulder,Elbow,Wrist, Arm, Hexapod,Joint




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
elbow_3 = Elbow(pwm2, 3,420,520)
wrist_3 = Wrist(pwm2, 9,590,430)
arm_3 = Arm(shoulder_3, elbow_3, wrist_3)

shoulder_4 = Shoulder(pwm1, 4,300,440)
elbow_4 = Elbow(pwm2, 4,384,484)
wrist_4 = Wrist(pwm2, 10,660,500)
arm_4 = Arm(shoulder_4, elbow_4, wrist_4)

shoulder_5 = Shoulder(pwm1, 5,350,490)
elbow_5 = Elbow(pwm2, 5,400,500)
wrist_5 = Wrist(pwm2, 11,650,490)
arm_5 = Arm(shoulder_5, elbow_5, wrist_5)

hexapod = Hexapod(arm_0, arm_1, arm_2, arm_3, arm_4, arm_5)

def arm_0_stand():
	shoulder_0.middle()
	elbow_0.down()
	wrist_0.down()
def arm_1_stand():
	shoulder_1.middle()
	elbow_1.down()
	wrist_1.down()
def arm_2_stand():
	shoulder_2.middle()
	elbow_2.down()
	wrist_2.down()
def arm_3_stand():
    shoulder_3.middle()
    elbow_3.down()
    wrist_3.down()
def arm_4_stand():
    shoulder_4.middle()
    elbow_4.down()
    wrist_4.down()
def arm_5_stand():
    shoulder_5.middle()
    elbow_5.down()
    wrist_5.down()

def arm_0_raise():
    elbow_0.up()
    wrist_0.up()
def arm_1_raise():
    elbow_1.up()
    wrist_1.up()
def arm_2_raise():
    elbow_2.up()
    wrist_2.up()
def arm_3_raise():
    elbow_3.up()
    wrist_3.up()
def arm_4_raise():
    elbow_4.up()
    wrist_4.up()
def arm_5_raise():
    elbow_5.up()
    wrist_5.up()

def arm_0_landing():
    elbow_0.down()
    wrist_0.down()
def arm_1_landing():
    elbow_1.down()
    wrist_1.down()
def arm_2_landing():
    elbow_2.down()
    wrist_2.down()
def arm_3_landing():
    elbow_3.down()
    wrist_3.down()
def arm_4_landing():
    elbow_4.down()
    wrist_4.down()
def arm_5_landing():
    elbow_5.down()
    wrist_5.down()

def robot_stand():
	arm_0_stand()
	arm_1_stand()
	arm_2_stand()
	arm_3_stand()
	arm_4_stand()
	arm_5_stand()

def robot_walk_foward():
    arm_1_landing()
    arm_3_landing()
    arm_5_landing()
    time.sleep(0.2)
    arm_0_raise()
    arm_2_raise()
    arm_4_raise()
    time.sleep(0.1)
    shoulder_0.up()
    shoulder_2.up()
    shoulder_4.up()
    arm_1_stand()
    arm_3_stand()
    arm_5_stand()
    time.sleep(0.1)
    arm_0_landing()
    arm_2_landing()
    arm_4_landing()
    time.sleep(0.2)
    arm_1_raise()
    arm_3_raise()
    arm_5_raise()
    time.sleep(0.1)
    arm_0_stand()
    arm_2_stand()
    arm_4_stand()
    shoulder_1.up()
    shoulder_3.up()
    shoulder_5.up()
    time.sleep(0.1)
    arm_1_stand()
    arm_3_stand()
    arm_5_stand()


def robot_walk_backward():
    arm_1_landing()
    arm_3_landing()
    arm_5_landing()

    time.sleep(0.3)

    arm_0_raise()
    arm_2_raise()
    arm_4_raise()

    time.sleep(0.2)

    shoulder_0.down()
    shoulder_2.down()
    shoulder_4.down()

    arm_1_stand()
    arm_3_stand()
    arm_5_stand()

    time.sleep(0.2)
    arm_0_landing()
    arm_2_landing()
    arm_4_landing()

    time.sleep(0.3)

    arm_1_raise()
    arm_3_raise()
    arm_5_raise()

    time.sleep(0.2)

    arm_0_stand()
    arm_2_stand()
    arm_4_stand()

    shoulder_1.down()
    shoulder_3.down()
    shoulder_5.down()

    time.sleep(0.2)

    arm_1_stand()
    arm_3_stand()
    arm_5_stand()
	

def robot_walk_turnL():
    arm_1_landing()
    arm_3_landing()
    arm_5_landing()

    time.sleep(0.2)

    arm_0_raise()
    arm_2_raise()
    arm_4_raise()

    time.sleep(0.1)

    shoulder_0.down()
    shoulder_2.down()
    shoulder_4.up()

    arm_1_stand()
    arm_3_stand()
    arm_5_stand()

    time.sleep(0.1)
    arm_0_landing()
    arm_2_landing()
    arm_4_landing()

    time.sleep(0.2)

    arm_1_raise()
    arm_3_raise()
    arm_5_raise()

    time.sleep(0.1)

    arm_0_stand()
    arm_2_stand()
    arm_4_stand()
    shoulder_1.down()
    shoulder_3.up()
    shoulder_5.up()
    time.sleep(0.1)
    arm_1_landing()
    arm_3_landing()
    arm_5_landing()
    time.sleep(0.2)
    arm_0_raise()
    arm_2_raise()
    arm_4_raise()
    time.sleep(0.1)
    arm_1_stand()
    arm_3_stand()
    arm_5_stand()
    time.sleep(0.1)
    arm_0_stand()
    arm_2_stand()
    arm_4_stand()

def robot_walk_turnR():
    arm_1_landing()
    arm_3_landing()
    arm_5_landing()

    time.sleep(0.2)

    arm_0_raise()
    arm_2_raise()
    arm_4_raise()

    time.sleep(0.1)

    shoulder_0.up()
    shoulder_2.up()
    shoulder_4.down()

    arm_1_stand()
    arm_3_stand()
    arm_5_stand()

    time.sleep(0.1)
    arm_0_landing()
    arm_2_landing()
    arm_4_landing()

    time.sleep(0.2)

    arm_1_raise()
    arm_3_raise()
    arm_5_raise()

    time.sleep(0.1)

    arm_0_stand()
    arm_2_stand()
    arm_4_stand()
    shoulder_1.up()
    shoulder_3.down()
    shoulder_5.down()
    time.sleep(0.1)
    arm_1_landing()
    arm_3_landing()
    arm_5_landing()
    time.sleep(0.2)
    arm_0_raise()
    arm_2_raise()
    arm_4_raise()
    time.sleep(0.1)
    arm_1_stand()
    arm_3_stand()
    arm_5_stand()
    time.sleep(0.1)
    arm_0_stand()
    arm_2_stand()
    arm_4_stand()


print("hexapod is start")

server_sock=BluetoothSocket( RFCOMM )
server_sock.bind(("",PORT_ANY))
server_sock.listen(1)

port = server_sock.getsockname()[1]

uuid = "94f39d29-7d6d-437d-973b-fba39e49d4ee"


                   
print("Waiting for connection on RFCOMM channel %d" % port)

client_sock, client_info = server_sock.accept()
print("Accepted connection from ", client_info)

while(True):
	commandnum = client_sock.recv(1024)
	if(commandnum == "1"):
		robot_stand()
		print("hexapod stand...")
		
	if(commandnum=="2"):
		robot_stand()
		robot_walk_foward()
		print("hexapod walk forward..")
		
	if(commandnum=="3"):
		robot_stand()
		robot_walk_backward()
		print("hexapod backward..")
	if(commandnum=="4"):
		robot_stand()
		robot_walk_turnL()
		print("hexapod turn left...")
	if(commandnum=="5"):
		robot_stand()
		robot_walk_turnR()
		print("hexapod turn right...")	
	if(commandnum == "-1"):
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
        print("disconnected")
        client_sock.close()
        server_sock.close()
        print("hexapod exit..")
        break
