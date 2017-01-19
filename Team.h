#include<iostream>
#include<string>        //for use of strings
#include"Player.h"

using namespace std;

class Team
{
      private:
              //Instance variables and Player objects
               string teamName;
               Player QuarterBack;
               Player RunningBack1;
               Player RunningBack2;
               Player WideReciever1;
               Player WideReciever2;
               Player TightEnd;
               Player Flex;
               Player Kicker;
               Player DEF; 
             
             int overallRank;
             double calcPoints;
             
      public:
             Team();
             Team(string);
             ~Team();
             
             //accessor functions, setters
             void setTeamName(string);
             string getTeamName();
             void findTeam(string);
             
             string caseConverter(string);
             double calcSim(int);
             void toString();
             
};
Team::Team()
{
    teamName = "";
    overallRank = 0;
    calcPoints = 0.0;  
}
Team::Team(string team)
{
       setTeamName(team);   
       findTeam(team);
}
Team::~Team()
{
                     
}

void Team::setTeamName(string theTeam)
{
    teamName = theTeam;
}
string Team:: getTeamName()
{
       return teamName;
}
void Team::findTeam(string team)
{
     string line1;  //holds username
     string line2;  //holds password
     string line3;  //holds team
     string find = team; //team that is passed
     
     //Get player names
     string qb;
     string rb1;
     string rb2;
     string wr1;
     string wr2;
     string te;
     string flex;
     string k;
     string d;
     
     
     ifstream inFile;
     inFile.open("custom.txt");
        
     while(inFile.good())
     {
         //Read from the file
         getline(inFile, line1);
         getline(inFile, line2);
         getline(inFile, line3);
         getline(inFile, qb); 
         getline(inFile, rb1); 
         getline(inFile, rb2); 
         getline(inFile, wr1); 
         getline(inFile, wr2); 
         getline(inFile, te); 
         getline(inFile, flex); 
         getline(inFile, k); 
         getline(inFile, d); 
            
         if(caseConverter(team) == caseConverter(line3))
         {
             //Set all player objects
             QuarterBack.setStats(qb, "QB");
             RunningBack1.setStats(rb1, "RB"); 
             RunningBack2.setStats(rb2, "RB");
             WideReciever1.setStats(wr1, "WR");
             WideReciever2.setStats(wr2, "WR");
             TightEnd.setStats(te, "TE");
             Flex.setStats(flex, "Flex");
             Kicker.setStats(k, "K");
             DEF.setStats(d, "DEF");   
             inFile.close();
             break;     
         }
         if(inFile.eof())  
         {
             inFile.close();
             break;                  
         }                                      
     }    
}
double Team:: calcSim(int week)
{
       //holds total points
     double total = 0;
     
     //Get week stats from each player
     double q1 = QuarterBack.getWeek(week);
     double r1 = RunningBack1.getWeek(week);
     double r2 = RunningBack2.getWeek(week);
     double w1 = WideReciever1.getWeek(week);
     double w2 = WideReciever2.getWeek(week);
     double t1 = TightEnd.getWeek(week);
     double f1 = Flex.getWeek(week);
     double k1 = Kicker.getWeek(week);
     double d1 = DEF.getWeek(week);    
     
     //Show reults
     cout << "Week: " << week << "\tPlayer: " << endl;
     
     cout << q1 << "\t\t";
     QuarterBack.toString();
     
     cout << r1 << "\t\t";
     RunningBack1.toString();
     
     cout << r2 << "\t\t";
     RunningBack2.toString();
     
     cout << w1 << "\t\t";
     WideReciever1.toString();
     
     cout << w2 << "\t\t";
     WideReciever2.toString();
     
     cout << t1 << "\t\t";
     TightEnd.toString();
     
     cout << f1 << "\t\t";
     Flex.toString();
     
     cout << k1 << "\t\t";
     Kicker.toString();
     
     cout << d1 << "\t\t";
     DEF.toString();
     
     //Add to total
     total = q1 + r1 + r2 + w1 + w2 + t1 + f1 + k1 + d1;
     
     cout << "Total: " << total << endl << "\n";  //show end total
     
     return total;
}
//Show player stats
void Team:: toString()  
{
     QuarterBack.toString();
     RunningBack1.toString();
     RunningBack2.toString();
     WideReciever1.toString();
     WideReciever2.toString();
     TightEnd.toString();
     Flex.toString();
     Kicker.toString();
     DEF.toString();
}
//Converts string to upper case
//Avoids case sensitivity
string Team:: caseConverter(string line)
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
/////////////////////////////////////////////////////////////////////////////
