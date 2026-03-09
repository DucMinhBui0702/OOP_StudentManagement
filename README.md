# OOP_StudentManagement

Assignment Project of Group MAPL

Brief description of the project

## Team Roles

* **Minh**: Repo Manager, Slides, Code Review, MISRA check, Final Intergration
* **Long**: Development of `Student` and `Course` modules
* **Phong**: `Enrollment` logic and Grade management
* **An**: `SystemManager` implementation and `Console UI`

## Project structure

```OOP_StudentManagement
├── include/      # Header files (.h)
├── src/          # Source files (.cpp)
├── data/         # I/O Data files (.txt/.bin)
└── bin/          # Compiled executables
```

## Coding standards

### Naming conventions

* **Classes**: Use `PascalCase`: `Student`, `SystemManager`...
* **Methods/Function**: Use `camelCase`, start with a verb: `calculateGPA`, `displayInfo`...
* **Members Variables**: Use `m_camelCase`: `m_studentID`, `m_courseName`... 
* **Constants**: Use `UPPER_SNAKE_CASE`: `MAX_STUDENT`...
* **File**: Match with class name: `Student.txt`...

### Technic

* Use smart pointers `unique_ptr` `shared_ptr`
* Follow RAII principles

## Github Workflow

1. Switch to your branch
2. Coding
3. `Commit` your work
4. `Push` to your branch
5. Open a `Pull Request`

### Branches

* **Long**: dev-student-course
* **Phong**: dev-enrollment
* **An**: dev-system

### Sync with main

1. Switch to your branch
2. Fetch origin: to update from GitHub Web
3. Branch -> Choose a branch to merge into -> main
4. Push origin