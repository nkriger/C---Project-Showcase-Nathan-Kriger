

#include <iostream>
#include <string>
#include <assert.h>
#include "cust.h"

using namespace std;

Cust::Cust(string name, bool is_robber, int arrival_time, int item_count) {
  m_name = name;
  m_is_robber = is_robber;
  m_arrival_time = arrival_time;
  m_item_count = item_count;
}
//core get data functions
string Cust::getName() { return m_name; }

bool Cust::getIsRobber() { return m_is_robber; }

int Cust::getArrivalTime() { return m_arrival_time; }

int Cust::getItemCount() { return m_item_count; }

//print data
void Cust::print(ostream &os) {
  os << m_name << " " << ((m_is_robber) ? "robber" : "shopper") << " " << m_arrival_time << " " << m_item_count << endl;
}

//print on "entering Store"
void Cust::outputEnteredStore(ostream &os, int clock) {
  assert(clock == m_arrival_time);
  os << clock << ": " << m_name << " entered store" << endl;
}

//print on exiting Store
void Cust::outputDoneShopping(ostream &os, int clock) {
  os << clock << ": " << m_name << " done shopping" << endl;
}

//print started check out
void Cust::outputStartedCheckout(ostream &os, int clock, int checker) {
  os << clock << ": " << m_name << " started checkout with checker " << checker << endl;
}

//print paid
void Cust::outputPaidToChecker(ostream &os, int clock, int amount_paid, int checker) {
  os << clock << ": " << m_name << " paid $" << amount_paid << " for " << m_item_count << ((m_item_count == 1) ? " item" : " items") << " to checker " << checker << endl;
}

//or print stolen
void Cust::outputStoleFromChecker(ostream &os, int clock, int amount_stolen, int checker) {
  os << clock << ": " << m_name << " stole $" << amount_stolen << " and " << m_item_count << ((m_item_count == 1) ? " item" : " items") << " from checker " << checker << endl;
}
