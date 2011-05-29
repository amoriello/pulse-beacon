import time
from xmlrpclib import ServerProxy, Error

PULSE_URL      = "http://localhost:8080/xmlrpc"
PULSE_USER     = "USER"
PULSE_PASSWORD = "PASSWORD"
SERVER         = ServerProxy(PULSE_URL)

def log_on():
    """
        Log on to Pulse with the credentials provided.
    """
    try:
        token = SERVER.RemoteApi.login(PULSE_USER, PULSE_PASSWORD)
        return token
    except Error, v:
        print "Error:", v

def get_child_projects(token, project_name):
    """
        Get the all the projects that depend on the specified one and returns a list containing their names.

        Note that only a 1st degree search is performed for now.
        Calling the function recursively with its result should allow us to retrieve all the children,
        no matter the degree.

        Keyword Arguments:
        token         -- The token obtained to connect to Pulse.
        project_name  -- The project whose children we are looking for.
    """
    print "[*] Detecting child projects..."
    child_list = []
    for project in SERVER.RemoteApi.getAllProjectNames(token):
        # Is there a configuration specified for the project?
        if len(SERVER.RemoteApi.getConfig(token, "projects/" + project + "/dependencies/dependencies")):
            # Does the project depend from the desired project? (Yeah, accessing that info is a pain.)
            if SERVER.RemoteApi.getConfig(token, "projects/" + project + "/dependencies/dependencies").pop()['project'] == "projects/" + project_name:
                print project + " is a child of " + project_name
                child_list.append(project)

    return child_list


def pool_project(token, project_name):
    """
        Monitor specified project, and print notifications when it starts building
    """
    print "[*] Monitoring " + project_name + "..."
    while True:
        time.sleep(2)
        project_state = SERVER.RemoteApi.getProjectState(token, project_name)
        if project_state == "building":
            build = SERVER.RemoteApi.getLatestBuildForProject(token, project_name, False)
            print build[0]['reason']

            while build[0]['status'] == "pending":
                print "Build is currently pending..."
                time.sleep(5)
                build = SERVER.RemoteApi.getLatestBuildForProject(token, project_name, False)

            while build[0]['status'] == "in progress":
                print "Project is building... (" + str(build[0]['progress']) + "%)"
                time.sleep(5)
                build = SERVER.RemoteApi.getLatestBuildForProject(token, project_name, False)

            print "Build complete ! Status: " + build[0]['status'] + "."


if __name__ == "__main__":
    token = log_on()
    print get_child_projects(token, "Test project")
    pool_project(token, "Test project")

    # Revoke token after use
    SERVER.RemoteApi.logout(token)
