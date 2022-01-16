#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    private:
        char name[100];
    public:
        Employee(const char* _name) {
            strcpy(name, _name);
        }
        void ShowYourName() const {
            cout << "name: " << name << endl;
        }
};

class PermanentWorker : public Employee {
    private:
        int salary;
    public:
        PermanentWorker(const char* _name, int _salary)
            : Employee(_name), salary(_salary) {}
        int GetPay() const {
            return salary;
        }
        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class TemporaryWorker : public Employee {
    private:
        int workTime;
        int payPerHour;
    public:
        TemporaryWorker(const char* _name, int _payPerHour)
            : Employee(_name), workTime(0), payPerHour(_payPerHour) {}
        void AddWorkTime(int time) {
            workTime += time;
        }
        int GetPay() const {
            return workTime * payPerHour;
        }
        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker : public PermanentWorker {
    private:
        int salesResult;
        double bonusRatio;
    public:
        SalesWorker(const char* _name, int _salary, double _bonusRatio)
            : PermanentWorker(_name, _salary), salesResult(0), bonusRatio(_bonusRatio) {}
        void AddSalesResult(int value) {
            salesResult += value;
        }
        int GetPay() const {
            return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
        }
        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};



class EmployeeHandler {
    private:
        Employee* employeeList[50];
        int employeeNumber;
    public:
        EmployeeHandler() : employeeNumber(0) {}
        void AddEmployee(Employee* employee) {
            employeeList[employeeNumber++] = employee;
        }
        void ShowAllSalaryInfo() const {
            // for (int i = 0; i < employeeNumber; i++)
            //     employeeList[i] -> ShowSalaryInfo();
        }
        void ShowTotalSalary() const {
            int sum = 0;
            // for (int i = 0; i < employeeNumber; i++)
            //     sum += employeeList[i] -> GetPay();
            cout << "salary sum: " << sum << endl;
        }
        ~EmployeeHandler() {
            for (int i = 0; i < employeeNumber; i++)
                delete employeeList[i];
        }
};

int main(void) {
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    
    TemporaryWorker *alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker *seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    return 0;
}