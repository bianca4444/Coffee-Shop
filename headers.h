#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//CLASE
class Employee {
protected:
    string first_name;
    string last_name;
    string function;
    string shift_time_start;
    string shift_time_end;
    int salary;
    vector<vector<string>> data;
public:
    //Constructor
    Employee(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data);
    void addToSystem(string filename, string function, vector<vector<string>> data);
    void removeFromSystem(string filename, string id, vector<vector<string>> data);
    void setShift(string filename, string id,string shift_time_start, string shift_time_end, vector<vector<string>> data);
    virtual void print() = 0; // ABSTRACTIZARE

    //Destructor
    virtual ~Employee() {}
};

class Barista : public Employee { // MOSTENIRE
public:
    // Constructor
    Barista(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data);
    void print() override;  // ABSRACTIZARE

};

class Manager : public Employee { // MOSTENIRE
public:
    //Constructor
    Manager(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data);
    void print() override;  // ABSRACTIZARE
};

class Waiter : public Employee { // MOSTENIRE
public:
    //Constructor
    Waiter(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary,vector<vector<string>> data);
    void print() override;  // ABSRACTIZARE
};
//Design Pattern: Singleton
class Importer
{
    private:
        string filename;
        vector<vector<string>> data;
        ifstream file;
    
    public:
    //Constructor
        Importer (string filename);

    // Singleton: instanta unica
        static Importer& getInstance(const string& filename);

        vector<vector<string>> getdata();  // INCAPSULARE

        Importer(const Importer&) = delete;
        Importer& operator=(const Importer&) = delete;

    //Destructor
        ~Importer()
        {
            if (file.is_open()) {
            file.close(); 
        }
        }
};

class Stock
{
    private: 
        vector<vector<string>> data;
        string filename;
    public:
    //Constructor
        Stock(vector<vector<string>> data, string filename);
        void addToStock(string item, int quantity, double price, vector<vector<string>> data);
        void removeFromStock(string item, vector<vector<string>> data);
        void updateStock(string item, int quantity, double price, vector<vector<string>> data);
        void updateStock(string item, double price, vector<vector<string>> data); //POLIMORFISM
        void updateStock(string item, int quantity, vector<vector<string>> data);
        double spendings(vector<vector<string>> data);
};

class addOrder {
    private:
        vector<vector<string>> data;
        string filename;
    public:
    //Constructor
        addOrder(vector<vector<string>> data, string filename);
        void addOrderToSystem(string id, string name, string item,double total);
        int checkHistory(string id);
};


class Events {
    private:
        vector<vector<string>> data;
        string filename;
    public:
    //Constructor
        Events(vector<vector<string>> data, string filename);
        void addEventToSystem(string name, string date, string item, double total);
};


void generateReport(string order_file, string stock_file, string employee_file, string event_file);

