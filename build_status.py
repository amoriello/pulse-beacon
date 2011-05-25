#! /usr/bin/env python
import time
from xmlrpclib import ServerProxy, Error


PULSE_URL      = "http://localhost:8080/xmlrpc"
PULSE_USER     = "USER"
PULSE_PASSWORD = "PASSWORD"


server = ServerProxy(PULSE_URL)

def log_on(server):
	try:
 		token = server.RemoteApi.login(PULSE_USER, PULSE_PASSWORD)
 		return (token)
	except Error, v:
		print "Error:", v


def pool_project(token, project_name):
	completeOnly = True

        next_build_id = server.RemoteApi.getNextBuildNumber(token, project_name)
        curr_build_id = next_build_id - 1

	while True:
		time.sleep(2)
		next_build_id = server.RemoteApi.getNextBuildNumber(token, project_name)

		if (next_build_id != (curr_build_id + 1)):
			curr_build_id = curr_build_id + 1
			build = server.RemoteApi.getBuild(token, project_name, curr_build_id)

			print build[0]['reason']

			while (build[0]['status'] == "in progress"):
				time.sleep(5)
				print "Still building..."
				build = server.RemoteApi.getBuild(token, project_name, curr_build_id)

			print build[0]['status']


def main():
	token = log_on(server)
	pool_project(token, "ltb")


main()
