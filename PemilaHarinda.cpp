#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


const int MAX_PLAYERS = 100;


struct Players {
    int id;
    string firstname;
    string lastname;
    string dob;
    string scored;
    string firstTeam;
    string secondTeam;
    string ReDate;
    string NIC;
};


Players players[MAX_PLAYERS];
int numplayers = 0;


void registerp();
void login();
void deleteplayer();
void updateplayer();
void search();
void display();
void save();
void logout();
void load();


int main() {
    load();


    int choice;
    do {
        cout << " \t\t\t====================================================================\t\t\t" << endl;
        cout << "\n\t\t\t=======  Upcountry Warriors Baseball club Record Management  =======\t\t\t\n" << endl;
        cout << " \t\t\t====================================================================\t\t\t" << endl;
        cout << "1. Register a player: " << endl;
        cout << "2. Login : " << endl;
        cout << "3. update player details: " << endl;
        cout << "4. Delete a player records: " << endl;
        cout << "5. Display All players " << endl;
        cout << "6. Save players Records to File " << endl;
        cout << "7. Search for player " << endl;
        cout << "8. logout" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerp();
            break;

        case 2:
            login();
            break;

        case 3:
            updateplayer();
            break;

        case 4:
            deleteplayer();
            break;


        case 5:
            display();
            break;

        case 6:
            save();
            break;

        case 7:
            search();
            break;

        case 8:
            logout();
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;

        }
    } while (choice != 9);

    return 0;
}


void registerp() {
    if (numplayers >= MAX_PLAYERS) {
        cout << "Maximum number of players reached. Cannot insert more." << endl;
        return;
    }

    int id;
    string firstname;
    string lastname;
    string dob;
    int scored;
    string firstTeam;
    string secondTeam;
    string ReDate;
    string NIC;


    cout << "Enter player ID: ";
    cin >> id;

    for (int i = 0; i < numplayers; ++i) {
        if (players[i].id == id) {
            cout << "player with ID " << id << " already exists. Please enter a different ID." << endl;
            return;
        }
    }

    cout << "Enter player firstname: ";
    cin.ignore();
    cin >> (cin, firstname);


    cout << "Enter player lastname: ";
    cin.ignore();
    cin >> (cin, lastname);


    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    cin.ignore();
    cin >> (cin, dob);


    cout << "Enter player scored : ";
    cin.ignore();
    cin >> (cin, scored);


    cout << "choose your Team :\n 1.BLACK_DRAGON\n 2.WOLFS_KINGS \n 3.NIGHT_BIRDS" << endl;


    cout << "Enter your first Team : ";
    cin.ignore();
    cin >> (cin, firstTeam);


    cout << "Enter you second Team : ";
    cin.ignore();
    cin >> (cin, secondTeam);


    cout << "Enter Registration date (YYYY/MM/DD) : ";
    cin.ignore();
    cin >> (cin, ReDate);

    cout << "Enter your NIC NO : ";
    cin.ignore();
    cin >> (cin, NIC);



    players[numplayers].id = id;
    players[numplayers].firstname = firstname;
    players[numplayers].lastname = lastname;
    players[numplayers].dob = dob;
    players[numplayers].scored = scored;
    players[numplayers].firstTeam = firstTeam;
    players[numplayers].secondTeam = secondTeam;
    players[numplayers].ReDate = ReDate;
    players[numplayers].NIC = NIC;

    numplayers++;



    cout << "player register successfully." << endl;
}



void save() {
    ofstream outFile("players.txt");

    if (!outFile) {
        cerr << "Unable to open file players.txt" << endl;
        return;
    }

    for (int i = 0; i < numplayers; ++i) {
        outFile << players[i].id << "," << players[i].firstname << "," << players[i].lastname << "," << players[i].dob << ","
            << players[i].scored << "," << players[i].firstTeam << ","
            << players[i].secondTeam << "," << players[i].ReDate << players[i].NIC << endl;
    }

    outFile.close();
    cout << "player records saved to players.txt." << endl;
}


