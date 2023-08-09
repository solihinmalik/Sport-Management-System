#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

#define N 20
using namespace std;


class Payment
{
   private:
   int discountFee;
   bool statusA;
   double amount,
          amount2,
          amount3,
          fee;

   public:
   
   Payment() 
   {
    amount2 = 0;
   }
   
    // Accessor to get the value of fee
   double getFee(int sport_type,string categoryName)
   { 

        if(sport_type == 1)
        {
            if (categoryName == "Men's Single")
                fee = 10;    
            else 
            if (categoryName == "Men's Doubles")
                fee = 20.00;
            else 
            if (categoryName == "Mixed Doubles")
                fee = 25.00;
            else 
            if (categoryName == "Women's Doubles")
                fee = 20.00;
            else
                fee = 10.00;
        }
        else
             fee = 30;

        return fee; 
    }
    double getDiscount( double total )
    {
        discountFee = total  - (total * 0.05);
    
        return discountFee;
    }
    void status_payment(double d) 
    {
        double balance = 0.0;
        double temp = 0.0;
          
        cout << fixed << setprecision(2);

        char ch;
        cout << "ARE YOU A UTM CITIZENS OR NOT (Y/N) : ";
        cin  >> ch;
        
        system("cls");

        if (ch == 'Y' || ch == 'y')
        {
            double dissTotal = getDiscount(d);
            cout << "AMOUNT THAT NEED TO BE PAID : " << dissTotal + fee << endl;  
            amount3 = dissTotal + fee;
        }
        else
        {
            cout << "AMOUNT THAT NEED TO BE PAID : " << d + fee << endl;
            amount3 = d + fee;
        }
                   
                cout << "AMOUNT YOU PAY              : RM";
                cin >> amount;
                temp = amount;

        do
        {
             if (amount >= amount3) {
                    cout << "STATUS PAYMENT              : PAID\n";
                    balance = amount - amount3;
                    cout << "YOUR BALANCE                : RM" << balance << endl;
                    statusA = true;
                }
                else
                {
                    cout << "STATUS PAYMENT              : UNPAID\n\n"
                         << "NOTES : YOU NEED TO ENTER MORE MONEY " << endl;
                    
                    cout << "AMOUNT YOU PAY              : RM";
                    cin >> amount2;

                    temp = temp + amount2;
                    statusA = false;
                    amount = temp;

                    getch();
                }  
        }while(statusA == false);

        cout << "THANK YOU FOR PAYING WITH US :) PRESS ANY KEY TO CONTINUE" << endl;
        getch();

    }
    
    void displayInvoice()
    {
        if(statusA == true)
        {
            cout << "              STATUS         : PAID " << endl
                 << "	      TOTAL PAYMENT  : RM" << amount3 << endl
                 << "	      AMOUNT PAID    : RM" << amount;
        }
        else
        {
            cout << "STATUS         : UNPAID " << endl
                 << "TOTAL PAYMENT  : RM" << amount3 + fee << endl;
        }
        
    }
    
};
class Equipment
{
    private:
        int stockF; //futsalball
        int stockR; //Racket 
        int stockS; //shuttlecock
        int stockG; //shin Guard
        int quantity1,quantity2, eqptypeF, eqptypeB, cont;
        double totalAll;

        
        Payment pay; 
    
