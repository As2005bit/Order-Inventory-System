#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H

#include "DBManager.h"
using namespace std;

class ProductService {
private:
    DBManager &db;

public:
    ProductService(DBManager &dbRef) : db(dbRef) {}

    void showProducts() {
        cout << "\nAvailable Products:\n";
        for (auto &p : db.products) {
            cout << "ID: " << p.id
                 << " | Name: " << p.name
                 << " | Price: " << p.price
                 << " | Stock: " << p.stock << endl;
        }
    }

    bool checkStock(int productId, int quantity) {
    for (auto &p : db.products) {
        if (p.id == productId) {
            if (p.stock >= quantity)
                return true;
            else
                return false;
             }
        }
    cout << "Invalid Product ID!\n";
    return false;
    }

    void updateStock(int productId, int quantity) {
    for (auto &p : db.products) {
        if (p.id == productId) {
            p.stock -= quantity;
            return;
            }
        }
    }
};

#endif