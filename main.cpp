#include "functions.cpp"

int main() {
    cout << "\n\n*********************"<<endl;
    cout << "VEHICLE RENTAL SYSTEM" << endl;
    cout << "*********************\n\n";
    cout << "1. Admin login/signup" << endl;
    cout << "2. User login/signup" << endl;
    cout << "3. Exit\n" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (strcmp(choice, "1") == 0) {
            cout << "\n1. Login" << endl;
            cout << "2. Signup\n" << endl;
            cout << "\nEnter your choice: ";
            cin >> choice;
            if (strcmp(choice, "1") == 0)
                adminlogin();
            else if (strcmp(choice, "2") == 0)
                adminsignup();
            else
                cout << "\nInvalid input...try again" << endl;
        } else if (strcmp(choice, "2") == 0) {
            cout << "\n1. Login" << endl;
            cout << "2. Signup\n" << endl;
            cout << "\nEnter your choice: ";
            cin >> choice;
            if (strcmp(choice, "1") == 0)
                userlogin();
            else if (strcmp(choice, "2") == 0)
                usersignup();
            else
                cout << "\nInvalid input...try again" << endl;
        } else if (strcmp(choice, "3") == 0) {
            exit(0);
        } else {
            cout << "\nInvalid input...try again" << endl;
        }
    }

    return 0;
}


