#ifndef SEASON_H
#define SEASON_H

#include "player.h"

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iterator>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::iterator;

class Season
{
    friend class Player;
    public:

        Season() : year_(0) {};
        void newSeason(int & year) { year_ = year; }
        void addPlayer(const string & name, int & byear, char & status);
        void lookUp(const string & name);
        void generateList(string & what_category, string & ifs_file);
        void writeFile(map<string, Player> & m);
        void readFile(map<string, Player> & m, string & what_category, string & file_name);

        //get & set methods
        void set_name(string new_name) { p.name_ = new_name; }
        void set_byear(int new_birth_year) { p.birth_year = new_birth_year; }
        void set_status(char new_status) { p.status_ = new_status; }
        void set_category(string new_category) { p.category_ = new_category; }

    protected:

    private:
        int year_;
        map<string, Player> m_player;
        Player p;
};

#endif // SEASON_H

void Season::readFile(map<string, Player> & m, string & what_category, string & file_name){

    ofstream out;
    out.open(file_name);

    ifstream in;
    in.open("source_file.txt");
    while(getline(in, p.category_)){
        if(p.category_ == what_category){
            in >> p.name_;
            out << p.name_ << "\n" << p.birth_year << "\n" << p.status_ << "\n" << p.category_ << endl;
        }
    }
}

void Season::writeFile(map<string, Player> & m){

    ofstream out;
    out.open("source_file.txt");
    for(auto itr = m.begin(); itr != m.end(); itr++){
        out << p.name_ << "\n" << p.birth_year << "\n" << p.status_ << "\n" << p.category_ << endl;
    }
}

void Season::addPlayer(const string & name, int & byear, char & status){

    string category;
    int age;
    age = year_ - byear;

    if(age <= 3){
        cout << "Error: to young to play in this summer's league \n";
    }
    else if(age < 6){
        category = "U6\n"; //U6
    }
    else if((age == 6) || (age == 7)){
        category = "U8\n"; //U8
    }
    else if((age == 8) || (age == 9)){
        category = "U10\n"; //U10
    }
    else if((age == 10) || (age == 11)){
        category = "U12\n"; //U12
    }
    else if((age == 12) || (age == 13)){
        category = "U14\n"; //U14
    }
    else if((age >= 14) || (age <= 16)){
        category = "U17\n"; //U17
    }
    else if(age >= 17){
        cout << "Error: to old to play in this summer's league \n";
    }

    set_name(name);
    set_byear(byear);
    set_status(status);
    set_category(category);

    m_player[name] = Player(name, byear, status, category);

    writeFile(m_player);
}

void Season::lookUp(const string & name){ //I combined look up/edit

    auto itr = m_player.find(name);
    if(itr != m_player.end()){
        p.name_ = name;
        cout << p.name_ << "\n" << p.birth_year << "\n" << p.status_ << "\n" << p.category_ << endl;

        char ans;
        cout << "Would you like to edit: " << p.name_ << "? [y/n]" << endl;
        cin >> ans;
        if((ans == 'y') || (ans == 'Y')){

            string new_name;
            cout << "Enter new name: [first name only]\n";
            cin >> new_name;
            set_name(new_name);

            int new_year;
            cout << "What year was this player born?\n";
            cin >> new_year;
            if(cin.fail()){
                cout << "Error: invalid year, please try again\n";
                cin >> new_year;
            }
            else{
                set_byear(new_year);
            }

            char new_status;
            cout << "Is this player's status paid or unpaid? [p/u]\n";
            cin >> new_status;
            set_status(new_status);

            cout << "Player edited: "<< "\n" << p.name_ << "\n" << p.birth_year << "\n" << p.status_ << "\n" << p.category_ << endl;
        }
        else if((ans == 'n') || (ans == 'N')){
            cout << "Message confirmed: will not edit player: " << name << endl;
        }
    }

    else{
        cout << "Error: player " << name << " could not be found\n";
    }
}

void Season::generateList(string & what_category, string & ofs_file){

        string copy_file = ofs_file;

        ofstream out;
        out.open(ofs_file);

        if(!out.is_open()){
            cout << "Error Message: file " << ofs_file << " cannot open\n";
            exit(1);
        }

        readFile(m_player, what_category, copy_file);
}
