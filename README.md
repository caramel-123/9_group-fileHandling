# 📚 Student Grade File Management System

A menu-driven C program that manages student academic records stored in a persistent text file (`grades.txt`).

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Data Structure](#data-structure)
- [Menu Options](#menu-options)
- [How to Run](#how-to-run)
- [Sample Usage](#sample-usage)
- [File Format](#file-format)
- [Design Decisions](#design-decisions)

## 🔍 Overview
This program allows users to **add, edit, delete, and view** student grade records through an interactive text-based menu. All records are saved to `grades.txt` and persist across program runs.

## ✨ Features
- Add new student records with auto-computed average
- Search and edit grades by student number and subject
- Soft-delete records with confirmation prompt
- View all records including deleted ones with a `[Deleted Record]` tag
- Data persists via file I/O using `grades.txt`

## 🗂️ Data Structure

| Field | Type | Description |
|---|---|---|
| `studentNumber` | `char[20]` | Unique student identifier |
| `studentName` | `char[50]` | Full name of the student |
| `subject` | `char[50]` | Subject enrolled |
| `midGrade` | `float` | Midterm grade |
| `finalGrade` | `float` | Final grade |
| `average` | `float` | Auto-computed: `(mid + final) / 2` |
| `deleted` | `int` | `0` = active, `1` = deleted |

## 🎮 Menu Options

### [A] Add
- Enter student number, name, subject, mid grade, and final grade
- Average is **automatically calculated**
- Record is saved immediately to `grades.txt`

### [E] Edit
- Search by **student number + subject**
- Displays current record if found
- Allows updating mid grade and final grade
- Prints `Record not found!` if no match

### [D] Delete
- Search by **student number + subject**
- Displays the record and prompts confirmation
- Typing `yes` soft-deletes the record
- Prints `Record not found!` if no match

### [V] View
- Displays all records in the file
- Active records shown normally
- Deleted records shown with `[Deleted Record]` tag

### [X] Exit
- Terminates the program

## ▶️ How to Run

Compile:
```bash
gcc student_grade.c -o student_grade
```

Run:
```bash
./student_grade
```

## 💡 Sample Usage

Adding a student:
```
Please select: A

Add New Student
Student Number: ABC9
Student Name  : Jao
Subject       : Psychology
MidGrade      : 1.0
FinalGrade    : 1.0
Record added successfully.
```

Viewing all records:
```
Please select: V

View all records:

ABC10      Colarina        Prog2        1.00        1.00        1.00
ABC12      Brences         Prog2        2.00        1.00        1.75
ABC9       Jao             Psychology   1.00        1.00        1.00    [Deleted Record]
```

## 📄 File Format

Records in `grades.txt` are space-separated:
```
ABC10 Colarina Prog2 1.00 1.00 1.00 0
ABC12 Brences Prog2 2.00 1.00 1.75 0
ABC9 Jao Psychology 1.00 1.00 1.00 1
```

## 🔧 Design Decisions
- **Soft Delete** — Deleted records are flagged instead of erased, so they still appear in View with a `[Deleted Record]` label
- **Dual Search Key** — Edit and Delete search by both student number AND subject since one student can have multiple subjects
- **Auto Average** — Computed automatically on Add and recalculated on Edit
- **File Persistence** — `grades.txt` is created automatically on first run

## 👨‍💻 Author
Made for academic purposes as a C programming file management exercise.
