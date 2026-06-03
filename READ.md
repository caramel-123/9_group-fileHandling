# 🚗 Vehicle Service Management System

A structured C program that manages vehicle service records using nested structs, file I/O, and search functionality.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Data Structure](#data-structure)
- [Program Flow](#program-flow)
- [How to Run](#how-to-run)
- [Sample Usage](#sample-usage)
- [File Format](#file-format)

## 🔍 Overview
This program collects service information for 5 vehicles, displays records, filters by service cost, saves data to a file, and allows searching by plate number. Built as a C programming exercise covering structs, arrays, functions, and file handling.

## ✨ Features
- Input details for 5 vehicles using an array of structs
- Display all vehicle records with plate number, owner, and service type
- Filter and display only vehicles with service cost above 500
- Save all records to `service.txt`
- Load records from file and search by plate number

## 🗂️ Data Structure

### ServiceRecord
| Field | Type | Description |
|---|---|---|
| `date` | `char[20]` | Date of service |
| `serviceCost` | `float` | Cost of the service |

### Vehicle (contains nested ServiceRecord)
| Field | Type | Description |
|---|---|---|
| `plateNumber` | `char[20]` | Vehicle plate number |
| `ownerName` | `char[50]` | Name of the owner |
| `serviceType` | `char[50]` | Type of service performed |
| `record` | `ServiceRecord` | Nested service record |

## 🔄 Program Flow

### Easy Task
- Input 5 vehicles via `scanf`
- `displayAllVehicles()` prints plate number, owner name, and service type for each

### Average Task
- `displayExpensiveServices()` filters and prints only vehicles with service cost above 500

### Difficult Task
- `saveToFile()` writes all records to `service.txt` using pipe `|` as delimiter
- `loadAndSearch()` reads from `service.txt` and lets user search by plate number

## ▶️ How to Run

Compile:
```bash
gcc vsms.c -o vsms
```

Run:
```bash
./vsms
```

## 💡 Sample Usage

Input:
```
Enter details for 5 vehicles:

Vehicle 1
Plate Number: 001
Owner Name: Juan dela Cruz
Service Type: Carwash
Service Date: January 5, 2025
Service Cost: 100
```

Display all vehicles:
```
--- Vehicle Records ---

Vehicle 1:
Plate Number: 001
Owner Name: Juan dela Cruz
Service Type: Carwash
```

Display vehicles with cost above 500:
```
--- Vehicles with Service Cost Above 500 ---

Plate Number: 003
Owner Name: Joshua Lopez
Service Type: Repaint
Date: February 25, 2025
Service Cost: 4500.00
```

Search by plate number:
```
Enter Plate Number to search: 003

--- Search Result ---

Plate Number: 003
Owner Name: Joshua Lopez
Service Type: Repaint
Date: February 25, 2025
Service Cost: 4500.00
```

## 📄 File Format

Records in `service.txt` are pipe-separated:
```
001|Juan dela Cruz|Carwash|January 5, 2025|100.00
002|Dave Garcia|Change Oil|January 20, 2025|500.00
003|Joshua Lopez|Repaint|February 25, 2025|4500.00
```

## 🔧 Design Decisions
- **Nested Struct** — `ServiceRecord` is embedded inside `Vehicle` to group related data cleanly
- **Pipe Delimiter** — `|` is used in `service.txt` instead of spaces or commas since dates and names contain spaces
- **Functions Outside main()** — All display and file functions are defined outside `main()` as required
- **Soft Search** — `loadAndSearch()` loads the entire file into memory first before searching

## 👨‍💻 Author
Made for academic purposes as a C programming structs and file handling exercise.
