# E-Commerce Order Management System

## Overview

This project is a console-based **E-Commerce Order Management System** developed in C++. It manages products, customers, orders, and payments.

The program demonstrates the use of the following C++ concepts:

- Classes
- Structs
- Unions
- Enums
- Constructors
- Member functions
- Access specifiers
- Basic input validation

## Approach

The system is divided into four main components:

### 1. Product Class

The `Product` class stores:

- Product ID
- Product name
- Price
- Stock
- Product category

It provides functions to:

- Display product details
- Update stock
- Check product availability

### 2. Customer Class

The `Customer` class stores:

- Customer ID
- Name
- Email
- Phone
- Address

It provides functions to:

- Display customer details
- Update customer information

### 3. Order Struct

The `Order` struct stores:

- Order ID
- Customer ID
- Product ID
- Quantity
- Total amount
- Order status
- Payment status
- Payment method

Enums are used for order status, payment status, payment method, and product category.

### 4. Payment Union

A `union PaymentInfo` is used to store payment-specific information.

- Credit Card → Last 4 digits
- UPI → UPI ID
- Cash → No additional information

Only the required payment information is stored at a time.

## Validation

The program handles several invalid situations, including:

1. Invalid product ID
2. Invalid customer ID
3. Product out of stock
4. Invalid quantity
5. Invalid credit card details
6. Invalid UPI ID
7. Invalid payment method
8. Confirming an order when payment has failed
