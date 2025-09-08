// COMSC-210 | Lab 3A | Sunny Anand
// IDE used: Visual Studio Code

/*********************************************************************
* Importing C++ Built-in Library Functions
**********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using std::string;
using std::getline;

/*********************************************************************
* User defined data types (struct) are
* defined here before main().
**********************************************************************/
struct Restaurant {
    string eateryName;
    string address;
    int rating;
    int yearStarted;
    double avgPrice;
};

/*********************************************************************
* User Defined Function Prototypes are defined
* here as the actual functions are defined
* below main().
**********************************************************************/
void printIdentification(const string& labDescription);
Restaurant userInputRestaurantInfo(int serialNumber);
void printOutputHeading();
void printOutputRestaurantData(int serialNum, const Restaurant& outputRestaurant);

/*********************************************************************
* The main() function
**********************************************************************/
int main() {
    // Identifying information in comment form is included at the top of this file.
    // Here, identifying information in cout form similar to sample-comment.cpp is provided.
    printIdentification("Lab 3A: Restaurant Struct Objects Practice\n");

    // Call the user input function for each restaurant.
    // The function gets user input about a Restaurant object and returns it.
    Restaurant restaurant1, restaurant2, restaurant3, restaurant4;
    restaurant1 = userInputRestaurantInfo(1);
    restaurant2 = userInputRestaurantInfo(2);
    restaurant3 = userInputRestaurantInfo(3);
    restaurant4 = userInputRestaurantInfo(4);

    // Now output the four restaurants in a nice table.
    printOutputHeading();
    printOutputRestaurantData(1, restaurant1);
    printOutputRestaurantData(2, restaurant2);
    printOutputRestaurantData(3, restaurant3);
    printOutputRestaurantData(4, restaurant4);
    cout << "\n";

    return 0;
}

/*********************************************************************
* User Defined Functions
**********************************************************************/

/*********************************************************************
* Function: userInputRestaurantInfo
*
* Asks the user for input about restaurants, populating a struct that
* is then returned.
*
* Parameters:
* serialNumber: Data type: int, Pass-by-Value. Restaurant sequence #.
*
* Return:
* Restaurant: A `Restaurant` struct object with the user-entered data.
**********************************************************************/
Restaurant userInputRestaurantInfo(int serialNumber) {
    Restaurant inputRestaurant;

    if (serialNumber > 1) {
        cin.ignore(200, '\n');
    }

    // Get user input about the restaurant's name.
    cout << "\nEnter the name of restaurant " << serialNumber << ": ";
    getline(cin, inputRestaurant.eateryName);

    // Get user input about the restaurant's address.
    cout << "In which address is " << inputRestaurant.eateryName << " located? ";
    getline(cin, inputRestaurant.address);

    // Get user input about the restaurant's rating.
    cout << "What's " << inputRestaurant.eateryName << "'s rating? ";
    cin >> inputRestaurant.rating;

    // Get user input about the restaurant's founded year.
    cout << "Enter " << inputRestaurant.eateryName << "'s year founded: ";
    cin >> inputRestaurant.yearStarted;

    // Get user input about the restaurant's Avg. Price.
    cout << "And now " << inputRestaurant.eateryName << "'s average price: ";
    cin >> inputRestaurant.avgPrice;

    return inputRestaurant;
}

/*********************************************************************
* Function: printOutputHeading
*
* Prints the heading for the output table.
*
* Parameter:
* None.
*
* Return:
* None.
**********************************************************************/
void printOutputHeading() {
    cout << "\n\n";
    cout << left << setw(4) << "#" << setw(22) << "Restaurant Name" << setw(27) << "Address"
         << setw(8) << "Rating" << setw(14) << "Year Founded" << setw(15) << "Avg. Price\n";
    cout << "== " << string(20, '=') << " " << string(25, '=') << " " << string(6, '=')
         << " " << string(12, '=') << " " << string(11, '=') << "\n";
}

/*********************************************************************
* Function: printOutputRestaurantData
*
* Prints information about the restaurant's attributes in a tabular format.
* The struct is passed by constant reference to avoid making a copy,
* adhering to the convention for passing large objects that are not modified.
*
* Parameter:
* 1) serialNum: Data type: int, Pass-by-Value. Restaurant sequence #.
* 2) outputRestaurant: Data type: `const Restaurant&`, Pass-by-Constant-Reference.
*
* Return:
* None.
**********************************************************************/
void printOutputRestaurantData(int serialNum, const Restaurant& outputRestaurant) {
    // Align all data nicely towards the left of the table.
    cout << left << setw(4) << serialNum << setw(22) << outputRestaurant.eateryName
         << setw(27) << outputRestaurant.address << setw(8) << outputRestaurant.rating
         << setw(14) << outputRestaurant.yearStarted << fixed << setprecision(2)
         << setw(15) << outputRestaurant.avgPrice << "\n";
}

/*********************************************************************
* Function: printIdentification
*
* Prints identifying information in `cout` form.
*
* Parameters:
* labDescription: Data type: const string&, Pass-by-Constant-Reference.
* The lab description is passed as a string parameter.
*
* Return: None.
**********************************************************************/
void printIdentification(const string& labDescription) {
    cout << "######################################################################\n";
    cout << "\t\t\tIdentifying Information\n";
    cout << "######################################################################\n";

    cout << left;
    cout << setw(20) << "Programmer:" << "Sunny Anand\n";
    cout << setw(20) << "Course: " << "COMSC-210-5470-F25, Prof. Mark Dietrich.\n";
    cout << setw(20) << "Lab Description: " << labDescription;
    cout << setw(20) << "Editor(s) used: " << "VSC\n";
    cout << setw(20) << "Compiler(s) used: " << "G++\n";
    cout << setw(20) << "File: " << __FILE__ << "\n";
    cout << setw(20) << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

    cout << "______________________________________________________________________\n\n";
    cout << "\t\tNow the actual program execution\n";
    cout << "______________________________________________________________________\n\n";
}
