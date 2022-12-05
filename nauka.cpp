#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
fstream file;
struct Person {
    int id = 0;
    string name, surname, phone_number, adress, email;
};
void saving_to_file(vector <Person> &people) {

    string name, surname, phone_number, email, adress;
    file.open ( "adress_book.txt", ios::out );
    if (file.good() == true ) {
    int persons_amount = people.size();
        for (int i = 0; i < persons_amount; i++){
        file << people[i].id << "|";
        file << people[i].name<< "|";
        file << people[i].surname << "|";
        file << people[i].phone_number<< "|";
        file << people[i].email << "|";
        file << people[i].adress << "|" << endl;

    }

    file.close();
    } else {
        cout << "couldnt open file" << endl;
    }
}
string load_line() {
    string input;
    cin.sync();
    getline(cin, input);
    return input;
}
int insert_persons_data(vector <Person> &people,int persons_amount) {

    Person new_persons;
    string name, surname, phone_number, email, adress;

    cout << "insert name:" << endl;
    new_persons.name = load_line();
    cout << "insert surname: " << endl;
    new_persons.surname = load_line();
    cout << "insert phone number: " << endl;
    new_persons.phone_number = load_line();
    cout << "insert adress: " << endl;
    new_persons.adress = load_line();
    cout << "insert email: " << endl;
    new_persons.email = load_line();
    new_persons.id = persons_amount + 1;

    people.push_back(new_persons);
    saving_to_file(people);

    return persons_amount+1;
}
int loading_from_file (vector <Person>& people) {

    Person new_persons;
    string personals_data = "";
    fstream file;
    file.open("adress_book.txt", ios :: in);

    if (file.good()) {
        while(getline(file,personals_data)) {
            string persons_data{};
            int persons_number = 1;

            for (size_t index{}; index < personals_data.length(); ++index) {
                if (personals_data[index] != '|') {
                    persons_data += personals_data[index];
                } else {
                    switch(persons_number) {
                    case 1:
                        new_persons.id = stoi(persons_data);
                        break;
                    case 2:
                        new_persons.name = persons_data;
                        break;
                    case 3:
                        new_persons.surname = persons_data;
                        break;
                    case 4:
                        new_persons.phone_number = persons_data;
                        break;
                    case 5:
                        new_persons.email = persons_data;
                        break;
                    case 6:
                        new_persons.adress = persons_data;
                        break;
                    }
                    persons_data = "";
                    persons_number ++;
                }
            }
            people.push_back(new_persons);
        }
    }
    file.close();

    return new_persons.id ;
}
void showing_people_by_name (vector <Person> &people) {
    string name;

    cout << "enter surname to show friends with that name: " << endl;
    cin >> name;

    int i = 0;
    int name_number = 0;
    int persons_amount = people.size();
    while (i < persons_amount) {
        if (people[i].name == name) {
            cout << "Friend's ID " << " --------- " << people[i].id << endl;
            cout << "Friend's name " << " --------- " << people[i].name << endl;
            cout << "Friend's surname " << " --------- " << people[i].surname << endl;
            cout << "Friend's phone number " << " --------- " << people[i].phone_number << endl;
            cout << "Friend's e-mail " << " --------- " << people[i].email << endl;
            cout << "Friend's adress " << " --------- " <<  people[i].adress << endl;
            cout << endl;
            name_number++;
        }
        i++;
    }
    if (name_number == 0)
        cout << "no person with that name!" << endl;
}
void showing_people_by_surname (vector <Person> &people) {
    string surname;

    cout << "enter surname to show friends with that surname: " << endl;
    cin >> surname;

    int i = 0;
    int surname_number = 0;
    int persons_amount = people.size();
    while (i < persons_amount) {
        if (people[i].surname == surname) {
            cout << "Friend's ID " << " --------- " << people[i].id << endl;
            cout << "Friend's name " << " --------- " << people[i].name << endl;
            cout << "Friend's surname " << " --------- " << people[i].surname << endl;
            cout << "Friend's phone number " << " --------- " << people[i].phone_number << endl;
            cout << "Friend's e-mail " << " --------- " << people[i].email << endl;
            cout << "Friend's adress " << " --------- " <<  people[i].adress << endl;
            cout << endl;
            surname_number++;
        }
        i++;
    }
    if (surname_number == 0)
        cout << "no person with that surname!" << endl;
}
void every_single_person(vector <Person> &people) {

    int people_amount = people.size();
    for (int i = 0; i < people_amount; i++) {
        cout << "Friend's ID " << " --------- " << people[i].id << endl;
        cout << "Friend's name " << " --------- " << people[i].name << endl;
        cout << "Friend's surname " << " --------- " << people[i].surname << endl;
        cout << "Friend's phone number " << " --------- " << people[i].phone_number << endl;
        cout << "Friend's e-mail " << " --------- " << people[i].email << endl;
        cout << "Friend's adress " << " --------- " <<  people[i].adress << endl;
        cout << endl;
    }
}
void modifying_person(vector <Person> &people) {

    Person new_persons;
    string name, surname, phone_number, email, adress;

    char choice;
    int persons_id;
    int vectors_value_int = people.size();
    cout << "enter person's id to edit:" << endl;
    cin >> persons_id;

    int i=0;

    while (i < vectors_value_int) {
        if ( persons_id == people[i].id ) {
            cout << "Friend's ID " << " --------- " << people[i].id << endl;
            cout << "Friend's name " << " --------- " << people[i].name << endl;
            cout << "Friend's surname " << " --------- " << people[i].surname << endl;
            cout << "Friend's phone number " << " --------- " << people[i].phone_number << endl;
            cout << "Friend's e-mail " << " --------- " << people[i].email << endl;
            cout << "Friend's adress " << " --------- " <<  people[i].adress << endl;
            cout << endl;

            cout << "Choose which feature you want to modify: " << endl;
            cout << "1. Name" << endl;
            cout << "2. Surname" << endl;
            cout << "3. Phone number" << endl;
            cout << "4. Email" << endl;
            cout << "5. Adress" << endl;
            cout << "6. Exit" << endl;
            cin >> choice;

            switch (choice) {

            case '1': {
                cout << "set new name" << endl;
                people[i].name = load_line();
                cout << "Name set correctly" << endl;
                break;
            }
            case '2': {
                cout << "set new surname" << endl;
                people[i].surname = load_line();
                cout << "Surname set correctly" << endl;
                break;
            }
            case '3': {
                cout << "set new phone number" << endl;
                people[i].phone_number = load_line();
                cout << "Name set correctly" << endl;
                break;
            }
            case '4': {
                cout << "set new email" << endl;
                people[i].email = load_line();
                cout << "Email set correctly" << endl;
                break;
            }
            case '5': {
                cout << "set new adress" << endl;
                people[i].adress = load_line();
                cout << "Adress set correctly" << endl;
                break;
            }
            case '6': {
                break;
            }
            default:
                cout << "enter proper character" << endl;
                cin >> choice;
            }
        }
        i++;
    }
    saving_to_file(people);
}
void deleting_user(vector <Person>&people) {

    Person new_persons;

    int users_id;
    char choice;
    cout << "enter user's ID you wish to delete: ";
    cin >> users_id;

    cout << "are you sure? (y/n)" << endl;
    cin >> choice;

    while (choice != 'y' || choice != 'n') {

        if (choice == 'y') {

            for (auto iterator = people.begin(); iterator != people.end(); iterator++) {

                if (iterator -> id == users_id) {
                    people.erase(iterator);
                    break;
                }
            }
            cout << "user deleted." << endl;
            system("pause");
            break;
        }
        else if (choice == 'n') {
            cout << "OK. user not deleted" << endl;
            system ("pause");
            break;
        }
        else {
            cout << "enter proper character: " << endl;
            cin >> choice;
        }
    }
    saving_to_file(people);
}
int main() {

    char choice;
    vector <Person> people;

    int persons_amount = people.size();

    persons_amount = loading_from_file(people);

    while (true) {

        system("cls");
        cout << "1. Add friend" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Search by surname" << endl;
        cout << "4. Show my friends list" << endl;
        cout << "5. Edit user" << endl;
        cout << "6. Delete user" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice) {

        case '1' : {
           persons_amount = insert_persons_data(people,persons_amount);
            system("pause");
            break;
        }
        case '2' : {
            showing_people_by_name (people);
            system("pause");
            break;
        }
        case '3' : {
            showing_people_by_surname(people);
            system("pause");
            break;
        }
        case '4' : {
            every_single_person(people);
            system("pause");
            break;
        }
        case '5': {
            modifying_person(people);
            system("pause");
            break;
        }
        case '6': {
            deleting_user(people);
            break;
        }
        case '8': {
            exit(0);
        }
        default: {
            cout << "try that again " << endl;
            cin>> choice;
            system("pause");
        }
        }
    }
    return 0;
    }
