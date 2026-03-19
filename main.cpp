#include "OrderService.h"
using namespace std;

int main() {
    DBManager db;
    ProductService ps(db);
    OrderService os(db, ps);

    int choice;

    while (true) {
        cout << "\n===== Order & Inventory Menu =====\n";
        cout << "1. Show Products\n";
        cout << "2. Place Order\n";
        cout << "3. View Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (!cin) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            ps.showProducts();
        }
        else if (choice == 2) {
            os.placeOrder();
        }
        else if (choice == 3) {
             os.showOrders();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
             break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}