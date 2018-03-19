init:
	gpio -g mode 12 out
	gpio -g write 12 0
on:
	gpio -g write 12 1
off:
	gpio -g write 12 0

toggle:
	gpio -g write 12 1
	sleep 1
	gpio -g write 12 0
	sleep 1
	gpio -g write 12 1
	sleep 1
	gpio -g write 12 0
	sleep 1
