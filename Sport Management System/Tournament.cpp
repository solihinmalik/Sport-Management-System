#include<iostream>
#include<string>
#include <iomanip>

using namespace std;


class Tournament 
{
    private:
        string participants[10];
        string team_name;
        int sports_type;
        int venue;
    

    public:
        Tournament(){}
    
        //Accessors
        int getVenue()
        {
            return venue;
        }
        int getType()
        {
            return sports_type;
        }
        void getName(int num)
        {
            participants[num];

            cout << endl;

            for(int i = 0; i < num ; i++)
            {
                cout << left << setw(5) <<""<<"(" << i+1 << ")"<<participants[i] << endl;
            }
        }
        //Mutator
        void input(int num)
        {
            system("cls");
            cin.ignore();
            cout << "\n==================[FILLING PARTICIPANTS NAME]====================="<<  endl ;
            cout << endl;
            participants[num];

            for(int i = 0 ; i < num ; i++)
            {
                cout << "Player #" << i+1 << " -> ";
                getline(cin,participants[i]);
            }

            cout << "Thank you for filling the participants' name " << endl;
        }
        void type()
        {
            system("cls");

            cout << "\n===============[SPORT TYPE]================="<< endl;
            cout<< "1) Badminton\n"
                << "2) Futsal\n";

            cout << "\nChoice -> ";
            cin >> sports_type;
        }
        void displayVenue()
        {

            if(sports_type == 1)
            {
                system("cls");

                cout<< "Badminton Hall: \n"<<endl;
                cout<< "1) Kolej Tun Dr Ismail Badminton Hall\n"
                    << "2) Kolej Tuanku Canselor Badminton Hall\n"
                    << "3) Kolej 9&10 Badminton Hall\n"
	                << "4) Kolej Tun Razak Badminton Hall\n"
	                << "5) Kolej Rahman Putra Badminton Hall\n\n";

                cout<< "Enter your venue -> ";
                cin >> venue;
            }
            else
            if(sports_type == 2)
            {
            	system("cls");
            	
                cout<< "Futsal Court: \n"<<endl;
                cout<< "1) Kolej Tun Dr Ismail Futsal Court\n"
                    << "2) Kolej Tuanku Canselor Futsal Court\n"
                    << "3) Kolej 9&10 Futsal Court\n"
	                << "4) Kolej Tun Razak Futsal Court\n"
	                << "5) Kolej Rahman Putra Futsal Court\n\n";

                cout<< "Enter your venue -> ";
                cin >> venue;
            }
        }
        int displayMainMenu();
        int displayBadmintonMenu();
        void displayFutsalMenu();
};

int Tournament::displayMainMenu()
{
    int choice;

            cout << "\n===============[MAIN MENU]================="<< endl;
    
            cout << " press <1> for Register for a tournament\n"
                 << " press <2> for Listing all of the registered tournament\n" 
                 << " press <3> for Exit the program\n";

            cout << "\nChoice -> ";
            cin>> choice;

            return choice; 
}
int Tournament::displayBadmintonMenu()
{
    int choice;

            system("cls");

            cout << "\n=============== [ BADMINTON ] ================="<< endl;
    
            cout<< " press <1> if the category is Men's single\n"
                << " press <2> if the category is Men's doubles\n" 
                << " press <3> if the category is Mixed doubles\n"
                << " press <4> if the category is Women's Doubles\n"
                << " press <5> if the category is Women's single\n";

            cout << "\nChoice -> ";
            cin>> choice;

            return choice; 
}
void Tournament::displayFutsalMenu()
{
    int choice;

            cout << "\n============================ [ FUTSAL ] ============================"<< endl;
    
            cout << " Disclaimer : For Futsal tournament, we already set the total players\n "
                 << " that is needed to fill in is 7 players in total " << endl;
}

