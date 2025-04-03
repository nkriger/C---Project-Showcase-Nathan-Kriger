//Nathan, Kriger

#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iostream>

#include "cust.h"
#include "pqueue.h"

using namespace std;

const int COST_PER_ITEM = 3;
const int SHOP_TIME_PER_ITEM = 2;
const int CHECKOUT_TIME_PER_ITEM = 1;

const int ROB_TIME = 7;
const int STARTING_CHECKER_CASH = 250;

struct Checker
{
  int m_cash;
  int m_done_time;

  Cust *m_cust;
};
//pointer to pointer pain
void initialize_checkers(Checker **checkers, const int checker_count)
{
  for (int i = 0; i < checker_count; ++i)
  {
    Checker *checker = new Checker{
        STARTING_CHECKER_CASH, 0, nullptr,
    };
    checkers[i] = checker;
  }
}

void process_arriving_customers(PQueue &arrivalQueue, PQueue &shoppingQueue, int clock, ostream &os)
{
  int priority;
  Cust *customer;
  while (arrivalQueue.getFirstPriority(priority) && clock == priority)
  {
    arrivalQueue.dequeue(customer);
    customer->outputEnteredStore(os, clock);

    int shopping_end_time = clock + (customer->getItemCount() * SHOP_TIME_PER_ITEM);
    shoppingQueue.enqueue(customer, shopping_end_time);
  }
}

void process_customers_done_shopping(PQueue &shoppingQueue, PQueue &checkerQueue, int clock, ostream &os)
{
  int priority;
  Cust *customer;
  while (shoppingQueue.getFirstPriority(priority) && clock == priority)
  {
    shoppingQueue.dequeue(customer);
    customer->outputDoneShopping(os, clock);

    checkerQueue.enqueue(customer, 0);
  }
}

void process_completed_checkouts(Checker **checkers, const int checker_count, const int checker_break_duration, int &customer_count, int clock, ostream &os)
{
  for (int i = 0; i < checker_count; ++i)
  {
    if (checkers[i]->m_cust != nullptr && checkers[i]->m_done_time == clock)
    {
      if (checkers[i]->m_cust->getIsRobber())
      {
        checkers[i]->m_cust->outputStoleFromChecker(os, clock, checkers[i]->m_cash, i);
        checkers[i]->m_cash = 0;
        checkers[i]->m_done_time = clock + checker_break_duration;

      }
      else
      {

        int amount_paid = checkers[i]->m_cust->getItemCount() * COST_PER_ITEM;
        checkers[i]->m_cust->outputPaidToChecker(os, clock, amount_paid, i);

        checkers[i]->m_cash += amount_paid;
      }
      delete checkers[i]->m_cust;
      checkers[i]->m_cust = nullptr;
      --customer_count;
    }
  }
}

void assign_customers_to_checkers(Checker **checkers, const int checker_count, PQueue &checkerQueue, int clock, ostream &os)
{
  for (int i = 0; i < checker_count; ++i)
  {
    if (checkers[i]->m_done_time <= clock && checkers[i]->m_cust == nullptr)
    {
      if (checkerQueue.getSize() != 0)
      {
        Cust *next_customer;

        checkerQueue.dequeue(next_customer);
        checkers[i]->m_cust = next_customer;
        next_customer->outputStartedCheckout(os, clock, i);

        if (next_customer->getIsRobber())
          checkers[i]->m_done_time = clock + ROB_TIME;
        else
          checkers[i]->m_done_time = clock + (next_customer->getItemCount() * CHECKOUT_TIME_PER_ITEM);
      }
    }
  }
}

void output_checker_balances(Checker **checkers, const int checker_count, ostream &os)
{
  for (int i = 0; i < checker_count; ++i)
  {
    os << "registers[" << i << "] = $" << checkers[i]->m_cash << endl;
  }
}

void cleanup_checkers(Checker **checkers, const int checker_count)
{
  for (int i = 0; i < checker_count; ++i)
  {
    delete checkers[i];

  }
  delete[] checkers;
}

void run_simulation(const int checker_count, PQueue &arrivalQueue, const int checker_break_duration, ostream &os)
{
  /* Array of check*/

  Checker **checkers;
  checkers = new Checker *[checker_count];
  initialize_checkers(checkers, checker_count);

  PQueue shoppingQueue;

  PQueue checkerQueue;

  int clock;
  int customer_count;
  customer_count = arrivalQueue.getSize();

  for (clock = 1; customer_count > 0; ++clock)
  {
    process_arriving_customers(arrivalQueue, shoppingQueue, clock, os);
    process_customers_done_shopping(shoppingQueue, checkerQueue, clock, os);

    process_completed_checkouts(checkers, checker_count, checker_break_duration, customer_count, clock, os);

    assign_customers_to_checkers(checkers, checker_count, checkerQueue, clock, os);
  }

  output_checker_balances(checkers, checker_count, os);
  os << "time = " << clock << endl;

  cleanup_checkers(checkers, checker_count);
}

void read_input(ifstream &ifile, PQueue &arrivalQueue)
{
  string name, role;
  int arrival_time, item_count;

  while (ifile >> name >> role >> arrival_time >> item_count)
  {
    bool is_robber = (role == "robber");
    Cust *customer = new Cust(name, is_robber, arrival_time, item_count);

    arrivalQueue.enqueue(customer, arrival_time);
  }

  ifile.close(); // Closing the input file.
}

bool is_legal_integer(const char *str)
{
  int length = strlen(str);
  for (int i = 0; i < length; ++i){
    
    if (!isdigit(str[i]))

      return false;
  }

  return true;
}

int get_checker_count(char *argv)
{
  if (!is_legal_integer(argv) || strcmp(argv, "0") == 0)
  {
    string err = "Error: invalid number of checkers specified.";
    throw err;
  }
  return atoi(argv);
}

int get_checker_break_duration(char *argv)
{
  if (!is_legal_integer(argv))
  {
    string err = "Error: invalid checker break duration specified.";
    throw err;
  }
  return atoi(argv);
}

int main(int argc, char *argv[])
{
  int status = 0;
  try
  {
    if (argc != 5)
    {
      string err = "Error: invalid number of command line arguments.";
      throw err;
    }

    const int checker_count = get_checker_count(argv[1]);

    const int checker_break_duration = get_checker_break_duration(argv[2]);

    ifstream ifile(argv[3]);

    if (!ifile)
    {
      string err = "Error: could not open input file <FILENAME>.";
      throw err.replace(err.find("FILENAME"), sizeof("FILENAME") - 1, argv[3]);

    }

    ofstream ofile(argv[4]);

    if (!ofile)
    {

      string err = "Error: could not open output file <FILENAME>.";
      throw err.replace(err.find("FILENAME"), sizeof("FILENAME") - 1, argv[4]);
    }
    // priority que arrival stuffs

    PQueue arrivalQueue;
    read_input(ifile, arrivalQueue);
    run_simulation(checker_count, arrivalQueue, checker_break_duration, ofile);


    ofile.close();
  }
  catch (string err)
  {
    cerr << err << endl;

    status = 1;
  }

  return status;
}