    public:
        
       
        Equipment() {
            stockF = 50;
            stockR = 70;
            stockS = 100;
            stockG = 85;
            totalAll = 0;
            quantity1 = 0;
            quantity2 = 0;
        }
        bool status()
        {
            bool status;

            if(totalAll > 0)
                status = true;
            else
                status = false;

            return status;
        }
        //display futsal
        void displayF() 
        { 
        
            do
            {
                
                system("cls");
                cout <<  "    *******   ******      **   **  ********  *******    ***    ****   *******  ***    **   ********    " << endl
                     <<  "    **       **    **     **   **    **      **     *   ** ** ** **   **       ** **  **      **       " << endl
                     <<  "    *******  **    **     **   **    **      *******    **  **   **   *****    **  ** **      **       " << endl 
                     <<  "    **       *   *** *    **   **    **      **         **       **   **       **  ** **      **       " << endl 
                     <<  "    *******   ***** **    *******  ********  **         **       **   *******  **  ** **      **       " << endl; 

                cout << " ========================================== [ EQUIPMENT TYPE ] ===================================== " << endl; 

                cout << "\nWHAT EQUIPMENT DO YOU WANT TO BOOK ?\n"
                     << "1. FUTSAL BALL    STOCKS   : " << "(" << stockF << ")" << endl
                     << "2. SHIN GUARD     STOCKS   : " << "(" << stockG << ")" << endl;
                     
                cout << "\nPLEASE SELECT        : ";
                cin >> eqptypeF;
                if(eqptypeF == 1)
                {
                    cout << "QUANTITY       : ";
                    cin >> quantity1;
                }
                else
                {
                    cout << "QUANTITY       : ";
                    cin >> quantity2;
                }
                
                double total = calcTotal();

                cout << "TOTAL PRICE        : RM " << total << endl<<endl;

                cout << "DO YOU WANT TO CONTINUE ? IF YES PRESSS <1>, IF NO PRESS <0> => ";
                cin >> cont;

                totalAll = totalAll + total;

            }
			while (cont == 1);

            cout << "\nTOTAL THAT IS NEEDED TO BE PAID IS RM" << totalAll << "\n" << endl;

        }
        // Display Badminton
        void displayB() 
        { 
            do
            {
                 
                system("cls");
                cout <<  "    *******   ******      **   **  ********  *******    ***    ****   *******  ***    **   ********    " << endl
                     <<  "    **       **    **     **   **    **      **     *   ** ** ** **   **       ** **  **      **       " << endl
                     <<  "    *******  **    **     **   **    **      *******    **  **   **   *****    **  ** **      **       " << endl 
                     <<  "    **       *   *** *    **   **    **      **         **       **   **       **  ** **      **       " << endl 
                     <<  "    *******   ***** **    *******  ********  **         **       **   *******  **  ** **      **       " << endl; 

                cout << " ========================================== [ EQUIPMENT TYPE ] ==================================== " << endl; 

                cout << "\nWHAT EQUIPMENT TYPE DO YOU WANT ?\n"
                     << "1. RACKET          STOCKS: " << "(" << stockR << ")" << endl
                     << "2. SHUTTLECOCK     STOCKS: " << "(" << stockS << ")" << endl;

                cout << "\nPLEASE SELECT    : ";     
                cin >> eqptypeB;
                if(eqptypeB == 1)
                {
                    cout << "QUANTITY       : ";
                    cin >> quantity1;
                }
                else
                {
                    cout << "QUANTITY       : ";
                    cin >> quantity2;
                }

                double total = calcTotal();

                cout << "TOTAL PRICE        : RM " << total << endl<<endl;

                cout << "DO YOU WANT TO CONTINUE ? IF YES PRESS <1> , IF NO PRESS <0> => ";
                cin >> cont;
                
                getch();
                
                totalAll = totalAll + total;


            }
            
			while (cont == 1);

            cout << "\nTOTAL FOR ALL EQUIPMENTS IS RM" << totalAll << "\n" << endl;

        }

        double calcTotal()
        {
            double total = 0;
            if (eqptypeF == 1) 
            {
                if(quantity1 < stockF)
                {
                    total = 5 * quantity1;
                    stockF -= quantity1;
                }
                else 
                    cout << "FUTSAL BALL IS OUT OF STOCKS" << endl; 
            
            }   
            else if(eqptypeF == 2) 
            {
                if(quantity2 < stockG) 
                {
                    total = 20 * quantity2;
                    stockG -= quantity2;
                }
                else 
                    cout << "SHIN GUARD IS OUT OF STOCKS" << endl;
            }
            
            else if (eqptypeB == 1) 
            {
               if(quantity1 < stockR)
               {
                    total = 10 * quantity1;
                    stockR -= quantity1;
                } 
                else
                    cout << "RACKET IS OUT OF STOCKS";       
            }
            else if(eqptypeB == 2) 
            {
                if(quantity2 < stockS)
               {
                    total = 10 * quantity2;
                    stockS -= quantity2;
                }  
                else
                    cout << "SHUTLECOCK IS OUT OF STOCKS";       
            }
            
            return total;
        
        }
        double getFee(int sport_type, string categoryName)
        {   
            double fee;
            
            // Showing composition between class Equipment and Payment
            fee = pay.getFee(sport_type, categoryName);

           

            return fee;    
        }

        void status_payment()
        {
            pay.status_payment(totalAll);
        }
        
        void displayInvoice (int sport_type)
        {
            if(sport_type == 1) // Badminton
            {
                cout << "\n              ================== [ INVOICE EQUIPMENT ] ================           " << endl;

                cout << "              NUMBER OF RACKET       : " << quantity1 << endl;
                cout << "              NUMBER OF SHUTTLECOCK  : "<< quantity2<<endl;

                cout << "\n              ==================== [ STATUS PAYMENT ] ================" << endl;
        
                pay.displayInvoice();
     
            }
            else
            {
                cout<< "\n              ================= [ INVOICE EQUIPMENT ] ================= " << endl;

                cout<< "              NUMBER OF FUTSALL BALL  : " << quantity1<<endl;
                cout<< "              NUMBER OF SHIN GUARD    : "<< quantity2<<endl;
                
                cout << "\n              ===================== [ STATUS PAYMENT ] =================" << endl;
        
                pay.displayInvoice();
                
            }
        }
};
class Time
{
    protected:
    	
    	int hour1, hour2, minute1,minute2;
    	int days, months,years;
        string status1,status2;
    
    public:
    