int main()
{
    Tournament p1;
    int choiceMain;
    do
    {
        if(choiceMain ==1)
            system("cls");

        choiceMain = p1.displayMainMenu();
        
        string categoryName;
        int num;
        double fee;
        int category;

        if(choiceMain == 1)
        {
            p1.type(); // Get the type of sport tha they want to register

            if(p1.getType()==1)//Badminton
            {

                category = p1.displayBadmintonMenu(); //get the category of competition in Badminton

                if (category == 1)
                {
                    num = 1;
                    p1.input(num);
                    categoryName = "Men's single";
                    fee = 10.00;
                }
                else
                if (category == 2)
                {
                    num =2;
                    p1.input(num);
                    categoryName = "Men's doubles";
                    fee = 20.00;
                }
                else
                if (category == 3)
                {
                    num = 2 ;
                    p1.input(num);
                    categoryName = "Mixed doubles";
                    fee = 20.00;
                }
                else
                if (category == 4)
                {
                    num = 2;
                    p1.input(num);
                    categoryName = "Women's Doubles";
                    fee = 20.00;
                }
                else
                {
                    num = 1;
                    p1.input(num);
                    categoryName = "Women's single";
                    fee = 10.00;
                }
                
                p1.displayVenue();

            }
            else //Futsal
            {
                p1.displayFutsalMenu(); //display Futsal Menu

                p1.input(7);
                
                p1.displayVenue();
            }

        }
        else
        if (choiceMain == 2)
        {
            string name;
            string venueName;
            if (category == 1)
                categoryName = "Men's single";
            else
            if (category == 2)
                categoryName = "Men's doubles";
            else
            if (category == 3)
                categoryName = "Mixed doubles";
            else
            if (category == 4)
                categoryName = "Women's Doubles";
            else
                categoryName = "Women's single";

            system("cls");
            if(p1.getType()==1)
            {
                name = "Badminton";

                if(p1.getVenue() == 1)
                {
                    venueName = "Kolej Tun Dr Ismail ";
                }
                else
                if (p1.getVenue()==2 )
                {
                    venueName = "Kolej Tuanku Canselor ";
                }
                else 
                if (p1.getVenue()==3)
                {
                    venueName = "Kolej 9&10 ";
                }
                else
                if (p1.getVenue() == 4)
                {
                    venueName = "Kolej Tun Razak ";
                }
                else
                venueName = "Kolej Rahman Putra ";

                cout << "\n---------------------------- SUMMARY --------------------------------" << endl;
                cout << "Name of the tournament : " << name << endl;
                cout << "Venue                  : " << venueName + "Badminton Hall" << endl;
                cout << "Category               : " << categoryName <<  endl;
                cout << "Fee                    : RM" << fee << endl << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                cout <<"List Of Participants" << endl;

                if (category == 1)
                {
                    int num = 1;
                    p1.getName(num);
                }
                else
                if (category == 2)
                {
                    num =2;
                    p1.getName(num);
                
                }
                else
                if (category == 3)
                {
                    num = 2 ;
                    p1.getName(num);
                    
                }
                else
                if (category == 4)
                {
                    num = 2;
                    p1.getName(num);
                }
                else
                {
                    num = 1;
                    p1.getName(num);
                }

            }
            else
            {
                name= "Futsal";
                
                p1.displayFutsalMenu();

                if(p1.getVenue() == 1)
                {
                    venueName = "Kolej Tun Dr Ismail ";
                }
                else
                if (p1.getVenue()==2 )
                {
                    venueName = "Kolej Tuanku Canselor ";
                }
                else 
                if (p1.getVenue()==3)
                {
                    venueName = "Kolej 9&10 ";
                }
                else
                if (p1.getVenue() == 4)
                {
                    venueName = "Kolej Tun Razak ";
                }
                else
                venueName = "Kolej Rahman Putra ";

                system("cls");

                cout << "\n------------------- SUMMARY ------------------------" << endl;
                cout << "Name of the tournament : " << name << endl;
                cout << "Venue                  : " << venueName + "Futsal Court" << endl;
                cout << "Fee                    : " << "RM60.00 " << endl << endl;
                cout << "------------------------------------------------------" << endl;

                cout <<"List Of Participants    :" << endl;
                num = 7;
                p1.getName(num);
            
            }
            char p;
            cout << "\nDo you want to go to the main menu ?" << endl;
                cout << "Answer (Y/N) -> ";
                cin >> p;

                if(p == 'N' || p == 'n')
                {
                    choiceMain == 3;
                    break;

                }
            system("cls");

        }
    }while (choiceMain != 3);
    
    cout << "\nThank you for using our system :) ";

    system("pause");

    return 0;
}



   
            cout << "\t\t\t       ******* ****** *******  ******  ****** " << endl;
            cout << "\t\t\t       **        **   **   **  **      **     " << endl; 
            cout << "\t\t\t       *******   **   *******  ******  ****** " << endl; 
            cout << "\t\t\t            **   **   **   **  **      **     " << endl; 
            cout << "\t\t\t       *******   **   **   **  **      **     " << endl << endl; 



            cout << "\t\t       ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t\t       **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t\t            ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t\t       ******* **  ******  **     ***        ******  **"      << endl; 




             
            cout << "\t\t\t       ***    **  *******  ***    **       **  **  ****** ***     ***  " << endl;
            cout << "\t\t\t       ** **  **  **   **  ** **  **       **  **    **   ** ** ** **  " << endl; 
            cout << "\t\t\t       **  ** **  **   **  **  ** **  **** **  **    **   **   *   **  " << endl; 
            cout << "\t\t\t       **   ****  **   **  **   ****       **  **    **   **       **  " << endl; 
            cout << "\t\t\t       **    ***  *******  **    ***       ******    **   **       **  " << endl << endl; 



            cout << "\t\t       ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t\t       **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t\t            ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t\t       ******* **  ******  **     ***        ******  **"      << endl; 