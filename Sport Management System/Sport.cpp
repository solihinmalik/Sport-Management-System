#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <ctime>

#define N 20
using namespace std;

class Equipment
{
    private:
        int price[2] = {5, 10};
        int stockF = 10;
        int stockB = 20;
        int quantity, eqptype, cont, numData;
        string equipmentType[2]= {"futsalball","racket & shuttlecock"};
    
    public:

        double display() 
        {
            double totalAll = 0;
        
            do
            {
                system("cls"); 

                cout << "What equipment type do you want? \n1. FutsalBall=>Stocks: " << stockF
                    << "\n2. Racket&shuttlecock=>Stocks: " << stockB << "\n=> ";
                cin >> eqptype;
                cout << "Quantity: ";
                cin >> quantity;

                double total = calcTotal();

                int cont;

                cout << "Total price: RM " << total << endl;                
                
                totalAll = totalAll + total;

                cout << "Do you want to continue? if YES press <1> => ";
                cin >> cont;

                numData++;

            }while (cont == 1);

            //cout << "\nTotal that is need to be paid is RM"<< totalAll << endl;

            return totalAll;

        }

        double getData() {
            return numData;
        }

        string getEtype(int index) {
            return equipmentType[index];
        }
        
        double getQtt() {
            return quantity;
        }

        double calcTotal()
        {
            double total;
            if (eqptype == 1) {
                total = price[0] * quantity;
                stockF -= quantity;
            }
            if (eqptype == 2) {
                total = price[1] * quantity;
                stockB -= quantity;
            }
            return total;
        }

        //bool availability()
      
};

class Tournament {
    private:
        string participants[N];
        string team_name;
        int sports_type;
        int venue;
        string badmintonCategoryname;
        int totPlayer;
        Equipment eqp; //showing composition

        friend class Person;

    public:
        Tournament(){}

        Tournament (int _type, int _venue)
        {
            sports_type = _type;
            venue = _venue;
            
        }
        void

        void setParticipants() // set the total player based on the category chose by user
        {
            int choiceBadminton;

            if(sports_type == 1)
            {
                choiceBadminton = displayBadmintonMenu();

                if (choiceBadminton == 1)
                {
                    setCategoryName("Men's Single");
                    totPlayer = 1;
                }
                else
                if (choiceBadminton == 2)
                {
                    setCategoryName("Men's Doubles");
                    totPlayer = 2;
                }
                else
                if (choiceBadminton == 3)
                {
                    setCategoryName("Mixed Doubles");
                    totPlayer = 2;
                }
                else
                if (choiceBadminton == 4)
                {
                    setCategoryName("Women's Doubles");
                    totPlayer = 2;
                 }
                else
                {
                    setCategoryName("Women's Single");
                    totPlayer = 1;
                }
            }

            system("cls");
            cout << "\n================[FILLING PARTICIPANTS NAME]====================="<<  endl ;

            for(int i =0 ;i < totPlayer ; i++)
            {
                cout << "Player #" << i+1 << " -> ";
                cin  >> participants[i];
                cout <<  endl;
            }

            cout << "Thank you for filling the participants' name " << endl;
        }
        void bookEquipment()
        {
            double Total = eqp.display();
        }
        void display()
        {   
            string name;

            if (sports_type == 1)
            {
                name = "BADMINTON";
                cout << "SPORT'S NAME   : " << name << endl;
                cout << "CATEGORY       : " << badmintonCategoryname << endl;
                cout << "VENUE          : " << venue << endl    
                     << "FEE            : ";
                
                //Print name of all participants that has been registered
                cout << "==============[ PARTICIPANTS ]===============" << endl;
                for (int i = 0; i< totPlayer ; i++)
                {
                    cout << "(" << i + 1 << ")" <<  toupper(participants[i]) << endl;
                }

                cout << "==============[ ITEMS BOOKED ]===============" << endl;      
                cout << "ITEMS BOOKED   : " << eqp.getEtype(1) << endl;
                cout << ""
                
                 
            }
            else
            {
                name = "FUTSAL";
                cout << "SPORT'S NAME   : " << name << endl;
                cout << "CATEGORY       : " << badmintonCategoryname << endl;
                cout << "VENUE          : " << venue << endl    
                     << "FEE            : ";
                
                //Print name of all participants that has been registered
                cout << "==============[ PARTICIPANTS ]===============" << endl;
                for (int i = 0; i< 7 ; i++) // Size for futsal player is fixed which is 7
                {
                    cout << "(" << i + 1 << ")" <<  toupper(participants[i]) << endl;
                }

                cout << "==============[ ITEMS BOOKED ]===============" << endl;
                cout << "ITEMS BOOKED   : " << eqp.getEtype(0) << endl;

            }

        }
};


