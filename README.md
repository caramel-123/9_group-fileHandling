```markdown
# 📚 Student Grade File Management System

A menu-driven C program that manages student academic records stored in a persistent text file (`grades.txt`).
---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Data Structure](#data-structure)
- [Menu Options](#menu-options)
- [How to Run](#how-to-run)
- [Sample Usage](#sample-usage)
- [File Format](#file-format)
- [Design Decisions](#design-decisions)

---

## 🔍 Overview

This program allows users to **add, edit, delete, and view** student grade records through an interactive text-based menu. All records are saved to `grades.txt` and persist across program runs.

---

## ✨ Features

- Add new student records with auto-computed average
- Search and edit grades by student number and subject
- Soft-delete records with confirmation prompt
- View all records including deleted ones with a `[Deleted Record]` tag
- Data persists via file I/O using `grades.txt`

---

## 🗂️ Data Structure

Each student record contains the following fields:

| Field | Type | Description |
|---|---|---|
| `studentNumber` | `char[20]` | Unique student identifier |
| `studentName` | `char[50]` | Full name of the student |
| `subject` | `char[50]` | Subject enrolled |
| `midGrade` | `float` | Midterm grade |
| `finalGrade` | `float` | Final grade |
| `average` | `float` | Auto-computed: `(mid + final) / 2` |
| `deleted` | `int` | `0` = active, `1` = deleted |

---

## 🎮 Menu Options

```
[A]dd
[E]dit
[D]elete
[V]iew
E[X]it
Please select:
```

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
- Displays the record and prompts:
  ```
  Do you want to delete [yes/no]?
  ```
- Typing `yes` soft-deletes the record
- Prints `Record not found!` if no match

### [V] View
- Displays all records in the file
- Active records are shown normally
- Deleted records are shown with a `[Deleted Record]` tag

### [X] Exit
- Terminates the program

---

## ▶️ How to Run

### Compile
```bash
gcc student_grade.c -o student_grade
```

### Run
```bash
./student_grade
```

> On Windows:
> ```bash
> student_grade.exe
> ```

---

## 💡 Sample Usage

### Adding a Student
```
[A]dd
Please select: A

Add New Student
Student Number: ABC9
Student Name  : Jao
Subject       : Psychology
MidGrade      : 1.0
FinalGrade    : 1.0
Record added successfully.
```

### Editing a Student
```
Please select: E

Search and Edit Student Information:
Student Number: ABC10
Subject       : Prog2

ABC10      Colarina        Prog2        1.75        1.0        1.5

Input new Student information
MidGrade  : 1.0
FinalGrade: 1.0
Record updated successfully.
```

### Deleting a Student
```
Please select: D

Search and Delete Student Information
Student Number: ABC9
Subject       : Psychology

ABC9       Jao             Psychology   1.0         1.0        1.0

Do you want to delete [yes/no]? yes
Record deleted.
```

### Viewing All Records
```
Please select: V

View all records:

ABC10      Colarina        Prog2        1.00        1.00        1.00
ABC12      Brences         Prog2        2.00        1.00        1.75
ABC9       Jao             Psychology   1.00        1.00        1.00    [Deleted Record]
```

---

## 📄 File Format

Records are stored in `grades.txt` with space-separated values:

```
ABC10 Colarina Prog2 1.00 1.00 1.00 0
ABC12 Brences Prog2 2.00 1.00 1.75 0
ABC9 Jao Psychology 1.00 1.00 1.00 1
```

| Column | Description |
|---|---|
| 1 | Student Number |
| 2 | Student Name |
| 3 | Subject |
| 4 | Mid Grade |
| 5 | Final Grade |
| 6 | Average |
| 7 | Deleted flag (`0` or `1`) |

---

## 🔧 Design Decisions

- **Soft Delete** — Deleted records are flagged (`deleted = 1`) instead of being erased, so they still appear in View with a `[Deleted Record]` label
- **Dual Search Key** — Edit and Delete search by both student number AND subject, since one student can be enrolled in multiple subjects
- **Auto Average** — Average is computed automatically on Add and recalculated on Edit; no manual input needed
- **File Persistence** — `grades.txt` is created automatically on first run if it doesn't exist

---

## 👨‍💻 Author

Made for academic purposes as a C programming file management exercise.
```

Copy-paste mo na yan sa `README.md` file ng repo mo. Lahat ng sections may proper markdown formatting, code blocks, and tables na GitHub-ready.
