#include <iostream>
#include <limits>
#include "LinkedList.hpp"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    LinkedList list;
    int choice = 0;

    while (true) {
        cout << "\n1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All\n";
        cout << "5. Count Students\n";
        cout << "6. Add a course\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            clearInput();
            cout << "Please type a number.\n";
            continue;
        }

        if (choice == 1) {
            int id; string name; double gpa;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(); // clear leftover newline
            cout << "Enter Name: ";
            getline(cin, name);   // <-- instead of cin >> name
            cout << "Enter GPA: ";
            cin >> gpa;
            Student s(id, name, gpa);
            list.insertEnd(s);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            if (list.deleteById(id)) {
                cout << "Deleted student with ID " << id << "\n";
            } else {
                cout << "Student not found.\n";
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            Node* n = list.searchById(id);
            if (n) {
                cout << "Found: " << n->data.getId() << " "
                     << n->data.getName() << " "
                     << n->data.getGpa();
                cout << "\nCourses: ";
                n->data.printCourses();
                cout << "\n";
            } else {
                cout << "Not found.\n";
            }
        }
        else if (choice == 4) {
            list.displayAll();
        }
        else if (choice == 5) {
            cout << "Total students: " << list.count() << "\n";
        }
        else if (choice == 6) {
            int id; string cname; int loc;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, cname);
            cout << "Enter location: ";
            cin >> loc;
            bool ok = list.addCourseToStudent(id, Course(cname, loc));
            if (!ok) cout << "Student not found for adding course.\n";
        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Done. Bye!\n";
    return 0;
}
