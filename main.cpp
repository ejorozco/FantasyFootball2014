/* Chapter No. 0       Final Project
   File Name:          main.ccp, Team.h, Player.h
   Programmer:         Eric Orozco
   Date Last Modified: 05/13/2014

   Problem Statement: For my CS150 final project, i will attempt to recreate
                      my own version of fantasy football program
   
   Overall Plan:
   main.ccp
   1. Create a main menu that uses a switch case and and a do-while loop
      switch case for entering a option, do-while to return to the main menu
   2. We will give the user 6 options. 
         1) Simulate two person team battle
         2) Create a custom team
         3) View cutom team
         4) Reseach
         5) Rules
         6) Exit
   3. We will create functions for all 6 options
   4. Do research and obtain actuall player stats, place stats to the file
   5. I will create a txt file for every fooball player position
   6. For each player stat line, it will have rank, first, lastName, totalYards,
      then points earned per week over the week 16 week season
   7. Option one: simulate: Ask for the users for thier username and passwords
      if entered correctly, pull all the players in thier team and construct
      a team object and the 9 player objects in the file. Data will be collected
      from the text file. Once the file is read and the objects are created,
      display the teams then pull thier weekly stats, use a random generator to 
      pull a specific weekly stats, add the stats to a total variable
      the team with the highest total wins. Use a loop to allow re-simulation
   8. Option two: Create a custom team. Get username, password, and team name
      from the user. Ask what player they want in thier team byb position.
      Add a total of 9 players ina team. Search the files
      Confirm the team with the user. If yes, save to file
   9. Option three: get username and password from the user. If the entered data
      matches the data in the file. Display custom team
   10.Option 4: Research, allow the user to enter a desired position to research.
       ASk the user for a player name, search files. If match, show all stats for
       the football player
   11. option 5: Rules. Dsplay rules how how points and determined
                 show rules on players and the game of fantasy football
                 note: RUN OUT OF TIME, INCLUDE IN SUMMER UPDATE
   12.Option 6: exit the program
   
   Team.h
   1. Create private instance variables for team name and 9 player objects
   2. Create getters and setters
   3. Create a constructor ffor the class, default and deconstructor
   4. create a function that searches through the custome file
      if username and password matches, create the Team object and its Player objects
   5. Create toStrings to view the team
   6. Create a case converter to avoid case sensitivity
   7. create a simulator function tyat pulls all weekly stats
      and calulates a winner versus another team
   8.Show reults
   
   Player.h
   1. create a stat instance varables
   2. Create its construcotrs and deconstructors
   3. Create getters and setters
   4. create a function that reads to a file and pull
      player stats. If name and player match, create the player object
   5. Use toString to show reults
   6. Use getters and setters to calculate the Player stats in the 
      simulator
      
   Classes needed and Purpose: To use all topics learned in class
                               variables, datatypes, loops, functions, classes
*/

//include all neccessay librarys/directories
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <iomanip>
#include"Team.h" //Include Team which hold Player objects

using namespace std;

//Create prototype functions
void logo();
void simulate();  
string getTeam(string, string);
void createTeam();
void viewTeam();
void Research();
void getFullStats(string);
void Rules();
string playerFinder(string);
string caseConverter(string);

int main()
{
    //Calls Personal NFL character picture
    logo();
    
    //Main Menu
    cout << "Prove Your Knowledge of NFL FootBall!" << endl;
    int option;
    do
    {
        //Main Menu screen
        cout << "\nMain Menu: " << endl;
        cout << "To Simulate 2 Team Battle:.Enter 1" << endl
             << "To Create a custom Team:...Enter 2" << endl
             << "To View Custom Team:.......Enter 3" << endl
             << "Research Players:..........Enter 4" << endl
             << "Fantasy Rules:.............Enter 5" << endl
             << "To Exit:...................Enter 6" << endl
             << "\nEnter option: ";
        
        cin >> option;
        
        switch(option)
        {
            case 1:
                 simulate(); //Simulate a two player battle
                 break;
            case 2:
                 createTeam(); //Allow the user to construct a custom team
                 break;
            case 3:
                 viewTeam();  //Allows user to view their team
                 break;
            case 4:
                 Research(); //Allows User to look up personal stats
                 break;
            case 5:
                 Rules(); //Allows user to Read Fantasy Football rules
                 break;
            case 6: 
                 exit(0); //Exit Program
                 break;
            default: 
              cout << "\nImproper Input: Please Enter a number from 1 - 6" << endl;
              break;               
        }
    }while(option > 0 || option < 4);
    
    //Ends Program
    cout << "\nThank You for Using BIG BOSS Football Simulator" << endl;
    cout << "Go Seahawks!!" << endl;
    
    system("PAUSE");
    return 0;
}

