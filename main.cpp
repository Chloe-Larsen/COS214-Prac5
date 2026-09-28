#include "include/Incident.h"
#include "include/ClosedState.h"
#include "include/ReportedState.h"
#include "include/ResolvedState.h"
#include "include/DispatchedState.h"
#include "include/InProgressState.h"

#include "include/Area.h"
#include "include/AreaGroup.h"

#include "include/IncidentCoordinator.h"
#include "include/SecurityTeam.h"
#include "include/MedicalResponder.h"
#include "include/FacilitiesTeam.h"
#include "include/CommunicationService.h"

#include "include/CityBroadcastAdapter.h"

#include "include/OperatorConsole.h"
#include "include/DispatchUnitCommand.h"
#include "include/LockAreaCommand.h"
#include "include/IssueAlertCommand.h"
#include "include/CancelActionCommand.h"

#include "include/EmergencyResponseFacade.h"

bool testing = true;

void printSeparator(const std::string &title = "", bool skip = false)
{
    if (!testing && !skip)
    {
        std::cout << ColourHelper::BOLD << ColourHelper::UNDERLINE << ColourHelper::RED << "\nPress Enter to continue..." << ColourHelper::RESET;
        std::cin.get();
    }

    std::cout << ColourHelper::BOLD << "\n"
              << std::string(60, '=') << ColourHelper::RESET << std::endl;
    if (!title.empty())
    {
        std::cout << ColourHelper::BOLD << ColourHelper::UNDERLINE << ColourHelper::RED << "\t" << title << ColourHelper::RESET << std::endl;
        std::cout << ColourHelper::BOLD << std::string(60, '=') << ColourHelper::RESET << std::endl;
    }
    std::cout << std::endl;
}

class CampusGuardApp
{
private:
    IncidentCoordinator *coordinator;
    CityBroadcastAdapter *cityAdapter;
    OperatorConsole *console;

    SecurityTeam *security;
    MedicalResponder *medical;
    FacilitiesTeam *facilities;
    CommunicationService *comms;

    Incident *incident;
    AreaGroup *campus;

public:
    CampusGuardApp() : coordinator(nullptr), cityAdapter(nullptr), console(nullptr), security(nullptr), medical(nullptr), facilities(nullptr), comms(nullptr), incident(nullptr), campus(nullptr)
    {
    }

    ~CampusGuardApp()
    {
        if (incident)
        {
            delete incident;
            incident = nullptr;
        }

        if (campus)
        {
            delete campus;
            campus = nullptr;
        }

        if (comms)
        {
            delete comms;
            comms = nullptr;
        }

        if (facilities)
        {
            delete facilities;
            facilities = nullptr;
        }

        if (medical)
        {
            delete medical;
            medical = nullptr;
        }

        if (security)
        {
            delete security;
            security = nullptr;
        }

        if (console)
        {
            delete console;
            console = nullptr;
        }

        if (cityAdapter)
        {
            delete cityAdapter;
            cityAdapter = nullptr;
        }

        if (coordinator)
        {
            delete coordinator;
            coordinator = nullptr;
        }
    }

    void setUp()
    {
        printSeparator("CampusGuard Setup", true);
        coordinator = new IncidentCoordinator();
        cityAdapter = new CityBroadcastAdapter();

        security = new SecurityTeam("Security Bros");
        medical = new MedicalResponder("Medical Team");
        facilities = new FacilitiesTeam("Facilities Workers");
        comms = new CommunicationService("Comms", cityAdapter);

        coordinator->registerColleague(security);
        coordinator->registerColleague(medical);
        coordinator->registerColleague(facilities);
        coordinator->registerColleague(comms);

        console = new OperatorConsole();

        printSeparator("Campus composite tree setup");
        campus = new AreaGroup("Main Campus");

        AreaGroup *library = new AreaGroup("Library Building");
        library->add(new Area("Reading Room"));
        library->add(new Area("Archive"));
        library->add(new Area("Server Room"));

        AreaGroup *science = new AreaGroup("Science Block");
        science->add(new Area("Chem Lab 1"));
        science->add(new Area("Chem Lab 2"));

        campus->add(library);
        campus->add(science);
    }

    void scenario1()
    {
        printSeparator("SCENARIO 1: Fire in the Library");
        incident = new Incident("INC-1001", "Library Building", "Smoke detected in Reading Room", 4);
        incident->addObserver(coordinator);
        console->executeCommand(new DispatchUnitCommand(security, incident));
        console->executeCommand(new DispatchUnitCommand(facilities, incident));
        security->reportUnsafeArea(campus);
        EmergencyResponseFacade facade(coordinator, cityAdapter);
        facade.initiateLockdown(incident, campus);
        console->executeCommand(new IssueAlertCommand(comms, "Evacuate Library Building immediately", 5));
        incident->continueProcess();
        incident->continueProcess();
        incident->continueProcess();
        console->undoLast();    
        printSeparator("SCENARIO 1: COMPLETE", true);
    }

    void scenario2()
    {
        printSeparator("SCENARIO 2: Medical Emergency");
        incident = new Incident("INC-2002", "Science Block",
                                "Student collapsed in Chem Lab 1", 3);
        incident->addObserver(coordinator);
        incident->resolve();  
        console->executeCommand(new DispatchUnitCommand(medical, incident));
        Area *chemLab = new Area("Chem Lab 1");
        LockAreaCommand *lockLab = new LockAreaCommand(chemLab);
        console->executeCommand(lockLab);
        incident->continueProcess(); 
        console->executeCommand(new CancelActionCommand(incident));
        delete chemLab;
        chemLab = nullptr;
        printSeparator("SCENARIO 2: COMPLETE", true);
    }

    void run()
    {
        setUp();
        scenario1();
        delete incident;
        incident = nullptr;
        scenario2();
    }
};

int main()
{
    CampusGuardApp *app = new CampusGuardApp();
    app->run();
    delete app;
    return 0;
}