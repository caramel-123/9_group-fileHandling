# Inventory Management System in C

A simple console-based Inventory Management System written in C that allows users to create, store, update, and display product inventory records using file handling.

## Features

- Add multiple products
- Store inventory records in a text file (Inventory.txt)
- Search products using Product Code
- Update product quantities
  - Add stock (A)
  - Subtract stock (S)
- Display the current inventory
- Save updated records back to the file
- Input validation for product searching

## Concepts Demonstrated

This project demonstrates the following C programming concepts:

- Structures (struct)
- Arrays of Structures
- Functions
- File Handling
  - fopen()
  - fprintf()
  - fclose()
- String Handling
  - strcmp()
  - strlen()
  - fgets()
- Character Functions
  - toupper()
- Loops and Conditional Statements

## File Structure

text Inventory.txt 

The inventory file stores records in the following format:

text P001       Ballpen              100 P002       Notebook             50 P003       Pencil               75 

## Program Workflow

### 1. Enter Products

The user specifies the number of products and enters:

- Product Code
- Product Name
- Quantity

Example:

text Product Code: P001 Product Name: Ballpen Quantity: 100 

### 2. Save Initial Inventory

The program writes all product records to:

text Inventory.txt 

### 3. Update Inventory

The user may choose to update product quantities.

Example:

text Product Code: P001 Update Code (A = Add / S = Subtract): A Quantity: 25 

Result:

text 100 + 25 = 125 

### 4. Save Updated Inventory

After all updates are completed, the inventory file is rewritten with the latest quantities.

### 5. Display Inventory

The final inventory is displayed on the screen.

Example:

text Product Code    Product Name         Quantity ------------    ------------------   -------- P001            Ballpen              125 P002            Notebook             50 P003            Pencil               75 

## Compilation

Using GCC:

bash gcc inventory.c -o inventory 

## Running the Program

bash ./inventory 

For Windows:

bash inventory.exe 

## Sample Execution

text Please enter how many products: 2  Product Code: P001 Product Name: Ballpen Quantity: 100  Product Code: P002 Product Name: Notebook Quantity: 50  Do you want to update the inventory? [Y/N]: Y  Product Code: P001 Update Code (A = Add / S = Subtract): A Quantity: 20  Update more? [Y/N]: N 

## Author

Mel