        void getDatestart(){
        	
        	char c;
            
        	cout<<"     \nDATE TODAY:[dd-mm-yyyy] :";
        	cin>>days>>c>>months>>c>>years;
		}
		
		void displayDate(){

            string month;
			
            if (months==1)
                month="January";

            else 
            if(months==2)
                month="February";

            else 
            if (months==3)
                month="March";

            else 
            if (months==4)
                month="April";

            else 
            if (months==5)
                month="May";

            else 
            if(months==6)
                month="June";

            else 
            if (months==7)
                month="July";

            else 
            if (months==8)
                month="August";

            else 
            if (months==9)
                month="September";

            else 
            if (months==10 )
                month="October";

            else 
            if (months==11)
                month="November";
            else
                month="December";


            cout <<"              DATE      : "<< days <<" "<< month <<" "<< years <<endl;
		} 	
        // Assume start time
        void get_StartTime()
        {   
            
            system("cls");
          cout  << "\t\t  ********   ******   ***    ****   *******   " << endl
                << "\t\t     **        **     ** ** ** **   **        " << endl 
                << "\t\t     **        **     **  **   **   *****     " << endl
                << "\t\t     **        **     **       **   **        " << endl 
                << "\t\t     **      ******   **       **   *******   " << endl;
                
        cout << "============================ [ START TIME ] ========================== " << endl;
        
            cout << "       NOTES : USE 12-HOUR SYSTEM FORMAT FOR BOTH START AND END TIME\n\n"
                 << "     \nENTER < START > TIME OF THE GAME : \n"
                 << "     \nHOUR     -> ";
            cin  >> hour1;
            cout << "     \nMINUTE   -> ";
            cin >>  minute1;

            string status;
            cout << "      \nAM or PM -> ";
            cin >> status1;

            if (status1 == "AM"||status1=="am")
            {
                cout << "          \nSTART TIME -> " << hour1 << ":" << minute1<< " AM" << endl;
            }
            else
            {
                 cout << "         \nSTART TIME -> " << hour1 << ":" << minute1 << " PM" << endl;
            }
               
        } 
        void get_EndTime()// Assume End time
        {   
            cout << "============================ [ END TIME ] ========================== " << endl;
            
            cout << "\t\t       \nENTER < END > TIME OF THE GAME   : \n"
                 << "\t\t       \nHOUR     -> ";
            cin  >> hour2;
            cout << "\t\t      \nMINUTE   -> ";
            cin >> minute2;

            cout << "\t\t       \nAM or PM -> ";
            cin >> status2;

            if (status2 == "AM"||status2=="am")
                cout << "\t\t       \nEND TIME -> " << hour2 << ":" << minute2 << " AM" << endl;
            else
                cout << "\t\t      \nEND TIME -> " << hour2 << ":" << minute2<< " PM" << endl;

        } 

        void displayTime()
        {  
            cout<<"              START TIME     : "<< hour1 <<":"<< minute1 << " " << status1 << endl;
            cout<<"              END TIME       : "<< hour2 <<":"<< minute2 << " " << status2 << endl;
        }
        
};
class Tournament {
    private:
        string participants[N];
        string team_name;
        int sports_type;
        int venue;
        string badmintonCategoryname;
        int totPlayer;
        Time t;     //showing composition
        Equipment eqp;  //showing composition

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
            cout << "\n\t\t================[FILLING PARTICIPANTS NAME]====================="<<  endl << endl;

            cin.ignore();
            for(int i =0 ;i < totPlayer ; i++)
            {
                cout << "\t\tPlayer #" << i+1 << "  -> ";
                getline(cin,participants[i]);
                cout <<  endl;
            }

