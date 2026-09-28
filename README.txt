CampusGuard
Zander Schoeman (U25097726), Chloe Larsen (U25004141) and Lebogang Nxumalo (U05175552).

CampusGuard coordinates the response to emergencies on a university campus, from the moment an incident is reported until it is closed. 

An incident moves through the statuses Reported, Dispatched, In Progress, Resolved and Closed, and it can be cancelled before it is resolved. Operators act through a console that runs commands to dispatch a response unit, lock an area, issue an alert or cancel an incident. The security team, medical responder, facilities team and communication service coordinate through a central incident coordinator. Alerts that leave the campus go to a legacy city broadcast system through an adapter, and a single lockdown operation performs the full emergency workflow in one call.


Design patterns

The application uses six Gang of Four patterns. Command represents each operator action as an object that the operator console executes and can undo. Mediator lets the four response units communicate through the incident coordinator instead of with each other. Adapter translates the alert interface that CampusGuard uses into the interface of the legacy city broadcast system. Facade provides the lockdown operation, which locks an area, dispatches every response unit, advances the incident and raises an external alert. State models the incident status, with one class for each status. Composite models the campus as a tree of buildings and rooms, so a lock request works the same way at any level.


Running with Docker

The assessed demonstration runs in Docker. From the repository root, in a clean shell, run the following command.

    docker compose up --build

This command builds the image from the Dockerfile, which installs the toolchain and runs make clean followed by make. It then creates the campusguard-demo container and runs ./campusGuard without any manual input. The two scenarios execute to completion, and the container exits when the application returns from main().

To remove the stopped container afterwards, run the following command.

    docker compose down


Building without Docker

The project targets C++11 and builds with make. From the repository root, run the following commands.

    make
    ./campusGuard

To remove the build output, run make clean.


Scenarios

The application runs two scenarios one after the other. In the first, smoke is detected in the library. The operator dispatches the security and facilities teams, security reports the area as unsafe, the coordinator has facilities secure it, and the lockdown operation locks the campus, dispatches all units and sends an external alert through the adapter. The incident then moves through its later statuses, and the last command is undone.

In the second scenario, a student collapses in a chemistry lab. An attempt to resolve the newly reported incident is rejected, which shows the invalid operation case. The medical responder is dispatched, a command locks the lab, and the incident is cancelled through a command.

The variable testing at the top of main.cpp is set to true, which lets the scenarios run without pausing. When it is set to false, the program waits for Enter between sections.


Repository layout

The include directory holds the headers and the src directory holds the implementations. The file main.cpp holds the application driver and the two scenarios. The directory resources/visualParadigm holds the Visual Paradigm projects and the exported UML diagrams, and the docs directory holds the ownership rationale, the collaboration reflection, the contribution statement and the GitHub history. The Makefile, Dockerfile and docker-compose.yml are in the repository root.
