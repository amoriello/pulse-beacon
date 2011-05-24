#! /usr/bin/env python
import time
from xmlrpclib import ServerProxy, Error


PULSE_URL      = "http://localhost:8080/xmlrpc"
PULSE_USER     = "valblade"
PULSE_PASSWORD = "valblade"


server = ServerProxy(PULSE_URL)

def log_on(server):
	try:
 		token = server.RemoteApi.login(PULSE_USER, PULSE_PASSWORD)
 		return (token)
	except Error, v:
		print "Error:", v


def pool_project(token, project_name):
	completeOnly = True
	project = server.RemoteApi.getLatestBuildsForProject(token, project_name, completeOnly, 1)
	curr_project_id =  project[0]['id']

	while True:
		time.sleep(2)
		next_build_id = server.RemoteApi.getNextBuildNumber(token, "ltb")
		
		if (next_build_id != (curr_project_id + 1)):
			curr_project_id = curr_project_id + 1
			build = server.RemoteApi.getBuild(token, project_name, curr_project_id)

			print build[0]['reason']

			while (build[0]['status'] == "in progress"):
				time.sleep(5)
				print "Still building..."
				build = server.RemoteApi.getBuild(token, project_name, curr_project_id)

			print build[0]['status']


def main():
	token = log_on(server)
	pool_project(token, "ltb")


main()