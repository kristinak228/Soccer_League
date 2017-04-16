#include "player.h"
#include "season.h"

#include <string>
#include <iostream>
#include <ostream>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::endl;
using std::ofstream;
using std::ifstream;

class BeginProgram
{
public:
    void run();

private:
    Season s;

};

void BeginProgram::run(){

        bool done = false;
        while(!done){

        cout << "choices: [n]ew season  [a]dd player  [l]ook up/edit player  [g]enerate list  [q]uit\n";
        char command;
        cin >> command;
        cin.get();

        switch(command){

            char ans;

            case 'n':{ //start new season

                cout << "Would you like to start a new season? [y/n]\n";
                cin >> ans;
                if((ans == 'y') || (ans == 'Y')){
                    cout << "Are you sure? This will delete the previous file. [y/n]\n";
                    cin >> ans;
                    if((ans == 'y') || (ans == 'Y')){
                        int current_year;
                        cout << "What's the current year?\n";
                        cin >> current_year;
                        if(cin.fail()){
                            cout << "Error: invalid year, please try again\n";
                            cin >> current_year;
                        }
                        else{
                        s.newSeason(current_year);
                        }
                    }
                    else if((ans == 'n') || (ans == 'N')){
                        cout << "Message confirmed: will not start a new season\n";
                    }
                }
                else if((ans == 'n') || (ans == 'N')){
                    cout << "Message confirmed: will not start a new season\n";
                }
                break;
            }

            case 'a':{ //add player
                cout << "Would you like to add a player? [y/n]\n";
                cin >> ans;
                if((ans == 'y') || (ans == 'Y')){
                    string p_name;
                    cout << "Player name: [first name only]\n";
                    cin >> p_name;
                    int y_birth;
                    cout << "Player's year of birth: \n";
                    cin >> y_birth;
                    cin.get();
                    if(cin.fail()){
                        cout << "Error: invalid year, please try again\n";
                        cin >> y_birth;
                    }
                    else{
                        char stat;
                        cout << "Are you paid or unpaid? [p/u]\n";
                        cin >> stat;

                        s.addPlayer(p_name, y_birth, stat);
                    }
                }
                else if((ans == 'n') || (ans == 'N')){
                    cout << "Message confirmed: will not add a player\n";
                }
                break;
            }

            case 'l':{ //look up & edit player
                cout << "Would you like to search for a player? [y/n]\n";
                cin >> ans;
                if((ans == 'y') || (ans == 'Y')){
                    string find_p;
                    cout << "Who are you searching for? [first name only]\n";
                    cin >> find_p;
                    s.set_name(find_p);
                    s.lookUp(find_p);
                }
                else if((ans == 'n') || (ans == 'N')){
                    cout << "Message confirmed: will not search for a player\n";
                }
                break;
            }

            case 'g':{ //generate list
                cout << "Would you like to search by category? [y/n]\n";
                cin >> ans;
                if((ans == 'y') || (ans == 'Y')){
                    string gen_cat;
                    cout << "Which category do you want to search? [U6, U8, U10, U12, U14, U17]\n";

                    cin >> gen_cat;
                    string ofs_filename;
                    cout << "Name your file: [no spaces in file name]\n";
                    cin >> ofs_filename;
                    s.generateList(gen_cat, ofs_filename);
                }
                else if((ans == 'n') || (ans == 'N')){
                    cout << "Message confirmed: will not search by category\n";
                }
                break;
            }

            case 'q':{ //quit program
                cout << "Closing program now... Goodbye.\n";
                done = true;
                break;
            }
        }
        cout << endl;
    }
}

int main(){

    BeginProgram b;
    b.run();

    return 0;
}
