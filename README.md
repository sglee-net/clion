# CLion based development envirionment
 - Structure of common folders of bin, include, lib.
 - Put your CLion project under "prj" folder.
 - Referential header files and libraries should be put under "include" and "lib", respectively.

## Directory structure
```
root
└── README.md
├── bin
├── include
    └── project_name1
    └── project_name2   
├── lib
├── prj
    └── CMakeList.txt
    └── project_name1
    └── project_name2
        └── gtest
            └── lib
            └── CMakeList.txt
```
