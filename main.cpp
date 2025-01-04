#include <iostream>
#include "headers.h"

using namespace std;

int main() {
    cout << "Welcome to the Coffee Shop Management System!" << endl;
    cout << "Please enter the city where the coffee shop is located: ";
    cout << " 1 - Bucharest  2 - Cluj-Napoca  3 - Timisoara  4 - Iasi  5 - Brasov" << endl;
    int answer;
    string employee_file, stock_file, orders_file, events_file;
    vector<vector<string>> employee_data, stock_data, order_data, event_data;
    cin >> answer;
    if (answer == 1) {
        cout << "You have selected Bucharest." << endl;
         employee_file = "angajatiBucuresti.csv";
            //OBIECTE
            Importer importer(employee_file);
             employee_data = importer.getdata();
         stock_file = "stocBucuresti.csv";
            Importer importer2(stock_file);
             stock_data = importer2.getdata();
         orders_file = "comenziBucuresti.csv";
            Importer importer3(orders_file);
                 order_data = importer3.getdata();
         events_file = "evenimenteBucuresti.csv";
            Importer importer4(events_file);
                 event_data = importer4.getdata();
    } else if (answer == 2) {
        cout << "You have selected Cluj-Napoca." << endl;
         employee_file = "angajatiCluj.csv";
            Importer importer(employee_file);
                 employee_data = importer.getdata();
         stock_file = "stocCluj.csv";
            Importer importer2(stock_file);
                 stock_data = importer2.getdata();
         orders_file = "comenziCluj.csv";
            Importer importer3(orders_file);
                 order_data = importer3.getdata();
         events_file = "evenimenteCluj.csv";
            Importer importer4(events_file);
                 event_data = importer4.getdata();
    } else if (answer == 3) {
        cout << "You have selected Timisoara." << endl;
         employee_file = "angajatiTimisoara.csv";
            Importer importer(employee_file);
                 employee_data = importer.getdata();
         stock_file = "stocTimisoara.csv";
            Importer importer2(stock_file);
                 stock_data = importer2.getdata();
         orders_file = "comenziTimisoara.csv";
            Importer importer3(orders_file);
                 order_data = importer3.getdata();
         events_file = "evenimenteTimisoara.csv";
            Importer importer4(events_file);
                 event_data = importer4.getdata();
    } else if (answer == 4) {
        cout << "You have selected Iasi." << endl;
         employee_file = "angajatiIasi.csv";
            Importer importer(employee_file);
                 employee_data = importer.getdata();
         stock_file = "stocIasi.csv";
            Importer importer2(stock_file);
                 stock_data = importer2.getdata();
         orders_file = "comenziIasi.csv";
            Importer importer3(orders_file);
                 order_data = importer3.getdata();
         events_file = "evenimenteIasi.csv";
            Importer importer4(events_file);
                 event_data = importer4.getdata();
    } else if (answer == 5) {
        cout << "You have selected Brasov." << endl;
         employee_file = "angajatiBrasov.csv";
         stock_file = "stocBrasov.csv";
         orders_file = "comenziBrasov.csv";
         events_file = "evenimenteBrasov.csv";
            Importer importer(employee_file);
                 employee_data = importer.getdata();
            Importer importer2(stock_file);
                 stock_data = importer2.getdata();
            Importer importer3(orders_file);
                 order_data = importer3.getdata();
            Importer importer4(events_file);
                 event_data = importer4.getdata();
    } else {
        cout << "Invalid city selected." << endl;
        return 0;
    }

    cout << "What would you like to do?" << endl;
    cout << " 1 - Add an employee  2 - Remove an employee  3 - Set an employee's shift" << endl;
    cout << " 4 - Add a product to the stock  5 - Remove a product from the stock 6 - Update price 7- Update quantity 8 - View spendings" << endl;
    cout << " 9 - Add an order " << endl;
    cout << " 10 - Add an event" << endl;
    cout << " 11 - Generate a report" << endl;

    cin >> answer;
    if (answer == 1) {
        cout << "You have selected to add an employee." << endl;
        cout << "Please enter the employee's first name: ";
        string first_name;
        cin >> first_name;
        cout << "Please enter the employee's last name: ";
        string last_name;
        cin >> last_name;
        int ok = 0;
        string shift_time_start, shift_time_end;
        while( ok == 0){
        ok = 1;
        cout << "Please enter the employee's shift start time: hh:mm ";
        cin >> shift_time_start;
        if(shift_time_start.size() != 5 || shift_time_start[2] != ':' || shift_time_start[0] < '0' || shift_time_start[0] > '2' || shift_time_start[1] < '0' || shift_time_start[1] > '9' || shift_time_start[3] < '0' || shift_time_start[3] > '5' || shift_time_start[4] < '0' || shift_time_start[4] > '9') {
            cout << "Invalid time format. Please enter the time in the format hh:mm" << endl;
            ok = 0;
        }
        cout << "Please enter the employee's shift end time: hh:mm";
        cin >> shift_time_end;
        if(shift_time_end.size() != 5 || shift_time_end[2] != ':' || shift_time_end[0] < '0' || shift_time_end[0] > '2' || shift_time_end[1] < '0' || shift_time_end[1] > '9' || shift_time_end[3] < '0' || shift_time_end[3] > '5' || shift_time_end[4] < '0' || shift_time_end[4] > '9') {
            cout << "Invalid time format. Please enter the time in the format hh:mm" << endl;
            ok = 0;
        }

        if(shift_time_start >= shift_time_end) {
            cout << "Invalid shift time. The start time must be earlier than the end time." << endl;
            ok = 0;
        }
        }
        cout << "Please enter the employee's function: barista, manager or waiter" << endl;
        string function;
        cin >> function;
        int salary = 0;
        if ( function == "barista" || function == "Barista" || function == "BARISTA") {
            salary = 2800;
            Barista barista(first_name, last_name, function, shift_time_start, shift_time_end, salary, employee_data);
            barista.addToSystem(employee_file, function, employee_data);
        } else if ( function == "manager" || function == "Manager" || function == "MANAGER") {
            salary = 4000;
            Manager manager(first_name, last_name, function, shift_time_start, shift_time_end, salary, employee_data);
            manager.addToSystem(employee_file, function, employee_data);
        } else if ( function == "waiter" || function == "Waiter" || function == "WAITER" || function == "chelner" || function == "Chelner" || function == "CHELNER") {
            salary = 2500;
            Waiter waiter(first_name, last_name, function, shift_time_start, shift_time_end, salary, employee_data);
            waiter.addToSystem(employee_file, function, employee_data);
        } else {
            cout << "Invalid function." << endl;
            return 0;
        }
    } else if (answer == 2) {
        cout << "You have selected to remove an employee." << endl;
        cout << "Please enter the employee's ID: ";
        string id;
        cin >> id;
        Barista employee(id, "", "", "", "", 0, {});
        employee.removeFromSystem(employee_file, id, employee_data);
    } else if (answer == 3) {
        cout << "You have selected to set an employee's shift." << endl;
        cout << "Please enter the employee's ID: ";
        string id;
        cin >> id;
        cout << "Please enter the employee's new shift start time: ";
        string shift_time_start;
        cin >> shift_time_start;
        cout << "Please enter the employee's new shift end time: ";
        string shift_time_end;
        cin >> shift_time_end;
        Barista barista("", "", "", "", "", 0, {});
        barista.setShift(employee_file, id, shift_time_start, shift_time_end, employee_data);
    } else if (answer == 4) {
        cout << "You have selected to add a product to the stock." << endl;
        cout << "Please enter the product's name: ";
        string name;
        cin >> name;
        cout << "Please enter the product's quantity: ";
        int quantity;
        cin >> quantity;
        cout << "Please enter the product's price: ";
        double price;
        cin >> price;
        Stock stock(stock_data, stock_file);
        stock.addToStock(name, quantity, price, stock_data);
    } else if (answer == 5) {
        cout << "You have selected to remove a product from the stock." << endl;
        cout << "Please enter the product's name: ";
        string name;
        cin >> name;
        Stock stock(stock_data, stock_file);
        stock.removeFromStock(name, stock_data);
    } else if (answer == 6) {
        cout << "You have selected to update the price of a product." << endl;
        cout << "Please enter the product's name: ";
        string name;
        cin >> name;
        cout << "Please enter the new price: ";
        double price;
        cin >> price;
        Stock stock(stock_data, stock_file);
        stock.updateStock(name, price, stock_data);
    }else if(answer == 7) {
        cout << "You have selected to update the quantity of a product." << endl;
        cout << "Please enter the product's name: ";
        string name;
        cin >> name;
        cout << "Please enter the new quantity: ";
        int quantity;
        cin >> quantity;
        Stock stock(stock_data, stock_file);
        stock.updateStock(name, quantity, stock_data);
    }else if(answer == 8) {
        cout << "You have selected to view the total spendings." << endl;
        Stock stock(stock_data, stock_file);
        stock.spendings(stock_data);
    }else if (answer == 9) {
        cout << "You have selected to add an order." << endl;
        cout << "Does the client have an id? (yes/no) ";
        string answer2, id;
        double sum = 0;
        cin >> answer2;
        int ok = 0, counter = 0;
        if (answer2 == "yes") {
            while(ok == 0) {
                cout << "Please enter the client's ID: ";
                cin >> id;
                for(auto row : order_data) {
                    if (row[0] == id) {
                        ok = 1;
                    }
                }
                if(ok == 0) {
                    cout << "ID not found. Please enter a different ID." << endl;
                }
            }
        }
        else {
            srand(static_cast<unsigned int>(std::time(0)));
            int idd = 100 + (rand() % 900);
            id = to_string(idd);
        }
        cout << "Please enter the client's name: ";
        string name;
        cin >> name;
        string choice = "yes", product, product_list;
        int found, quantity, stock;
        double price, total;
        while (choice == "yes")
        {
            found = 0;
            while(found == 0) {
                cout << "Please enter the product: ";
                cin >> product;
                for(auto row : stock_data) {
                    if (row[0] == product) {
                        price = stod(row[1]);
                        found = 1;
                        stock = stoi(row[2]);
                    }
                }
                if(found == 0) {
                    cout << "Product not found. Please enter a different product." << endl;
                }else {
                    cout << "Please enter the quantity: ";
                    cin >> quantity;
                    if (quantity > stock) {
                        cout << "Not enough stock. Please enter a smaller quantity. Current stock is: " << stock << endl;
                        found = 0;
                    }
                }

            }
            if (counter == 0) product_list = product + " x" + to_string(quantity);
            else product_list = product_list + " " + product + " x" + to_string(quantity);
            sum = sum + quantity * price;
            cout << "Would you like to add another product to the order? (yes/no) ";
            cin >> choice;
            counter++;
        }
            total = sum;
            Stock update(stock_data, stock_file);
            int n_quantity = stock - quantity;
            update.updateStock(product, n_quantity, price, stock_data);
            addOrder order(order_data, orders_file);
            order.addOrderToSystem(id, name, product_list,total);
        
    } else if (answer == 10) {
        cout << "You have selected to add an event." << endl;
        cout << "Please enter the event's name: ";
        string name;
        cin >> name;
        string date;
        int ok = 0;

        while(ok == 0) {
            ok = 1;
            cout << "Please enter the event's date: dd/mm/yyyy ";
            cin >> date;
            if(date.size() != 10 || date[2] != '/' || date[5] != '/') {
                cout << "Invalid date format. Please enter the date in the format dd/mm/yyyy." << endl;
                ok = 0;
            }

            // Obține data curentă
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int current_day = now->tm_mday;
        int current_month = now->tm_mon + 1; // Lunile sunt de la 0 la 11
        int current_year = now->tm_year + 1900;

            // Extrage ziua, luna și anul din data introdusă
        int day = stoi(date.substr(0, 2));
        int month = stoi(date.substr(3, 2));
        int year = stoi(date.substr(6, 4));

            // Compară data introdusă cu data curentă
        if (year < current_year || 
            (year == current_year && month < current_month) || 
            (year == current_year && month == current_month && day < current_day)) {
            cout << "The date is earlier than today. Are you sure you want to continue? (yes/no)" << endl;
            string answer;
            cin >> answer;
            if (answer == "no") ok = 0;
        }

            for(auto row : event_data) {
                if (row[1] == date) {
                    cout << "An event already exists on this date. Please enter a different date." << endl;
                    ok = 0;
                    break;
                } 
            }
        }

        double sum = 0;
        string choice2 = "yes", product, product_list;
        int found, quantity, stock, counter = 0;;
        double price, total;
        cout << "What products do you need for this event?" << endl;
        while (choice2 == "yes")
        {
            found = 0;
            while(found == 0) {
                cout << "Please enter the product's name: ";
                cin >> product;
                for(auto row : stock_data) {
                    if (row[0] == product) {
                        price = stod(row[1]);
                        found = 1;
                        stock = stoi(row[2]);
                    }
                }
                if(found == 0) {
                    cout << "Product not found. Please enter a different product." << endl;
                }else {
                    cout << "Please enter the quantity: ";
                    cin >> quantity;
                    if (quantity > stock) {
                        cout << "Not enough stock. Please enter a smaller quantity. Current stock is: " << stock << endl;
                        found = 0;
                    }
                }

            }
            if (counter == 0) product_list = product + " x" + to_string(quantity);
            else product_list = product_list + " " + product + " x" + to_string(quantity);
            sum = sum + quantity * price;
            cout << "Would you like to add another product to the order? (yes/no) ";
            cin >> choice2;
            counter++;
        }    
            total = sum;
            Stock update(stock_data, stock_file);
            int n_quantity = stock - quantity;
            update.updateStock(product, n_quantity, price, stock_data);
            Events event(event_data, events_file);
            event.addEventToSystem(name, date, product_list, total);
        
    } else if (answer == 11) {
        cout << "You have selected to generate a daily report." << endl;
        generateReport(orders_file,stock_file,employee_file,events_file);
    } else {
        cout << "Invalid option selected." << endl;
    }

}