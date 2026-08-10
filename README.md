# 1337 Pool — C & Shell Exercises

A collection of my solutions and work from the **1337 Piscine**, covering C programming, shell scripting, and other similar projects.

The repository contains exercises from **C00 through C11**, Shell exercises, and projects such as **Rush01** and **BSQ**.

> **Note:** This repository is primarily a record of my work during the 1337 Pool. Some exercises may be incomplete, experimental, or contain files used for testing/debugging.

---

## 📁 Repository Structure

```text
1337-pool-26/
│
├── BSQ/                  # Biggest Square project
│   ├── srcs/
│   ├── ft.h
│   ├── Makefile
│   └── map_gen.sh
│
├── rush01/               # Rush01 — Skyscraper puzzle
│   └── srcs/
│
├── c00/                  # Introduction to C
├── c01/                  # Pointers
├── c02/                  # Strings
├── c03/                  # String manipulation
├── c04/                  # Functions & conversions
├── c05/                  # Recursion & algorithms
├── c06/                  # Command-line arguments
├── c07/                  # Memory allocation
├── c08/                  # Structures & headers
├── c09/                  # Makefiles & libraries
├── c10/                  # Additional C exercises
├── c11/                  # Function pointers
├── c12/                  # Advanced C
├── c13/                  # Advanced C
│
├── Shell00/              # Shell exercises
├── Shell01/              # Shell scripting exercises
│
└── subjects/             # Exercise subject PDFs
```

---

## 🧠 C Exercises

### C00 — Basics

Introduction to C programming and basic output:

* `ft_putchar`
* `ft_print_alphabet`
* `ft_print_reverse_alphabet`
* `ft_print_numbers`
* `ft_is_negative`
* `ft_print_comb`
* `ft_print_comb2`
* `ft_putnbr`

### C01 — Pointers

Introduction to pointers and modifying values through addresses:

* `ft_ft`
* `ft_ultimate_ft`
* `ft_swap`
* `ft_div_mod`
* `ft_ultimate_div_mod`
* `ft_putstr`
* `ft_strlen`
* `ft_rev_int_tab`
* `ft_sort_int_tab`

### C02 — Strings

String manipulation and character classification:

* `ft_strcpy`
* `ft_strncpy`
* `ft_str_is_alpha`
* `ft_str_is_numeric`
* `ft_str_is_lowercase`
* `ft_str_is_uppercase`
* `ft_str_is_printable`
* `ft_strupcase`
* `ft_strlowcase`
* `ft_strcapitalize`
* `ft_strlcpy`
* `ft_putstr_non_printable`
* `ft_print_memory`

### C03 — String Functions

Reimplementation of common string functions:

* `ft_strcmp`
* `ft_strncmp`
* `ft_strcat`
* `ft_strncat`
* `ft_strstr`
* `ft_strlcat`

### C04 — Conversions & Numbers

* `ft_strlen`
* `ft_putstr`
* `ft_putnbr`
* `ft_atoi`
* `ft_putnbr_base`
* `ft_atoi_base`

### C05 — Recursion & Algorithms

* Factorial
* Power
* Fibonacci
* Square root
* Prime checking
* Next prime
* Ten Queens Puzzle

### C06 — Command-Line Arguments

Exercises involving:

* `argc`
* `argv`
* Program name
* Program parameters
* Sorting command-line arguments

### C07 — Dynamic Memory

Exercises involving dynamic allocation and more complex string/array operations:

* `ft_strdup`
* `ft_range`
* `ft_ultimate_range`
* `ft_strjoin`
* Base conversion
* `ft_split`

### C08 — Structures & Headers

Introduction to:

* Header files
* Macros
* Structures
* `typedef`
* `struct`

### C09 — Makefiles & Libraries

Building and organizing a small C library using:

* `Makefile`
* Object files
* Static libraries
* Compilation rules

### C11 — Function Pointers

Exercises involving higher-order behavior through function pointers:

* `ft_foreach`
* `ft_map`
* `ft_any`
* `ft_count_if`
* `ft_is_sort`
* `do_op`
* String sorting

---

## 🐚 Shell Exercises

### Shell00

Introduction to Unix commands, permissions, archives, Git, and files.

Topics include:

* File creation
* Permissions
* `ls`
* `tar`
* SSH keys
* Git commands
* `.gitignore`
* File types
* `find`
* `file`

### Shell01

Shell scripting exercises covering:

* User/group information
* `find`
* File counting
* MAC address retrieval
* Special filenames
* Command execution and filtering

---

## 🏗️ Projects

### Rush01

A **Skyscraper puzzle solver** implemented in C.

The project uses:

* Backtracking
* Constraint checking
* Visibility checks
* Recursive search

Main source files include:

```text
rush01/srcs/
├── main.c
├── ft_backtrack.c
├── ft_checks.c
├── ft_other_funcs.c
└── ft_view_checks.c
```

### BSQ

The **Biggest Square** project.

The goal is to find the largest possible square in a map while respecting obstacles.

The project contains:

```text
BSQ/
├── srcs/
│   ├── bsq.c
│   ├── check_map.c
│   ├── check_map_1.c
│   ├── check_map_2.c
│   ├── find_bsq.c
│   └── print_bsq.c
├── ft.h
├── Makefile
└── map_gen.sh
```

---

## 🛠️ Technologies

* **C**
* **Shell / Bash**
* **Unix/Linux**
* **Git**
* **Make**
* **POSIX system concepts**
* **Algorithms & recursion**
* **Pointers & memory management**

---

## 🎯 Purpose

This repository documents my progress through the 1337 Pool and serves as a reference for the C and Unix concepts learned during the program.

The exercises gradually progress from basic C syntax to:

**C fundamentals → pointers → strings → algorithms → recursion → memory allocation → structures → function pointers → libraries → larger projects**

---

## ⚠️ Disclaimer

This repository is intended for **learning and reference**.

If you are currently doing the 1337/42 Piscine, try solving the exercises yourself before looking at existing solutions. Understanding *why* a solution works is more valuable than simply copying it.

---

## 📚 Subjects

The `subjects/` directory contains the exercise subject PDFs used during the Pool, including the C exercises, Shell exercises, Rush01, and BSQ.

