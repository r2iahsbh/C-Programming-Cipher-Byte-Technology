#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student(int id, string name, int age) : id(id), name(name), age(age) {}
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(int id, const string &name, int age) {
        students.emplace_back(id, name, age);
        cout << "Student added successfully.\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students in the record.\n";
            return;
        }
        cout << "ID\tName\tAge\n";
        for (const auto &student : students) {
            cout << student.id << "\t" << student.name << "\t" << student.age << endl;
        }
    }

    void updateStudent(int id, const string &name, int age) {
        for (auto &student : students) {
            if (student.id == id) {
                student.name = name;
                student.age = age;
                cout << "Student updated successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

void displayMenu() {
    cout << "\nStudent Management System\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, age;
                string name;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore(); // To ignore the newline left in the buffer
                getline(cin, name);
                cout << "Enter Student Age: ";
                cin >> age;
                sms.addStudent(id, name, age);
                break;
            }
            case 2:
                sms.displayStudents();
                break;
            case 3: {
                int id, age;
                string name;
                cout << "Enter Student ID to update: ";
                cin >> id;
                cout << "Enter new Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new Age: ";
                cin >> age;
                sms.updateStudent(id, name, age);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Student ID to delete: ";
                cin >> id;
                sms.deleteStudent(id);
                break;
            }
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

