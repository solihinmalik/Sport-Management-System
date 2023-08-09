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
   int fee, discountFee,sports_type;
   int cat,newReg;
   string status;

   public:
   
    // Accessor to get the value of fee
   double getFeeBadminton(int sport_type,string categoryName)
   { 

        if(sports_type == 1)
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
    double getDiscount()
    {
       
    
            discountFee = fee - (fee * 0.05);
            cout << "\nYour fees after discount is RM"<< discountFee;
        }
        else 
        {
            discountFee = fee; 
            cout << "\nYour fees after discount is RM"<< discountFee << "\n";
        }

        return discountFee;
    }
   void display_invoice()
   {

        cout << "\n====================[PAYMENT INVOICE]====================" << endl;
        
        
        cout << "\nFees after discount is RM" << discountFee << endl;
        
        cout << "Total Fee       : " << discountFee<<endl;
        
        cout << "Status Payment  : " << status;

   }
   string status_payment(){
   	
       cout <<"\n" << endl;
       cout << "\n===============[PAYMENT STATUS]================="<<endl;
       cout << "\nHave you paid the fees?" << endl;
       cout << "State Y for yes, N for no." << endl;
       cin >> status;
       return status;
   }
    
    
};
class Equipment
{
    private:
        int stockF; //futsalball
        int stockR; //Racket 
        int stockS; //shuttlecock
        int stockG; //shin Guard
        int quantity, eqptypeF, eqptypeB, cont;
        double totalAll;
        
        Payment pay; 
    
    public:
        
        Equipment() {
            stockF = 50;
            stockR = 70;
            stockS = 100;
            stockG = 85;
            totalAll = 0;
        }
        double getFee()
        {
            
        }
        //display futsal
        void displayF() 
        { 
        
            do
            {
                system("cls");

                cout << "What equipment type do you want?\n"
                     << "1. Futsal Ball    Stocks: " << "(" << stockF << ")" << endl
                     << "2. Shin Guard     Stocks: " << "(" << stockG << ")" << endl;
                     
                cout << "Please select: ";
                cin >> eqptypeF;
                cout << "Quantity: ";
                cin >> quantity;
                

                double total = calcTotal();

                cout << "Total price: RM " << total << endl;

                cout << "Do you want to continue? if YES press <1> => ";
                cin >> cont;

                totalAll = totalAll + total;

            }
            
			while (cont == 1);

            cout << "\nTotal that is need to be paid is RM" << totalAll << endl;

        }
        // Display Badminton
        void displayB() 
        { 
            do
            {
                system("cls");

                cout << "What equipment type do you want?\n"
                     << "1. Racket          Stocks: " << "(" << stockR << ")" << endl
                     << "2. Shuttlecock     Stocks: " << "(" << stockS << ")" << endl;
                     
                cin >> eqptypeB;
                cout << "Quantity: ";
                cin >> quantity;
                

                double total = calcTotal();

                cout << "Total price: RM " << total << endl;

                cout << "Do you want to continue? if YES press <1> => ";
                cin >> cont;
                
                getch();
                
                totalAll = totalAll + total;


            }
            
			while (cont == 1);

            cout << "\nTotal that is need to be paid is RM" << totalAll << endl;

        }

        double calcTotal()
        {
            double total = 0;
            if (eqptypeF == 1) 
            {
                if(quantity < stockF)
                {
                    total = 5 * quantity;
                    stockF -= quantity;
                }
                else 
                    cout << "bola tak cukup" << endl; 
            
            }   
            else if(eqptypeF == 2) 
            {
                if(quantity < stockG) 
                {
                    total = 20 * quantity;
                    stockG -= quantity;
                }
                else 
                    cout << "Shin guard tak cukup" << endl;
            }
            
            else if (eqptypeB == 1) 
            {
               if(quantity < stockR)
               {
                    total = 10 * quantity;
                    stockR -= quantity;
                }  // kalau beli more than 10 , dia keluar "tak cukup" + d
                else
                    cout << "Racket tak cukup";       
            }
            else if(eqptypeB == 2) 
            {
                if(quantity < stockS)
               {
                    total = 10 * quantity;
                    stockS -= quantity;
                }  
                else
                    cout << "Shuttlecock tak cukup";       
            }
        
        }
        // Showing composition between class Equipment and class Payment
        void totalPayment()
        {
            cout << fixed << setprecision(2);

           char ch;
            cout << "ARE YOU A UTM CITIZENS OR NOT (Y/N) : ";
            cin >> ch;
            
            if (ch == 'Y' || ch == 'y')
            {
                double dissTotal = pay.getdiscountFee(totalAll);
                cout<<"Total Payment for Equipment is RM "<< dissTotal << endl;
            }
        	cout<<"Total Payment for Equipment is RM "<< totalAll << endl;
        }

