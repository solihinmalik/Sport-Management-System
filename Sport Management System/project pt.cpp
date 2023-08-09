#include<iostream>
#include<iomanip>
using namespace std;
#define HARGA 10.0


class Date {
    private:
        string datebook;
    public:
        void setDateBook(string hari) {
            datebook = hari;
        }

        string getDateBook() {
            return datebook;
        }

};

class Time {
    private:
        string timebook;
    public:
        void setTimeBook(string masa) {
            timebook = masa;
        }

        string getTimeBook() {
            return timebook;
        }
};

class Reservation {
    private: 
        double bucket;
        Time t1;
        Date d1;
    public:
        Reservation(string masa = "", string hari = "") {
            cout << "Please enter the time you want to book (ex : 9am - 10am): ";
            cin.ignore();
            getline(cin, masa);
            cout << "Please enter the date as well (ex : 27 / 9): ";
            getline(cin, hari);
            d1.setDateBook(hari);
            t1.setTimeBook(masa); 
        }

        void setBucket(int bola) {  
            bucket = bola;
        }

        int getBucket() {
            return bucket;
        }

        string getTimeBook() {
            return t1.getTimeBook();
        }

        string getDateBook() {
            return d1.getDateBook();
        }

        double totalPrice() {
            return bucket * HARGA;
        }
};

class Customer {
    private:
        Reservation *ptr; 
    protected:
        string name, phone, email;
    public:
        Customer(string nama = "", string phonenum = "", string address = "") {
            /*cout << "\nPlease enter your name: ";
            getline(cin, nama);
            setName(nama);
            cout << "Please enter your phone number ";
            cin >> phonenum;
            setPhone(phonenum);
            cout << "PLease enter your e-mail address: ";
            cin >> address;
            setEmail(address);*/
            ptr = NULL;
        }

        void setReservation(Reservation *_ptr) {
            ptr = _ptr;
        }

        double getReservationPriceMember() const {
            if(ptr != NULL)
			{
				cout << "The total price is: RM" << ptr->totalPrice() * 0.8 << endl;
			}
			return 0;
		}

        double getReservationPriceNonMember() const {
            if(ptr != NULL)
			{
				cout << "The total price is: RM" << ptr->totalPrice() << endl;
			}
			return 0;
		}
        
        void setName(string nama) {
            name = nama;
        }

        void setPhone(string phonenum) {
            phone = phonenum;
        }

        void setEmail(string address) {
            email = address;
        }

        string getName() {
            return name;
        }
        
        string getPhone() {
            return phone;
        }

        string getEmail() {
            return email;
        }

        virtual void print() = 0; 
        virtual void registration() = 0;
};

class Member : public Customer {
    string idnum;

    public:
        Member(string nama = "", string phonenum = "", string email = "", int nom = 0) : Customer(nama, phonenum, email) {
            idnum = nom;
            /*cout << "Please enter your id membership club : ";
            cin >> nom;
            setIdNum(nom);*/
        }

        void setIdNum(int nom) {
            idnum = nom;
        }

        string getIdNum() {
            return idnum;
        }
        void registration()
        {
            string nama,phonenum,address;

            int nom;

            cout << "Please enter your id membership club: ";
            cin >> nom;
            setIdNum(nom);

            cout << "\nPlease enter your name           : ";
            cin.ignore();
            getline(cin, nama);
            setName(nama);
            cout << "Please enter your phone number     : ";
            cin >> phonenum;
            setPhone(phonenum);
            cout << "Please enter your e-mail address   : ";
            cin >> address;
            setEmail(address);
        }
        void print() {
            /*cout << "==============CUSTOMER RESERVATION DETAILS===============" << endl
                 << "NAME                         : " << name << endl
                 << "PHONE NUMBER                 : " << phone << endl
                 << "EMAIL ADDRESS                : " << email << endl*/
            cout << "==============CUSTOMER RESERVATION DETAILS===============" << endl
                 << "NAME                         : " << name << endl
                 << "PHONE NUMBER                 : " << phone << endl
                 << "EMAIL ADDRESS                : " << email << endl 
                 << "CLUB MEMBERSHIP ID           : " << idnum << endl;
        } 

};

class NonMember : public Customer {
    string icnum;

    public:
        NonMember(string nama = "", string phonenum = "", string email = "", int nom = 0) : Customer(nama, phonenum, email) {
            setIcNum(nom);
        }

        void setIcNum(int nom) {
            icnum = nom;
        }

