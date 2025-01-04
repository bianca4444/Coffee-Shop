#include "headers.h"

Importer::Importer (const string filename){
    file.open(filename);
        if (!file.is_open()) {
            throw runtime_error("Cannot open file: " + filename);
        }

    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        string obj;
        vector<string> row;
        while(getline(ss, obj,','))
        {
            row.push_back(obj);
        }
        data.push_back(row);

    }
    file.close();
}

Importer& Importer::getInstance(const string& filename) { // SINGLETON
    static Importer instance(filename);
    return instance;
}

vector<vector<string>> Importer::getdata(){ // INCAPSULARE
    return data;
}

Employee::Employee(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data)
        : first_name(first_name), last_name(last_name), function(function), shift_time_start(shift_time_start), shift_time_end(shift_time_end), salary(salary), data(data) {}


void Employee::addToSystem(string filename, string function, vector<vector<string>> data) {
    ofstream file(filename, ios::app);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    int found, id;
    do{
        found = 0;
        srand(static_cast<unsigned int>(std::time(0)));
        id = 100 + (rand() % 900);
        for(auto row : data)
        {
            if(row[0] == to_string(id))
            {
                found = 1;
                break;
            }
        }
    } while(found == 1);
    file << id << "," << first_name << "," << last_name << "," << function  << "," << shift_time_start << "," << shift_time_end << "," << salary << "\n";
    cout << "Employee added to system." << endl;
    file.close();
}

void Employee::removeFromSystem(string filename, string id, vector<vector<string>> data) {

    if(id.size() != 3) {
        cerr << "Invalid ID.";
        return;
    }

    vector<vector<string>>::const_iterator it;
    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it)[0] == id)
        {
            data.erase(data.begin() + std::distance(data.cbegin(), it));
            break;
        }
    }
    ofstream file(filename);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    for(auto row : data)
    {
        file << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "," << row[4] << "," << row[5] << "," << row[6] << "\n";
    }
    file.close();
    cout << "Employee removed from system." << endl;
}

void Employee::setShift(string filename, string id, string shift_time_start, string shift_time_end, vector<vector<string>> data) {

    if(id.size() != 3) {
        cerr << "Invalid ID.";
        return;
    }

    if(shift_time_start.size() != 5 || shift_time_end.size() != 5 || shift_time_start[2] != ':' || shift_time_end[2] != ':' || shift_time_start[0] < '0' || shift_time_start[0] > '2' || shift_time_end[0] < '0' || shift_time_end[0] > '2' || shift_time_start[1] < '0' || shift_time_start[1] > '9' || shift_time_end[1] < '0' || shift_time_end[1] > '9' || shift_time_start[3] < '0' || shift_time_start[3] > '5' || shift_time_end[3] < '0' || shift_time_end[3] > '5' || shift_time_start[4] < '0' || shift_time_start[4] > '9' || shift_time_end[4] < '0' || shift_time_end[4] > '9') {
        cerr << "Invalid time format.";
        return;
    }

    ofstream file(filename);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    int found = 0;
    for(auto row : data)
    {
        if(row[0] == id)
        {
            row[4] = shift_time_start;
            row[5] = shift_time_end;
            found = 1;
        }
        file << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "," << row[4] << "," << row[5] << "\n";
    }

    if(found == 0) {
        cerr << "Employee not found.";
        return;
    }

    cout << "Shift updated." << endl;

    file.close();
}

Barista::Barista(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data)
        : Employee(first_name, last_name, function, shift_time_start, shift_time_end, salary, data) {}

void Barista::print() { 
    cout << "Barista added to system." << endl;
}

Manager::Manager(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data)
        : Employee(first_name, last_name, function, shift_time_start, shift_time_end, salary, data) {}

void Manager::print() {
    cout << "Manager added to system." << endl;
}

Waiter::Waiter(string first_name, string last_name, string function, string shift_time_start, string shift_time_end, int salary, vector<vector<string>> data)
        : Employee(first_name, last_name, function, shift_time_start, shift_time_end, salary, data) {}

void Waiter::print() {
    cout << "Waiter added to system." << endl;
}

Stock::Stock(vector<vector<string>> data, string filename) : data(data), filename(filename) {}

void Stock::addToStock(string item, int quantity, double price, vector<vector<string>> data) {
    ofstream file(filename, ios::app);
    for(auto row : data)
    {
        if(row[0] == item)
        {
            cerr << "Item already in stock. You can update the quantity or price.";
            return;
        }
    }
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    file << item << "," << price << "," << quantity << "\n";
    cout << "Item added to stock." << endl;
    file.close();
}

void Stock::removeFromStock(string item, vector<vector<string>> data) {
    vector<vector<string>>::iterator it;
    int found = 0;
    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it)[0] == item)
        {
            data.erase(it);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cerr << "Product not found.";
        return;
    }
    ofstream file(filename);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    for(auto row : data)
    {
        file << row[0] << "," << row[1] << "," << row[2] << "\n";
    }
    file.close();
    cout << "Item removed from stock." << endl;
}