            cout << "\n\n\tTHANK YOU FOR FILLING THE PARTICIPANTS' NAME. PRESS ANY KEY TO CONTINUE.." << endl;
            getch();
        }
        // will be call in Person class to access the time and time
        void displayTime()
        {
            t.displayTime();
        }
        void displayDate()
        {
             t.displayDate();
        }
        void setTime(){
            t.get_StartTime();      //showing composition
            cout<<endl;
            t.get_EndTime();
        }
        void setDate()
        {
            t.getDatestart();       //showing composition
        }
        // Composition with the class Equipment to get items from class Payment
        double getFee()
        {
            double fee;

            if (sports_type == 1)
                //Badminton
                fee = eqp.getFee(sports_type,badmintonCategoryname);
            else
                //Futsal
                fee = eqp.getFee(sports_type,badmintonCategoryname);

            return fee;
        }
        // Book the equipment (Composition with class Equipment to do the booking process)
        void bookEquipmentFutsal()
        {
            system("cls");
    
            eqp.displayF();

            eqp.status_payment();
        }
        
        void bookEquipmentBadminton()
        {
            system("cls");
            
            eqp.displayB();

            eqp.status_payment();
        }
        void displayInvoice()
        {
            eqp.displayInvoice(sports_type);
        }
    
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
            cout << "\t\n\n              ====================[ PARTICIPANTS ]=====================" << endl;
            for (int i = 0; i< totPlayer ; i++)
            {
                    cout << "\t      (" << i + 1 << ")   " <<  participants[i] << endl;
            }
        }
        bool getStatus()
        {
            return eqp.status();
        }
};
int displayType()
{
    system("cls");
    int choice;


    cout << "\t\t    ********  ******   ******    ******   *******   ******  **    **  ******   ******  "<<endl
         << "\t\t    **        **   *  **    **   **   *     **        **     **  **   **    *  **      "<<endl
         << "\t\t    ********  *****   **    **   *****      **        **       **     ******   ******  "<<endl
         << "\t\t          **  **      **    **   **  **     **        **       **     **       **      "<<endl
         << "\t\t    ********  **       ******    **   **    **        **       **     **       ******  "<<endl << endl;

    cout << "\t\t   =============================== [ SPORT TYPES ] =================================== "<< endl << endl ;

    cout << "\t\t                                    1) BADMINTON\n"
         << "\t\t                                    2) FUTSAL   \n\n";

    cout << "\t\t   =================================================================================== "<< endl << endl;

    cout << "\n\n\t\t                           CHOICE -> "; 
    cin >> choice;

    return choice;
}
int displayVenue(int type)
{
    int choice;
    system("cls");

    cout << "\t\t        **        ** ******  ***   **  **    **  ******  "<<endl
         << "\t\t         **      **  **      ** ** **  **    **  **      "<<endl
         << "\t\t          **    **   ******  **  ****  **    **  ******  "<<endl
         << "\t\t           **  **    **      **    **  **    **  **      "<<endl
         << "\t\t             **      ******  **    **    ****    ******  "<<endl;

    if(type == 1)
    {
        cout << "\t\t   ================ [ BADMINTON HALL ] =====================" << endl << endl;

        cout<< "\t\t              1) Kolej Tun Dr Ismail Badminton Hall\n"
            << "\t\t              2) Kolej Tuanku Canselor Badminton Hall\n"
            << "\t\t              3) Kolej 9&10 Badminton Hall\n"
            << "\t\t              4) Kolej Tun Razak Badminton Hall\n"
            << "\t\t              5) Kolej Rahman Putra Badminton Hall\n\n";

        cout<< "\t\t     ENTER YOUR VENUE -> ";
        cin >> choice;
    }
    else
    if(type == 2)
    {
        cout << "\t\t   ================ [ FUTSAL COURT ] =====================" << endl << endl;
        cout<< "\t\t            1) Kolej Tun Dr Ismail Futsal Court\n"
            << "\t\t            2) Kolej Tuanku Canselor Futsal Court\n"
            << "\t\t            3) Kolej 9&10 Futsal Court\n"
            << "\t\t            4) Kolej Tun Razak Futsal Court\n"
            << "\t\t            5) Kolej Rahman Putra Futsal Court\n\n";

        cout<< "\t\t     ENTER YOUR VENUE -> ";
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

    cout << "\t\t  ========================= [ FEATURES ] =========================" << endl << endl;

    cout << "\t\t  press <1> for REGISTER FOR A TOURNAMENT \n"
         << "\t\t  press <2> for PRINTING THE SUMMARY FOR REGISTERED TOURNAMENT\n" 
         << "\t\t  press <3> for EXIT\n\n";

    cout << "\t\t  ================================================================" << endl << endl;

    cout << "\t\t                ENTER YOUR CHOICE  -> ";
    cin>> choice;

    return choice; 

}
int displayMainMenu() // Stand Alone Function
{
    system("cls");
    int choice;

    cout  << "\t\t\t\t    ***    ****  ******  ***    **   **    **   "<< endl
          << "\t\t\t\t    ** ** ** **  **      ** **  **   **    **   "<< endl
          << "\t\t\t\t    **  **   **  ******  **  ** **   **    **   "<< endl
          << "\t\t\t\t    **       **  **      **   ****   **    **   "<< endl
          << "\t\t\t\t    **       **  ******  **    ***     ****     "<< endl << endl;

    cout << "\t\t\t\t  ============== [ MAIN MENU ] ================"<< endl<< endl;
    cout << "\t\t\t\t  <1> FOR LOGIN INTO THE SYSTEM\n"
         << "\t\t\t\t  <2> FOR REGISTER NEW ACCOUNT (1ST TIME USER)\n\n";
    cout << "\t\t\t\t  ============================================="<< endl << endl << endl;

    cout<< "\t\t\t\t      ENTER YOUR CHOICE -> ";
    cin>> choice;


    return choice; 
}
int displayBadmintonMenu() 
{
    int choice;


system("cls");
cout    << "\t\t  ********   *******   *******    ***    ****   ********   ***    **  ********   ******   ***    **   " << endl
        << "\t\t  **    **   **   **   **    **   ** ** ** **      **      ** **  **     **     **    **  ** **  **   " << endl
        << "\t\t  ********   *******   **    **   **  **   **      **      **  ** **     **     **    **  **  ** **   " <<  endl
        << "\t\t  **    **   **   **   **    **   **       **      **      **  ** **     **     **    **  **  ** **   " <<  endl
        << "\t\t  ********   **   **   *******    **       **   ********   **  ** **     **      ******   **  ** **   " <<  endl;
           

cout << "\t\t\t\n                =========================================== [ BADMINTON ] =========================================="<< endl << endl;

cout << " \t\t                            press <1> if the category is Men's single\n"
     << " \t\t                            press <2> if the category is Men's doubles\n" 
     << " \t\t                            press <3> if the category is Mixed doubles\n"
     << " \t\t                            press <4> if the category is Women's doubles\n"
     << " \t\t                            press <5> if the category is Women's single\n\n";

cout << "\t\t\t\t\t\n                ===================================================================================================="<< endl << endl;

    cout <<"\t\t\t\t                  PLEASE CHOOSE YOUR CATEGORY -> ";
    cin  >> choice;
    
    return choice; 
}
void displayFutsalMenu() // Stand Alone Function
{
 system("cls");

  cout << "\t\t         ******  **    **  ******  ******  *******  **      "<< endl
       << "\t\t         **      **    **    **    **      **   **  **      "<< endl
       << "\t\t         ******  **    **    **    ******  *******  **        "<< endl
       << "\t\t         **      **    **    **        **  **   **  **         "<< endl
       << "\t\t         **        ****      **    ******  **   **  *****   "<< endl << endl;
 
    int choice; 

    cout << "\n\t\t     ==================== [ FUTSAL ] ====================="<< endl << endl;

    cout << " \t\t       DISCLAIMER : FOR FUTSAL TOURNAMENT, WE ALREADY SET"  << endl
         << " \t\t                    THE TOTAL PLAYERS THAT ARE NEEDED "     << endl
         << " \t\t                    TO FILL IN IS 7 PLAYERS IN TOTAL " << endl;

    cout << "\n\t\t     ====================================================="<< endl << endl;


    cout << "\n\n\t\t PRESS ANY KEY TO CONTINUE...";
    getch();

}
int displayCategory() // Stand Alone Function
{
    system("cls");
    
    int choice;

    cout  << "\t\t    *****   *******   ********   ******    ******     ******   ******    **    **   " << endl
          << "\t\t  **        **   **      **      **       **         **    **  **   *     **  **    " << endl
          << "\t\t  **        *******      **      ****     **   ****  **    **  *****        **      " << endl 
          << "\t\t  **        **   **      **      **       **    **   **    **  **  **       **      " << endl
          << "\t\t    *****   **   **      **      ******    ******     ******   **   **      **      " << endl; 

    cout << "\n\t\t  ================================== [ CATEGORY ] =================================="<< endl << endl;
    cout << "\t\t                            press <1> if UTM Student\n"
         << "\t\t                            press <2> if UTM Staff\n" 
         << "\t\t                            press <3> if non UTM Student\n\n";
    cout << "\t\t  =================================================================================="<< endl << endl;

    cout<< "\t\t\t\t\t    ENTER YOUR CHOICE -> ";

    cin >> choice;

    return choice;
}
// Class Person that have aggregation with class Tournament and inheritance with UTMStudent, Staff and NonUTM
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
                    cout << "\t\t****** **  **  ***  *** ***  *** ****** ****** **    ** "<< endl
                         << "\t\t**     **  **  ** ** ** ** ** ** **  ** **  **  **  **   "<< endl
                         << "\t\t****** **  **  **    ** **    ** ****** ******    **     "<< endl
                         << "\t\t    ** **  **  **    ** **    ** **  ** **   **   **     "<< endl
                         << "\t\t****** ******  **    ** **    ** **  ** **    **  **     "<< endl << endl;

                    cout << "\t      =======================[ DETAILS ]========================" << endl;
                    cout << "\t      NAME      : " << name << endl
                         << "\t      ID        : "  << id << endl;
                    list[i]->displayDate();
                }
                
                cout << "\n\n\t      ===================[ TOURNAMENT " << i + 1 << " ]======================" << endl;
                string name;

                if (list[i]->getSportType() == 1)
                {
                    cout << "\t      SPORT'S NAME   : " << list[i]->getSportName() << endl;
                    cout << "\t      CATEGORY       : " << list[i]->getCategoryName() << endl;
                    cout << "\t      VENUE          : " << venueName + "Badminton Hall" << endl    
                         << "\t      FEE            : " << list[i]->getFee() <<endl;
                    list[i]->displayTime();
                    
                    //Print name of all participants that has been registered
                    list[i]->getParticipants();

                    if(list[i]->getStatus() == true)
                        list[i]->displayInvoice();     
                }
                else
                {
                    cout << "\t      SPORT'S NAME   : " << list[i]->getSportName() << endl;
                    cout << "\t      VENUE          : " << venueName + "Futsal Court" << endl    
                         << "\t      FEE            : " << list[i]->getFee() << endl;
                    list[i]->displayTime();
                                        
                    // Print name of all participants that has been registered
                    list[i]->getParticipants();

                     //cout<<"\tPress any key to continue->";
                    if(list[i]->getStatus() == true)
                        list[i]->displayInvoice();
                    
                }

            }
        }
        // Other Methods
        virtual void registration() = 0; //Polymorphism (Step 1)
        virtual bool login() = 0; //Polymorphism (Step 1)
        bool createPassword();     
};

