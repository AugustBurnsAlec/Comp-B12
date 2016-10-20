//
//  main.cpp
//  TeamRosterProject
//
//  Created by Alec Sherlock on 10/11/16.
//  Copyright © 2016 Alec Sherlock. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Function that prints menu
void menu()
{
    cout << "\n MENU \n a - Add player \n d - Remove player \n u - Update player rating \n r - Output players above a rating \n o - Output roster \n q - Quit \n ";
}

//Function that adds player to roster
void addPlayer(vector<int>& jerseyNumbers, vector<int>& ratings)
{
    int temp;
    
    //Reading jersey numbers
    cout << "\n Enter player jersey number: ";
    cin >> temp;
    
    //Storing in vector
    jerseyNumbers.push_back(temp);
    
    //Reading rating
    cout << "\n Enter player rating: ";
    cin >> temp;
    
    //Storing in vector
    ratings.push_back(temp);
    
    cout << "\n Player has been added successfully \n";
}

//Function that prints ROSTER to console
void outputRoster(vector<int> jerseyNumbers, vector<int> ratings)
{
    int i;
    
    cout << "\n\n ROSTER \n";
    
    //Looping over each element in the vector and printing to console
    for(i=0; i<jerseyNumbers.size(); i++)
        cout << "\n Player " << (i+1) << " --- Jersey Number: " << jerseyNumbers[i] << ", Rating: " << ratings[i];
    
    cout << "\n\n";
}

//Function that deletes an existing player from roster
void deletePlayer(vector<int>& jerseyNumbers, vector<int>& ratings)
{
    int jerseyNumber;
    int pos = -1;             //flag for
    int i;
    
    //Reading jersey numbers
    cout << "\n Enter player jersey number: ";
    cin >> jerseyNumber;
    
    //Looping over each element in the vector and searching for given jersey number
    for(i=0; i<jerseyNumbers.size(); i++)
    {
        //Comparing player jersey numbers
        if(jerseyNumbers[i] == jerseyNumber)
            pos = i;
    }
    
    //If player not found
    if(pos == -1)
    {
        cout << "\n No player exists with given Jersey Number.... \n";
    }
    else
    {
        //Deleting jersey number from vector
        jerseyNumbers.erase(jerseyNumbers.begin() + pos);
        
        //Deleting ratings from vector
        ratings.erase(ratings.begin() + pos);
        
        cout << "\n Player with jersey number " << jerseyNumber << " has been deleted.... \n";
    }
}

//Function that updates an existing player from roster
void updatePlayer(vector<int>& jerseyNumbers, vector<int>& ratings)
{
    int jerseyNumber, rating;
    int pos = -1,i;
    
    //Reading jersey numbers
    cout << "\n Enter player jersey number: ";
    cin >> jerseyNumber;
    
    //Looping over each element in the vector and searching for given jersey number
    for(i=0; i<jerseyNumbers.size(); i++)
    {
        //Comparing player jersey numbers
        if(jerseyNumbers[i] == jerseyNumber)
            pos = i;
    }
    
    //If player not found
    if(pos == -1)
    {
        cout << "\n No player exists with given Jersey Number.... \n";
    }
    else
    {
        //Reading new rating
        cout << "\n Enter a new rating for player: ";
        cin >> rating;
        
        //Updating ratings vector
        ratings[pos] = rating;
        
        cout << "\n Player with jersey number " << jerseyNumber << " has been updated.... \n";
    }
}

//Function that displays the details of player whose rating is above the given rating
void aboveRating(vector<int> jerseyNumbers, vector<int> ratings)
{
    int rating, i;
    
    //Reading rating
    cout << "\n Enter a rating: ";
    cin >> rating;
    
    cout << "\n\n ABOVE " << rating << " \n";
    
    //Looping over each element in the vector and printing to console
    for(i=0; i<jerseyNumbers.size(); i++)
    {
        if(ratings[i] > rating)
            cout << "\n Player " << (i+1) << " --- Jersey Number: " << jerseyNumbers[i] << ", Rating: " << ratings[i];
    }
    
    cout << "\n\n";
}

//Main function
int main()
{
    //Vectors to hold jersey numbers
    vector<int> jerseyNumbers;
    
    //Vectors to hold ratings
    vector<int> ratings;
    
    int i;
    int temp;
    int flag = 1;
    char option;
    
    //Storing five player details
    for(i=0; i<5; i++)
    {
        //Reading jersey numbers
        cout << "\n Enter player " << (i+1) << "'s jersey number: ";
        cin >> temp;
        
        //Storing in vector
        jerseyNumbers.push_back(temp);
        
        //Reading rating
        cout << "\n Enter player " << (i+1) << "'s rating: ";
        cin >> temp;
        
        //Storing in vector
        ratings.push_back(temp);
    }
    
    //Loop till user wants to quit
    while(flag)
    {
        //Printing menu
        menu();
        
        //Reading option from user
        cout << "\n Choose an option: ";
        cin >> option;
        
        //Calling appropriate function
        switch(option)
        {
            case 'a': addPlayer(jerseyNumbers, ratings); break;
            case 'd': deletePlayer(jerseyNumbers, ratings); break;
            case 'u': updatePlayer(jerseyNumbers, ratings); break;
            case 'r': aboveRating(jerseyNumbers, ratings); break;
            case 'o': outputRoster(jerseyNumbers, ratings); break;
            case 'q': flag = 0; break;
            default:
                cout << "\n\n Invalid option....\n"; break;
        }
    }
    
    
    return 0;
}
