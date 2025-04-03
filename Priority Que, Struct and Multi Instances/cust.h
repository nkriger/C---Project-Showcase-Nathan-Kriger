

#ifndef CUST_H
#define CUST_H

#include <iostream>
#include <string>
using namespace std;

class Cust {
  public:
    /**
     * @brief Constructor for the `Cust` class.
     * @param name The name of the customer.
     * @param is_robber A bool representing the type of the customer; true for robber, otherwise false.
     * @param arrival_time The arrival time of the customer.
     * @param item_count The count of items.
    */
    Cust(string name, bool is_robber, int arrival_time, int item_count);

    /**
     * @brief Getter method for the customer's name.
     * @return The name of the customer.
     */
    string getName();
    
    /**
     * @brief Getter method for the customer type.
     * @return Returns true if the customer is a robber; otherwise false.
     */
    bool getIsRobber();
    
    /**
     * @brief Getter method for the customer's arrival time.
     * @return Customer's arrival time.
     */
    int getArrivalTime();

    /**
     * @brief Getter method for the item count of the customer.
     * @return The count of the items.
     */
    int getItemCount();

    /**
     * @brief Prints the Cust object on the provided output stream.
     * @param os A reference to the output stream object.
     */
    void print(ostream &os);

    /**
     * @brief 
     * @param os A reference to the output stream object.
     * @param clock Current simulation clock tick.
     */
    void outputEnteredStore(ostream &os, int clock);
    
    /**
     * @brief 
     * @param os A reference to the output stream object.
     * @param clock Current simulation clock tick.
     */
    void outputDoneShopping(ostream &os, int clock);
    
    /**
     * @brief 
     * @param os A reference to the output stream object.
     * @param clock Current simulation clock tick.
     * @param checker The id of the checker assigned to the customer.
     */
    void outputStartedCheckout(ostream &os, int clock, int checker);
    
    /**
     * @brief 
     * @param os A reference to the output stream object.
     * @param clock Current simulation clock tick.
     * @param amount_paid The amount paid to the checker by the customer.
     * @param checker The id of the checker assigned to the customer.
     */
    void outputPaidToChecker(ostream &os, int clock, int amount_paid, int checker);
    
    /**
     * @brief 
     * @param os A reference to the output stream object.
     * @param clock Current simulation clock tick.
     * @param amount_stolen The amount stolen from the checker by the customer.
     * @param checker The id of the checker assigned to the customer.
     */
    void outputStoleFromChecker(ostream &os, int clock, int amount_stolen, int checker);
  private:
    /* A string value to hold the name of the customer. */
    string m_name;
    /* A boolean value to determine the type of customer. true for a robber; false for a shopper. */
    bool m_is_robber;
    /* An integer value to represent arbitary time unit. */
    int m_arrival_time;
    /* An integer value to hold the number of items. */
    int m_item_count;
};

#endif