// Will be call when user want to create the password in the registration function
bool Person::createPassword() 
{	
    bool status;
    
    int pSize;

    cout << "\n\n\tCreate your password: (8 to 10 characters, must be alphanumeric, case and space sensitive)\n";
    cout << "\tPASSWORD                          : " ;

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
        status = false;
    }
    
    status = true;

    setCheckPassword(checkPassword);  

    return status;
}

// Class UTM Student that is the child class to the Person Class
class UTMstud:public Person 
{
    private:
       string matricNum;

    public:
        UTMstud(){}

        void registration()
        {
            bool status;
            bool statusAll;
            
            do
            {
                system("cls");

                cout << "\t **   **  ******  ****    ***     *******  ******   **   **  ******   ******  ****  ** ****** "<< endl;
                cout << "\t **   **    **    ** ** ** **     **         **     **   **  **   **  **      ** ** **   **   "<< endl; 
                cout << "\t **   **    **    **  ***  **     *******    **     **   **  **   **  ******  **  ****   **   "<< endl; 
                cout << "\t **   **    **    **       **          **    **     **   **  **   **  **      **   ***   **   "<< endl; 
                cout << "\t *******    **    **       **     *******    **      *****   ******   ******  **    **   **   "<< endl<<endl; 

                cout << "\t\t       ******* **  *****   ***     **       **    ** *******  " << endl;
                cout << "\t\t       **      ** **       ** **   **       **    ** **     * " << endl; 
                cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******  " << endl; 
                cout << "\t\t            ** ** **    *  **    ****       ***  *** **       " << endl; 
                cout << "\t\t       ******* **  ******  **     ***        ******  **       " << endl; 

                cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
            
                cin.ignore();

                //Ask for user to input their name            
                cout << "\n\tENTER NAME ( in capital letters ) : ";
                getline(cin,name);

                setName(name); // set the name 
                
                //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
                cout << "\n\t* 9 characters\n\t* Case insensitive\n\t* eg : A21EC0011 " << endl << endl; 
                cout << "\tENTER YOUR MATRIC NUMBER           : ";
                cin  >> matricNum;

                int size = matricNum.size();
                
                status = createPassword();

                if(size != 9 || status == false )
                {
                    statusAll = false;
                    cout << "\n\tREGISTRATION FAILED ! PASSWORD OR MATRIC NUMBER WAS NOT ENTERED BASED ON THE CORRECT FORMAT." << endl;
                    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE... ";
                    getch();
                }
                else
                {
                    statusAll = true;

                }
                
                setCheckID(matricNum); // Set the check Id in the parent class

            }while(statusAll == false);

            cout << "\n\n\t\t\t REGISTRATION SUCCESS ! PRESS ANY KEY TO PROCEED..";

            
            getch();
            
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            bool status;
            bool statusAll;
            int size;
            do
            {
                system("cls");
                 cout << "   **   **  ******  ****    ***     *******  ******   **   **  ******   ******  ****  ** ****** "<< endl;
                 cout << "   **   **    **    ** ** ** **     **         **     **   **  **   **  **      ** ** **   **   "<< endl; 
                 cout << "   **   **    **    **  ***  **     *******    **     **   **  **   **  ******  **  ****   **   "<< endl; 
                 cout << "   **   **    **    **       **          **    **     **   **  **   **  **      **   ***   **   "<< endl; 
                 cout << "   *******    **    **       **     *******    **      *****   ******   ******  **    **   **   "<< endl;
                 cout << endl << endl; 

                 cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
                      << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
                      << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
                      << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
                      << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;
            
                cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n\n";;	
    
            
                cout << "\t\t\t\t ID        : ";
                cin  >> id;
                cin.ignore();

                cout<<endl;                
                cout << "\t\t\t\t PASSWORD  : ";
                getline(cin,password);

                if(id != checkId || password != checkPassword)
                {
                    status = false;
                    cout << "\n\tPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                    getch();
                }	
                else
                {
                    status = true;

                }
                    

            }while (status == false);

            statusAll = true; 
            cout << "\n\t\t\t\t LOG IN SUCCESS " << endl;
            cout << "\n\n\t\t\tDIRECT TO FEATURES PAGE, PRESS ANY KEY TO CONTINUE : ";
            getch();
        
            return status;
        }
};
// Class Staff (showing Inheritance and polymorphism )
class Staff:public Person {
    private:
       string staffID;