void displayType()
{
    system("cls");
    int choice;

    cout << "\n===============[SPORT TYPE]================="<< endl;
    cout << "1) Badminton\n"
         << "2) Futsal\n";

    cin >> choice;

    return choice;
}
int displayVenue(int type)
{
    int choice;

    if(type == 1)
    {
        system("cls");

        cout<< "Badminton Hall: \n\n"<<endl;
        cout<< "1) Kolej Tun Dr Ismail Badminton Hall\n"
            << "2) Kolej Tuanku Canselor Badminton Hall\n"
            << "3) Kolej 9&10 Badminton Hall\n"
            << "4) Kolej Tun Razak Badminton Hall\n"
            << "5) Kolej Rahman Putra Badminton Hall\n\n";

        cout<< "Enter your venue -> ";
        cin >> choice;
    }
    else
    if(type == 2)
    {
        system("cls");
        
        cout<< "Futsal Court: \n\n"<<endl;
        cout<< "1) Kolej Tun Dr Ismail Futsal Court\n"
            << "2) Kolej Tuanku Canselor Futsal Court\n"
            << "3) Kolej 9&10 Futsal Court\n"
            << "4) Kolej Tun Razak Futsal Court\n"
            << "5) Kolej Rahman Putra Futsal Court\n\n";

        cout<< "Enter your venue -> ";
        cin >> choice;
    }
    
    return choice;
}
int displayFeatures()
{
    int choice;
			
    cout << "\n===============[ FEATURES ]================="<< endl;
    
    cout << " press <1> for Register the tournament\n"
         << " press <2> for Printing all the registered tournament\n" 
         << " press <3> for Exit\n";
    cin>> choice;

    return choice; 

}
int displayMainMenu() // Stand Alone Function
{
    int choice;
			
    cout << "\n===============[MAIN MENU]================="<< endl;

    cout << " press <1> for Login to the system\n"
         << " press <2> for Register new account in this system\n";

    cin>> choice;

    return choice; 
}
int displayBadmintonMenu() 
{
    int choice;

    system("cls");

    cout << "\n=============== [ BADMINTON ] ================="<< endl;

    cout << " press <1> if the category is Men's single\n"
         << " press <2> if the category is Men's doubles\n" 
         << " press <3> if the category is Mixed doubles\n"
         << " press <4> if the category is Women's Doubles\n"
         << " press <5> if the category is Women's single\n";
    cin  >> choice;
    
    return choice; 
}
void displayFutsalMenu() // Stand Alone Function
{
    int choice;

    cout << "\n=============== [ FUTSAL ] ================"<< endl;

    cout << " Disclaimer : For Futsal tournament, we already set the total players\n "
         << " that is needed to fill in is 7 players in total " << endl;
}
int displayCategory() // Stand Alone Function
{
    int choice;

    cout << "\n=============== [ CATEGORY ] ================="<< endl;

    cout<< " press <1> if UTM Student\n"
        << " press <2> if UTM Staff\n" 
        << " press <3> if non UTM Student\n";
    cin>> choice;

    return choice;
}





class Person
{
    protected:
        string id,
               name,
               password;
        Tournament *tournament_list[10]; // showing Aggregation
        int numTournament;

    public:
        Person()
        {
            numTournament = 0;
        }
        Person(string _id = 0,string _name = 0,string _password = 0 ) 
        {
            id = _id;
            name = _name;
            password = _password;
        }
        void register_sport(Tournament *list) // Function for register the tournament
        {
            tournament_list[numTournament++] = list; // Update the number of tournament user registered
        }
        void displayAll()
        {
            cout << "-------------------- DETAILS  --------------------" << endl;
            cout << "NAME      : " << name << endl
                 << "ID        : " << id << endl;

            for(int i = 0; i< num_t ; i++)
            {
                cout << "-------------------- TOURNAMENT " << i+1 << " --------------------" << endl;
                tournament_list[i]->display();
            }
        }

        //Mutator Of The Class Person 
        void setID(string _id)
        {
            id = _id;
        }
        void setName(string _name)
        {
            name = _name;
        }   

        // Other Methods
        virtual void registration() = 0; //Polymorphism (Step 1)
        bool login() = 0; //Polymorphism (Step 1)
        void createPassword();
        
};
// Will be call when user want to create the password in the registration function
void Person::createPassword() 
{	
    do
    {
        int pSize;

        cout << "\t PASSWORD  : " ;//cout << "Create your password: (8 to 10 characters, must be alphanumeric. case and space sensitive)\n"

        cin.ignore();
        getline(cin, password);
        pSize = password.size();

        bool status;
        
        //Check whether the password created is alphanumeric
        for(int i = 0; i < pSize; i++)
        {
            if(isalpha(password[i]))
                bool alpha = true;
            if(isdigit(password[i]))
                bool digit = true;
        }
        
        //Control no. of characters of password
        if(pSize < 8 || pSize > 10)
        {
            cout << "\nSTATUS: ";
            cout << "\n   Password is too short or too long! Please re-enter a new password.\n";
            getch();
            
            status = false;
        }
    } while (status == false);      
}
// Will be use to check the status of the password entered by the user

// Class UTM Student that is the child class to the Person Class
class UTMstud:public Person {
     private:
       string matricNum;

    public:
        UTMstud(){}

