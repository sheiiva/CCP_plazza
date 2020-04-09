The Plazza
===

Time:       5 weeks

Team:       3

Language:   C++


The project
----
The purpose of this project is to make you realize a simulation of a pizzeria, which is composed of the **reception** that accepts new commands, of **several kitchens**, themselves with **several cooks**, themselves cooking **several pizzas**.

You will learn to deal with various problems, including **load balancing**, **process** and **thread synchronization and communication**. 

Prerequisites:
* Processes (man fork,man exit,man wait,man ...)
* Inter-process communication (IPC)
* STL threads
* POSIX threads (man pthread_*)


## USAGE:

```
>> make
>> ./plazza time cooks restock
```

#### DESCRIPTION
* time         the cooking time (between [0, 1])
* cooks        the number of cooks per kitchen
* restock      the time in milliseconds, used by the kitchen stock to replace ingredients


## TESTS

```
>> make tests_run
``` 

 > other rules: `make fclean`, `make clean`, `make re`


Author [**Corentin COUTRET-ROZET**](https://github.com/sheiiva), [**PATRICIA MONFA-MATAS**](https://github.com/patumm)
