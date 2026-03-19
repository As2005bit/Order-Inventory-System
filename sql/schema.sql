-- Database schema for Order & Inventory System

CREATE TABLE customers (
    cust_id SERIAL PRIMARY KEY,
    cust_name VARCHAR(100) NOT NULL
);

CREATE TABLE products (
    p_id SERIAL PRIMARY KEY,
    p_name VARCHAR(100) NOT NULL,
    price NUMERIC NOT NULL,
    stock_quantity INTEGER DEFAULT 100,
    CHECK (stock_quantity >= 0)
);

CREATE TABLE orders (
    ord_id SERIAL PRIMARY KEY,
    ord_date DATE DEFAULT CURRENT_DATE,
    cust_id INTEGER REFERENCES customers(cust_id)
);

CREATE TABLE order_items (
    item_id SERIAL PRIMARY KEY,
    ord_id INTEGER REFERENCES orders(ord_id),
    p_id INTEGER REFERENCES products(p_id),
    quantity INTEGER NOT NULL
);
