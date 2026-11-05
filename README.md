# Structural Programming Language (CSE 1134)

This repository contains my C programming lab codes, assignment tasks, and term project for the Structured Programming Language course.

---

## Repository Structure

* **`W3Schools_C_ Tutorial/`**
  * Basic practice problems and lab tasks (Data types, Loops, GCD, LCM, Factorial, Fibonacci, etc.).
  * Assignment problem sets (`01.c` to `25.c` and `Assignment-1-cse-1134-sec.c`).

* **`project/`**
  * Term Project: **Organisation Management System** (`main.c`).

---

## Project: Organisation Management System

A menu-driven console application in C to keep track of organisations and their employees.

### Features
* **Organisation Info:** Store ID, name, location, category (IT, Healthcare, Education, etc.), established year, and contact email.
* **Employee Management:** Add employees to any organisation with details like ID, name, designation, monthly salary, and email.
* **Search Options:** 
  * Search organisations by name, location, or category.
  * Search employees by name or designation across all organisations.
* **Organisation Details & Stats:** View detailed profile of an organisation with its full employee roster, total payroll, average salary, and top earner.
* **Overall Statistics:** View total organisations, total employees, and total payroll expenses across the system.
* **File Storage:** Saves data to `organisations.txt` so records are preserved between runs.

---

### How to Compile and Run

1. Open a terminal and go into the `project` directory:
   ```bash
   cd project
   ```

2. Compile the code using GCC:
   ```bash
   gcc main.c -o main
   ```

3. Run the executable:
   ```bash
   ./main
   ```

---

## Author
* **Name:** Shafikuzzaman ([@rafsansourov26-ux](https://github.com/rafsansourov26-ux))
* **Roll:** 60
* **Reg:** 2025331560
* **Batch:** CSE-19
* **Institute:** Sylhet Engineering College
