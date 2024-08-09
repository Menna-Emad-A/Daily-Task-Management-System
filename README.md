# Task Management System

## Overview
The Task Management System is a C++ application that utilizes a binary search tree (BST) and a priority queue to manage tasks. Each task has a priority and a description, and the system allows users to add tasks, mark them as completed, display tasks by priority, and search for specific tasks.

## Features
- **Add Tasks**: Allows the addition of tasks with a specified priority and description.
- **Mark Tasks as Done**: Tasks can be marked as completed using their name.
- **Display Tasks by Priority**: Displays all tasks, sorted by their priority, with their completion status.
- **Search for a Task by Name**: Quickly find a task by its name using an efficient search in the BST.

## How to Run
To run the Task Management System, ensure you have a C++ compiler such as `g++` installed. Follow these steps:
1. Compile the source code:
   ```bash
   g++ -o TaskManager ds.cpp
