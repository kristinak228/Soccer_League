#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using std::string;

class Player
{
    friend class Season;
    public:
        Player() : name_("none"), birth_year(0), status_('u'), category_("U3") {};
        Player(const string & name, int & byear, char & status, string & category) : name_(name), birth_year(byear),
            status_(status), category_(category) {};


    private:
        string name_;
        int birth_year;
        char status_; //p or u
        string category_;
};

#endif // PLAYER_H
