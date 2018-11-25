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
    string firstName, lastName;
    double luggage;
    int flightNo;
    
public:
    passenger() {
        firstName = lastName = "";
        luggage = flightNo = 0;
    }
    
    passenger(string firstName, string lastName, int luggage, int flightNo) {
        this -> firstName = firstName;
        this -> lastName = lastName;
        this -> luggage = luggage;
        this -> flightNo = flightNo;
        writePassengers << firstName << " " << lastName << " " << flightNo << " " << luggage << endl;
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

//passenger option function
void passengers() {
    
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
            throw "Wrong Input! Should be of the form HHMM (Eg. 2310). Please try again.";
        cout << "Arrival Time (HHMM): ";
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

void adminLogin() {
    string usr, pwd;
    string fusr, fpwd;
    
    try {
        int flag = 0;
        cout <<"\nUSERNAME: ";
        cin >> usr;
        while(readAdmin >> fusr >> fpwd) {
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
                adminOptions();
            }
            else{
                throw "Password is incorrect! Please try again.";
            }
        }
        else {
            throw "Username not found!";
        }
    }
    
    catch(const char* msg) {
        cout << msg << endl;
        adminLogin();
    }
    
}

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
    planesGen f9("KOL", "PUN", "19:00", "21:40", 8823, 'E', 3100, 36);
    planesGen f10("BAN", "MUM","16:00", "17:30", 3819, 'F', 6500, 35);
    cout << "Flights Generated!" << endl;
    
    passenger p1("Sudarshan", "Kumar", 9991, 25);
    passenger p2("Tanisha", "Naik", 8823, 16);
    passenger p3("Siddharth", "Mallapa", 4829, 9);
    passenger p4("Siddhant", "Sud", 3819, 6);
    cout << "People generated!" << endl;
    
    adminAcc a1("user1", "password123");
    adminAcc a2("user2", "password234");
    adminAcc a3("a", "a");
    cout << "Admin Accounts generated!" << endl;
}

//reset Files
void resetFiles() {
    ofstream temp1("flightDetails.txt");
    ofstream temp2("Passengers.txt");
    ofstream temp3("admins.txt");
    temp1.close();
    temp2.close();
    temp3.close();
    cout << "\nFILES RESET\n";
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

void privilage() {
    int userType;
    cout << "\n____________________________________________________________\n\n";
    cout << "PLANE RESERVATION SYSTEM " << endl;
    cout << "Please select user type:" << endl;
    cout << "1. PASSENGER \n2. ADMIN \n3. EXIT\nINPUT: ";
    cin >> userType;
    switch(userType) {
        case 1: passenger();
            break;
        case 2: admin();
            break;
        case 99: debug();
            break;
        case 3:
            return;
        default: cout << "Wrong option! Please try again." << endl;
    }
    privilage();
}

int main() {
    privilage();
    return 0;
}
