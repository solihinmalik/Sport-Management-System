#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <conio.h>


#define N 20
using namespace std;

class Tournament {
    private:
        string participants[N];
        string team_name;
        int sports_type;
        int venue;
        string badmintonCategoryname;
        int totPlayer;
    public:
        Tournament(){}
        
        //Mutators
        void setVenue (int choiceVenue)
        {
            venue = choiceVenue;
        }
        void setSportType(int choiceType)
        {
            sports_type = choiceType;
        }
        void setCategoryName(string name)
        {
            badmintonCategoryname = name;
        }
        void setParticipants(int choiceBadminton) // set the total player based on the category chose by user
        {
            if(sports_type == 1)
            {
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
                if(choiceBadminton == 5)
                {
                    setCategoryName("Women's Single");
                    totPlayer = 1;
                }
            }
            if(sports_type == 2)
            {
                totPlayer = 7;
            }
            system("cls");
            cout << "\n================[FILLING PARTICIPANTS NAME]====================="<<  endl ;

            cin.ignore();
            for(int i =0 ;i < totPlayer ; i++)
            {
                cout << "Player #" << i+1 << " -> ";
                getline(cin,participants[i]);
                cout <<  endl;
            }

            cout << "Thank you for filling the participants' name " << endl;
        }
        // Book the equipment
        // void bookEquipment()
        // {
        //     double Total = eqp.display();
        // }
        

