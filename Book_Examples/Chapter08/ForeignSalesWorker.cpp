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
        virtual int GetPay() const = 0;
        virtual void ShowSalaryInfo() const = 0;
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

namespace RISK_LEVEL {
    enum {RISK_A = 30, RISK_B = 20, RISK_C = 10};
}
class ForeignSalesWorker : public SalesWorker {
    private:
        const int riskLevel;
    public:
        ForeignSalesWorker(const char* _name, int _salary, double _bonusRatio, int _riskLevel)
            : SalesWorker(_name, _salary, _bonusRatio), riskLevel(_riskLevel) {}

        int GetRiskPay() const {
            return (int)(SalesWorker::GetPay() * (riskLevel / 100.0));
        }
        int GetPay() const {
            return SalesWorker::GetPay() + GetRiskPay();
        }
        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << SalesWorker::GetPay() << endl;
            cout << "risk pay: " << GetRiskPay() << endl;
            cout << "sum: " << GetPay() << endl << endl;
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
            for (int i = 0; i < employeeNumber; i++)
                employeeList[i] -> ShowSalaryInfo();
        }
        void ShowTotalSalary() const {
            int sum = 0;
            for (int i = 0; i < employeeNumber; i++)
                sum += employeeList[i] -> GetPay();
            cout << "salary sum: " << sum << endl;
        }
        ~EmployeeHandler() {
            for (int i = 0; i < employeeNumber; i++)
                delete employeeList[i];
        }
};

int main(void) {
    EmployeeHandler handler;
    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();
    return 0;
}