        double getFee(int sport_type, string categoryName)
        {   
            double fee;
            
            // Showing composition between class Equipment and Payment
            fee = pay.getFeeBadminton(sport_type, categoryName)

            return fee;    
        }

        void displayInvoice (){
            cout<<"==================INVOICE EQUIPMENT======================"<<endl;
            cout<<"Availability of futsal ball left in the store:"<<stockF-quantity<<endl;
            cout<<"Availability of badminton Racket left in the store:"<<stockR-quantity<<endl;
            cout<<""vailability of shSttlecock left in the storek<<stockS-quantity<<endl;
            cout<<"Availability of shin guard"left in the storec<<stockG-quantity<<endl;
            cout<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Your equipments booking";

            
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
            
        	cout<<"\nDate today:[dd-mm-yyyy] :";
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


            cout <<"DATE        : "<< days <<" "<< month <<" "<< years <<endl;
		} 
			
	
        void get_StartTime(){   // Assume start time

            system("cls");

            cout << "NOTES : USE 12-HOUR SYSTEM FORMAT FOR BPOTH START AND END TIME\n\n"
                 << "\nENTER < START > TIME OF THE GAME : \n"
                 << "\nHOUR     -> ";
            cin  >> hour1;
            cout << "\nMINUTE   -> ";
            cin >> minute1;

            string status;
            cout << "\nAM or PM -> ";
            cin >> status1;

            if (status1 == "AM"||status1=="am")
                cout << "\nSTART TIME -> " << hour1 << ":" << minute1<< " AM" << endl;
            else
                cout << "\nSTART TIME -> " << hour1 << ":" << minute1 << " PM" << endl;

        
        
        } 
        void get_EndTime(){   // Assume End time
            
            

            cout << "\nENTER < END > TIME OF THE GAME   : \n"
                 << "\nHOUR     -> ";
            cin  >> hour2;
            cout << "\nMINUTE   -> ";
            cin >> minute2;

            cout << "\nAM or PM -> ";
            cin >> status2;

            if (status2 == "AM"||status2=="am")
                cout << "\nEND TIME -> " << hour2 << ":" << minute2 << " AM" << endl;
            else
                cout << "\nEND TIME -> " << hour2 << ":" << minute2<< " PM" << endl;

        } 

        void displayTime()
        {  
            cout<<"START TIME     : "<< hour1 <<":"<< minute1 << " " << status1 << endl;
            cout<<"END TIME       : "<< hour2 <<":"<< minute2 << " " << status2 << endl;
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
                fee = eqp.getFee(sport_type,badmintonCategoryname);
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
        }
        
        void bookEquipmentBadminton()
        {
            system("cls");
            
            eqp.displayB();
        }
        void displayInvoice()
        {
            eqp.displayInvoice();
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
                    cout << "\t\t  ****** **  **  ***  *** ***  *** ****** ****** **     ** "<< endl
                         << "\t\t  **     **  **  ** ** ** ** ** ** **  ** **  **  **  **   "<< endl
                         << "\t\t  ****** **  **  **    ** **    ** ****** ******    **     "<< endl
                         << "\t\t      ** **  **  **    ** **    ** **  ** **   **   **     "<< endl
                         << "\t\t  ****** ******  **    ** **    ** **  ** **    **  **     "<< endl << endl;

                    cout << "\t=====================[ DETAILS ]=======================" << endl;
                    cout << "\tNAME      : " << name << endl
                        << "\tID        : "  << id << endl;
                
                }
                
                cout << "\t\n\n===================[ TOURNAMENT " << i + 1 << " ]===================" << endl;
                string name;

