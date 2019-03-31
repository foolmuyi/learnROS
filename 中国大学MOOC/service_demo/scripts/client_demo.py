#!/usr/bin/env python


import rospy
from service_demo.srv import *


def client_srv():
	rospy.init_node('greetings_client')
	rospy.wait_for_service('greetings')
	try:
		greetings_client = rospy.ServiceProxy('greetings',Greeting)
		resp = greetings_client('Neo',26)
		rospy.loginfo('Message from Oracle:%s'%resp.feedback)
	except rospy.ServiceException, e:
		rospy.logwarn('Service call failed:%s'%e)

if __name__ == '__main__':
	client_srv()