#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <bits/stdc++.h>
using namespace std;

// Product structure
struct Product {
    int id;
    string name;
    int price;
    int stock;
};

// Customer structure
struct Customer {
    int id;
    string name;
};

struct Order {
    int customerId;
    int productId;
    int quantity;
};

class DBManager {
public:
    vector<Product> products;
    vector<Customer> customers;
    vector<Order> orders;

    DBManager() {
        // sample products
        products.push_back({1, "Laptop", 55000, 5});
        products.push_back({2, "Mouse", 500, 10});
        products.push_back({3, "Keyboard", 800, 7});
        products.push_back({4, "Cable", 250, 20});

        // sample customers
        customers.push_back({1, "Raju"});
        customers.push_back({2, "Sham"});
        customers.push_back({3, "Paul"});
    }
};

#endif