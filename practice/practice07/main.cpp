//Used chatgpt to assist

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual ~Employee() {} 

    virtual double calculateSalary() const = 0; 

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
    double monthlySalary;
public:
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2) << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << (commissionRate * 100) << "%"
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

void processPayroll(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::vector<Employee*> employees;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type, name;
        int id;

        iss >> type >> id;
        if (iss.fail()) continue; 

        iss.ignore(); 
        std::getline(iss, name, ' '); 

        if (type == "Salaried") {
            double salary;
            if (iss >> salary) {
                employees.push_back(new SalariedEmployee(name, id, salary));
            }
        }
        else if (type == "Hourly") {
            double hourlyRate;
            int hoursWorked;
            if (iss >> hourlyRate >> hoursWorked) {
                employees.push_back(new HourlyEmployee(name, id, hourlyRate, hoursWorked));
            }
        }
        else if (type == "Commission") {
            double baseSalary, salesAmount, commissionRate;
            if (iss >> baseSalary >> salesAmount >> commissionRate) {
                employees.push_back(new CommissionEmployee(name, id, baseSalary, salesAmount, commissionRate));
            }
        }
        else {
            std::cerr << "Warning: Invalid employee type in file: " << type << std::endl;
        }
    }

    file.close();

   
    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    
    for (auto emp : employees) {
        delete emp;
    }
}

int main() {
    std::string filename = "employees.txt";
    processPayroll(filename);
    return 0;
}