#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
class Person {
protected:
    int id;
    string first_name;
    string last_name;
public:
    virtual void input()=0;
    virtual void display()=0;
};
class Customer : public Person {
private:
    int id;
    string first_name;
    string last_name;
    string product;
    int quantity;
    double price;
    string buy_date;
public:
    void input(){
        cout << "Enter Customer ID : ";
        cin >> id;
        cout << "Enter First Name : ";
        cin >> first_name;
        cout << "Enter Last Name : ";
        cin >> last_name;
        cout << "Enter Product : ";
        cin >> product;
        cout << "Enter Quantity : ";
        cin >> quantity;
        cout << "Enter Price : ";
        cin >> price;
        cout << "Enter Buy Date (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, buy_date);
    }
        double calculateTotal(){
        return quantity * price;
    }
        string concatenate(){
        return first_name + " " + last_name;
    }
    void display(){
        cout << left << setw(10) << "ID" << setw(15) << "Full Name" << setw(15) << "Product" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Buy Date" << endl;
        cout << left << setw(10) << id << setw(15) << concatenate() << setw(15) << product << setw(10) << quantity << setw(10) << price << setw(10) << buy_date << endl;
        cout << "\t-------Total Purchase Amount: " << calculateTotal() << endl;
    }
};
class Employee : public Person {
private:
    int id;
    string first_name;
    string last_name;
    string role;
    double salary;
public:
    string concatenate(){
        return first_name + " " + last_name;
    }
    void input(){
        cout << "Enter Employee ID : ";
        cin >> id;
        cout << "Enter First Name : ";
        cin >> first_name;
        cout << "Enter Last Name : ";
        cin >> last_name;
        cout << "Enter Role : ";
        cin >> role;
        cout << "Enter Salary : ";
        cin >> salary;
    }
    void display(){
        cout << left << setw(15) << "ID" << setw(15) << "Full Name" << setw(15) << "Role" << setw(15) << "Salary" << endl;
        cout << left << setw(15) << id << setw(15) << concatenate() << setw(15) << role << setw(15) << salary << endl;
    }
    double calculateTotalSalary(){
        return salary;
    }
};

int main(){ 
    int n;
    Customer c[20];
    Employee e[20];
    int choice;
    do {
        here:
        
            system("cls");
        cout << "\n1. Add Customer\n2. Add Employee\n3. Display Customers\n4. Display Employees\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "Enter the number of customers: ";
                cin >> n;
                for(int i=0; i<n; i++){
                    cout << "Details of Customer " << i+1 << ":" << endl;
                    c[i].input();
                }
                break;
            }
            case 2: {
                cout << "Enter the number of employees: ";
                cin >> n;
                for(int i=0; i<n; i++){
                    cout << "Details of Employee " << i+1 << ":" << endl;
                    e[i].input();
                }
                break;
            }
            case 3: {
                cout << "\nCustomer Details: " << endl;
                for(int i=0; i<n; i++){
                    c[i].display();
                }
                break;
            }
            case 4: {
                cout << "\nEmployee Details: " << endl;
                float total = 0;
                for(int i=0; i< n; i++){
                    e[i].display();
                    total += e[i].calculateTotalSalary();
                }
                cout << "Total of employees salary : " << total ;
                break;
            }
            default:{
                cout << "Exit...";
                exit(0);
            }
        }
        getch();
        goto here;
    }while (choice!= 5);
    return 0;
}