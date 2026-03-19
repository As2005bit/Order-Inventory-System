# Order & Inventory Management System

A console-based system developed in C++ to manage product inventory and process customer orders.

---

## Features

* Display available products with stock
* Place orders using customer and product IDs
* Validate customer ID, product ID, and stock availability
* Update stock after successful order
* Prevent invalid or inconsistent operations
* Store order records during execution

---

## Implementation

* Products, customers, and orders are stored using vectors
* Order processing follows a validation-first approach
* Stock is updated only after all checks pass
* If validation fails, no changes are applied (rollback-like behavior)

---

## Concepts Used

* Object-Oriented Programming (OOP)
* Service Layer Design
* Data Structures (vector)
* Input validation and edge case handling

---

## How to Run

Compile:
g++ main.cpp -o app

Run:
.\app

---

## Database

A PostgreSQL schema is included in the repository (`/sql` folder) for future integration with persistent storage.

---

## Sample Run

```
Enter choice: 1
Available Products:
ID: 1 | Name: Laptop | Price: 55000 | Stock: 5

Enter choice: 2
Enter Customer ID: 1
Enter Product ID: 3
Enter Quantity: 2
Order placed successfully!
```

---

## Note

The system currently stores data in memory. It can be extended by integrating PostgreSQL for persistent storage.
