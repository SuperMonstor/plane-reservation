#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//initialize database files
ofstream writePlane("flightDetails.txt", ios::app);
ifstream readPlane("fightDetails.txt");
ofstream writePassengers("Passengers.txt", ios::app);
ifstream readPassengers("Passengers.txt");
ofstream writeAdmin("admins.txt", ios::app);
ifstream readAdmin("admins.txt");

//PLANES CLASS
class planesGen {
    string fromLoc, toLoc, leave, arrive;
    int  number, noSeats;
    char cl;
    double price;
    
public:
    planesGen() {
        leave = arrive = fromLoc = toLoc = "";
        cl = ' ';
        number = 0;
        price = 0.0;
    }
    
    planesGen(string fromLoc, string toLoc, string leave, string arrive, int number, char cl, double price, int noSeats) {
        this -> fromLoc = fromLoc;
        this -> toLoc = toLoc;
        this -> leave = leave;
        this -> arrive = arrive;
        this -> number = number;
        this -> cl = cl;
        this -> price = price;
        this -> noSeats = noSeats;
        writePlane << fromLoc << " " << toLoc << " " << leave << " " << arrive << " " << number << " " << noSeats << " " << cl << " " << price << endl;
    }
    
    ~planesGen() {
        cout << "Flight successfully added!" << endl;
    }
};

//CLASS PASSENGERS
class passenger {
    string firstName, lastName, date;
    double luggage;
    int flightNo;
    
public:
    passenger() {
        firstName = lastName = date = "";
        luggage = flightNo = 0;
    }
    
    passenger(string firstName, string lastName, string date, int luggage, int flightNo) {
        this -> firstName = firstName;
        this -> lastName = lastName;
        this -> date = date;
        this -> luggage = luggage;
        this -> flightNo = flightNo;
        writePassengers << firstName << " " << lastName << " " << date << " " << flightNo << " " << luggage << endl;
    }
    
    ~passenger() {
        cout << "Passenger added!" << endl;
    }
};

//CLASS ADMIN-ACCOUNTS
class adminAcc {
    string username, password;
    
public:
    adminAcc() {
        username = password = "";
    }
    
    adminAcc(string username, string password) {
        this -> username = username;
        this -> password = password;
        writeAdmin << username << " " << password << endl;
    }
    
    ~adminAcc() {
        cout << "Account successfully created!" << endl;
    }
};

//print flight details function
void printFlights() {
    ifstream readPlane1("flightDetails.txt");
    if(readPlane1.is_open()) {       //broken
        string from, to, leave, arrive;
        int number, noSeats;
        char cl;
        double price;
        cout << "FRO" << " " << "TO" << " " << "DEPART" << " " << "ARRIVE" << " " << "FLTNO" << " " << "SEATS" << " " << "CL" << " " << "PRICE" << endl;
        while(readPlane1 >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
            cout << from << " " << to << " " << leave << " " << arrive << "  " << number << "  " << noSeats << "    " << cl << "  " << price << endl;
        }
    }
    else {
        cout << "File Missing! Please run the program again." << endl;
    }
    readPlane1.close();
}

