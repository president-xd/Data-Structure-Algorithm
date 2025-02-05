#include <iostream>
#include <string>
using namespace std;

// Class for Project
class Project {
public:
    int id;
    string name;
    int duration;
    string status;
    Project* next;  // Pointer to the next project (circular list)

    Project(int i, string n, int d, string s) : id(i), name(n), duration(d), status(s), next(NULL) {}

    // Function to print project details
    void print() {
        cout << "Project ID: " << id << ", Name: " << name
             << ", Duration: " << duration << " months, Status: " << status << endl;
    }
};

// Class for Developer
class Developer {
public:
    int id;
    string name;
    string specialization;
    Project* projects;  // Pointer to the projects of the developer
    Developer* next;    // Pointer to the next developer (doubly circular list)
    Developer* prev;    // Pointer to the previous developer

    Developer(int i, string n, string s) : id(i), name(n), specialization(s), projects(NULL), next(NULL), prev(NULL) {}

    // Function to add a new project to the developer
    void addProject(int projectId, string projectName, int duration, string status) {
        Project* newProject = new Project(projectId, projectName, duration, status);
        if (!projects) {
            projects = newProject;
            newProject->next = newProject;  // Circular list setup
        } else {
            newProject->next = projects->next;
            projects->next = newProject;
        }
    }

    // Function to print developer details
    void print() {
        cout << "Developer ID: " << id << ", Name: " << name
             << ", Specialization: " << specialization << endl;
    }
};

// Class for managing Developers and their Projects
class DevProj {
private:
    Developer* head;            // Pointer to the head developer
    Developer* current;         // Pointer to the currently selected developer
    Project* currentProject;    // Pointer to the currently selected project

public:
    // Constructor to initialize pointers
    DevProj() : head(NULL), current(NULL), currentProject(NULL) {}

    // Function to add a developer
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

    // Function to add a project to a developer
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

    // Function to find a developer by ID
    Developer* findDeveloper(int id) {
        if (!head) return NULL;
        Developer* temp = head;
        do {
            if (temp->id == id) return temp;
            temp = temp->next;
        } while (temp != head);
        return NULL;
    }

    // Function to search for a developer and print their details
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

    // Function to search for a project by its ID
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

    // Function to view all developers
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

    // Function to show the next developer
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

    // Function to show the previous developer
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

    // Function to show the next project
    void showNextProject() {
        if (!currentProject) {
            cout << "No current project selected. Search for a developer first." << endl;
            return;
        }
        currentProject = currentProject->next;
        currentProject->print();
    }

    // Main menu and program loop
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

int main() {
    DevProj system;
    system.run();
    return 0;
}
