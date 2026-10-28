#include <iostream>

using namespace std;
class Hotel{
private:
    int rooms;
    int reserve;
    int weddingHall;
    double rate;

public:

    friend void Display_Hotel_Information(Hotel h);

    Hotel() {
    rooms =0;
    reserve =0;
    weddingHall =0;
    rate =0;

    }


    Hotel(int r,int w){
     rooms =r;
    reserve =w;
     weddingHall =0;
     rate =0.0;
}

    Hotel(int r,int w,double rt){
     rooms =r;
     reserve =0;
     weddingHall=w;
     rate =rt;
    }

    void reserveroom(){
    if (reserve<rooms){
     reserve++;
     cout<<"\tTHIS ROOM IS BOOKED successfully ! :"<<endl;

    }else {
    cout<<"SORY IS NOT AVAILABLE ANY ROOMS "<<endl;
    }
    }

void updaterate(){
    double newrate;
cout<<"HI DEAR I hope to be happy during your stay with us"<<endl;
     cin>>newrate;

if (rate==0.0){
     rate=newrate;
    }
    else
     {
     rate = (rate + newrate) / 2.0;

        }
cout << "Hotel rating updated to: " << rate << endl;
  }

  void leaveRoom() {
    if (reserve > 0) {
    reserve--;
cout << "Room vacated (Guest checked out).\n";
updaterate();
} else {
    cout << "No rooms are currently reserved!\n";
    }
    }
~Hotel(){
cout << "Thank you for using Hotel Management System. Closing object...\n";}

};
    void Display_Hotel_Information(Hotel h)
 {
cout<<"<              Hotel Details       >"<<endl;
cout<<" ALL ROOMS : "<<h.rooms<<endl;
cout<<" THIS ROOM IS RESERVED : "<<h.reserve<<endl;
cout<<" wedding Hall :"<<h.weddingHall<<endl;
cout<<" RATE OF HOTEL :"<<h.rate<<endl;
    }
int main()
{
    Hotel h1(100,2,0.0);
    Display_Hotel_Information(h1);


char Choice;
int hotelChoice;
cout << " Starting Receptionist System < Hotels >" << endl;


    do {
        cout << "\nChoose Hotel to manage (1 for Hotel 1, or 0 to Exit) : ";
        cin >> hotelChoice;

        if (hotelChoice == 0) break;

        cout << "Enter 'e' to reserve a room (entering), or 'l' to check-out (leaving): ";
        cin >> Choice;


        if (hotelChoice == 1) {
            if (Choice == 'e' || Choice == 'E') {
                h1.reserveroom();
            }
            else if (Choice == 'l' || Choice == 'L') {
                h1.leaveRoom();
            }
            cout << "\n--- Updated Hotel 1 Info ---" << endl;
            Display_Hotel_Information(h1);
        }
        else {
            cout << "Invalid Hotel Choice! Please choose 1 or 2." << endl;
        }

    }
    while (hotelChoice != 0);

    return 0;
}