        //Accesors
        int getVenue ()
        {
            return venue;
        }
        string getSportName()
        {
            if(sports_type == 1)
                return "Badminton";
            else
                return "Futsal";
        }
        string getCategoryName()
        {
            return badmintonCategoryname;
        }
        string getName(int index)
        {
            return participants[index];
        }
        int getSportType()
        {
            return sports_type;
        }
        void getParticipants()
        {
            cout << "\n\n=================[ PARTICIPANTS ]==================" << endl;
            for (int i = 0; i< totPlayer ; i++)
            {
                    cout << "(" << i + 1 << ")" <<  participants[i] << endl;
            }
        }
};
int displayType()
{
    system("cls");
    int choice;


    cout << "\t\t    ********  ******   ******    ******   ******   ******  **    **  ******   ******  "<<endl
         << "\t\t    **        **   *  **    **   **   *    **        **     **  **   **    *  **      "<<endl
         << "\t\t    ********  *****   **    **   *****     **        **       **     ******   ******  "<<endl
         << "\t\t          **  **      **    **   **  **    **        **       **     **       **      "<<endl
         << "\t\t    ********  **       ******    **   **   **        **       **     **       ******  "<<endl;

    cout << "\n\t\t\t\t\t1) Badminton\n"
         << "\t\t\t\t\t2) Futsal\n";

    cout << "\n\n"; 
    cout << "\n\n\t\t Choice ->"; 
    cin >> choice;

    return choice;
}
int displayVenue(int type)
{
    int choice;
    system("cls");

    cout << "\t\t  **        ** ******  ***   **  **    **  ******  "<<endl
         << "\t\t   **      **  **      ** ** **  **    **  **      "<<endl
         << "\t\t    **    **   ******  **  ****  **    **  ******  "<<endl
         << "\t\t     **  **    **      **    **  **    **  **      "<<endl
         << "\t\t       **      ******  **    **    ****    ******  "<<endl;

    if(type == 1)
    {

        cout<< "\t\t\tBadminton Hall: \n\n"<<endl;
        cout<< "\t\t\t1) Kolej Tun Dr Ismail Badminton Hall\n"
            << "\t\t\t2) Kolej Tuanku Canselor Badminton Hall\n"
            << "\t\t\t3) Kolej 9&10 Badminton Hall\n"
            << "\t\t\t4) Kolej Tun Razak Badminton Hall\n"
            << "\t\t\t5) Kolej Rahman Putra Badminton Hall\n\n";

        cout<< "\t\t\tEnter your venue -> ";
        cin >> choice;
    }
    else
    if(type == 2)
    {
        
        cout<< "\t\t\tFutsal Court: \n\n"<<endl;
        cout<< "\t\t\t1) Kolej Tun Dr Ismail Futsal Court\n"
            << "\t\t\t2) Kolej Tuanku Canselor Futsal Court\n"
            << "\t\t\t3) Kolej 9&10 Futsal Court\n"
            << "\t\t\t4) Kolej Tun Razak Futsal Court\n"
            << "\t\t\t5) Kolej Rahman Putra Futsal Court\n\n";

        cout<< "\t\t\tEnter your venue -> ";
        cin >> choice;
    }
    
    return choice;
}
int displayFeatures()
{
    system("cls");

    int choice;
	 cout << "\t\t  ******  ****** ******* ****** **    **  *******  ******  ******  "<< endl
          << "\t\t  **      **     **   **   **   **    **  **   **  **      **      "<< endl
          << "\t\t  ******  ****** *******   **   **    **  *******  ******  ******  "<< endl
          << "\t\t  **      **     **   **   **   **    **  **   **  **          **  "<< endl
          << "\t\t  **      ****** **   **   **     ****    **    ** ******  ******  "<< endl << endl;
    
    cout << "\t\t\t press <1> for Register the tournament\n"
         << "\t\t\t press <2> for Printing all the registered tournament\n" 
         << "\t\t\t press <3> for Exit\n";

    cout<< "\t\t\tEnter your choice -> ";
    cin>> choice;

    return choice; 

}
int displayMainMenu() // Stand Alone Function
{
    system("cls");
    int choice;

    cout  << "\t\t  ***    ****  ******  ***    **   **    **   "<< endl
          << "\t\t  ** ** ** **  **      ** **  **   **    **   "<< endl
          << "\t\t  **  **   **  ******  **  ** **   **    **   "<< endl
          << "\t\t  **       **  **      **   ****   **    **   "<< endl
          << "\t\t  **       **  ******  **    ***     ****     "<< endl << endl;

    cout << "\t\t<1> for Login to the system\n"
         << "\t\t<2> for Register new account in this system\n";

    cout<< "\t\t\tEnter your choice -> ";
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
    system("cls");

    int choice;

    cout << "\n=============== [ FUTSAL ] ================"<< endl;

    cout << " Disclaimer : For Futsal tournament, we already set the total players\n "
         << " that is needed to fill in is 7 players in total " << endl;
}
int displayCategory() // Stand Alone Function
{
    system("cls");

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
        //Variables that is used to hold the id and the password of the user when they register
        string checkId; 
        string checkPassword;

        Tournament *list[10];
        int count;

    public:

        Person(string _id = "",string _name = "",string _password = "",string _checkId = "",string _checkPassword = "" ) 
        {
            count = 0;

            id = _id;
            name = _name;
            password = _password;
            checkId = _checkId;
            checkPassword = _checkPassword;
        }
        void assignTournament(Tournament *t)
        {
            list[count++] = t;
        }

        //Mutator Of The Class Person 
        void setID(string _id)
        {
            id = _id;
        }
        void setCheckID(string _tempID)
        {
            checkId = _tempID;
        }
        void setCheckPassword(string _pass)
        {
            checkPassword = _pass;
        }

        void setName(string _name)
        {
            name = _name;
        }   
        //Accessors of the class Person
        string getName()
        {
            return name;
        }
        string getId()
        {
            return id;
        }
        void displaySummarry()
        {
            string venueName;
            
            system("cls");

            for(int i = 0 ; i < count ; i++)
            {
                if (list[i]->getVenue() == 1)
                {
                    venueName = "Kolej Tun Dr Ismail ";
                }
                else 
                if (list[i]->getVenue() == 2)
                {
                    venueName = "Kolej Tuanku Canselor ";
                }
                else
                if (list[i]->getVenue() == 3)
                {
                    venueName = "Kolej K9 & K10 ";
                }
                else
                if (list[i]->getVenue() == 4)
                {
                    venueName = "Kolej Tun Razak ";
                }
                else
                {
                    venueName = "Kolej Rahman Putra";
                }
                if(i == 0)
                {
                        cout << "====================[ DETAILS ]======================" << endl;
                        cout << "NAME      : " << name << endl
                             << "ID        : " << id << endl;
                }
                
                cout << "\n\n===================[ TOURNAMENT " << i + 1 << " ]===================" << endl;
                string name;

                if (list[i]->getSportType() == 1)
                {
                    cout << "SPORT'S NAME   : " << list[i]->getSportName() << endl;
                    cout << "CATEGORY       : " << list[i]->getCategoryName() << endl;
                    cout << "VENUE          : " << venueName + "Badminton Hall" << endl    
                         << "FEE            : " << endl;

                    
                    //Print name of all participants that has been registered
                    list[i]->getParticipants();

                    // cout << "==============[ ITEMS BOOKED ]===============" << endl;      
                    // cout << "ITEMS BOOKED   : " << eqp.getEtype(1) << endl;
                    // cout << ""     
                }
                else
                {
                    cout << "SPORT'S NAME   : " << list[i]->getSportName() << endl;
                    cout << "VENUE          : " << venueName + "Futsal Court" << endl    
                         << "FEE            : ";
                    
                    // Print name of all participants that has been registered
                    list[i]->getParticipants();

                    // cout << "==============[ ITEMS BOOKED ]===============" << endl;
                    // cout << "ITEMS BOOKED   : " << eqp.getEtype(0) << endl;
                }

            }
        }
        // Other Methods
        virtual void registration() = 0; //Polymorphism (Step 1)
        virtual bool login() = 0; //Polymorphism (Step 1)
        void createPassword();     
};

