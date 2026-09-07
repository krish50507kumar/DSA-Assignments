#include <iostream>
using namespace std;

class Employee {
    int id;
    string name;
    string department;
    double salary;

public:

    Employee() {
        id = 0;
        name = "";
        department = "";
        salary = 0;
    }

    Employee(int i, string n) {
        id = i;
        name = n;
    }

    Employee(int i, string n, string d, double s) {
        id = i;
        name = n;
        department = d;
        salary = s;
    }

    Employee(Employee &e) {
        id = e.id;
        name = e.name;
        department = e.department;
        salary = e.salary;
    }

    double calculatePay() {
        return salary;
    }

    double calculatePay(double bonus) {
        return salary + bonus;
    }

    double calculatePay(int hours, double rate) {
        return salary + hours * rate;
    }

    double calculatePay(double bonus, int tax) {
        return salary + bonus - (bonus * tax / 100);
    }

    void updateProfile(string d) {
        department = d;
    }

    void updateProfile(double s) {
        salary = s;
    }

    void updateProfile(string d, double s) {
        department = d;
        salary = s;
    }

    void display() {
        cout << id << " " << name << " " << department << " " << salary << endl;
    }
};

int main() {

    Employee e1;
    Employee e2(101, "Krish");
    Employee e3(102, "Rahul", "IT", 50000);
    Employee e4(e3);

    e1.display();
    e2.display();
    e3.display();
    e4.display();

    cout << e3.calculatePay() << endl;
    cout << e3.calculatePay(5000.0) << endl;
    cout << e3.calculatePay(10, 500.0) << endl;
    cout << e3.calculatePay(5000.0, 10) << endl;

    e3.updateProfile("AI");
    e3.updateProfile(60000.0);
    e3.updateProfile("CSE", 70000.0);

    e3.display();

    return 0;
}
