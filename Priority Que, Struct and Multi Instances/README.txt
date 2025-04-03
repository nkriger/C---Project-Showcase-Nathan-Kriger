Objectives
Implement a Priority Queue
Practice using a struct
Practice working with command line arguments
Practice using file streams
Deploy multiple instances of your priority queue
Practice using assert(·)

---------
Overview
---------

Write a program to simulate the daily operations of a Kwik-E-Mart.

There are two types of customers, those that buy things (shoppers), and those that steal things and money (robbers).

Your program will:

read in a list of customers (name, shopper/robber, arrival time, number of items to buy/steal)
run the simulation.
Output will be generated while the simulation is running.

Customers will enter the store at a specified arrival time, spend time shopping for their items, get in line to pay/steal (our robbers are very polite, they wait in line to rob the store), spend some time paying or stealing money, and then leave the store. When a customer performs an action (arrive in store, get in checkout line, start paying/stealing, finish paying/stealing) your program will print a message documenting the customer's action and the current time.