// Will be call when user want to create the password in the registration function
void Person::createPassword() 
{	
    bool status;
    do
    {
        int pSize;

        cout << "\nCreate your password (8 to 10 characters, must be alphanumeric. case and space sensitive)\n";
        cout << "PASSWORD                               : " ;

        cin.ignore();
        getline(cin, checkPassword);
        pSize = checkPassword.size();
        
        //Check whether the password created is alphanumeric
        for(int i = 0; i < pSize; i++)
        {
            if(isalpha(checkPassword[i]))
                bool alpha = true;
            if(isdigit(checkPassword[i]))
                bool digit = true;
        }
        
        //Control no. of characters of password
        if(pSize < 8 || pSize > 10)
        {
            cout << "\nSTATUS: ";
            cout << "\n   Password is too short or too long! Please re-enter a new password.\n";

            status = false;
        }
        cout << "REGISTRATION SUCCESS ! BACK TO MAIN PAGE , ENTER ANY KEY TO CONTINUE...";
        getch();

        status = true;

    } while (status != true);    

    setCheckPassword(checkPassword);  
}


// Class UTM Student that is the child class to the Person Class
class UTMstud:public Person {
    private:
       string matricNum;

    public:
        UTMstud(){}

        void registration()
        {
            
            system("cls");

            cout << "\t **   **  ******  ****    ***     *******  ******   **   **  ******   ******  ****  ** ****** "<< endl;
            cout << "\t **   **    **    ** ** ** **     **         **     **   **  **   **  **      ** ** **   **   "<< endl; 
            cout << "\t **   **    **    **  ***  **     *******    **     **   **  **   **  ******  **  ****   **   "<< endl; 
            cout << "\t **   **    **    **       **          **    **     **   **  **   **  **      **   ***   **   "<< endl; 
            cout << "\t *******    **    **       **     *******    **      *****   ******   ******  **    **   **   "<< endl << endl; 

            cout << "\t\t       ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t\t       **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t\t            ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t\t       ******* **  ******  **     ***        ******  **"      << endl; 

            cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT\n";
	        
            cin.ignore();

            //Ask for user to input their name            
            cout << "\n\nENTER NAME ( in capital letters )         : ";
            getline(cin,name);

            setName(name); // set the name 
    
            //Ask for user to input their id (for UTM Student is MATRIC NUMBER) 
	        cout << "ENTER MATRIC NUMBER ( eg : A21EC0011 )    : ";
	        cin  >> matricNum;

            int size = matricNum.size();
            
            //Input Validation for matric number
            while(size != 9)
            {
                cout << "INVALID FORMAT OF MATRIC NUMBER!!" << endl
                     << "PLEASE ENTER AGAIN !!" << endl;

                cout << "ENTER YOUR MATRIC NUMBER : ";
	            cin  >> matricNum;
	             
	            int size = matricNum.size();
	             
            }
            createPassword();

            setCheckID(matricNum); // Set the check Id in the parent class
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            system("cls");

            bool status;
            bool statusAll;
            int size;

            cout << endl << endl; 
	        cout << "\t\t\t    **        ******   *****   **  ***     **  "<< endl
   		         << "\t\t\t    **       **    ** **       **  ** **   **  "<< endl
   		         << "\t\t\t    **       **    ** **   *** **  **  **  **  "<< endl
		         << "\t\t\t    **       **    ** **    *  **  **    ****  "<< endl
		         << "\t\t\t    ********  ******   ******  **  **     ***  "<< endl << endl;
		
            cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n\n";	
            cout << " " << setfill('=') << setw(130);	
	        cout << "\n\n"; 
            do
            {
                cout << "\t\tID       : ";
	            cin  >> id;

	            cin.ignore();
	            cout << "\t\tPASSWORD : ";
	            getline(cin,password);

                if(id != checkId || password != checkPassword)
                {
                    status = false;
                    cout << "\n\t\tPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                }	
                else
                    status = true;

            }while (status == false);

            statusAll = true;

            cout << "\n\t\tLOG IN SUCCESS !" << endl;
            getch();
        
            return statusAll;
        }    
};


int main()
{
    Tournament *tournament;
    Tournament obj[10];// Maximum daftar 10
    Person *ptr;
    UTMstud utmstudObj; //UTMstud object

    int choiceCategory;
    int choiceMain;
    int choiceFeature;
    int choiceType;
    int choiceCategoryBadminton;
    int choiceVenue;
    bool statusLogin;
    int count = 0;
    
    // Get the user choice for category of user (either UTM Student, UTM Staff or Non-UTM)
    choiceCategory = displayCategory();
    if(choiceCategory == 1)
    	ptr = &utmstudObj;
    // else
    // if (choiceCategory == 2)
    //     ptr = &staffobj;
    
    A:
        // Get the users'choice for Main Menu
        choiceMain = displayMainMenu();

        switch (choiceMain)
        {
            //Log In to the system
            case 1:

                A1 :
                    //Go to the log in menu
                    statusLogin = ptr->login(); //If the user did not register  go to login menu then it will be directly go to registration menu.

                    if(statusLogin == true)
                    {
                        //Get the users's choice for features ( [1. REGISTER THE TOURNAMENT ] [2. PRINT THE REPORT ] )
                        choiceFeature = displayFeatures();
            
                        while(choiceFeature == 1 || choiceFeature == 2)
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

                                    obj[count].setSportType(choiceType);

                                    obj[count].setVenue(choiceVenue);
            
                                    //Set the participants based on the category chose by the user
                                    obj[count].setParticipants(choiceCategoryBadminton);  
            
                                }
                                else
                                if (choiceType == 2)// Futsal
                                {
                                    choiceVenue = displayVenue(choiceType);
            
                                    //Display Futsal Menu
                                    displayFutsalMenu();
            
                                    obj[count].setSportType(choiceType);

                                    obj[count].setVenue(choiceVenue);
            
            
                                    //Set the participants based on the category chose by the user
                                    obj[count].setParticipants(7); 
            
                                } 
                    
                                tournament = &obj[count];

                                ptr->assignTournament(tournament);

                                count++;

                                
                            }
                            else
                            if (choiceFeature == 2) // Print the report onto the screen
                            {
                                ptr->displaySummarry();

                                getch();
                            }

                            choiceFeature = displayFeatures();
                        }
                    }
                    else
                    {
                        statusLogin = ptr->login();

                        //Get the users's choice for features ( [1. REGISTER THE TOURNAMENT ] [2. PRINT THE REPORT ] )
                        choiceFeature = displayFeatures();

                        while(choiceFeature == 1 || choiceFeature == 2)
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
            
                                    obj[count].setSportType(choiceType);

                                    obj[count].setVenue(choiceVenue);
            
            
                                    //Set the participants based on the category chose by the user
                                    obj[count].setParticipants(choiceCategoryBadminton);  
            
            
                                }
                                else
                                if (choiceType == 2)// Futsal
                                {
                                    choiceVenue = displayVenue(choiceType);
            
                                    //Display Futsal Menu
                                    displayFutsalMenu();
            
                                    obj[count].setSportType(choiceType);

                                    obj[count].setVenue(choiceVenue);
            
                                    //Set the participants based on the category chose by the user
                                    obj[count].setParticipants(8); // send any value  
                                } 

                                count++;

                                tournament = &obj[count];

                                ptr->assignTournament(tournament);
                            }
                            else
                            if (choiceFeature == 2) // Print the report onto the screen
                            {
                                ptr->displaySummarry();

                                getch();

                            }

                            choiceFeature = displayFeatures();
                        }

                    }
                    break;
                
            //Register to the system
            case 2:

                //User will be register in our system
                ptr->registration();

                goto A;
                
                break;

            //Exit the program
            case 3:

                cout << "THANK YOU FOR USING OUR SYSTEM :)";
                break;

                
            //Invalid Input
            default:

                cout << "INVALID INPUT ! WILL GO DIRECTLY TO MAIN MENU PAGE ! PRESS ANY KEY TO CONTINUE " << endl;
                getch();

                goto A;
                
                break;

            }

    system("pause");

    return 0;
}
