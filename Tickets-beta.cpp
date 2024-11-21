#include <iostream>
#include <D:\ALPROG\.PROJECT\Project Alpro Kelompok 3\ascii-art-main\Ascii.h>//pilih file Ascii.h pada folder klik kanan pilih "Copy Path" kemudian paste pada bagian ini
#include <D:\ALPROG\.PROJECT\Project Alpro Kelompok 3\termcolor.hpp>//pilih file termcolor.hpp klik kanan  pilih "Copy Path" kemudian paste pada bagian ini
#include <string>
#include <ctime>
#include <iomanip> // Untuk manipulasi output
using namespace std;
using namespace ascii;

int x=0;
string movieArr[100],timeArr[100],seatNum[100];

class Cinema {
public:
    bool seats[4][4][10][9] ;// Array 4D untuk kursi bioskop dengan 10 baris (A-J) dan 9 kolom

    Cinema() {
        // Inisialisasi semua kursi menjadi 'n' (kosong)
        for(int i=0;i<4;i++){
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 10; k++) {
                    for(int l=0;l < 9;l++){
                        seats[i][j][k][l]=false;
                    }
                }
            }
        }
    }
    void display(int choiceMov,int choiceTime) {
        cout << "\n\n";
        cout << "\t\t\t\t  " << termcolor::on_yellow <<  "SCREEN THIS SIDE" << termcolor::on_grey << "\n\n";
        cout << termcolor::green <<"  ----------------------------------------------------------------------------------\n\n" << termcolor::white << termcolor::bold;
        
        for (int i = 0; i < 10; i++) {
            for(int j=0;j<9;j++){
                if (seats[choiceMov-1][choiceTime-1][i][j] == false) {
                    cout << "       " << termcolor::on_bright_blue << char('A' + i) << j + 1 << termcolor::on_grey; // Tampilan kursi kosong
                } else {
                    cout << "       " << termcolor::on_red << char('A' + i) << j + 1 << termcolor::on_grey; // Tampilan kursi kosong
                }
            }
            cout << "\n\n";
        }
        cout << termcolor::green <<"  ----------------------------------------------------------------------------------\n\n" << termcolor::white;
    }


    void bookTickets(int choiceMov,int choiceTime,string movie, string waktu) {
        int tiket;
        string seat;

        cout << "\n\nNumber of tiket to book: ";
        cin >> tiket;

        int booked = 0;
        for (int i = 0; i < tiket; i++) {
            cout << "Enter row (A-J) and seat number (1-9) for ticket " << i + 1 << ": ";
            cin >> seat;

            if(seat[0]>90) {seat[0]=char(seat[0]-32);}
            int rowIndex = seat[0] - 'A';
            int seatIndex = seat[1] - '1';

            if (rowIndex >= 0 && rowIndex < 10 && seatIndex >= 0 && seatIndex < 9) {
                if (seats[choiceMov-1][choiceTime-1][rowIndex][seatIndex] == false) {
                    seats[choiceMov-1][choiceTime-1][rowIndex][seatIndex] = true;
                    booked++;
                    if(x==100) x=0;
                    movieArr[x]=movie;
                    timeArr[x]=waktu;
                    seatNum[x]=seat;
                    x++;
                    cout <<termcolor::green<< "Seat " <<termcolor::yellow<< seat <<termcolor::green<< " booked successfully!\n"<<termcolor::white;
                } else {
                    cout <<termcolor::red<< "Seat " <<termcolor::yellow<< seat <<termcolor::red<< " is already booked.\n"<<termcolor::white;
                    i--;
                }
            } else {
                cout <<termcolor::red<< "Invalid seat number! Please try again.\n"<<termcolor::white;
                i--;
            }
            
        }
        cout<<endl<<endl;
        system("pause");
        cout <<termcolor::green<< "\n" << booked << " ticket(s) booked successfully.\n\n"<<termcolor::white;
        for(int i=0;i<tiket;i++){
            time_t t=time(0); auto waktu = put_time(localtime(&t),"%d/%m/%y");
            cout<<"------------------------------------"<<endl;
            cout<<"|"<<setw(25)<<left<<"ITIX"<<setw(1)<<right<<"|"<<endl;
            cout<<"|-----------------------------------|"<<endl;
            cout<<"|"<<setw(5)<<left<<movieArr[x-1]<<setw(20)<<right<<"|"<<endl<<endl;
            cout<<"|"<<setw(5)<<left<<" Date : "<<left<<waktu<<setw(20)<<right<<"|"<<endl;
            cout<<"|"<<setw(5)<<left<<" Time : "<<left<<timeArr[x-1]<<setw(20)<<right<<"|"<<endl;
            cout<<"|"<<setw(5)<<left<<" seat : "<<left<<seatNum[x-(i+1)][0]<<"\tRow : "<<seatNum[x-(i+1)][1]<<setw(20)<<right<<"|"<<endl;
            cout<<"|-----------------------------------"<<endl;
        }
    }

    void cancelBooking(int choiceMov, int choiceTime) {
        char row;
        int seat;
        cout << "\nEnter row (A-J) and seat number (1-9) to cancel booking: ";
        cin >> row >> seat;
        if(row>90)row=char(row-32);
        int rowIndex = row - 'A';
        int seatIndex = seat - 1;

        if (rowIndex >= 0 && rowIndex < 10 && seatIndex >= 0 && seatIndex < 9) {
            if (seats[choiceMov-1][choiceTime-1][rowIndex][seatIndex] == true) {
                seats[choiceMov-1][choiceTime-1][rowIndex][seatIndex] = false;
                cout << termcolor::green<<"Booking for seat "<<termcolor::yellow << row << seat <<termcolor::green<< " canceled successfully.\n\n"<<termcolor::white;
            } else {
                cout <<termcolor::red<< "This seat is not booked, so it cannot be canceled.\n\n"<<termcolor::white;               
            }
        } else {
            cout <<termcolor::red<< "Invalid seat number! Please try again.\n"<<termcolor::white;
        }
        cout<<endl;system("pause");
    }

};
// int a=0;