        string getIcNum() {
            return icnum;
        }
        void registration()
        {
            string nama,phonenum,address;
            
            int nom;

            cout << "Please enter your identity card number (ex : 020927870027): ";
            cin >> nom;
            setIcNum(nom);

            cout << "\nPlease enter your name           : ";
            cin.ignore();
            getline(cin, nama);
            setName(nama);
            cout << "Please enter your phone number     : ";
            cin >> phonenum;
            setPhone(phonenum);
            cout << "Please enter your e-mail address   : ";
            cin >> address;
            setEmail(address);
        }
        void print() {
            cout << "==============CUSTOMER RESERVATION DETAILS===============" << endl
                 << "NAME                         : " << name << endl
                 << "PHONE NUMBER                 : " << phone << endl
                 << "EMAIL ADDRESS                : " << email << endl 
                 << "IDENTITY CARD NUMBER         : " << icnum << endl;
        }
};

int menu() {
    cout << endl
         << "            _____________________________________________________" << endl
         << "           | --------------------------------------------------- | " << endl
         << "           || (***********************************************) || " << endl
         << "           ||                                                   || " << endl
         << "           ||            H E L L O !     W E L C O M E          || " << endl
         << "           ||                                                   || " << endl
         << "           ||                 TO DRIVING RANGE                  || " << endl
         << "           ||                                                   || " << endl
         << "           ||            B O O K I N G  S Y S T E M             || " << endl
         << "           ||                                                   || " << endl
         << "           ||                                                   || " << endl
         << "           || (***********************************************) || " << endl
         << "           | --------------------------------------------------- | " << endl
         << "           |_____________________________________________________| " << endl
         << "          /  ________________________________________________ o / " << endl
         << "         /  /                                               /  / " << endl
         << "        /  /                                               /  / " << endl
         << "       /  /                                               /  / " << endl
         << "      /  /                                               /  / " << endl
         << "     /  /                                               /  / " << endl
         << "    /  /_______________________________________________/  / " << endl
         << "   /_____________________________________________________/ " << endl
         << "\n ************************************************************* " << endl;
    
    /*cout << "============================" << endl
         << "|       " << "W E L C O M E" << "       |" << endl
         << "DRIVING RANGE BOOKING SYSTEM" << endl
         << "============================" << endl; */
    return 0;
}

int main() {
    menu();
    
    double price;
    char club, decision;
    Customer *point;
    Member m1;
    NonMember n1;
    Reservation r1;


    //Customer *point;
    cout << "Do you want to make a reservation? : ";
    cin >> decision;

    if(decision == 'Y' || decision == 'y') 
    {
        do{
            cout << "Are u a club golf member? (Y for yes/N for no): ";
            cin >> club;

            if(club == 'Y' || club =='y') {

                //Reservation r1;
                point = &m1;

                point->registration();

                //Reservation r1;
                point->setReservation(&r1);
                int ball;
                cout << "Please enter the number of bucket: ";
                cin >> ball;
                r1.setBucket(ball);
                price = r1.totalPrice() * 0.8;
                m1.getReservationPriceMember();
                point->print(); 
            }
            else 
            if(club == 'N' || club == 'n') 
            {
                //Reservation r1;
                point = &n1;
               
                point->registration();

                //Reservation r1;
                point->setReservation(&r1);
                int ball;
                cout << "Please enter the number of bucket: ";
                cin >> ball;
                r1.setBucket(ball);
                point = &n1;
                price = r1.totalPrice();
                n1.getReservationPriceNonMember();
                cout << "(The total price remains the same)" << endl;
                point->print(); 
            }
            else
            {
                cout << "You have entered an INVALID INPUT. Please Try Again" << endl;
            }
            
        }while((club == 'Y' || club == 'y') && (club == 'N'|| club == 'n'));

            cout << "RESERVATION DATE AND TIME    : " << r1.getDateBook() << "(" << r1.getTimeBook() << ")" << endl
                 << "NUMBER OF BUCKET             : " << r1.getBucket() << endl
                 << "TOTAL PRICE                  : RM" << price << endl;
    }
        /*cout << "RESERVATION DATE AND TIME    : " << r1.getDateBook() << "(" << r1.getTimeBopk() << "" << endl
             << "NUMBER OF BUCKET             : " << r1.getBucket() << endl
             << "TOTAL PRICE                  : " << r1.totalPrice() << endl; */
    system("pause");
    return 0;
}