    public:
        Staff(){}

        void registration()
        {
            bool status;
            bool statusAll;
            
            do
            {
                system("cls");

                cout << "\t\t\t       ******* ****** *******  ******  ****** " << endl;
                cout << "\t\t\t       **        **   **   **  **      **     " << endl; 
                cout << "\t\t\t       *******   **   *******  ******  ****** " << endl; 
                cout << "\t\t\t            **   **   **   **  **      **     " << endl; 
                cout << "\t\t\t       *******   **   **   **  **      **     " << endl << endl;  

                cout << "\t\t       ******* **  *****   ***     **       **    ** *******  " << endl;
                cout << "\t\t       **      ** **       ** **   **       **    ** **     * " << endl; 
                cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******  " << endl; 
                cout << "\t\t            ** ** **    *  **    ****       ***  *** **       " << endl; 
                cout << "\t\t       ******* **  ******  **     ***        ******  **       " << endl; 

                cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
            
                cin.ignore();

                //Ask for user to input their name            
                cout << "\n\tENTER NAME ( in capital letters )  : ";
                getline(cin,name);

                setName(name); // set the name 
                
                //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
                cout << "\n\t* 4 characters\n\t* Case insensitive\n\t* eg : DS41 " << endl << endl; 
                cout << "\tENTER YOUR STAFF ID                : ";
                cin  >> staffID;

                int size = staffID.size();
                
                status = createPassword();

                if(size != 4 || status == false )
                {
                    statusAll = false;
                    cout << "\n\tREGISTRATION FAILED ! PASSWORD OR STAFF ID WAS NOT ENTERED BASED ON THE CORRECT FORMAT." << endl;
                     cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE... ";
                    getch();
                }
                else
                {
                    statusAll = true;

                }
                

                setCheckID(staffID); // Set the check Id in the parent class

            }while(statusAll == false);

            cout << "\n\n\t\t\t REGISTRATION SUCCESS ! PRESS ANY KEY TO PROCEED..";
            getch();
            
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            bool status;
            bool statusAll;
            int size;
            do
            {
                system("cls");

                cout << "\t\t\t     ******* ****** *******  ******  ****** " << endl;
                cout << "\t\t\t     **        **   **   **  **      **     " << endl; 
                cout << "\t\t\t     *******   **   *******  ******  ****** " << endl; 
                cout << "\t\t\t          **   **   **   **  **      **     " << endl; 
                cout << "\t\t\t     *******   **   **   **  **      **     " << endl << endl;

                cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
                     << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
                     << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
                     << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
                     << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;
             
                cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";	
               	
                cout << "\n\n"; 
                
                    cout << "\t\t\t\t ID        : ";
                    cin  >> id;
                    cin.ignore();

                    cout<<endl;                
                    cout << "\t\t\t\t PASSWORD  : ";
                    getline(cin,password);

                    if(id != checkId || password != checkPassword)
                    {
                        status = false;
                        cout << "\n\tPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                        getch();
                    }	
                    else
                        status = true;

            }while (status == false);

            statusAll = true;

            cout << "\n\t\t\t\t        LOG IN SUCCESS " << endl;
            cout << "\n\n\t\t\tDIRECT TO FEATURES PAGE, PRESS ANY KEY TO CONTINUE : ";
            getch();
        
            return statusAll;
        }    
};
// Class NonUTM (showing Inheritance)
class NonUTM:public Person {
    private:
       string icNum;