void movChoice(int &choiceMov,string &movie){
    string movieName[4] = {"The Shawshank Redemption","Avengers: Endgame","Inception","The Godfather"};
    cout <<endl<< termcolor::yellow <<setw(88)<<setfill('=')<<"\n";
    cout <<setfill(' ')<< "|  NO |"<<setw(46)<<"Movie Title"<<setw(34)<<"|"<<"\n";
    cout << termcolor::yellow <<setw(88)<<setfill('=')<<"\n";
    cout <<setfill(' ')<< "|  1  |" <<setw(54)<< termcolor::white <<movieName[0]<<setw(27)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n";
    cout <<setfill(' ')<< "|  2  |" <<setw(48)<< termcolor::white <<movieName[1]<<setw(33)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n";
    cout <<setfill(' ')<< "|  3  |" <<setw(44)<< termcolor::white <<movieName[2]<<setw(37)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n";
    cout <<setfill(' ')<< "|  4  |" <<setw(46)<< termcolor::white <<movieName[3]<<setw(35)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n"<<termcolor::white;
    cout << "Select Movie (1-4) : "; 
    cin >> choiceMov;
    movie=movieName[choiceMov-1];
    
}
void timeChoice(int &choiceTime,string &time){
    string showTime[4] = {"12.15", "14.20", "16.25", "18.30"};
    cout<<endl;
    cout <<endl<< termcolor::yellow <<setw(88)<<setfill('=')<<"\n";
    cout <<setfill(' ')<< "|  NO |"<<setw(46)<<"Movie Showtime"<<setw(34)<<"|"<<"\n";
    cout << termcolor::yellow <<setw(88)<<setfill('=')<<"\n";
    cout <<setfill(' ')<< "|  1  |" <<setw(43)<< termcolor::white <<showTime[0]<<setw(38)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n";
    cout <<setfill(' ')<< "|  2  |" <<setw(43)<< termcolor::white <<showTime[1]<<setw(38)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n";
    cout <<setfill(' ')<< "|  3  |" <<setw(43)<< termcolor::white <<showTime[2]<<setw(38)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n";
    cout <<setfill(' ')<< "|  4  |" <<setw(43)<< termcolor::white <<showTime[3]<<setw(38)<< termcolor::yellow << "|\n" << termcolor::yellow;
    cout << termcolor::yellow <<setw(88)<<setfill('-')<<"\n"<<termcolor::white;
    cout << "Select Movie Showtime (1-4) : "; 
    cin >> choiceTime;
    time=showTime[choiceTime-1];
}