void cancelFlight()
{
    string  firstname, lastname;
    int flightsbooked[6];
    int ctr=0;
    string fname, lname;
    int lug ,fno;
    ifstream sred("Passengers.txt");
    cout<<"enter yor  first name: ";
    cin>> firstname;
    cout << "Enter your last name: ";
    cin>>lastname;
    
    while (sred>>fname>>lname>>lug>>fno)
    {
        if (fname==firstname && lname==lastname)
        {
            flightsbooked[ctr++]=fno;
        }
    }
    cout << "Flights booked: \n\n" << endl;
    string from, to, leave, arrive;
    int number, noSeats;
    char cl;
    double price;
    
    ifstream readFlight("flightDetails.txt");
    cout << "FRO" << " " << "TO" << " " << "DEPART" << " " << "ARRIVE" << " " << "FLTNO" << " " << endl;
    while(readFlight >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
        for(int i = 0; i <= ctr; i++) {
           if(number == flightsbooked[i])
        cout << from << " " << to << " " << leave << " " << arrive << "  " << number << "  " << endl;
        }
    }
    int cancelNo;
    ifstream pas("Passengers.txt");
    ofstream fr("tempPassengers.txt");
    cout << " Enter the flight no to be cancelled.\n ";
    cin >> cancelNo;
    if(pas.is_open())
    {
        while(pas >> fname >> lname >> lug >> fno)
        {
            if (firstname == fname && lastname == lname && cancelNo==fno)
                continue;
            else
            {
                fr << fname << " " << lname << " " << lug << " " << fno << endl;
            }
        }
    }
    else {
        cout << "File not open!" << endl;
    }
    
    ofstream red("tempflight.txt");
    ifstream readPlane1("flightDetails.txt");
    if(readPlane1.is_open()) {
        while(readPlane1 >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
            if(number == cancelNo)
                red << from << " " << to << " " << leave << " " << arrive << " " << number << " " << noSeats+1 << " " << cl << " " << price << endl;
            else {
                red << from << " " << to << " " << leave << " " << arrive << " " << number << " " << noSeats << " " << cl << " " << price << endl;
            }
        }
    }
    else {
        cout << "File not open!" << endl;
    }
    remove("flightDetails.txt");
    rename("tempflight.txt","flightDetails.txt");
    remove("Passengers.txt");
    cout << "\nFLIGHT CANCELLED.\n";
    rename("tempPassengers.txt","Passengers.txt");
}

void viewdetails()
{
    string  firstname, lastname;
    int flightsbooked[6];
    int ctr=0;
    string fname, lname;
    int lug ,fno;
    ifstream sred("Passengers.txt");
    cout<<"enter yor  first name: ";
    cin>> firstname;
    cout << "Enter your last name: ";
    cin>>lastname;
    
    while (sred>>fname>>lname>>lug>>fno)
    {
        if (fname==firstname && lname==lastname)
        {
            flightsbooked[ctr++]=fno;
        }
    }
    cout << "Hello, " << firstname << "! Here are the details of the flights you have booked." << endl;
    string from, to, leave, arrive;
    int number, noSeats;
    char cl;
    double price;
    
    ifstream readFlight("flightDetails.txt");
    cout << "FRO" << " " << "TO" << " " << "DEPART" << " " << "ARRIVE" << " " << "FLTNO" << " " << endl;
    while(readFlight >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
        for(int i = 0; i <= ctr; i++) {
            if(number == flightsbooked[i])
                cout << from << " " << to << " " << leave << " " << arrive << "  " << number << "  " << endl;
        }
    }
}

