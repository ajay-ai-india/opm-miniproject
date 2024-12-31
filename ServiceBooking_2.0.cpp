#include <iostream>
#include <string>
#include <chrono>

using namespace std;


// ================================== Main Class of App ===========================================================
class serviceBooking
{
private:
    string selectedService;
    string selectedUrgency;
    string address;
    string paymentMethod;
    double total_amount = 0;
    double platform_fee = 0;
    double urgent_charges = 0;

public:
    void giveRating();
    void choosePersonnel();
    void enterAddress();
    void processPayment();
    void lookurgency();
    void showSuccessMessage();
    void showMainMenu();
    void selectService();
    void paywith();
};


// =============================== structure contain data of Personnels =================================================
struct Personnel
{
    string name;
    int age;
    int experience;        // In years
    float rating;          // Out of 5.0
    double distance;       // Distance from user's address in km
    float payment;         // Payment based on rating and experience
    string serviceComment; // Comment about the employee's service
};

Personnel Carpentor[5] = {
    {"Rajesh", 23, 5, 4.5, 2.8, 50.0, "\nOne of the best person for this work, honest and smartworking"},
    {"Raju", 19, 1, 3.6, 4, 30.0, "\nVery new to this work worse experience for me"},
    {"Mahesh", 45, 25, 4.1, 7.5, 60.0, "\nHe is very experienced but also slow he follows every norms"},
    {"Ramesh", 30, 10, 4.9, 5.1, 60.0, "\nHe is one of the best personnel best services available"},
    {"Suresh", 35, 8, 4.0, 10, 35, "\nHe is experience but one should supervise him"}};
Personnel Plumber[5] = {
    {"Gajendra", 23, 5, 4.5, 2.8, 50.0, "\nOne of the best person for this work, honest and smartworking"},
    {"Mahendra", 19, 1, 3.6, 4, 30.0, "\nVery new to this work worse experience for me"},
    {"Surendra", 45, 25, 4.1, 7.5, 60.0, "\nHe is very experienced but also slow he follows every norms"},
    {"Ravi", 30, 10, 4.9, 5.1, 60.0, "\nHe is one of the best personnel best services available"},
    {"Suraj", 35, 8, 4.0, 10, 25, "\nHe is experience but one should supervise him"}};
Personnel Housekeeper[5] = {
    {"Ali", 23, 5, 4.5, 2.8, 10.0, "\nOne of the best person for this work, honest and smartworking"},
    {"Ayush", 19, 1, 3.6, 4, 20.0, "\nVery new to this work worse experience for me"},
    {"Raj", 45, 25, 4.1, 7.5, 30.0, "\nHe is very experienced but also slow he follows every norms"},
    {"Raja", 30, 10, 4.9, 5.1, 50.0, "\nHe is one of the best personnel best services available"},
    {"Sumer", 35, 8, 4.0, 10, 40, "\nHe is experience but one should supervise him"}};
Personnel Electrician[5] = {
    {"Rajesh", 23, 5, 4.5, 2.8, 100.0, "\nOne of the best person for this work, honest and smartworking"},
    {"Raju", 19, 1, 3.6, 4, 60.0, "\nVery new to this work worse experience for me"},
    {"Mahesh", 45, 25, 4.1, 7.5, 120.0, "\nHe is very experienced but also slow he follows every norms"},
    {"Reena", 30, 10, 4.9, 5.1, 120.0, "\nShe is one of the best personnel best services available"},
    {"Priya", 35, 8, 4.0, 10, 70, "\nShe is experience but one should supervise him"}};

Personnel *currentPersonnelList;
Personnel selectedPersonnel;


// ------------------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------===========Function Definitions=============------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------


// -----------------------------------Main Menu---------------------------------------------------------------------
void serviceBooking::showMainMenu()
{
    cout << "Main menu: " << endl;
    cout << "1. Book a Service" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
label1:
    int choice;
    // Validate input
    if (!(cin >> choice))
    {
        cout << "Invalid input! Please enter a numeric value: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        goto label1;                                         // Retry the loop
    }

    switch (choice)
    {
    case 1:
        selectService();
        break;
    case 2:
        cout << "\n\nThank you for using Believers Service Booking!" << endl;
        exit(0);
    default:
        cout << "\nInvalid choice. Try again." << endl;
        showMainMenu();
    }
}


// ------------------------------------------Select Service type--------------------------------------------------------------
void serviceBooking::selectService()
{
    cout << "\n\nServices available at our bench" << endl;
    cout << "1. Plumber" << endl;
    cout << "2. Electrician" << endl;
    cout << "3. Carpenter" << endl;
    cout << "4. HouseKeeper" << endl;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter your choice: ";
label2:
    int serviceChoice;
    // Validate input
    if (!(cin >> serviceChoice))
    {
        cout << "Invalid input! Please enter a numeric value: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        goto label2;                                         // Retry the loop
    }

    switch (serviceChoice)
    {
    case 1:
        selectedService = "Plumber";
        currentPersonnelList = Plumber;
        break;
    case 2:
        selectedService = "Electrician";
        currentPersonnelList = Electrician;
        break;
    case 3:
        selectedService = "Carpentor";
        currentPersonnelList = Carpentor;
        break;
    case 4:
        selectedService = "HouseKeeper";
        currentPersonnelList = Housekeeper;
        break;
    case -1:
        cout << "\n\nThank you for using Believers Service Booking!" << endl;
        exit(0);
    default:
        cout << "\nInvalid option. Select right option.";
        selectService();
    }

    cout << "Selected Service: " << selectedService << endl;

    enterAddress();
}