//This function will display a text base NFL logo
void logo()
{
    cout << "\t  ____       ___     ___________     ____        " << endl
         << "\t |    \\     |   |   |           |   |    |       " << endl
         << "\t |     \\    |   |   |   ________|   |    |       " << endl
         << "\t |      \\   |   |   |   |_____      |    |       " << endl
         << "\t |   |\\  \\  |   |   |         |     |    |       " << endl
         << "\t |   | \\  \\ |   |   |    _____|     |    |       " << endl
         << "\t |   |  \\  \\|   |   |   |           |    |       " << endl
         << "\t |   |   \\      |   |   |           |    |       " << endl
         << "\t |   |    \\     |   |   |           |    |_____  " << endl
         << "\t |   |     \\    |   |   |           |          | " << endl
         << "\t |___|      \\___|   |___|           |__________| " << endl << "\n"; 
              
    cout << "Welcome BIG BOSS FANTASY FOOTBALL Simulator (C++ edition 1.0.12.69.1)" << endl;
}
//option 1: Simulate, Allows two player to login and  battle thier teams 
void simulate()      
{
     system("cls");
     cout << "Simulator Initialted: " << endl;
     
     string team1;
     //Get Team 1//
     do
     {
           //Get User 1 profile login
           cout << "Loging In team 1: " << endl;
           cout << "Username: ";
           string username;
           cin.ignore();
           getline(cin, username); //player one username
     
           cout << "Password: ";
           string password;
           getline(cin, password); //player two password
           
           team1 = getTeam(username, password); //find profile team name
          
     }while(team1 == " "); //If team name is found, stop loop
     
      //Get Team 2
      string team2;
     do
     {
             //Get User 2 profile login
            cout << "Loging In team 2: " << endl;
            cout << "Username: ";
            string username;
            getline(cin, username); //Player two username
     
            cout << "Password: ";
            string password;
            getline(cin, password); //Player two password
           
           team2 = getTeam(username, password);  //find profile name
          
     }while(team2 == " "); //if team is found, stop loop
     
     system("pause");     
     system("cls");
     
     //Announce teams
     cout << team1 << " VS. " << team2 << endl; 
     
     //Create Team objects
     Team fantasyTeam1(team1);
     Team fantasyTeam2(team2);
     
       
     //Show each user's roster
     cout << "\n";
     cout << "Player 1: "<< endl;
           fantasyTeam1.toString();
     cout << "\n";
     cout << "Player 2: " << endl;
           fantasyTeam2.toString();
           
     system("pause");
     system("cls");
      
      //Controls re-simulation loop
      int redo = 0;
      
      //Holds the records per each user
      int wins1 = 0;
      int lose1 = 0;
      
      int wins2 = 0;
      int lose2 = 0;
      
      
      do
      {     
            //Start Sim      
         cout << "\nTeams have been set: Simulation will now begin..."<< endl;
         int weekPlay = rand() % 15;
         cout << "Week " << weekPlay << " has been selected....." << endl;
         cout << "Press any key to initiate: " << endl;
         
         //Get reults
         double result1 = fantasyTeam1.calcSim(weekPlay);
         double result2 = fantasyTeam2.calcSim(weekPlay);
         
         //If player one has more pints
         if(result1 > result2)
         {
             cout << fantasyTeam1.getTeamName() << " WINS!!!" << endl;
             wins1++; //update records
             lose2++;           
         }
         else
         {
             cout << fantasyTeam2.getTeamName() << " WINS!!!" << endl;
             lose1++; //update records
             wins2++;    
         }
         
         //Show records
         cout << "\n";
         cout << fantasyTeam1.getTeamName() << "...(W/L).."<< wins1 << "-"<< lose1 << endl;
         cout << fantasyTeam2.getTeamName() << "...(W/L).."<< wins2 << "-"<< lose2 << endl;
         cout << "\n";
         
         //Ask for redo
         cout << "RE-TRY: 0=yes, 1=no" << endl;
         cin >> redo;
         system("cls");
             
      }while(redo == 0); //if ==0, re simulate
     cout << "Simulator Closing" << endl;              
}
//This function works with option 1:Simulate
//This will try and find team name and its players
string getTeam(string username, string password)
{
     //Open custom txt that holds teams
     ifstream inFile;
     inFile.open("custom.txt");
     
     //Convert to uppercase to rid of case sensitivity
     string temp1 = caseConverter(username);
     string temp2 = caseConverter(password);

     //Set pointer to begining of file
     inFile.seekg(0, ios::beg);
     
     //Continue reading file until a match is found
     do
     {
         string line1;
         getline(inFile, line1); //Get username
         
         string line2;
         getline(inFile, line2); //Get password
         
         //Convert to uppercase to avoid case senitivity
         string temp3 = caseConverter(line1);
         string temp4 = caseConverter(line2);
         
         string line3;
         getline(inFile, line3); //Team name
           
         string qb;
         getline(inFile, qb);  //qb name
         
         string rb1;
         getline(inFile, rb1); //rb name
         
         string rb2;
         getline(inFile, rb2); //rb name
         
         string wr1;
         getline(inFile, wr1); //wr name
         
         string wr2;
         getline(inFile, wr2); //wr name
         
         string te;
         getline(inFile, te); //te name
         
         string flex;
         getline(inFile, flex); //flex name
              
         string k;
         getline(inFile, k); //k name
         
         string d;
         getline(inFile, d); //d name
         
         if(temp1 == temp3 && temp2 == temp4) //if username and password matches
         {
             cout << "\tTeam Name:... " << line3 << endl;

              inFile.close(); //close file
              return line3; //show team name         
         }
         if(inFile.eof()) //end of file
         {
             inFile.close(); //close file
             break;                
         }                    
     }while(inFile.good());
     
     return " "; //return this if no match is found
}  
//Option 2
//View custom team for the user, they will enter username and password
void viewTeam()
{
     int message  = 0;
     system("cls");
     
     //open custom file that holds teams and thier players
     ifstream inFile;
     inFile.open("custom.txt");
     
     cout << "You have chosen to view Custom Team: " << endl;
     cout << "Username: ";
     string username;
     cin.ignore();
     getline(cin, username); //get username
     
     cout << "Password: ";
     string password;
     getline(cin, password); //get password
     
     //To upper case, avoid case sensitivity
     string temp1 = caseConverter(username);
     string temp2 = caseConverter(password);
     
     //Search through file
     while(inFile.good())
     {
         string line1;
         getline(inFile, line1);
         
         string line2;
         getline(inFile, line2);
         
         string temp3 = caseConverter(line1);
         string temp4 = caseConverter(line2);
         
         string line3;
         getline(inFile, line3);
         
         string qb;
         getline(inFile, qb); 
         
         string rb1;
         getline(inFile, rb1); 
         
         string rb2;
         getline(inFile, rb2); 
         
         string wr1;
         getline(inFile, wr1); 
         
         string wr2;
         getline(inFile, wr2); 
         
         string te;
         getline(inFile, te); 
         
         string flex;
         getline(inFile, flex); 
         
         string k;
         getline(inFile, k); 
         
         string d;
         getline(inFile, d); 
         
         if(temp1 == temp3 && temp2 == temp4) //if username and password matches
         {
             //Show custom team
             cout 
              << "\tTeam Name:... " << line3 << endl
              << "\tQB:.......... " << qb << endl
              << "\tRB:.......... " << rb1 << endl
              << "\tRB:.......... " << rb2 << endl
              << "\tWR:.......... " << wr1 << endl
              << "\tWR:.......... " << wr2 << endl
              << "\tTE:.......... " << te << endl
              << "\tFlex:........ " << flex << endl
              << "\tK:........... " << k << endl
              << "\tDEF:......... " << d << endl;
              system("pause");
              system("cls");
              return;
         }   
                             
     }
     message++; //increment if no record is found
     if(message == 1)
     {
         cout << "No record found: " << endl;
     }
}
//Option 3
//Allow the user to create thier own custom team
void createTeam()
{
         system("cls");
         string username;
         string password;
         string teamName;
         int size;
         
         
         cout << "You have selected to create a new Custom Team: " << endl
              << "Creating a new Account: " << endl;
         
         cout << "\nUsername: ";
         cin.ignore();
         getline(cin, username); //User enters thier username
         
         cout << "\nPassword: ";
         getline(cin, password); //User enters thier password
         
         cout << "\nTeam Name: ";
         getline(cin, teamName); //user enters thier team name
         
         system("cls");
         
         //Team info has been created
         
         //Find QB//////////////////////////////// 
         string foundQB;
         do
         {
            cout << "Selecting QuarterBack: " << endl;
            foundQB = playerFinder("QB");
            if(foundQB == " ")
            {
                cout << "Error: No Match Please try again" << endl << "\n\n";
            }
            
         }while(foundQB == " ");
         system("cls");
         /////////////////////////////////////////
         
         
         
         //Find RB////////////////////////////////
         string foundRB1;
         do
         {
            cout << "Selecting RB 1: " << endl;
            foundRB1 = playerFinder("RB");
            if(foundRB1 == " ")
            {
                cout << "Error: No Match Please try again" << endl << "\n\n";
            }
            
         }while(foundRB1 == " ");
         system("cls");
         
         ///////////////////////////////////////////
         string foundRB2;
         do
         {
            cout << "Selecting RB 2: " << endl;
            foundRB2 = playerFinder("RB");
            if(foundRB2 == " ")
            {
                cout << "Error: No Match Please try again" << endl << "\n\n";
            }
            if(foundRB2 == foundRB1)
            {
                 cout << "Cannot the same player twice"  << endl << "\n\n";     
            }
            
         }while(foundRB2 == " " || foundRB2 == foundRB1);
         system("cls");
         //////////////////////////////////////////
         
         //Find WR/////////////////////////////////
         string foundWR1;
         do
         {
            foundWR1 = playerFinder("WR");
            if(foundWR1 == " ")
            {
                cout << "Error: No Match Please try again" << endl << "\n\n";                    
            }
            
         }while(foundWR1 == " ");
         system("cls");
         
         /////////////////////////////////////////
         string foundWR2;
         do
         {
            foundWR2 = playerFinder("WR");
            
            if(foundWR2 == " ")
                 cout << "Error: No Match Please try again" << endl << "\n\n";
            
            if(foundWR2 == foundWR1)
            {
                 cout << "Cannot the same player twice"  << endl << "\n\n";     
            }
            
         }while(foundWR2 == " " || foundWR2 == foundWR1);
         system("cls");
         /////////////////////////////////////////////
         
         //Find TE////////////////////////////////////
         string foundTE1;
         do
         {
             foundTE1 = playerFinder("TE");
             if(foundTE1 == " ")
             {
                 cout << "Error: No Match Please try again" << endl << "\n\n"; 
             }
              
         }while(foundTE1 == " ");
         system("cls");
         //////////////////////////////////////////////
         
         //Find Flex//////////////////////////////////
         string foundFlex;
         int spot;
         do
         {
             cout << "Choose Your Flex type: [1] = RB, [2] = WR: "; 
             cin >> spot;
             if(spot == 1)
             do
             {
                  foundFlex = playerFinder("RB");
                  
             }while(foundFlex == " " || foundFlex == foundRB1 || foundFlex == foundRB2);
             if(spot == 2)
             do
             {
                  foundFlex = playerFinder("WR");
                  
             }while(foundFlex == " " || foundFlex == foundWR1 || foundFlex == foundWR2);
                  
         }while(spot < 1 || spot > 2);
         system("cls");
         //////////////////////////////////////////////
         
         //Find K/////////////////////////////////////
         string foundK1;
         do
         {
                foundK1 = playerFinder("K");
                if(foundK1 == " ")
                {
                    cout << "Error: No Match Please try again" << endl << "\n\n";        
                }
                
         }while(foundK1 == " ");
         system("cls");
         /////////////////////////////////////////////
         
         
         //Find Def//////////////////////////////////
         string foundDEF1;
         do
         {
                foundDEF1 = playerFinder("DEF");
                if(foundDEF1 == " ")
                {
                    cout << "Error: No Match Please try again" << endl << "\n\n";        
                }
                
         }while(foundDEF1 == " ");
         system("cls");
         /////////////////////////////////////////////
         //Show all player results
         cout << "\tUsername:.... " << username << endl
              << "\tPassword:.... " << password << endl
              << "\tTeam Name:... " << teamName << endl
              << "\tQB:.......... " << foundQB << endl
              << "\tRB:.......... " << foundRB1 << endl
              << "\tRB:.......... " << foundRB2 << endl
              << "\tWR:.......... " << foundWR1 << endl
              << "\tWR:.......... " << foundWR2 << endl
              << "\tTE:.......... " << foundTE1 << endl
              << "\tFlex:........ " << foundFlex << endl
              << "\tK:........... " << foundK1 << endl
              << "\tDEF:......... " << foundDEF1 << endl;
         
         //Allow user to accpet thier team
         char final;
         cout << "Do you like your Custom Team?(y/n): ";
         cin >> final;
         if(final == 'y' || final == 'Y')
         {
                // Create output stream object
                ofstream outFile;
                // Open file, nums.txt, to append at the end
                outFile.open("custom.txt", ios::app);
                
                outFile << username << endl
                        << password << endl
                        << teamName << endl
                        << foundQB << endl
                        << foundRB1 << endl
                        << foundRB2 << endl
                        << foundWR1 << endl
                        << foundWR2 << endl
                        << foundTE1 << endl
                        << foundFlex << endl
                        << foundK1 << endl
                        << foundDEF1 << endl;
                
                outFile.close(); //close the file
         }
         system("cls");
         return;
}
//option 4
//Allow user to find stats per individual player
void Research()
{
     system("cls");
     cout << "NFL Fantasy Research Center" << endl;
     bool flag = true;
     do
     {
       int option = 0;   
      
      //Allow user fo enter desired position
       cout << "Research Main Menu: " << endl;
       cout << "\n"
            << "QB:  QuarterBack.....Enter 1" << endl
            << "RB:  RunningBack.....Enter 2" << endl
            << "WR:  WideReciever....Enter 3" << endl
            << "TE:  TightEnd........Enter 4" << endl
            << "K:   Kicker..........Enter 5" << endl
            << "DEF: Defense.........Enter 6" << endl
            << "Return to Menu.......Enter 7" << endl
            << "\nEnter Option: " ;
            
       //determine which file to search
       cin >> option;
       switch(option)
       {
           case 1:
                getFullStats("QB"); //search Quarterbacks
                break;
           case 2:
                getFullStats("RB"); //search Runningbacks
                break; 
           case 3:
                getFullStats("WR"); //search Widereciever
                break;  
           case 4:
                getFullStats("TE"); //search Tightends
                break;
           case 5:
                getFullStats("K"); //search Kickers
                break;
           case 6:
                getFullStats("DEF"); //search DEF
                break;         
           case 7:
                system("cls");
                return;
                break;   
           default: 
              cout << "\nImproper Input: Please Enter a number from 1 - 5" << endl;
              break;            
       }
       system("cls");
     }while(flag == true);
     
}
//Called upon in option 4 research function
//Displays individual player stats from the files
void getFullStats(string position)
{
     
     string search;  //User desired search played
     ifstream inFile;
     string line;
     
     //If position is Kicker
     if(position == "K") //search for Kicker
     {
         
         if(position == "K")
              inFile.open("K.txt");
              
         if(!inFile)
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
         
         
         cout << "\nPlease Select a " << position << " : "<< endl;
         cout << "Enter Last or first name: "; //find player

         cout << "\nSearch: ";
         cin  >> search; 
         
         //To upper case
         string convertSearch = caseConverter(search);
         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            string convertLine = caseConverter(line); 
            
            //if player is found in the line string
            pos = convertLine.find(convertSearch);
            
            string stats[22]; //saved stats
            if(pos != string:: npos) //if match is found
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 for(int i = 0; i < 22; i++)
                 {
                      getFile >> stats[i];        
                 }
                 string name = stats[1] + " " + stats[2];
                 cout << "\n";
                      cout << "\tName:......... " << name << endl
                           << "\tTeam:......... " << stats[3] << endl
                           << "\tPosition:..... " << position << endl
                           << "\tRanking:...... " << stats[0] << endl
                           << "\tField Goals:.. " << stats[4] << endl
                           << "\tAccuracy:..... " << stats[5] << endl;
                           for(int i = 7; i < 22; i++)
                           {
                               if(i < 16)
                                  cout << "\tWeek " << (i-6) << ":   " << stats[i] << endl;         
                               else
                                  cout << "\tWeek " << (i-6) << ":  " << stats[i] << endl;         
                           }
                 system("pause");
                 break;
                           
            }//found Kicker
         }//end of while loop search
      
     }
     //If position is DEF
     else if(position == "DEF") //search for DEF
     {
            //Open DEF file
         if(position == "DEF")
                 inFile.open("DEF.txt");
                 
         if(!inFile)
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
         
         cout << "\nPlease Select a " << position << " : "<< endl;
         cout << "Enter Team Defense: ";

         cout << "\nSearch: ";
         cin  >> search;   //enter team
         
         //Convert to uppercase
         string convertSearch = caseConverter(search);
         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            string convertLine = caseConverter(line); 
            
            //Find search within the line
            pos = convertLine.find(convertSearch);
            
            string stats[20];
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close(); 
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 //Add to the stats array
                 for(int i = 0; i < 20; i++)
                 {
                      getFile >> stats[i];        
                 }
                   
                 //Show individual stats  
                 cout << "\n"
                      << "\tTeam:.......... " << stats[1] << endl
                      << "\tPosition:...... " << position << endl
                      << "\tRanking:....... " << stats[0] << endl
                      << "\tPoints Allow:.. " << stats[2] << endl
                      << "\tSacks:......... " << stats[3] << endl;
                       for(int i = 4; i < 20; i++)
                           {
                                 if(i < 13)
                                  cout << "\tWeek " << (i-3) << ":   " << stats[i] << endl;         
                               else
                                  cout << "\tWeek " << (i-3) << ":  " << stats[i] << endl;        
                           }
                 system("pause");
                 break;
            }
         }
     }
     else  //option will search for QB, WR, or RB
     {
         if(position == "QB")  
                 inFile.open("QB.txt");
         else if(position == "RB") 
                 inFile.open("RB.txt");
         else if(position == "WR")  
                 inFile.open("WR.txt");
         else if(position == "TE")
                 inFile.open("TE.txt");

         if(!inFile)
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
         
         cout << "\nPlease Select a " << position << " : "<< endl;
         cout << "Enter a first or last name: ";

         cout << "\nSearch: ";
         cin  >> search;
         
         string convertSearch = caseConverter(search);
         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            string convertLine = caseConverter(line); 
            
            pos = convertLine.find(convertSearch);
            
            string stats[22];
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  //write line to txtx file
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 //Put stats in string array
                 for(int i = 0; i < 22; i++)
                 {
                      getFile >> stats[i];        
                 }
                 
                 //Show stats
                 string name = stats[1] + " " + stats[2];
                 cout << "\n";
                 cout << "\tName:......... " << name << endl
                      << "\tTeam:......... " << stats[3] << endl
                      << "\tPosition:..... " << position << endl
                      << "\tRanking:...... " << stats[0] << endl
                      << "\tTotal Yards:.. " << stats[4] << endl
                      << "\tTDs:.......... " << stats[5] << endl;
                 for(int i = 6; i < 22; i++)
                 {
                       if(i < 15)
                          cout << "\tWeek " << (i-5) << ":   " << stats[i] << endl;         
                       else
                          cout << "\tWeek " << (i-5) << ":  " << stats[i] << endl;          
                 }
                 system("pause");
                 break;
            }
                                           
         }//of of inner while llopp   
     }
}
//option 5
void Rules()
{
     //RULES will be imp-lemented in a future update
     //Ran out of time to make this part of the code
     //Reder to NFL.com/fantasy for full rules and regulations
}