        void registration()
        {
            
            system("cls");

            cout << "\t    **   **  ******  ****    ***     *******  ******   **   **  ******   ******  ****  ** ****** "<< endl;
            cout << "\t    **   **    **    ** ** ** **     **         **     **   **  **   **  **      ** ** **   **   "<< endl; 
            cout << "\t    **   **    **    **  ***  **     *******    **     **   **  **   **  ******  **  ****   **   "<< endl; 
            cout << "\t    **   **    **    **       **          **    **     **   **  **   **  **      **   ***   **   "<< endl; 
            cout << "\t    *******    **    **       **     *******    **      *****   ******   ******  **    **   **   "<< endl; 

            cout << "\t\t    ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t\t    **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t\t    ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t\t         ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t\t    ******* **  ******  **     ***        ******  **"      << endl; 

            cout << "\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
	        cout << " " << setfill('=') << setw(124);	

            //Ask for user to input their name            
            cout << "\t\t\t\t   ENTER NAME : ";
            getline(cin,name);
    
            //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
        	cout << "\t\t\t\t * 9 characters\n\t\t\t\t * Case insensitive\n\t\t\t\t * eg : A21EC0011 " << endl << endl <<endl; 
	        cout << "\t ENTER YOUR MATRIC NUMBER : ";
	        cin  >> matricNum;

            int size = matricNum.size();
            
            //Input Validation for matric number
            do
            {
                cout << "INVALID FORMAT OF MATRIC NUMBER!!" << endl
                     << "PLEASE ENTER AGAIN !!" << endl;

                 cout << "\t ENTER YOUR MATRIC NUMBER : ";
	             cin  >> matricNum;
            }while(size == 8);

            setID(matricNum); // Set the Id in the parent class
        }


        // Will be call to check the status of id entered by the user
        bool login()
        {
            bool status_Password;
            bool status_Id;

            cout << endl << endl; 
	        cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
   		         << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
   		         << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
		         << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
		         << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;
		
            cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";
	        cout << " " << setfill('=') << setw(104);	
	        cout << "\n\n"; 
	        cout << "\t ID       : ";
	        cin  >> matricNum;
	        cin.ignore();
	        cout << "\t Password : ";
	        getline(cin, password);	

            //Control no. of characters of username
            size = id.size();

            if(size == 8)
                cout <<" (VALID)"<<endl;
                status_Id = true;
            else
            {
                cout << "\nSTATUS: ";
                cout << "\nINVALID ID !! BACK TO REGISTRATION PAGE ";
            }
        
            status_Password = verificaion_Password();

            if(status_Id == true && status_Password == true)
                return true;
            else
                registration();

        }     
};

int main()
{
    Tournament tournament;
    Person *personObj;  //Person pointer object
    Person person2;     //Person object
    UTMstud utmstudObj; //UTMstud object

    int choiceCategory;
    int choiceMain;
    int choiceFeature;
    int choiceType;
    int choiceCategoryBadminton;
    int choiceVenue;

    bool statusLogin;

    // Get the users'choice for Main Menu
    choiceMain = displayMainMenu();

    while(choiceMain >= 1 || choiceMain < 4)
    {
        // Get the user choice for category of user (either UTM Student, UTM Staff or Non-UTM)
        choiceCategory = displayCategory();
        if(choiceCategory == 1)
            personObj=&utmstudObj;

        switch (choiceMain)
        {
        //Log In to the system
        case 1:
            //Go to the log in menu
            statusLogin = personObj->login(); //If the user did not register  go to login menu then it will be directly go to registration menu.

            if(statusLogin == true)
            {
                
                //Get the users's choice for features ( [1. REGISTER THE TOURNAMENT ] [2. PRINT THE REPORT ] )
                choiceFeature = displayFeatures();

                while(choiceFeature == 1 && choiceFeature == 2)
                {
                    //Registration of the Tournament
                    if (choiceFeature == 1)
                    { 
                        //Dapatkan choice untuk type of sport ([1. BADMINTON ] [2. FUTSAL])
                        choiceType = displayType();
                    
                        if (choiceType == 1)// Badminton
                        {
                            choiceVenue = displayVenue(choiceType);

                            //Display Badminton Menu
                            choiceCategoryBadminton = displayBadmintonMenu();

                            Tournament temp(choiceType,choiceVenue);

                            //Set the participants based on the category chose by the user
                            temp.setParticipants();  

                            tournament = temp; 

                        }
                        else
                        if (choiceType == 2)// Futsal
                        {
                            choiceVenue = displayVenue(choiceType);

                            //Display Futsal Menu
                            choiceCategoryBadminton = displayFutsalMenu();

                            Tournament temp(choiceType,choiceVenue);

                            //Set the participants based on the category chose by the user
                            temp.setParticipants(); 

                            tournament = temp; 
                        } 
                        person2.register_sport(tournament);
                    }
                    else
                    if (choiceFeature == 2) // Print the report onto the screen
                    {
                        person2.displayAll();
                    }
                    choiceFeature = displayFeatures();
                }
            }
            break;
            
        //Register to the system
        case 2:
            break;


        //Exit the program
        case 3:
            break;

            
        //Invalid Input
        default
            break;

        }
        

    }
    
    
    
    return 0;

    system("pause");
}
