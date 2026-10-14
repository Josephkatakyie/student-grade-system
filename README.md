# Student Grade Management System (C++)

A console application for managing student grades using **parallel arrays**, a core Data Structures concept. Includes a simple AI-style grade classification and performance prediction feature.

## Features
- Add a student (name + grade)
- Display all students with AI-generated grade and prediction
- Search for a student by name
- View class statistics (average, highest, lowest)

## Data Structure Used
**Parallel Arrays** — two arrays linked by the same index:
- `studentNames[]` stores names
- `studentGrades[]` stores grades

Example: `studentNames[0]` and `studentGrades[0]` belong to the same student.

## AI Feature
- **Grade Classification** — maps numeric scores to letter grades (A–F)
- **Performance Prediction** — predicts exam outcome based on current score

## How to Compile and Run
```bash
g++ -o grade_system main.cpp
./grade_system