void bookHistory(){
    system("cls");
    cout<<"Booking History :"<<endl;
    for(int a=0;a<x;a++){
        cout<<a+1<<". "<<"Movie : "<<movieArr[a]<<", Showtime : "<<timeArr[a]<<", Seat : "<<seatNum[a]<<endl;
    }
    cout<<endl<<endl;
    system("pause");
}

int main() {
    Cinema cinema;
    int choice;
    char menu='n';
    int choiceMov=0;
    int choiceTime=0;
    Ascii font = Ascii(block);
    do{
        system("cls");
        cout<<termcolor::blue;
        font.print("ITIX");
        cout<<termcolor::white;
        cout<<setfill(' ')<<endl<<setw(54)<<"I F  T I C K E T S\n";
        cout<<setfill(' ')<<setw(45)<<"Powered by "<<termcolor::green<<"Kelompok 3\n"<<termcolor::white;
        
        cout<<endl<<"\tMAIN MENU "<<endl;
        cout<<"\t========================"<<endl;
        cout<<"\t1 | Cinema Tickets"<<endl;
        cout<<"\t2 | Booking History"<<endl;
        cout<<"\t3 | Quit"<<endl;
        cout<<"\tChoice : ";cin>>choice;

        if(choice==1){
            system("cls");
            string movie,time;
            movChoice(choiceMov,movie);
            timeChoice(choiceTime,time);
            do {
                system("cls");
                cinema.display(choiceMov,choiceTime); 
                cout<<setfill(' ')<<"| "<<choiceMov<<" | "<<movie<<endl;
                cout<<setfill('-')<<setw(40)<<"\n";    
                cout<<setfill(' ')<<"| "<<choiceTime<<" | "<<time<<endl;    
                cout << "\n\t\t\t\t**** Cinema Tickets *****\n";
                cout << "\t\t\t\t1. Book tickets\n";
                cout << "\t\t\t\t2. Show seat status\n";
                cout << "\t\t\t\t3. Cancel booking\n";
                cout << "\t\t\t\t4. Booking History\n";
                cout << "\t\t\t\t5. Back\n";
                cout << "\t\t\t\t6. Quit\n";
                cout << "\t\t\t\tChoice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cinema.bookTickets(choiceMov,choiceTime,movie,time);
                        cout<<endl<<endl;
                        system("pause");
                        break;
                    case 2:
                        cinema.display(choiceMov,choiceTime);
                        break;
                    case 3:
                        cinema.cancelBooking(choiceMov,choiceTime);
                        break;
                    case 4:
                        bookHistory();
                        break;
                    case 5: 
                        break;
                    case 6:
                        cout<<termcolor::red<<"\nwant to exit? (exit then all data will be deleted)"<<termcolor::white<<endl;
                        cout<<"Are you sure you want to quit? (y/n):";cin>>menu;
                        break;
                    default:
                        cout <<termcolor::red<< "Invalid choice. Please try again.\n"<<termcolor::white;
                        break;
                }
            } while (choice != 6 && choice !=5);
            if(menu=='y') break;
        } else if(choice==2){
            bookHistory();
        } else if(choice==3){
            cout<<termcolor::red<<"\nwant to exit? (exit then all data will be deleted)"<<termcolor::white<<endl;
            cout<<"Are you sure you want to quit? (y/n):";cin>>menu;
        } else {
            cout <<termcolor::red<< "Invalid choice. Please try again.\n"<<termcolor::white;
        }      
    }while(menu!='y');
    return 0;
}