//Search file functions
string playerFinder(string position)
{
     string search;
     ifstream inFile;
     string line;
     
     if(position == "K") //search for Kicker
     {
         
         if(position == "K")
              inFile.open("K.txt");
              
         if(!inFile)
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
         
         cout << "\nPlease Select a " << position << " : "<< endl;
         cout << "Enter Last or first name: ";

         cout << "\nSearch: ";
         cin  >> search;
         
         string convertSearch = caseConverter(search);
         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            string convertLine = caseConverter(line); 
            
            pos = convertLine.find(convertSearch);
            
            string stats[21];
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 for(int i = 0; i < 20; i++)
                 {
                      getFile >> stats[i];        
                 }
                 
                 string name = stats[1] + " " + stats[2];
                 cout << "\n";
                      cout << "\tName:......... " << name << endl
                           << "\tTeam:......... " << stats[3] << endl
                           << "\tPosition:..... " << position << endl
                           << "\tRanking:...... " << stats[0] << endl
                           << "\tField Goals:.. " << stats[4] << endl
                           << "\tAccuracy:..... " << stats[5] << endl;
                 char input;     
                  cout << "\nDo you accept player(Y/N):  ";
                  cin >> input;
                  if(input == 'y' || input == 'Y')
                  {
                           inFile.close();
                           return name;
                           break;        
                  }
                  else
                  {
                      break;
                  }
            }
         }
         return " ";       
     }
     else if(position == "DEF") //search for DEF
     {
            
         if(position == "DEF")
                 inFile.open("DEF.txt");
                 
         if(!inFile)
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
         
         cout << "\nPlease Select a " << position << " : "<< endl;
         cout << "Enter Team Defense: ";

         cout << "\nSearch: ";
         cin  >> search;
         
         string convertSearch = caseConverter(search);
         
         size_t pos;  
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            string convertLine = caseConverter(line); 
            
            pos = convertLine.find(convertSearch);
            
            string stats[20];
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 for(int i = 0; i < 20; i++)
                 { 
                      getFile >> stats[i];        
                 }
                   
                 cout << "\n"
                      << "\tTeam:.......... " << stats[1] << endl
                      << "\tPosition:...... " << position << endl
                      << "\tRanking:....... " << stats[0] << endl
                      << "\tPoints Allow:.. " << stats[2] << endl
                      << "\tSacks:......... " << stats[3] << endl;
                 char input;     
                  cout << "\nDo you accept player(Y/N):  ";
                  cin >> input;
                  if(input == 'y' || input == 'Y')
                  {
                           inFile.close();
                           return stats[1];
                           break;        
                  }
                  else
                  {
                      break;
                  }
            }
         }
         return " ";
     }
     else  //option will search for QB, WR, or RB
     {
         if(position == "QB")  
                 inFile.open("QB.txt");
         else if(position == "RB") 
                 inFile.open("RB.txt");
         else if(position == "WR")  
                 inFile.open("WR.txt");
         else if(position == "TE")
                 inFile.open("TE.txt");

         if(!inFile)
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
         
         cout << "\nPlease Select a " << position << " : "<< endl;
         cout << "Enter a first or last name: ";

         cout << "\nSearch: ";
         cin  >> search;
         
         string convertSearch = caseConverter(search);
         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good()) //search file
         {
            getline(inFile, line);
            string convertLine = caseConverter(line); 
            
            pos = convertLine.find(convertSearch);
            
            string stats[22];
            if(pos != string:: npos) //if search is found in the file
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 for(int i = 0; i < 22; i++)
                 {
                      getFile >> stats[i];        
                 }
                 
                 //Show stats
                 string name = stats[1] + " " + stats[2];
                 cout << "\n";
                 cout << "\tName:......... " << name << endl
                      << "\tTeam:......... " << stats[3] << endl
                      << "\tPosition:..... " << position << endl
                      << "\tRanking:...... " << stats[0] << endl
                      << "\tTotal Yards:.. " << stats[4] << endl
                      << "\tTDs:.......... " << stats[5] << endl;
                 char input;     
                  cout << "\nDo you accept player(Y/N):  ";
                  cin >> input;
                  if(input == 'y' || input == 'Y')
                  {
                           inFile.close();
                           return name;
                           break;        
                  }
                  else
                  {
                      break;
                  }
            }                                
         }//of of inner while llopp
         
         return " ";
         
     }
     system("cls"); 
}
//Function converts string to uppercase
//Elmintaes the need to be case sensitive
string caseConverter(string line)
{
     int size = line.size();
     for(int i = 0; i < size; i++)
     {
        if(islower(line[i]))
        {
           line[i] = toupper(line[i]);
        }
     }
     return line;
}
