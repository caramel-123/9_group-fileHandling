# 📦 Inventory Management System

A file-handling C program that manages product inventory by reading, updating, and saving records to `Inventory.txt`.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Data Structure](#data-structure)
- [Program Flow](#program-flow)
- [How to Run](#how-to-run)
- [Sample Usage](#sample-usage)
- [File Format](#file-format)
- [Design Decisions](#design-decisions)

## 🔍 Overview
This program allows users to input an initial inventory of N products, save them to `Inventory.txt`, and optionally update each product's quantity using Add or Subtract operations. The updated records are saved back to the file and displayed on screen.

## ✨ Features
- Input N number of products with code, name, and quantity
- Save initial inventory to `Inventory.txt`
- Validate product codes before updating
- Add or subtract quantity per product using update codes `A` and `S`
- Loop update process until user chooses to stop
- Save updated inventory back to file and display on screen

## 🗂️ Data Structure

| Field | Type | Description |
|---|---|---|
| `code` | `char[10]` | Unique product code |
| `name` | `char[50]` | Name of the product |
| `quantity` | `int` | Current stock quantity |

## 🔄 Program Flow

### Step 1 — Input Products
- User enters how many products to add
- For each product: input code, name, and quantity
- All records are saved to `Inventory.txt`

### Step 2 — Update Prompt
- Program asks `Do you want to update the inventory? [Y/N]`
- If `N`: displays the initial inventory and terminates
- If `Y`: proceeds to update loop

### Step 3 — Update Loop
- User inputs a product code
- If code is not found: prints `Record not found` and asks again
- If code is found: user inputs update code and quantity
  - `A` — Adds the quantity to current stock
  - `S` — Subtracts the quantity from current stock
- Asks `Update more? [Y/N]` after each update
- Loop continues until user enters `N`

### Step 4 — Save and Display
- Updated records are saved back to `Inventory.txt`
- Updated inventory is displayed on screen with headers

## ▶️ How to Run

Compile:
```bash
gcc inventory.c -o inventory
```

Run:
```bash
./inventory
```

## 💡 Sample Usage

Input products:
```
Please enter how many products: 3

Product Code: PN
Product Name: Pencil
Quantity: 50

Product Code: ER
Product Name: Eraser
Quantity: 30

Product Code: SH
Product Name: Sharpener
Quantity: 20
```

Initial `Inventory.txt`:
```
PN      Pencil          50
ER      Eraser          30
SH      Sharpener       20
```

Update process:
```
Do you want to update the inventory? [Y/N]: Y

Product Code: ER
Update Code: A
Quantity: 30
Update more? [Y/N]: Y

Product Code: PN
Update Code: S
Quantity: 10
Update more? [Y/N]: N
```

Updated inventory displayed:
```
Product Code        Product Name        Quantity
PN                  Pencil              40
ER                  Eraser              60
SH                  Sharpener           20
```

## 📄 File Format

Records in `Inventory.txt` are tab-separated:
```
PN      Pencil      50
ER      Eraser      30
SH      Sharpener   20
```

| Column | Description |
|---|---|
| 1 | Product Code |
| 2 | Product Name |
| 3 | Quantity |

## 🔧 Design Decisions
- **Validation Loop** — If product code is not found, program keeps asking until a valid code is entered instead of skipping
- **File Persistence** — `Inventory.txt` is overwritten on both initial save and after updates to always reflect the latest state
- **In-memory Updates** — All changes are made to the array in memory first, then written to file in one go at the end
- **Flexible N** — Program supports any number of products up to 100

## 👨‍💻 Author
Made for academic purposes as a C programming file handling exercise.
