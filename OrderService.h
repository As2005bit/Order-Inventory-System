#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H

#include "ProductService.h"
using namespace std;

class OrderService {
private:
    DBManager &db;
    ProductService &productService;

public:
    OrderService(DBManager &dbRef, ProductService &psRef)
        : db(dbRef), productService(psRef) {}

    void placeOrder() {
    int customerId, productId, quantity;

    cout << "\nEnter Customer ID: ";
    cin >> customerId;
    cout << "Enter Product ID: ";
    cin >> productId;
    cout << "Enter Quantity: ";
    cin >> quantity;

    //(1) Check customer
    bool validCustomer = false;
    for (auto &c : db.customers) {
        if (c.id == customerId) {
            validCustomer = true;
            break;
        }
    }

    if (!validCustomer) {
        cout << "Invalid Customer ID!\n";
        return;
    }

    //(2) Check product + stock
    if (!productService.checkStock(productId, quantity)) {
        cout << "Order failed.\n";
        return;
    }

    //(3) Update stock
    productService.updateStock(productId, quantity);

    //(4) Store order
    db.orders.push_back({customerId, productId, quantity});

    cout << "Order placed successfully!\n";
}
    void showOrders() {
    cout << "\nAll Orders:\n";

    if (db.orders.empty()) {
        cout << "No orders found.\n";
        return;
    }

    for (auto &o : db.orders) {
        cout << "Customer ID: " << o.customerId
             << " | Product ID: " << o.productId
             << " | Quantity: " << o.quantity << endl;
    }
}
};

#endif