// -------------------------------------------Address Selection---------------------------------------------------------
void serviceBooking::enterAddress()
{
    cout << "\nEnter your address (area name): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, address);

    if (address.empty())
    {
        cout << "\nAddress cannot be empty. Try again." << endl;
        enterAddress();
    }
    else
    {
        choosePersonnel();
    }
}




// -----------------------------------------------Select Personnel----------------------------------------------------------------------
void serviceBooking::choosePersonnel()
{
    cout << "\n\nAvailable Personnel for " << selectedService << ": \n"
         << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << currentPersonnelList[i].name
             << " | Age: " << currentPersonnelList[i].age
             << " | Experience: " << currentPersonnelList[i].experience << " years"
             << " | Rating: " << currentPersonnelList[i].rating << " star"
             << " | Distance: " << currentPersonnelList[i].distance << " km" << endl;
        cout << " | Comment: " << currentPersonnelList[i].serviceComment << endl;
        cout << " | personnel Fee: " << currentPersonnelList[i].payment << "$" << endl
             << endl;
    }
label4:
    cout << "Choose Personnel (1 - 5): ";
    // Validate input
    int personnelChoice;
    if (!(cin >> personnelChoice))
    {
        cout << "Invalid input! Please enter a numeric value.\n ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        goto label4;                                         // Retry the loop
    }
    if (personnelChoice < 1 || personnelChoice > 5)
    {
        cout << "Invalid option. try again." << endl;
        choosePersonnel();
    }
    selectedPersonnel = currentPersonnelList[personnelChoice - 1];
    processPayment();
}


// ----------------------------------------Bill Generation------------------------------------------------------------------------------------
void serviceBooking::processPayment()
{
    system("cls");
    cout << "\n";
    total_amount = selectedPersonnel.payment + urgent_charges;
    platform_fee = total_amount * 0.065;
    total_amount += platform_fee;
    double tax = total_amount * 0.18;
    total_amount += tax;
    cout << "\nSelected Personnel: " << selectedPersonnel.name << endl;
    cout << "\n\tTotal Payment: " << total_amount - 5 << "$" << endl;
    ;
    cout << "--------------------------------------------------------" << endl;
    cout << "\tPersonnel Service Fee:   " << selectedPersonnel.payment << "$" << endl;
    cout << "\tUrgency Charges:        +" << urgent_charges << "$" << endl;
    cout << "\tPlatform Fee:           +" << platform_fee << "$" << endl;
    cout << "\tTaxes:                  +" << tax << "$" << endl;
    cout << "\tDiscount:               -" << 5 << "$" << endl;
    paywith();
}

// ----------------------------------------------Select Payment Option------------------------------------------------------------------------------
void serviceBooking::paywith()
{
    cout << "\n\tChoose payment Method: " << endl;
    cout << "\t1. Credit/Debit Card" << endl;
    cout << "\t2. UPI" << endl;
    cout << "\t3. Cash" << endl;
    cout << "\tEnter -1 to exit" << endl;
    cout << "Enter your choice: ";
label5:
    int payment_choice;
    // Validate input
    if (!(cin >> payment_choice))
    {
        cout << "Invalid input! Please enter a numeric value: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        goto label5;                                         // Retry the loop
    }

    switch (payment_choice)
    {
    case 1:
        paymentMethod = "Credit/Debit Card";
        cout << "Currently Card payment is not available. Please try again later." << endl;
        cout << "Use Cash payment method." << endl;
        paywith();
        break;
    case 2:
        paymentMethod = "UPI";
        cout << "Currently UPI payment is not available. Please try again later." << endl;
        cout << "Use Cash payment method." << endl;
        paywith();
        break;
    case 3:
        paymentMethod = "Cash";
        system("cls");
        showSuccessMessage();
        break;
    case -1:
        cout << "\n\nThank you for using Believers Service Booking!" << endl;
        exit(0);
    default:
        cout << "Invalid option. Try again.";
        paywith();
    }
}


// -----------------------------------------------------Show Success Message---------------------------------------------------------------------
void serviceBooking::showSuccessMessage()
{
    cout << "\n\n\nThank you for booking " << selectedService << " service with " << selectedPersonnel.name << endl;
    cout << "Your booking details:" << endl;
    cout << "Service: " << selectedService << endl;
    cout << "Personnel: " << selectedPersonnel.name << endl;
    cout << "Urgency: " << selectedUrgency << endl;
    cout << "Address: " << address << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << "Total Payment: $" << total_amount << endl;
    cout << "The original bill will be sent to your mobile no or email";
    cout << "\nWe will contact you soon! Have a great day!" << endl;
}

// ----------------------------------------------Rating and Review-------------------------------------------------------------
void serviceBooking::giveRating()
{
    double rating;
    string comment;
    cout << "\n\nRate the service from 1 to 5 stars: ";
    cin >> rating;
    if (rating < 1 || rating > 5)
    {
        cout << "Invalid rating! Please enter a value between 1 and 5.\n";
        giveRating();
    }

    cout << "Enter your review: ";
    cin.ignore();
    getline(cin, comment);

    cout << "Thank you for your feedback!" << endl;
}

// -----------------------------------------------------End of Function Definitions-------------------------------------------------------------------

// -------------------------------------------------------------------Main Function-------------------------------------------------------------------
int main()
{
    cout << "\n\n\n";
    cout << "\t\tBelivers Service Booking!" << endl
         << endl
         << endl;
    cout << "Service Booking Made Easy" << endl;
    serviceBooking myservice;
    myservice.showMainMenu();
    cout << "\n\nIf You want to Rate us and give feedback press 1 else press 0: ";
    int rate;
    cin >> rate;
    if (rate == 1)
    {
        myservice.giveRating();
    }
    return 0;
}

// ===========================================End of program=======================================================================