void flightbooking()
{
    int source,destination;
    do
    {
        cout << "Source \n1.BAN\n2.MUM\n3.DEL\n4.KOL\n5.PUN\nINPUT: ";
        cin >> source;
    }while(source>6 && source<0);
    
    do
    {
        cout<<"Destination\n1.BAN\n2.MUM\n3.DEL\n4.KOL\n5.PUN\nINPUT: ";
        cin>>destination;
    }while(destination<0&&destination>6);
    
    //displaying matching flights
    
    string a[]={"","BAN","MUM","DEL","KOL","PUN"};
    ifstream readPlane1("flightDetails.txt");
    int flag=0;
    string from, to, leave, arrive;
    int number, noSeats;
    char cl;
    double price;
    cout << "\n\nTHE AVAILABLE FLIGHTS ARE: \n";
    if(readPlane1.is_open()) {
        cout << "FRO" << " " << "TO" << " " << "DEPART" << " " << "ARRIVE" << " " << "FLTNO" << " " << "SEATS" << " " << "CL" << " " << "PRICE" << endl;
        while(readPlane1 >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
            if(a[source]==from && a[destination]==to)
            {
                cout << from << " " << to << " " << leave << " " << arrive << "  " << number << "  " << noSeats << "    " << cl << "  " << price << endl;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"\t NO FLIGHTS AVAILABLE";
            return;
        }
    }
    else {
        cout << "File not open!" << endl;
        return;
    }
    readPlane1.close();
    //creating passaeger profile
    string firstName, lastName, date;
    double luggage;
    int flightNo;
    cout<<"Enter flight number to book: ";
    cin>>flightNo;
    cout << "Enter date of the flight (DD-MM-YYYY): ";
    cin >> date;
    //inputing passenger info
    cout<<"Enter first name: ";
    cin>>firstName;
    cout<<"Enter last name: ";
    cin>>lastName;
    while(1) {
        cout<<"Enter luggage weight (Kg): ";
        cin>>luggage;
        if(luggage > 30)
            cout << "Excess luggage! Please reduce baggage and try again";
        else
            break;
    }
    passenger *p1 =new passenger(firstName,lastName, date, flightNo,luggage);
    delete p1;
    
    ifstream readPlane2("flightDetails.txt");
    ofstream red("tempflight.txt");
    if(readPlane2.is_open()) {
        while(readPlane2 >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
            if(number == flightNo)
                red << from << " " << to << " " << leave<< " " << arrive<< " " << number << " " << noSeats-1<< " " << cl << " " << price << endl;
            else {
                red << from << " " << to << " " << leave << " " << arrive << " " << number << " " << noSeats << " " << cl << " " << price << endl;
            }
        }
    }
    remove("flightDetails.txt");
    cout << "\nFLIGHT BOOKED.\n";
    rename("tempflight.txt","flightDetails.txt");
}

void printTicket() {
    string  firstname, lastname, from, to, leave, arrive;
    string fname, lname, date;
    int number, noSeats, flightNo, fno, lug, flag = 0;
    char cl; double price;
    cout<<"enter yor  first name: ";
    cin>> firstname;
    cout << "Enter your last name: ";
    cin>>lastname;
    cout << "Enter your Flight Number: ";
    cin >> flightNo;
    
    ifstream pas("Passengers.txt");
    if(pas.is_open())
    {
        while(pas >> fname >> lname >> date >> lug >> fno)
        {
            if (firstname == fname && lastname == lname && fno == flightNo) {
                cout << "__________________________________\n";
                cout << "NAME: " << fname << " " << lname << endl;
                cout << "\n";
                flag = 1;
                break;
            }
        }
    if(flag == 1) {
            ifstream readFlight("flightDetails.txt");
            cout << "FRO" << " " << "TO" << "       " << "DEPART" << " " << "ARRIVE" << " " << "FLTNO" << " " << "DATE" << endl;
    
            while(readFlight >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
                if(number == flightNo) {
                        cout << from << " " << to << "       " << leave << " " << arrive << "  " << number << "  " << date << endl;
                        cout << "__________________________________\n";
                }
                }
    }
    else {
        cout << "_____________________________" << endl;
        cout << "FLIGHT NOT FOUND\n" << endl;
        cout << "-----------------------------" << endl;
    }
}
}


//passenger option function
void passengerChoice() {
    int choice;
    cout << "Hello. Please select one of the options below." << endl;
    cout << "1. Reserve Flight Seats \n2. Cancel Reservation \n3. Print Tickets \n4. Flight details \n5.Exit" << endl;
    cin >> choice;
    switch(choice) {
        case 1: flightbooking();
            break;
        case 2: cancelFlight();
            break;
        case 3: printTicket();
            break;
        case 4: viewdetails();
            break;
        case 5: return;
    }
}

//add flight function
void addFlight() {
    //(src, dest, arrTime, deptTime, flightNo, class, price, seats available)
    string src, dest, arrTime, deptTime;
    int flightNo = 0, seatsA = 0;
    double price = 0.0;
    char c = ' ';
    try{
        cout << "Please enter the flight details." << endl;
        cout << "Flight Source: ";
        cin >> src;

        cout << "Flight Destination: ";
        cin >> dest;
        cout << "Departure Time (Format: HHMM): ";
        cin >> arrTime;
         if(arrTime.length() != 5)
             throw "Wrong Input! Should be of the form HH:MM (Eg. 2310). Please try again.";
        cout << "Arrival Time (HH:MM): ";
        cin >> deptTime;
        cout << "Flight Number: ";
        cin >> flightNo;
        cout << "Number of vacant seats: ";
        cin >> seatsA;
        cout << "Price of seats: ";
        cin >> price;
        cout << "Seat Class (E, F): ";
        cin >> c;
    }
    catch(const char* msg) {
        cout << msg << endl;
        addFlight();
    }
    planesGen *fl = new planesGen(src, dest, arrTime, deptTime, flightNo, c, price, seatsA);
    delete fl;
}

//change time function
void changeTime() {
    printFlights();
    int flightNo;
    string nDept, nArrive;
    cout << "Enter flight number: ";
    cin >> flightNo;
    cout << "Enter new Time of Departure: ";
    cin >> nDept;
    cout << "Enter new Time of Arrival: ";
    cin >> nArrive;
    ofstream red("tempflight.txt");
    string line;
    ifstream fin("flightDetails.txt");
    string from, to, leave, arrive;
    int number, noSeats;
    char cl;
    double price;
    ifstream readPlane1("flightDetails.txt");
    if(readPlane1.is_open()) {
        while(readPlane1 >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
            if(number == flightNo)
                red << from << " " << to << " " << nDept << " " << nArrive << " " << number << " " << noSeats << " " << cl << " " << price << endl;
            else {
                red << from << " " << to << " " << leave << " " << arrive << " " << number << " " << noSeats << " " << cl << " " << price << endl;
            }
        }
    }
    else
        cout << "File not open!" << endl;
    remove("flightDetails.txt");
    cout << "\nTIMINGS FOR THE FLIGHT HAVE BEEN CHANGED.\n";
    rename("tempflight.txt","flightDetails.txt");
}

//delete flight function
void deleteFlight() {
    printFlights();
    int flightNo;
    cout << "Enter flight number: ";
    cin >> flightNo;
    ofstream red("tempflight.txt");
    string line;
    ifstream fin("flightDetails.txt");
    string from, to, leave, arrive;
    int number, noSeats;
    char cl;
    double price;
    ifstream readPlane1("flightDetails.txt");
    if(readPlane1.is_open()) {
        while(readPlane1 >> from >> to >> leave >> arrive >> number >> noSeats >> cl >> price) {
            if(number == flightNo)
                continue;
            else {
                red << from << " " << to << " " << leave << " " << arrive << " " << number << " " << noSeats << " " << cl << " " << price << endl;
            }
        }
    }
    else
    cout << "File not open!" << endl;
    remove("flightDetails.txt");
    cout << "\nFLIGHT DELETED.\n";
    rename("tempflight.txt","flightDetails.txt");
}

//Admin Options function
void adminOptions() {
    int choice;
    cout << "\n____________________________________________________________\n\n";
    cout << "Welcome administrator!" << endl;
    cout << "1. ADD FLIGHT \n2. DELETE FLIGHT \n3. CHANGE FLIGHT TIMINGS\n4. EXIT \nINPUT: ";
    cin >> choice;
    switch(choice) {
        case 1: addFlight();
            break;
        case 2: deleteFlight();
            break;
        case 3: changeTime();
            break;
        case 4:
            return;
        default: cout << "Wrong choice! Please try again." << endl;
    }
    adminOptions();
}

//Admin Login Function
void adminLogin() {
    string usr, pwd;
    string fusr, fpwd;
    try {
        int flag = 0;
        cout <<"\nUSERNAME: ";
        cin >> usr;
        ifstream readAdmin1("admins.txt");
        while(readAdmin1 >> fusr >> fpwd) {
            if(fusr == usr) {
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            flag = 0;
            cout <<"PASSWORD: ";
            cin >> pwd;
            if(fpwd == pwd) {
                flag = 1;
            }
            if(flag == 1) {
                cout << "\nLOGIN SUCCESSFUL!" << endl;
                readAdmin1.close();
                adminOptions();
            }
            else{
                readAdmin1.close();
                throw "Password is incorrect! Please try again.";
            }
        }
        else {
            readAdmin1.close();
            throw "Username not found!";
        }
    }
    
    catch(const char* msg) {
        cout << msg << endl;
        adminLogin();
    }
    
}

//admin create function
void adminCreate() {
    string key;
    cout << "\nEnter master key: ";
    cin >> key;
    if(key == "master") {
        cout << "Please enter your details below: \n";
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        adminAcc *ac = new adminAcc(username, password);
        delete ac;
    }
    else {
        cout << "\nWrong key. Please contact sysadmin." << endl;
    }

}


//administrator option function
void admin() {
    int adminchoice;
    cout << "Enter your choice\n";
    cout << "1. LOGIN \n2: CREATE NEW USER\nINPUT:";
    
    cin >> adminchoice;
    switch(adminchoice)
    {
        case 1: adminLogin();
            break;
            
        case 2: adminCreate();
            break;
            
    }
}

//generate text files
void generateFiles() {
    //(src, dest, arrTime, deptTime, flightNo, class, price, seats available)
    planesGen f1("BAN", "DEL", "00:00", "01:30", 9991, 'F', 4100, 35);
    planesGen f2("BAN", "DEL", "00:00", "01:30", 9992, 'F', 4000, 36);
    planesGen f3("DEL", "MUM", "01:30", "12:00", 1234, 'E', 1600, 36);
    planesGen f4("MUM", "KOL", "16:00", "18:30", 7721, 'E', 2400, 36);
    planesGen f5("KOL", "PUN", "19:00", "21:40", 8823, 'F', 4400, 35);
    planesGen f6("BAN", "PUN", "14:00", "15:50", 4573, 'E', 3500, 36);
    planesGen f7("PUN", "KOL", "23:10", "01:10", 4829, 'E', 2200, 35);
    planesGen f8("DEL", "BAN", "15:00", "03:30", 1294, 'E', 3200, 36);
    planesGen f9("KOL", "PUN", "19:00", "21:40", 8824, 'E', 3100, 36);
    planesGen f10("BAN", "MUM","16:00", "17:30", 3819, 'F', 6500, 35);
    cout << "Flights Generated!" << endl;
    
    passenger p1("Sudarshan", "Kumar", "12-12-2018", 9991, 25);
    passenger p2("Tanisha", "Naik", "10-12-2018", 8823, 16);
    passenger p3("Siddharth", "Mallapa", "12-01-2018", 4829, 9);
    passenger p4("Siddhant", "Sud", "06-12-2018", 3819, 6);
    cout << "People generated!" << endl;
    
    adminAcc a1("user1", "password123");
    adminAcc a2("user2", "password234");
    adminAcc a3("a", "a");
    cout << "Admin Accounts generated!" << endl;
}

//reset Files
void resetFiles() {
    remove("admins.txt");
    remove("flightDetails.txt");
    remove("Passengers.txt");
}

//debug
void debug() {
    int choice;
    cout << "\n____________________________________________________________\n\n";
    cout << "You have entered Debug mode." << endl;
    cout << "1. Generate Files \n2. Print Flights\n3. Reset Files\n4. Exit\nINPUT: ";
    cin >> choice;
    switch(choice) {
        case 1: generateFiles();
            break;
        case 2: printFlights();
            break;
        case 3: resetFiles();
            break;
        case 4: return;
        default: cout << "Wrong Option! Please try again." << endl;
    }
    debug();
}

void stripper() {
    cout << "Hello ladies and gents. " << endl;
    cout << "Your stripper name is " << endl;
    string name;
    cin >> name;
    cout << "Hello " << name << "! ;)" << endl;
    cout << "Now we present. " << endl;
    cout << "SEXYRED!!!" <<endl;
    cout << "AND SHANQTIE" << endl;
}

void privilage() {
    int userType;
    cout << "\n____________________________________________________________\n\n";
    cout << "PLANE RESERVATION SYSTEM " << endl;
    cout << "Please select user type:" << endl;
    cout << "1. PASSENGER \n2. ADMIN \n3. EXIT\nINPUT: ";
    cin >> userType;
    switch(userType) {
        case 1: passengerChoice();
            break;
        case 2: admin();
            break;
        case 99: debug();
            break;
        case -9999: stripper();
            break;
        case 3:
            return;
        default: cout << "Wrong option! Please try again." << endl;
    }
    privilage();
}

int main() {
    privilage();
    readPlane.close();
    writePlane.close();
    readAdmin.close();
    writeAdmin.close();
    readPassengers.close();
    writePassengers.close();
    return 0;
}
