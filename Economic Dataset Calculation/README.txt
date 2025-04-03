//Nathan Kriger
nkriger
211
/*

|||Files present|||
main.cpp //Runs the program
dataInject.cpp //Linked list and functions
dataInject.h // declaration of functions

input.txt //correct real world data on inflation rate
inputfalse.txt //incorrect fake data to test for false


|||Project OVerview|||
The goal of the project was to test if the unemployment rate within California would go up and down with the rate of inflation 
It tested if the values would increase and decrease together
IE. if in 1992 inflation was 2.1 and unemployment was 2.7
and in 1993 inflation was 2.7 and unemployment was 3.0
//////Both values increased from the last years rate meaning their is a correlation///
likewise the code tests if both go down together

However there needs to be enough frequency of this event to consider it true therefore the code will test if the the values correlate at least 80% of the time
if there is an 80% correlation then the data is true

in order to test the program you can give which data file to use
input 1-3 for whether to print data, analyse data or exit the program

|||to compile||| 
g++ main.cpp dataInject.cpp