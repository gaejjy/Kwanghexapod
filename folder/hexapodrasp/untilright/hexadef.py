import time


class Joint(object):
    pwm = None
    connector = None
    min_rotation = 0
    max_rotation = 100

    def __init__(self, pwm, connector, min=None, max=None):
        self.pwm = pwm
        self.connector = connector

        if min is not None:
            self.min_rotation = min

        if max is not None:
            self.max_rotation = max

    def move_min(self):
        self.pwm.setPWM(self.connector, 0, self.min_rotation)

    def move_mid(self):
        if self.min_rotation > self.max_rotation:
            mid_rotation = ((self.min_rotation - self.max_rotation) / 2) + self.max_rotation
        else:
            mid_rotation = ((self.max_rotation - self.min_rotation) / 2) + self.min_rotation
        self.pwm.setPWM(self.connector, 0, mid_rotation)

    def move_max(self):
        self.pwm.setPWM(self.connector, 0, self.max_rotation)

    def middle(self):
        raise NotImplementedError
	def up(self):
		raise NotImplementedError
	def down(self):
		raise NotImplementedError

class Shoulder(Joint):
    
	min_rotation = 250
	max_rotation = 400
	def middle(self):
		self.move_mid()
	def up(self):
		self.move_max()
	def down(self):
		self.move_min()

class Elbow(Joint):
	min_rotation = 250
	max_rotation = 400
	
	def middle(self):
		self.move_min()
	def up(self):
		self.move_max()
	def down(self):
		self.move_mid()

class Wrist(Joint):
    

	min_rotation = 250
	max_rotation = 400
	def middle(self):
		self.move_min()
	def up(self):
		self.move_max()
	def down(self):
		self.move_mid()

class Arm(object):
    shoulder = None
    elbow = None
    wrist = None

    def __init__(self, shoulder, elbow, wrist):
        self.shoulder = shoulder
        self.elbow = elbow
        self.wrist = wrist
	def stand(self):
		self.shoulder.middle()
		self.elbow.down()
		self.wrist.down()
	def Up_Go(self):
		self.shoulder.up()
		self.elbow.up()
		wrist.up()

class Hexapod(object):
    arm_1 = None
    arm_2 = None
    arm_3 = None
    arm_4 = None
    arm_5 = None
    arm_6 = None

    sleep_time = 2

    def __init__(self, arm_1, arm_2, arm_3, arm_4, arm_5, arm_6, sleep_time=None):
        """
        Hexapod skeleton
        @type arm_1: Arm
        @type arm_2: Arm
        @type arm_3: Arm
        @type arm_4: Arm
        @type arm_5: Arm
        @type arm_6: Arm
        """
        self.arm_1 = arm_1
        self.arm_2 = arm_2
        self.arm_3 = arm_3
        self.arm_4 = arm_4
        self.arm_5 = arm_5
        self.arm_6 = arm_6

        if sleep_time is not None:
            self.sleep_time = sleep_time
	def stand(self):
		self.arm_1.stand()
		self.arm_2.stand()
		self.arm_3.stand()
		self.arm_4.stand()
		self.arm_5.stand()
		self.arm_6.stand()
