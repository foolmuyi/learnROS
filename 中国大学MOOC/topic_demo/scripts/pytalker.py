#!/usr/bin/env python

import rospy
from topic_demo.msg import gps


def talker():
	pub = rospy.Publisher('gps_info',gps,queue_size = 10)
	rospy.init_node('pytalker',anonymous=True)
	rate = rospy.Rate(1)
	x = 2.0
	y = 3.0
	state = 'working'
	while not rospy.is_shutdown():
		rospy.loginfo('Talker:GPS: x = %f,y = %f',x,y)
		pub.publish(gps(x,y,state))
		x = 1.02 * x
		y = 1.02 * y
		rate.sleep()

if __name__ == '__main__':
	talker()