                if (list[i]->getSportType() == 1)
                {
                    cout << "\tSPORT'S NAME   : " << list[i]->getSportName() << endl;
                    cout << "\tCATEGORY       : " << list[i]->getCategoryName() << endl;
                    cout << "\tVENUE          : " << venueName + "Badminton Hall" << endl    
                         << "\tFEE            : " << list[i]->getFee() <<endl;
                    list[i]->displayTime();
                    
                    //Print name of all participants that has been registered
                    list[i]->getParticipants();

                    cout<<"Press any key to continue->";

                    list[i]->displayInvoice();     
                }
                else
                {
                    cout << "\tSPORT'S NAME   : " << list[i]->getSportName() << endl;
                    cout << "\tVENUE          : " << venueName + "Futsal Court" << endl    
                         << "\tFEE            : " << endl;
                   
                                        
                    // Print name of all participants that has been registered
                    list[i]->getParticipants();

                     cout<<"\tPress any key to continue->";

                    list[i]->displayInvoice();
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

        cout << "Create your password: (8 to 10 characters, must be alphanumeric. case and space sensitive)\n";
        cout << "\t PASSWORD  : " ;

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
            cout << "\t *******    **    **       **     *******    **      *****   ******   ******  **    **   **   "<< endl; 

            cout << "\t\t       ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t\t       **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t\t            ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t\t       ******* **  ******  **     ***        ******  **"      << endl; 

            cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
	        cout << " " << setfill('=') << setw(124);	

            cin.ignore();

            //Ask for user to input their name            
            cout << "\n\t\t\t\t   ENTER NAME ( in capital letters ) : ";
            getline(cin,name);

            setName(name); // set the name 
    
            //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
        	cout << "\t\t\t\t * 9 characters\n\t\t\t\t * Case insensitive\n\t\t\t\t * eg : A21EC0011 " << endl << endl <<endl; 
	        cout << "\t ENTER YOUR MATRIC NUMBER : ";
	        cin  >> matricNum;

            int size = matricNum.size();
            
            //Input Validation for matric number
            while(size != 9)
            {
                cout << "INVALID FORMAT OF MATRIC NUMBER!!" << endl
                     << "PLEASE ENTER AGAIN !!" << endl;

                cout << "\t ENTER YOUR MATRIC NUMBER : ";
	            cin  >> matricNum;
	             
	            int size = matricNum.size();
	             
            }
            createPassword();

            setCheckID(matricNum); // Set the check Id in the parent class
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            do
            {
                system("cls");

                bool status;
                bool statusAll;
                int size;

                cout << endl << endl; 
                cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
                    << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
                    << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
                    << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
                    << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;
            
                cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";;	
                cout << " " << setfill('=') << setw(124);	
                cout << "\n\n"; 
            
                cout << "\t\t ID       : ";
                cin  >> id;

                cin.ignore();
                cout << "\t\t Password : ";
                getline(cin,password);

                if(id != checkId || password != checkPassword)
                {
                    status = false;
                    cout << "\nPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                    getch();
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
// Class Staff (showing Inheritance and polymorphism )
class Staff:public Person {
    private:
       string staffID;

    public:
        Staff(){}

        void registration()
        {
            
            system("cls");

            cout << "\t\t\t       ******* ****** *******  ******  ****** " << endl;
            cout << "\t\t\t       **        **   **   **  **      **     " << endl; 
            cout << "\t\t\t       *******   **   *******  ******  ****** " << endl; 
            cout << "\t\t\t            **   **   **   **  **      **     " << endl; 
            cout << "\t\t\t       *******   **   **   **  **      **     " << endl << endl;  

            cout << "\t       ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t       **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t       ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t            ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t       ******* **  ******  **     ***        ******  **"      << endl; 

            
            cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
            int size;

            do
            {
                cin.ignore();

                //Ask for user to input their name            
                cout << "\n\t\t\t\t   ENTER NAME ( in capital letters ) : ";
                getline(cin,name);

                setName(name); // set the name 
        
                //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
                cout << "\t\t\t\t * 9 characters\n\t\t\t\t * Case insensitive\n\t\t\t\t * eg : DS51 " << endl << endl <<endl; 
                cout << "\t ENTER YOUR STAFF NUMBER : ";
                cin  >> staffID;

                size = staffID.size();
                
                //Input Validation for matric number
                if(size != 4)
                {
                    cout << "INVALID FORMAT OF MATRIC NUMBER!!" << endl
                         << "PLEASE ENTER AGAIN !!" << endl;                    
                }
                createPassword();

                setCheckID(staffID); // Set the check Id in the parent class
            } while (size != 4);
            
            
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            do
            {
                system("cls");

                bool status;
                bool statusAll;
                int size;

                cout << endl << endl; 
                cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
                    << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
                    << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
                    << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
                    << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;
            
                cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";;	
                cout << " " << setfill('=') << setw(124);	
                cout << "\n\n"; 
                
                    cout << "\t\t ID       : ";
                    cin  >> id;

                    cin.ignore();
                    cout << "\t\t Password : ";
                    getline(cin,password);

                    if(id != checkId || password != checkPassword)
                    {
                        status = false;
                        cout << "\nPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                        getch();
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
// Class NonUTM (showing Inheritance)
class NonUTM:public Person {
    private:
       string icNum;

    public:
        UTMstud(){}

        void registration()
        {
            
            system("cls");

       
            cout << "\t       ***    **  *******  ***    **       **  **  ****** ***     ***  " << endl;
            cout << "\t       ** **  **  **   **  ** **  **       **  **    **   ** ** ** **  " << endl; 
            cout << "\t       **  ** **  **   **  **  ** **  **** **  **    **   **   *   **  " << endl; 
            cout << "\t       **   ****  **   **  **   ****       **  **    **   **       **  " << endl; 
            cout << "\t       **    ***  *******  **    ***       ******    **   **       **  " << endl << endl; 

            cout << "\t\t       ******* **  *****   ***     **       **    ** *******" << endl;
            cout << "\t\t       **      ** **       ** **   **       **    ** **     *"<< endl; 
            cout << "\t\t       ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
            cout << "\t\t            ** ** **    *  **    ****       ***  *** **"      << endl; 
            cout << "\t\t       ******* **  ******  **     ***        ******  **"      << endl; 

            cout << "\n\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
	        cout << " " << setfill('=') << setw(124);	

            cin.ignore();

            //Ask for user to input their name            
            cout << "\n\t\t\t\t   ENTER NAME ( in capital letters ) : ";
            getline(cin,name);

            setName(name); // set the name 
    
            //Ask for user to input their id (for UTM Student is MATRIC NUMBER)
        	cout << "\t\t\t\t * 9 characters\n\t\t\t\t * Case insensitive\n\t\t\t\t * eg : A21EC0011 " << endl << endl <<endl; 
	        cout << "\t ENTER YOUR MATRIC NUMBER : ";
	        cin  >> matricNum;

            int size = matricNum.size();
            
            //Input Validation for matric number
            while(size != 9)
            {
                cout << "INVALID FORMAT OF MATRIC NUMBER!!" << endl
                     << "PLEASE ENTER AGAIN !!" << endl;

                cout << "\t ENTER YOUR MATRIC NUMBER : ";
	            cin  >> matricNum;
	             
	            int size = matricNum.size();
	             
            }
            createPassword();

            setCheckID(matricNum); // Set the check Id in the parent class
        }
        // Will be call to check the status of id entered by the user
        bool login()
        {
            do
            {
                system("cls");
                
                bool status;
                bool statusAll;
                int size;

                cout << endl << endl; 
                cout << "\t\t\t    **        ******   *****   **  ***     **  "<<endl
                    << "\t\t\t    **       **    ** **       **  ** **   **  "<<endl
                    << "\t\t\t    **       **    ** **   *** **  **  **  **  "<<endl
                    << "\t\t\t    **       **    ** **    *  **  **    ****  "<<endl
                    << "\t\t\t    ********  ******   ******  **  **     ***  "<<endl;
            
                cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";;	
                cout << " " << setfill('=') << setw(124);	
                cout << "\n\n"; 
            
                cout << "\t\t ID       : ";
                cin  >> id;

                cin.ignore();
                cout << "\t\t Password : ";
                getline(cin,password);

                if(id != checkId || password != checkPassword)
                {
                    status = false;
                    cout << "\nPlease re-enter the ID, it might be that you're not registered or you have entered wrong ID/Password" << endl;
                    getch();
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

                                    
                                    obj[count].setTime(); 

                                    //set the date from composition tournament;
                                    obj[count].setDate();

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
                                    obj[count].setParticipants(7); 

                                    //set the time from composition tournament
                                    obj[count].setTime();

                                     //set the date from composition tournament;
                                    obj[count].setDate(); 

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
                            else
                            if (choiceFeature == 3) // Booking the equipments
                            {

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
                            else
                            if (choiceFeature == 3) // Booking the equipments
                            {

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
