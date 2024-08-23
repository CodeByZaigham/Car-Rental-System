#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int price, flag = 0;
char username[100], password[100], name[30], choice[20];

void adminsignup()
{
     cout << "\n\nADMIN SIGNUP" << endl;
     cout << "************\n\n";
     cout << "Create Username: ";
     cin >> username;
     cout << "Create Password: ";
     cin >> password;
     ofstream file("adminaccount.txt", ios::app);
     if (file.is_open())
     {
          file << username << " " << password << endl;
          file.close();
          adminlogin();
     }
     else
     {
          cout << "Signup Unsuccessful...try again" << endl;
          adminsignup();
     }
}

void adminlogin()
{
     flag = 0;
     cout << "\n\nADMIN LOGIN" << endl;
     cout << "***********\n\n"
          << endl;
     cout << "Enter Username: ";
     cin >> username;
     cout << "Enter Password: ";
     cin >> password;
     ifstream file("adminaccount.txt");
     char Username[100], Password[100];
     while (file >> Username >> Password)
     {
          if (strcmp(Username, username) == 0 && strcmp(Password, password) == 0)
          {
               display_admin_menu();
               flag = 1;
               break;
          }
     }
     if (flag == 0)
     {
          cout << "Incorrect username or password...try again" << endl;
          adminlogin();
     }
}

void shopmenu()
{
     ifstream file("shopmenu.txt");
     char line[100];
     if (file.is_open())
     {
          cout << "\nSHOP MENU" << endl;
          cout << "=========\n"
               << endl;
          cout << "Vehicles " << " || " << " Prices" << endl;
          cout << "********      ******\n"
               << endl;
          while (file.getline(line,100))
          {
               cout << line << "\n"
                    << endl;
          }
          file.close();
     }
     else
     {
          cout << "Unable to open menu" << endl;
     }
}

void display_admin_menu()
{
     flag = 0;
     cout << "\nADMIN MENU" << endl;
     cout << "**********\n\n"
          << endl;
     cout << "1. Update Vehicles\n"
          << endl;
     cout << "2. Delete Users\n"
          << endl;
     cout << "3. Exit" << endl;
     while (true)
     {
          cout << "\nEnter your choice: ";
          cin >> choice;
          if (strcmp(choice, "1") == 0)
               update_admin_menu();
          else if (strcmp(choice, "2") == 0)
               delete_users();
          else if (strcmp(choice, "3") == 0)
               exit(0);
          else
          {
               cout << "Invalid input...try again" << endl;
          }
     }
}

void update_admin_menu()
{
     shopmenu();
     while (true)
     {
          cout << "\n\nEnter vehicle name: ";
          cin >> name;
          cout << "Enter vehicle price: ";
          cin >> price;
          if (cin.fail() || price<=0)
          {
               cin.clear();
               cin.ignore(100000, '\n');
               cout << "Incorrect price entered...try again" << endl;
               continue;
          }

          cout << "\nDo you wanna add Or delete vehicle? (ADD / DELETE): ";
          cin >> choice;
          if (strcmp(choice, "add") == 0)
          {
               ofstream file("shopmenu.txt", ios::app);
               if (file.is_open())
               {
                    file << name << "\t\t" << price << endl;
                    cout << "\nVehicle add-on successfully!\n"
                         << endl;
                    file.close();
               }
               else
               {
                    cout << "\nVehicle add-on unsuccessfull...try again\n"
                         << endl;
               }
               display_admin_menu();
          }
          else if (strcmp(choice, "delete") == 0)
          {
               flag = 0;
               ifstream infile("shopmenu.txt");
               ofstream outfile("temp.txt");
               char itemname[100];
               int itemprice;
               while (infile >> itemname >> itemprice)
               {
                    if (strcmp(itemname, name) == 0 && itemprice == price)
                    {
                         flag = 1;
                         continue;
                    }
                    outfile << itemname << " " << itemprice << endl;
               }
               infile.close();
               outfile.close();
               if (flag == 0)
               {
                    cout << "Can't delete vehicle!" << endl;
               }
               else
               {
                    remove("shopmenu.txt");
                    rename("temp.txt", "shopmenu.txt");
                    cout << "Vehicle deleted successfully!" << endl;
               }
               display_admin_menu();
          }
          else
          {
               cout << "\nInvalid choice...try again" << endl;
               cin.clear();
               cin.ignore(10000, '\n');
          }
     }
}

void usersignup()
{
     cout << "\n\nUSER SIGNUP" << endl;
     cout << "***********\n\n"
          << endl;
     cout << "Create Username: ";
     cin >> username;
     cout << "Create Password: ";
     cin >> password;

     ofstream file("useraccount.txt", ios::app);
     if (file.is_open())
     {
          file << username << " " << password << endl;
          file.close();
          userlogin();
     }
     else
     {
          cout << "Signup Unsuccessful...try again" << endl;
          usersignup();
     }
}

void userlogin()
{
     flag = 0;
     cout << "\n\nUSER LOGIN" << endl;
     cout << "*************\n\n"
          << endl;
     cout << "Enter Username: ";
     cin >> username;
     cout << "Enter Password: ";
     cin >> password;
     ifstream file("useraccount.txt");
     char Username[100], Password[100];
     while (file >> Username >> Password)
     {
          if (strcmp(Username, username) == 0 && strcmp(Password, password) == 0)
          {
               usermenu();
               flag = 1;
               break;
          }
     }
     if (flag == 0)
     {
          cout << "Incorrect username or password...try again" << endl;
          userlogin();
     }
}