    public:
        NonUTM(){}

             void registration()
        {
            bool status;
            bool statusAll;
            
            do
            {
                system("cls");

                cout << "\t   ***    **  *******  ***    **       **  **  ****** ***     ***  " << endl;
                cout << "\t   ** **  **  **   **  ** **  **       **  **    **   ** ** ** **  " << endl; 
                cout << "\t   **  ** **  **   **  **  ** **  **** **  **    **   **   *   **  " << endl; 
                cout << "\t   **   ****  **   **  **   ****       **  **    **   **       **  " << endl; 
                cout << "\t   **    ***  *******  **    ***       ******    **   **       **  " << endl << endl; 

                cout << "\t\t******* **  *****   ***     **       **    ** *******  " << endl;
                cout << "\t\t**      ** **       ** **   **       **    ** **     * " << endl; 
                cout << "\t\t******* ** **   *** **  **  **  ***  **    ** *******  " << endl; 
                cout << "\t\t     ** ** **    *  **    ****       ***  *** **       " << endl; 
                cout << "\t\t******* **  ******  **     ***        ******  **       " << endl; 

                cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
            
                cin.ignore();

                //Ask for user to input their name            
                cout << "\n\tENTER NAME ( in capital letters ) : ";
                getline(cin,name);

                setName(name); // set the name 
                
                //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
                cout << "\n\t* 12 characters\n\t* Case insensitive\n\t* eg : 02031211050312 " << endl << endl; 
                cout << "\tENTER YOUR IC NUMBER                : ";
                cin  >> icNum;

                int size = icNum.size();
                
                status = createPassword();

                if(size != 12 || status == false )
                {
                    statusAll = false;
                    cout << "\n\tREGISTRATION FAILED ! PASSWORD OR IC NUMBER WAS NOT ENTERED BASED ON THE CORRECT FORMAT." << endl;
                    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE... ";
                    getch();
                }
                else
                {
                    statusAll = true;

                }

                setCheckID(icNum); // Set the check Id in the parent class

            }while(statusAll == false);

            cout << "\n\n\t\t\t REGISTRATION SUCCESS ! PRESS ANY KEY TO PROCEED..";
            getch();
            
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            bool status;
            bool statusAll;
            int size;

            do
            {
                system("cls");
                cout << "\t   ***    **  *******  ***    **       **  **  ****** ***     ***  " << endl;
                cout << "\t   ** **  **  **   **  ** **  **       **  **    **   ** ** ** **  " << endl; 
                cout << "\t   **  ** **  **   **  **  ** **  **** **  **    **   **   *   **  " << endl; 
                cout << "\t   **   ****  **   **  **   ****       **  **    **   **       **  " << endl; 
                cout << "\t   **    ***  *******  **    ***       ******    **   **       **  " << endl << endl;
                 
                cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
                     << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
                     << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
                     << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
                     << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;            
                cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";	
            	
                cout << "\n\n"; 
            
                cout << "\t\t\t\t ID        : ";
                cin  >> id;
                cin.ignore();

                cout<<endl;                
                cout << "\t\t\t\t PASSWORD  : ";
                getline(cin,password);

                if(id != checkId || password != checkPassword)
                {
                    status = false;
                    cout << "\n\tPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                    getch();
                }	
                else
                    status = true;

            }while (status == false);

            statusAll = true;

            cout << "\n\t\t\t\tLOG IN SUCCESS " << endl;
            cout << "\n\n\t\t\tDIRECT TO FEATURES PAGE, PRESS ANY KEY TO CONTINUE : ";
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
    Staff staffobj;
    NonUTM nonutmobj;


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
    else
    if (choiceCategory == 2)
        ptr = &staffobj;
    else
        ptr = &nonutmobj;
    
    A:
        // Get the users'choice for Main Menu
        choiceMain = displayMainMenu();

        switch (choiceMain)
        {
            //Log In to the system
            case 1:

                    //Go to the log in menu
                    statusLogin = ptr->login(); //If the user did not register  go to login menu then it will be directly go to registration menu.

                    if(statusLogin == true)
                    {
                        //Get the users's choice for features ( [1. REGISTER THE TOURNAMENT ] [2. PRINT THE REPORT ] )
                        choiceFeature = displayFeatures();
            
                        while(choiceFeature == 1 || choiceFeature == 2 )
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

                                    //set the time from composition tournament
                                    obj[count].setTime(); 

                                    
                                    //set the date from composition tournament;
                                    obj[count].setDate();

                                    char ans;

                                    system("cls");

                                    cout << "DO YOU WANT TO BOOK ANY EQUIPMENTS FOR YOUR TOURNAMENT (Y/N) ? ";
                                    cin >> ans;
                                    
                                    if(ans == 'Y' || ans == 'y')
                                    {
                                        obj[count].bookEquipmentBadminton();
                                    }

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

                                    //set the time from composition tournament
                                    obj[count].setTime();

                                     //set the date from composition tournament;
                                    obj[count].setDate(); 

                                    system("cls");
                                    char ans;
                                    cout << "DO YOU WANT TO BOOK AN EQUIPMENTS FOR YOUR TOURNAMENT (Y/N) ? ";
                                    cin >> ans;
                                    
                                    if(ans == 'Y' || ans == 'y')
                                    {
                                        obj[count].bookEquipmentFutsal();
                                    }
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

                        while(choiceFeature == 1 || choiceFeature == 2 || choiceFeature == 3)
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

                                    //set the time from composition tournament
                                    obj[count].setTime();

                                     //set the date from composition tournament;
                                    obj[count].setDate(); 

                                    system("cls");

                                    char ans;

                                    cout << "DO YOU WANT TO BOOK AN EQUIPMENTS FOR YOUR TOURNAMENT (Y/N) ? ";
                                    cin >> ans;
                                    
                                    if(ans == 'Y' || ans == 'y')
                                    {
                                        obj[count].bookEquipmentBadminton();
                                    }
                                    
                                
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
                                    
                                    //set the time from composition tournament
                                    obj[count].setTime();

                                     //set the date from composition tournament;
                                    obj[count].setDate(); 

                                    system("cls");

                                    char ans;

                                    cout << "DO YOU WANT TO BOOK AN EQUIPMENTS FOR YOUR TOURNAMENT (Y/N) ? ";
                                    cin >> ans;
                                    
                                    if(ans == 'Y' || ans == 'y')
                                    {
                                        obj[count].bookEquipmentFutsal();
                                    }
                                
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
