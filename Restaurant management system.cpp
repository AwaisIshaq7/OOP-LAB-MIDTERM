
#include <iostream>
#include <vector>
#include <string>
#include<stdio.h>

using namespace std;

class Reservation {                 //Reservation Class
private:
    string name;
    string time;
public:
    Reservation(string n, string t) : name(n), time(t) {}
    string getName() const { return name; }
    string getTime() const { return time; }
};

class Restaurant {                  //Restaurant Class with all methods(function)
private:
    vector<string> availableTimeSlots;
    vector<Reservation> reservations;
public:
    Restaurant(vector<string> timeSlots) : availableTimeSlots(timeSlots) {}

    void displayAvailableTimeSlots() const {  
        cout << "Available Time Slots: " << endl;
        for (int i = 0; i < availableTimeSlots.size(); ++i) {   //loop for checking available time slots..
            cout << i + 1 << " . " << availableTimeSlots[i] << endl;
        }
    }

    void makeReservation() {
        string name;
        int choice;
        
        cout << "\tWelcome To Valhalla Restaurant\n ";
        cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout << "\nDear Customer, Enter your name: ";
        getline(cin, name);
        

        start:cout << "*-*-*-*-*-*-*-* \n";
        displayAvailableTimeSlots();
        cout << "Select the desired time slot for yourself (e.g. 1,2): ";
        cin >> choice;

        if (choice >= 1 && choice <= availableTimeSlots.size()) {
            string selectedTime = availableTimeSlots[choice - 1];
            availableTimeSlots.erase(availableTimeSlots.begin() + choice - 1);
            reservations.push_back(Reservation(name, selectedTime));
            cout << "\nDear Sir/Madam "<< name<<"  your reservation for "<< selectedTime
                <<" has been confirmed.\n\nyou can visit the main office for any query"<< endl;
            
        }
        else {
            cout << "Invalid choice!\n " << endl;
            cout << "\nSelect Again ";
            goto start;
        }
    }
};

int main() {
    //Took a vector to store the timeslots and select one
    vector<string> timeSlots = { "10:00 AM", "12:00 PM", "1:00 PM", "2:00 PM", "7:00 PM","9:00"};
    Restaurant restaurant(timeSlots);
    restaurant.makeReservation();

    return 0;
}