void delete_users()
{
     ifstream file("useraccount.txt");
     char line[100];
     if (file.is_open())
     {
          cout << "\nUSERS" << endl;
          cout << "=====\n"
               << endl;
          cout << "Usernames " << " || " << " Passwords" << endl;
          cout << "*********      ********\n"
               << endl;
          while (file.getline(line, 100))
          {
               cout << line << "\n"
                    << endl;
          }
          file.close();
     }
     else
     {
          cout << "Unable to open menu" << endl;
     }
     cout << "\nEnter name of user you wanna delete: ";
     cin >> username;
     cout << "\nEnter password: ";
     cin >> password;
     flag = 0;
     ifstream infile("useraccount.txt");
     ofstream outfile("temp.txt");
     char Username[100], Password[100];
     while (infile >> Username >> Password)
     {
          if (strcmp(Username, username) == 0 && strcmp(Password, password) == 0)
          {
               flag = 1;
               continue;
          }
          outfile << Username << " " << Password << endl;
     }
     infile.close();
     outfile.close();
     if (flag == 0)
     {
          cout << "Can't delete user!" << endl;
          delete_users();
     }
     else
     {
          remove("useraccount.txt");
          rename("temp.txt", "useraccount.txt");
          cout << "User deleted successfully!" << endl;
          display_admin_menu();
     }
}

void usermenu()
{

     cout << "\n\nUSER MENU" << endl;
     cout << "*********\n\n"
          << endl;
     cout << "1. book vehicle\n"
          << endl;
     cout << "2. view car booking history\n"
          << endl;
     cout << "3. exit\n\n"
          << endl;
     while (true)
     {
          cout << "\nenter your choice: ";
          cin >> choice;
          if (strcmp(choice, "1") == 0)
               book_vehicle();
          else if (strcmp(choice, "2") == 0)
               view_car_history();
          else if (strcmp(choice, "3") == 0)
               exit(0);
          else
          {
               cout << "invalid input...try again" << endl;
          }
     }
}

void book_vehicle()
{
     shopmenu();
     int quantity, total = 0;
     char filePath[100];
     strcpy(filePath, username);
     strcat(filePath, "_history.txt");
     ofstream writefile(filePath, ios::app);
     while (strcmp(choice, "2") != 0)
     {
          cout << "\n\nEnter vehilce name you wanna rent: ";
          cin >> name;
          cout << "\nEnter quantity: ";
          cin >> quantity;
          if (cin.fail() || quantity<=0)
          {
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Invalid quantity. Please enter an integer." << endl;
               continue;
          }
          ifstream readfile("shopmenu.txt");
          char pname[30];
          int price;
          flag = 0;
          while (readfile >> pname >> price)
          {
               if (strcmp(name, pname) == 0)
               {
                    total += (price * quantity);
                    if (writefile.is_open())
                    {
                         writefile << name << " " << total << endl;
                    }
                    else
                    {
                         cout << "vehicle add unsuccessful...try again" << endl;
                    }
                    cout << "\nvehicle added successfully!" << endl;
                    flag = 1;
                    break;
               }
          }
          readfile.close();
          if (flag == 0)
          {
               cout << "incorrect name entered...try again" << endl;
               cin.clear();
               cin.ignore(10000, '\n');
               continue;
          }
          while (true)
          {
               cout << "\nPress 1 to book another vehicle\n"
                    << endl;
               cout << "Press 2 for checkout\n"
                    << endl;
               cin >> choice;
               if (strcmp(choice, "1") == 0)
               {
                    break;
               }
               else if (strcmp(choice, "2") == 0)
               {
                    payment(total);
               }
               else
               {
                    cout << "\nincorrect choice...try again\n"
                         << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
               }
          }
     }
     writefile.close();
     usermenu();
}

void payment(int total)
{
     while (true)
     {
          cout << "\nPress 1 for cash payment\n"
               << endl;
          cout << "\nPress 2 for card payment\n"
               << endl;
          cout << "\nPress 3 for installment\n"
               << endl;
          cout << "\nEnter your choice: ";
          cin >> choice;
          if (strcmp(choice, "1") == 0)
          {
               cout << "YOUR TOTAL BILL IS: " << total << endl;
               cout << "\nRIDE SAVE...THANKYOU\n"
                    << endl;
               break;
          }
          else if (strcmp(choice, "2") == 0)
          {
               cout << "Enter your card number(3651): " << endl;
               cin >> password;
               if (strcmp(password, "3651") == 0)
               {
                    cout << "TOTAL AMOUNT PAID: " << total << endl;
                    cout << "\nRIDE SAVE...THANKYOU\n"
                         << endl;
                    break;
               }
               else
               {
                    cout << "\nincorrect card number...try again\n"
                         << endl;
               }
          }
          else if (strcmp(choice, "3") == 0)
          {
               cout << "YOUR TOTAL BILL IS: " << total << endl;
               cout << "\nYou have got 3 months installments plan having amount due " << total / 3 << " each month\n"
                    << endl;
               cout << "Please pay your dues on time\n"
                    << endl;
               cout << "\nRIDE SAVE...THANKYOU\n"
                    << endl;
               break;
          }
          else
          {
               cout << "\nincorrect choice...try again\n"
                    << endl;
               cin.clear();
               cin.ignore(10000, '\n');
          }
     }
     usermenu();
}

void view_car_history()
{
     char filePath[100];
     strcpy(filePath, username);
     strcat(filePath, "_history.txt");
     ifstream file(filePath);
     char line[100];
     if (file.is_open())
     {
          cout << "\nVEHICLES HISTORY"
               << endl;
          cout << "****************\n\n"
               << endl;
          while (file.getline(line,100))
          {
               cout << line << endl;
          }
          file.close();
     }
     else
     {
          cout << "Unable to show vehicle history" << endl;
     }
     usermenu();
}