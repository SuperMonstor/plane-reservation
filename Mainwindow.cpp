#include <iostream>

using namespace std;





    int ADMIN()
    {
        int adminchoice;
        cout<<"Enter your choice \n";
        cout<<"1 LOGIN \n 2: CREATE NEW USER";

        cin>>adminchoice;
        switch(adminchoice)
            {
               case 1: return 0;
                       break;

               case 2: return 0;
                       break;

            }

    }

  int passenger()
  {
      return 0;
  }

  int main()

  {
      int passengeroradmin;
      cout << "ENTER YOUR CHOICE \n";
      cout<<" 1: ADMIN \n 2: PASSENGER";
      cin>>passengeroradmin;



          switch (passengeroradmin)
          {

              case 1 : ADMIN();
                       break;
              case 2:  passenger();
                       break;

          }
      return 0;
  }

