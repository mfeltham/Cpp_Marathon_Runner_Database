/// file MikeF/main.cpp by Mike F
#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Runner.h"
void printV(vector <Runner> V);
void addRunner(vector <Runner> &V);
void delRunner(vector <Runner> &V);
bool leaderboard(Runner x,Runner y);
int main(){
    vector <Runner> V;
    string nn;
    int yy; //running time in seconds
    ifstream fin("athletes.txt");
    if ( !fin ) { cout << "not found"; return -1;}
    for (int i = 0; i < 6; i++){
        fin >> nn >> yy;
        Runner X(nn,yy);
        V.push_back(X);
    }
    cout << "************************* RUNNER DATABASE *************************";
    int op = 1;
    while (op!=0){
        cout<<" \n1.About Program\n2.Author\n3.Print Runners\n4.Add Runner\n5.Subtract Runner\n6.Print Leaderboard\n0.Exit\nYour Option: ";
        cin>>op;
        switch(op){
            case 1:
                cout<<"This program is a database of runners and their times of completion in marathon." << endl; break;
            case 2:
                cout<<"Mike Feltham" << endl; break;
            case 3:
                printV(V); break;
            case 4:
                addRunner(V); break;
            case 5:
                delRunner(V); break;
            case 6:
                sort(V.begin(),V.end(), leaderboard); printV(V); break;
            case 0: cout<<"****************************** EXIT *******************************";
                break;
            default:cout<<"ERROR" << endl;
        }
        }
    return 0;
}//main

void delRunner(vector <Runner> &V) {
   string nn; //name
   cout << "Delete runner. Name?:";  cin >> nn;
   int pos = -1;
   for (int i=0 ; i < V.size(); i++){
        if ( V[i].name == nn ) {pos = i; break;}
   }
   if (pos != -1) V.erase(V.begin() + pos);
}///addRunner

void addRunner(vector <Runner> &V) {
   string nn; //name
   int tt; //time in secs
   cout << "Name of runner?:";  cin >> nn;
   cout << "Time in minutes?:"; cin >> tt;
   Runner X(nn,tt);
   V.push_back(X);
}

bool leaderboard(Runner x,Runner y) {
 return x.time < y.time;
}

void printV(vector <Runner> V) {
    for (int i=0; i < V.size() ; i++){
        V[i].print();
    }
}
