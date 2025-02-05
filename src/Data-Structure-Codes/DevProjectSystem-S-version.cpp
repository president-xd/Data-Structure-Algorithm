#include <iostream>
#include<string>
using namespace std;

//creating a class for project
class Project
{
    public:
    int id;
    string name;
    int duration;
    string status;
    Project* next;  //pointer for the node
    Project(int i, string n, int d, string s) : id(i), name(n), duration(d), status(s), next(NULL) {}
   //print function for printing
    void print() {
        cout << "Project ID: " << id << ", Name: " << name << ", Duration: " << duration << " months, Status: " << status << endl;
}
}; //end of the class

//creating class for developer
class Developer
{
    public:
    int id;
    string name;
    string specialization;
    Project* projects;  //pointer for the project
    Developer* next;    //pointer for the developer pointing to next node
    Developer* prev;    //pointer for the developer pointing to the previous node

    Developer(int i, string n, string s) : id(i), name(n), specialization(s), projects(NULL), next(NULL), prev(NULL) {}

// function for adding a new project

    void addProject(int projectId, string projectName, int duration, string status) {
        Project* newProject = new Project(projectId, projectName, duration, status);
        if (!projects) {
            projects = newProject;
            newProject->next = newProject;  // Circular list
        } else {
            newProject->next = projects->next;
            projects->next = newProject;
        }
    }
 
 // function for printing on the screen
 
    void print() {
        cout << "Developer ID: " << id << ", Name: " << name << ", Specialization: " << specialization << endl;
    }
};

//class for DevProject

class DevProj {
private:
    Developer* head;   //Node which will be pointing to head
    Developer* current; //Node whcih will be pointing to current node
    Project* currentProject; //Node which will be pointing to the current project

public:
    DevProj() : head(NULL), current(NULL), currentProject(NULL) {}   //assigning values as null

//function for adding a developer

    void addDeveloper() {
        int id;
        string name, specialization;
        cout << "Enter Developer ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Specialization: ";
        getline(cin, specialization);

        Developer* newDev = new Developer(id, name, specialization);
        if (!head) {
            head = newDev;
            head->next = head;
            head->prev = head;
        } else {
            newDev->next = head;
            newDev->prev = head->prev;
            head->prev->next = newDev;
            head->prev = newDev;
            head = newDev;
        }
        cout << "Developer added successfully." << endl;
    }

//function for adding project

    void addProject() {
        int devId, projectId, duration;
        string projectName, status;
        cout << "Enter Developer ID: ";
        cin >> devId;
        Developer* dev = findDeveloper(devId);
        if (dev) {
            cout << "Enter Project ID: ";
            cin >> projectId;
            cin.ignore();
            cout << "Enter Project Name: ";
            getline(cin, projectName);
            cout << "Enter Duration (months): ";
            cin >> duration;
            cin.ignore();
            cout << "Enter Status: ";
            getline(cin, status);
            dev->addProject(projectId, projectName, duration, status);
            cout << "Project added successfully." << endl;
        } else {
            cout << "Developer not found." << endl;
        }
    }

// function for finding the developer

    Developer* findDeveloper(int id) {
        if (!head) return NULL;
        Developer* temp = head;
        do {
            if (temp->id == id) return temp;
            temp = temp->next;
        } while (temp != head);
        return NULL;
    }

// function for the searching of developer

    void searchDeveloper() {
        int id;
        cout << "Enter Developer ID: ";
        cin >> id;
        Developer* dev = findDeveloper(id);
        if (dev) {
            dev->print();
            current = dev;
            currentProject = dev->projects;
            if (currentProject) {
                currentProject->print();
            } else {
                cout << "No projects for this developer." << endl;
            }
        } else {
            cout << "Developer not found." << endl;
        }
    }

// function for searching the project

    void searchProject() {
        int projectId;
        cout << "Enter Project ID: ";
        cin >> projectId;
        Developer* dev = head;
        if (!dev) {
            cout << "No developers in the system." << endl;
            return;
        }
        do {
            Project* proj = dev->projects;
            if (proj) {
                do {
                    if (proj->id == projectId) {
                        cout << "Project found!" << endl;
                        dev->print();
                        proj->print();
                        return;
                    }
                    proj = proj->next;
                } while (proj != dev->projects);
            }
            dev = dev->next;
        } while (dev != head);
        cout << "Project not found." << endl;
    }

// function for viewing the developer we recently had created

    void viewDevelopers() {
        if (!head) {
            cout << "No developers in the system." << endl;
            return;
        }
        Developer* temp = head;
        do {
            temp->print();
            temp = temp->next;
        } while (temp != head);
    }

// function that will run when we have added more than 1 developer and it will show the next developers those were created

    void showNextDeveloper() {
        if (!current) {
            cout << "No current developer selected. Use 's' to search for a developer first." << endl;
            return;
        }
        current = current->next;
        current->print();
        currentProject = current->projects;
        if (currentProject) {
            currentProject->print();
        } else {
            cout << "No projects for this developer." << endl;
        }
    }

// function that will execute when the user is on the current developer and had the choice of switching next or prev but it switches previus to see the previous developer

    void showPreviousDeveloper() {
        if (!current) {
            cout << "No current developer selected. Use 's' to search for a developer first." << endl;
            return;
        }
        current = current->prev;
        current->print();
        currentProject = current->projects;
        if (currentProject) {
            currentProject->print();
        } else {
            cout << "No projects for this developer." << endl;
        }
    }

// function for viewing the next projects created

    void showNextProject() {
        if (!currentProject) {
            cout << "No current project selected. Search for a developer first." << endl;
            return;
        }
        currentProject = currentProject->next;
        currentProject->print();
    }

// function that displays the same menu

    void run() {
        char choice;
        while (true) {
            cout << "\nPlease choose a command:" << endl;
            cout << "d - Add a developer" << endl;
            cout << "p - Add a project" << endl;
            cout << "s - Search for a developer" << endl;
            cout << "t - Search for a project" << endl;
            cout << "v - View developers" << endl;
            cout << "f - Show next developer" << endl;
            cout << "r - Show previous developer" << endl;
            cout << "n - Show next project" << endl;
            cout << "e - Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

// use of case statement that will ask for the choice here

            switch (choice) {
                case 'd': addDeveloper(); break;
                case 'p': addProject(); break;
                case 's': searchDeveloper(); break;
                case 't': searchProject(); break;
                case 'v': viewDevelopers(); break;
                case 'f': showNextDeveloper(); break;
                case 'r': showPreviousDeveloper(); break;
                case 'n': showNextProject(); break;
                case 'e':
                    cout << "Exiting program." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};


int main() 
{
    DevProj system;   // obj to a class
    system.run();
    return 0;
}
