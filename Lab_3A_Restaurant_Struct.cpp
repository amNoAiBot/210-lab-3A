// COMSC-210 | Lab 3A: Restaurant Struct Objects Practice | Sunny Anand
// IDE used: Visual Studio Code

/*********************************************************************
* Importing C++ Built-in Library Functions
**********************************************************************/
#include <iostream>
using namespace std;

// Importing iomanip libraries to use with setting precision.
#include <iomanip>

// Importing string libraries
#include <string>
using std::string;
using std::getline;

// Importing cstdlib libraries for atoi and atof
#include <cstdlib>

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
// Declaring function prototypes. Function definitions must precede function calls,
// or you can use the following workaround of defining prototypes instead of having
// to define the functions before main().
void printIdentification(string);
Restaurant userInputRestaurantInfo(int);
void printWarningIfUserEnteredWrongInput(int);
void printOutputHeading();
void printOutputRestaurantData(int, Restaurant);

/*********************************************************************
* The main() function
**********************************************************************/
int main() {
    // Identifying information in comment form is included at the top of this file.
    // Here, identifying information in cout form similar to sample-comment.cpp is provided.
    printIdentification("Lab 3A: Restaurant Struct Objects Practice\n");

    // Call the user input function 3 times, once for each restaurant.
    // User input is gotten by this function about Restaurant objects and the function returns a Restaurant data type.
    Restaurant restaurant1, restaurant2, restaurant3, restaurant4;
    restaurant1 = userInputRestaurantInfo(1);    // Serial number is sent as argument to userInputRestaurantInfo() function.
    restaurant2 = userInputRestaurantInfo(2);
    restaurant3 = userInputRestaurantInfo(3);
    restaurant4 = userInputRestaurantInfo(4);

    // Now output the five restaurants in a nice table
    // Call the print output function 3 times, once for each restaurant.
    printOutputHeading();
    printOutputRestaurantData(1, restaurant1);    // Serial number and Restaurant object are sent as arguments to printOutputRestaurantData().
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
* Function: User Input Function: Ask user for input about restaurants.
* Return user defined struct Restaurant data type to the calling function.
*
* getline() is used get string inputs with spaces from the user.
*
* cin is used to get string buffer input which are later converted to numbers.
* atoi() and atof() are used to convert string buffers into numbers.
* If the user did not enter a number, print out a message warning the user.
*
* cin.ignore() is used between cin and getline(), so that getline doesn't get
* confused with the previously entered carriage return.
*
* Finally, user defined data type struct Restaurant is returned.
*
* Parameter:
* Sequence #: Data type: int., Pass-by-Value.
* Restaurant sequence #
*
* Return:
* Restaurant:    Data type: User defined struct Restaurant data type.
* From the user input about the 5 attributes of the restaurant is gotten.
* The Restaurant object is returned to the calling function.
**********************************************************************/
Restaurant userInputRestaurantInfo(int serialNumber) {
    Restaurant inputRestaurant;

    // Get user input about each restaurant
    // Get user input about the restaurant's name
    cout << "\nEnter the name of restaurant " << serialNumber << ": ";
    getline(cin, inputRestaurant.eateryName);

    // Get user input about the restaurant's address, the address where the restaurant is studying
    cout << "In which address is " << inputRestaurant.eateryName << " located? ";
    getline(cin, inputRestaurant.address);

    // Get user input about the restaurant's rating
    // Here, user input is gotten as a string into a string buffer, then later converted into number.
    string buf;
    cout << "What's " << inputRestaurant.eateryName << "'s rating? ";
    cin >> buf;
    inputRestaurant.rating = atoi(buf.c_str());
    // If the user did not enter a number, print out a message warning the user.
    printWarningIfUserEnteredWrongInput(atoi(buf.c_str()));

    // Get user input about the restaurant's founded year
    cout << "Enter " << inputRestaurant.eateryName << "'s year founded: ";
    cin >> buf;
    inputRestaurant.yearStarted = atoi(buf.c_str());
    // If the user did not enter a number, print out a message warning the user.
    printWarningIfUserEnteredWrongInput(atoi(buf.c_str()));

    // Get user input about the restaurant's Avg. Price
    cout << "And now " << inputRestaurant.eateryName << "'s average price: ";
    cin >> buf;
    inputRestaurant.avgPrice = atof(buf.c_str());
    // If the user did not enter a number, print out a message warning the user.
    printWarningIfUserEnteredWrongInput(atoi(buf.c_str()));

    // ignore 200 chars max, or newline is read
    // use cin.ignore after every cin >> and before getline()
    // Because during the next call to this function, getline() would follow the cin above,
    // so the following cin.ignore is needed.
    cin.ignore(200, '\n');

    return inputRestaurant;
}

void printWarningIfUserEnteredWrongInput(int resultOfUserInput) {
    if (!resultOfUserInput) {
        cout << "You did not enter a number, so your input will be considered as if you entered a zero.\n";
    }
}

/*********************************************************************
* Function: Print Output Table Heading
*
* Print the heading for the output table in which all the attributes
* about the restaurants are printed.
*
* Parameter:
* None.
*
* Return:
* None.
**********************************************************************/
void printOutputHeading() {
    cout << "\n\n";
    cout << "#  Restaurant Name      Address                   Rating Year Founded Avg. Price\n";
    cout << "== ==================== ========================= ====== ============ ===========\n";
}

/*********************************************************************
* Function: Print output about restaurants' attributes in tablular format.
*
* Print info about restaurants' 5 attributes in tabular format.
*
* Serial number and info about the restaurants are printed in tabular format.
* Input parameters are serial number and struct Restaurant (user defined data type).
*
* Restaurant data type's attributes are printed in tabular format for each restaurant
* (during each call of the function).
*
* Parameter:
* 1) Sequence #:   Data type: int.
* Pass-by-Value.
* Restaurant sequence #
*
* 2) Restaurant:     Data type: User defined struct Restaurant data type.
* Pass-by-Value
*
* Return:
* None.
**********************************************************************/
void printOutputRestaurantData(int serialNum, Restaurant outputRestaurant) {
    // Align all data nicely towards the left of the table
    cout.setf(ios::left);

    // width(n) sets the width for a column of an output table. Then, within that width we can
    // align left or right. In the following lines, column width of the table is set using
    // width(n), and within that column width, data is left aligned.
    cout.width(3);
    cout << serialNum;

    cout.width(21);
    cout << outputRestaurant.eateryName;

    cout.width(26);
    cout << outputRestaurant.address;

    cout.width(7);
    cout << outputRestaurant.rating;

    cout.width(13);
    cout << outputRestaurant.yearStarted;

    cout.setf(ios::fixed);
    cout.precision(2);     // Take only 2 decimal places of Avg. Price. E.g. If the user enters 3.21555 -> 3.22
    cout.width(4);
    cout << outputRestaurant.avgPrice << "\n";
}

/*********************************************************************
* Function: Identifying information in cout form similar to
* sample-comment.cpp is provided here.
*
* Parameters:
* labDescription: Data type: string.
* Pass-by-Value.
* Lab description is passed as the string parameter.
*
* Return: None.
**********************************************************************/

// Identifying information in comment form is included at the top of this file.
// Here, identifying information in cout form similar to sample-comment.cpp is provided.
void printIdentification(string labDescription) {
    cout << "######################################################################\n";
    cout << "\t\t\tIdentifying Information\n";
    cout << "######################################################################\n";

    // Width of 20 and left alignment are set here, so the output will be nicely aligned.
    cout.setf(ios::left);
    cout.width(20); cout << "Restaurant Name:" << "Sunny Anand\n";
    cout.width(20); cout << "Course: " << "COMSC-210-5470-F25, Prof. Mark Dietrich.\n";
    cout.width(20); cout << "Lab Description: " << labDescription;
    cout.width(20); cout << "Editor(s) used: " << "VSC\n";
    cout.width(20); cout << "Compiler(s) used: " << "G++\n";
    cout.width(20); cout << "File: " << __FILE__ << "\n";
    cout.width(20); cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

    cout << "______________________________________________________________________\n\n";
    cout << "\t\tNow the actual program execution\n";
    cout << "______________________________________________________________________\n\n";
}
