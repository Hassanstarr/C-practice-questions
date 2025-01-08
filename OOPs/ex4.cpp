/*
Large Project: 
    Inventory Management System for a Store

Description: 
    Manage inventory, process sales, and generate reports.

Key Features:
    Add, update, and remove products.
    Generate invoices for purchases.
    Maintain inventory levels and sales reports.

OOP Concepts Used:
    Encapsulation:
        Private attributes for product details (name, price, quantity).
        Methods to update and retrieve product information.
    Static Members:
        Track the total sales amount across all transactions.
    Inheritance:
        Base class Product with derived classes for Electronics, Groceries, and Clothing.
    Polymorphism:
        Virtual function applyDiscount() to calculate discounts differently for each product type.
    Friend Classes:
        Use a Transaction class as a friend to access Inventory and Customer details.
    Operator Overloading:
        Overload + to add quantities of the same product.
    Dynamic Memory Management:
        Allocate inventory and transaction records dynamically.
    Virtual Base Class:
        Use a virtual base class Entity to avoid ambiguity in multiple inheritance (e.g., Manager inherits from both Person and Employee).
*/