void Stock::updateStock(string item, int quantity, double price, vector<vector<string>> data) {
    vector<vector<string>>::iterator it;
    int found = 0;
    stringstream oss;
    oss << fixed << setprecision(2) << price;

    // Conversia in string
    string price_str = oss.str();

    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it)[0] == item)
        {
            (*it)[1] = price_str;
            (*it)[2] = to_string(quantity);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cerr << "Item not found.";
        return;
    }
    ofstream file(filename);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    for(auto row : data)
    {
        file << row[0] << "," << row[1] << "," << row[2] << "\n";
    }
    file.close();
}

void Stock::updateStock(string item, double price, vector<vector<string>> data) {
    vector<vector<string>>::iterator it;
    int found = 0;
    stringstream oss;
    oss << fixed << setprecision(2) << price;

    string price_str = oss.str();

    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it)[0] == item)
        {
            (*it)[1] = price_str;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cerr << "Item not found.";
        return;
    }
    ofstream file(filename);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    for(auto row : data)
    {
        file << row[0] << "," << row[1] << "," << row[2] << "\n";
    }
    file.close();
    cout << "Item updated." << endl;
}

void Stock::updateStock(string item, int quantity, vector<vector<string>> data) {
    vector<vector<string>>::iterator it;
    int found = 0;

    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it)[0] == item)
        {
            (*it)[2] = to_string(quantity);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cerr << "Item not found.";
        return;
    }
    ofstream file(filename);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    for(auto row : data)
    {
        file << row[0] << "," << row[1] << "," << row[2] << "\n";
    }
    file.close();
    cout << "Item updated." << endl;
}

double Stock::spendings(vector<vector<string>> data) {
    double total = 0;
    for (auto it = data.begin() + 1; it != data.end(); ++it) {
        auto row = *it;
        total += stod(row[1])*stod(row[2]);
    }
    cout << "Total spendings: " << total << endl;
    return total;
}

addOrder::addOrder(vector<vector<string>> data, string filename) : data(data), filename(filename) {}

void addOrder::addOrderToSystem(string id, string name, string item, double total) {
    ofstream file(filename, ios::app);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    if(checkHistory(id) && total != 0) total = total * 0.9;
    file << id << "," << name << "," << item << "," << total << "\n";

    cout << "Order added to system." << endl;    

    file.close();
}

int addOrder::checkHistory(string id) {
    Importer importer(filename);
    vector<vector<string>> data = importer.getdata();
    int count = 0;
    for(auto row : data)
    {
        if( row[0] == id) count++;
    }
    if(count > 10) return 1;
    return 0;
}

Events::Events(vector<vector<string>> data, string filename) : data(data), filename(filename) {}

void Events::addEventToSystem(string name, string date, string item, double total) {
    ofstream file(filename, ios::app);
    if(!file.is_open())
    {
        cerr << "Error upon openning file.";
        return;
    }
    file << name << "," << date << "," << item << "," << total << "\n";
    cout << "Event added to system." << endl;
    file.close();
}

template <typename NumericType>  // TEMPLATE
NumericType calculateTotal(const string& file, size_t column_index) {
    Importer importer(file);
    vector<vector<string>> data = importer.getdata();
    NumericType total = 0;

    for (auto it = data.begin() + 1; it != data.end(); ++it) {
        auto row = *it;
        if (row.size() <= column_index) {
            throw runtime_error("Incomplete data in file: " + file); 
        }
        try {
            total += static_cast<NumericType>(stod(row[column_index]));
        } catch (const invalid_argument&) {
            throw runtime_error("Invalid data format in file: " + file);
        } catch (const out_of_range&) {
            throw runtime_error("Data out of range in file: " + file);
        }
    }
    return total;
}



void generateReport(string order_file, string stock_file, string employee_file, string event_file) {
    try {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        ostringstream oss;
        oss << now->tm_mday << '-'
            << (now->tm_mon + 1) << '-'
            << (now->tm_year + 1900);
        string date_str = oss.str();
        string filename = "report_" + date_str + ".txt";

        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Error upon opening report file.");
        }

        file << fixed << setprecision(2);

        double order_total = calculateTotal<double>(order_file, 3);
        file << "Total income: " << order_total << "\n";

        double stock_total = calculateTotal<double>(stock_file, 1);
        file << "Total expenses for products: " << stock_total << "\n";

        double employee_total = calculateTotal<double>(employee_file, 6);
        file << "Total salaries for employees: " << employee_total << "\n";

        double event_total = calculateTotal<double>(event_file, 3);
        file << "Total expenses for events: " << event_total << "\n";

        file << "Total profit: " << order_total - stock_total - employee_total - event_total << "\n";

        file.close();
        cout << "Report generated successfully!" << endl;
    } catch (const exception& e) {              //EXCEPTIONS
        cerr << "An error occurred: " << e.what() << endl;
    }
}
