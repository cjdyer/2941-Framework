# Setup Instructions

Once installing [ProsV5](https://pros.cs.purdue.edu/v5/getting-started/index.html#installing-pros), and cloning the [repository](https://github.com/cjdyer/2941-Framework) using: 

```
git clone https://github.com/cjdyer/2941-Framework.git 
```

Then inside of the project folder use the ProsV5 conductor to add all of the pros required files:

``` 
prosv5 conductor new-project . 
```

Then remove the following files from the project:
- src/
    - main.cpp
- include/
    - okapi/ (the whole folder)
    - main.h
    - api.h
   


Verify that everything is installed and setup correctly by building the project:

```
make
```



