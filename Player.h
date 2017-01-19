#include<iostream>
#include<string>
#include<sstream>

using namespace std;

//Player class, holds stats per individual football player
class Player
{
      private: 
               //instance variables
               string name;
               string position;
               double points[16];
               double average;
               string rank;
               
      public:
             Player();
             Player(string, string);
             ~Player(){};
             
             //Setters
             void setStats(string, string);
             void setName(string);
             void setposition(string);
             void setpoints(double []);
             void setAverage(double []);
             void setRank(string);             
             void toString();
             
             //Getters
             string getName();
             string getPosition();
             double getPoints();
             double getAverage();
             string getRank();
             double getWeek(int);
};  
//default constructor 
Player::Player()
{
         name = "";
         position = "";        
         average = 0.0;
         rank = "";
         for(int i = 0; i < 16; i++)
                 points[i] = 0.0;
}
//Main constructor
Player::Player(string theName, string thePosition)
{
        name = theName;
        position = thePosition;                  
}
//Setters
void Player::setName(string aName)
{
     name = aName;
}
void Player::setposition(string aPosition)
{
     position = aPosition;
}
void Player::setpoints(double array[])
{
     for(int i = 0; i < 16; i++)
     {
             points[i] = array[i];        
     }
     
}
void Player::setAverage(double array[])
{
     double total;
     for(int i = 0; i < 16; i++)
     {
         total += points[i];        
     }
     average =  (total/16.0);
     
}
void Player::setRank(string aRank)
{
     rank = aRank;
}
void Player::setStats(string player, string position)
{
     ifstream inFile;
     string line;
     
     
     if(position == "K") //search for Kicker
     {
         inFile.open("K.txt");
          if(!inFile)
          {
             cout << "Error: No file found" << endl;
             exit(1);           
          }
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            
            pos = line.find(player);
            
            string stats[22]; 
            double temp[16];
            
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                  
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 //Get stats from the saved line
                 for(int i = 0; i < 22; i++)
                 {
                      getFile >> stats[i];  
                 }
                 
                 //Set name  
                 string name = stats[1] + " " + stats[2];
                 
                 //set temp array which holds 16 week stats
                 for(int i = 0; i < 16; i++)
                 {
                         stringstream ss(stats[7 + i]);
                         ss >> temp[i];     
                 }
                 
                 //Set all instance varriables
                 setName(name);
                 setposition(position);
                 setpoints(temp);
                 setAverage(temp);
                 setRank(stats[0]);
            }
         }
         return;       
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
         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            
            pos = line.find(player);
            
            string stats[20];
            double temp[16];
            
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close(); 
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 //Get stats from the saved line
                 for(int i = 0; i < 20; i++)
                 {
                      getFile >> stats[i];  
                 }
                 
                 //Set name
                 string name = stats[1]; 
                 
                 //set temp array which holds 16 week stats
                 for(int i = 0; i < 16; i++)
                 {
                         stringstream ss(stats[4 + i]);
                         ss >> temp[i];     
                 }
                 
                 //Set all instance varriables
                 setName(name);
                 setposition(position);
                 setpoints(temp);
                 setAverage(temp);
                 setRank(stats[0]);
            }
         }
         return;
     }
     else if(position == "Flex")
     {
          inFile.open("Flex.txt");
          if(!inFile)  
         {
             cout << "Error: No file found" << endl;
             exit(1);           
         }
          size_t pos;  
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            
            pos = line.find(player);
            
            string stats[22];
            double temp[16];
            
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 //Get stats from the saved line
                 for(int i = 0; i < 22; i++)
                 {
                      getFile >> stats[i];  
                 }
                     
                 //Set name
                 string name = stats[1] + " " + stats[2];
                 
                 //set temp array which holds 16 week stats
                 for(int i = 0; i < 17; i++)
                 {
                         stringstream ss(stats[5 + i]);
                         ss >> temp[i];     
                 }
                 
                 //Set all instance varriables
                 setName(name);
                 setposition(position);
                 setpoints(temp);
                 setAverage(temp);
                 setRank(stats[0]);
            }
         }
         return;                
          
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

         
         size_t pos;
         
         inFile.seekg(0, ios::beg);
         while(inFile.good())
         {
            getline(inFile, line);
            
            pos = line.find(player);
            
            string stats[22];
            double temp[16];
            
            if(pos != string:: npos)
            {
                 ofstream outFile;       
                 outFile.open("temp.txt");  
                 
                 outFile << line;
                 
                 outFile.close();
                 
                 ifstream getFile;
                 getFile.open("temp.txt");
                 
                 //Get stats from the saved line
                 for(int i = 0; i < 22; i++)
                 {
                      getFile >> stats[i];  
                 }
                     
                 //Set name
                 string name = stats[1] + " " + stats[2];
                 
                 //set temp array which holds 16 week stats
                 for(int i = 0; i < 17; i++)
                 {
                         stringstream ss(stats[5 + i]);
                         ss >> temp[i];     
                 }
                 
                 //Set all instance varriables
                 setName(name);
                 setposition(position);
                 setpoints(temp);  
                 setAverage(temp);
                 setRank(stats[0]);
            }
         }
         return;                
     } 
     system("cls");     
}
string Player::getName()
{
       return name;
}
string Player::getPosition()
{
       return position;
}
double Player::getPoints()
{
       return;
}
double Player::getAverage()
{
       return average;
}
string Player::getRank()
{
       return rank;
}
double Player::getWeek(int week, int random)
{
       return points[week-1];
}
double Player:: getWeek(int week)
{
    return points[week-1];
}
void Player:: toString()
{
     cout << position << ": " << name << endl;             
}