void login() {

    int count = 0;
    string id, password, pass;
    system("cls");
    cout << " \t\t\t  Please enter the username and id : " << endl;
    cout << " \t\t\t USERNAME ";
    cin >> id;
    cout << " \t\t\t ID";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == id && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (cout << 1)
    {
        cout << id << " \n your LOGIN is successfull \n Thanks for logging in ! \n ";

    }
    else {
        cout << " \n LOGIN ERROR \n please check your username and password\n ";

    }
}


void logout() {

    cout << "Logged out successfull\n";
}



void display() {
    if (numplayers == 0) {
        cout << "No players to display." << endl;
        return;
    }

    cout << "player Records:" << endl;
    cout << setw(5) << "ID" << setw(20) << "Firstname" << setw(20) << "Lastname" << setw(20) << "Date of Birth" << setw(15) << "scored" << setw(20) << "firstTeam"
        << setw(20) << "secondTeam" << setw(20) << "Registerd Date" << endl;

    for (int i = 0; i < numplayers; ++i) {
        cout << setw(5) << players[i].id << setw(20) << players[i].firstname << setw(20)
            << players[i].lastname << setw(20) << players[i].dob << setw(5) << players[i].scored
            << setw(20) << players[i].firstTeam << setw(20) << players[i].secondTeam << setw(20) << players[i].ReDate
            << setw(20) << players[i].NIC << endl;

    }
}




void updateplayer() {
    int id;
    string firstname;
    string lastname;
    string scored;
    string firstTeam;
    string secondTeam;

    cout << "Enter player ID to update: ";
    cin >> id;



    bool found = false;
    for (int i = 0; i < numplayers; ++i) {
        if (players[i].id == id) {
            cout << "Enter New first name: ";
            cin.ignore();
            cin >> (cin, firstname);
            cout << "Enter New last name: ";
            cin.ignore();
            cin >> (cin, lastname);

            cout << "Enter new scorde:";
            cin.ignore();
            cin >> (cin, scored);

            cout << "choose your New Teams :\n 1.BLACK_DRAGON\n 2.WOLFS_KINGS \n 3.NIGHT_BIRDS" << endl;

            cout << "Enter you new first Team : ";
            cin.ignore();
            cin >> (cin, firstTeam);

            cout << "Enter your new second Team : ";
            cin.ignore();
            cin >> (cin, secondTeam);

            if (found); {
                cout << "player details update successfully" << endl;
                break;
            }



            cin >> (cin, players[i].firstname);
            cin >> (cin, players[i].lastname);
            cin >> (cin, players[i].scored);
            cin >> (cin, players[i].firstTeam);
            cin >> (cin, players[i].secondTeam);


        }
    }

    if (!found) {
        cout << "player with ID " << id << " not found." << endl;

    }
}


void search() {
    int id;
    cout << "Enter player ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < numplayers; ++i) {
        if (players[i].id == id) {
            cout << "player found: ID = " << players[i].id << ", FirstName = " << players[i].firstname
                << " , lastName = " << players[i].lastname << ", dob = " << players[i].dob
                << " , scored = " << players[i].scored << " , firstTeam = " << players[i].firstTeam
                << " , secondTeam = " << players[i].secondTeam << "re Date = " << players[i].ReDate << " , NIC = " << players[i].NIC << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "player with ID " << id << " not found." << endl;
    }
}

void deleteplayer() {
    int id;
    cout << "Enter player ID to delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < numplayers; ++i) {
        if (players[i].id == id) {

            for (int j = i; j < numplayers - 1; ++j) {
                players[j] = players[j + 1];
            }
            numplayers--;
            found = true;
            cout << "player deleted successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "player with ID " << id << " not found." << endl;
    }
}

void load() {
    ifstream inFile("players.txt");
    numplayers = 0;

    if (!inFile) {
        cerr << "Unable to open file players.txt" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        players[numplayers].id = stoi(token);

        (ss, players[numplayers].firstname);
        (ss, players[numplayers].lastname);
        (ss, players[numplayers].dob);
        (ss, players[numplayers].scored);
        (ss, players[numplayers].firstTeam);
        (ss, players[numplayers].secondTeam);

        numplayers++;
    }

    inFile.close();
    cout << "player records loaded from players.txt." << endl;
}
