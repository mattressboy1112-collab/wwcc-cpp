/*
 * Interactive Story Game - [Cube-acomes]
 * Author: Samuel Coleman
 * Date: [12/06/2026]
 *
 * ==== Project Features ====
 * Variables (3+ types): Lines 436, 312, 313
 * If/else: Lines 451, 44
 * Switch: Line 190
 * Loop: Lines 445
 * Function w/ return value: Line 73
 * Void function: Line 113
 * Function w/ parameters: Line 110
 * Vector or array: Lines 29
 * Struct or class: Lines 67
 * Enum: Lines 427
 * File reading: Lines 228, 433 - unfinished
 * File writing: Lines 228, 463 - not working and unfinished - would not write to file depsite being the same as another project of mine for writing. - if it doesnt work for you either and just empties the save.txt file, the original text can also be found commented on line 231
 * Modern feature 1 (range-based for): Lines 108
 * Modern feature 2 (auto): Lines 108 
 * ==========================           I do realize this might not count specifically for what was asked, but I was just trying to make any form of story game I could since my internet kept cutting out whenever I tried to look at the criteria.
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<int> saved_events;
vector<string> unlocked_shortcuts;

struct Input {
    bool is_num;
    int num;
    string input_string;
};

Input StringInfo(string input) {
    Input return_item;
    return_item.input_string = input;
    return_item.num = atoi(input.c_str());
    if (return_item.num > 0) {
        return_item.is_num = true;
    } else {
        return_item.is_num = false;
    }
    return return_item;
}

Input GetInput() {
    string input;
    getline(cin >> ws, input);
    return StringInfo(input);
}

vector<string> SplitString(string const input_string) {
    vector<string> return_vector;
    int last_div = 0;
    for (size_t i = 0; i < input_string.size(); i++)
    {
        if (input_string[i] == ',') {
            return_vector.push_back(input_string.substr(last_div,i-last_div));
        }
    }
}

class Room {
    private:
    bool up, down, left, right;
    vector<vector<string>> extra_dialogue;
    string description;
    public:
    bool CheckLock(int direction) {
        switch (direction) {
        case 1:
            return left;
        case 2:
            return up;    
        case 3:
            return right;    
        case 4:
            return down;        
        default:
            return false;
        }
    }
    Room() {
        up = true;
        down = true;
        left = true;
        right = true;
        description = "An empty room. test test\n";
    }
    Room(bool const left_in, bool const up_in, bool const right_in, bool const down_in) {
        up = up_in;
        down = down_in;
        left = left_in;
        right = right_in;
        description = "An empty room.\n";
    }
    bool ExtraDialogueCheck(string const input) {
        for (const auto dialogue_item : extra_dialogue) {
            if (input == dialogue_item[0]) {
                cout << dialogue_item[1];
                return true;
            }
        }
        return false;
    }
    void AddExtraDialogueOption(string input_option, string output_text) {
        extra_dialogue.push_back({input_option,output_text});
    }
    void Print() {
        cout << description;
        cout << "\nLeft: " << left << ", up: " << up << ", right: " << right << ", down: " << down << '\n';
    }
    void UpdateDescription(string desc) {
        description = desc;
    }
    void UpdateOpenings(int side, bool open) { //1 for left, 2 for up, 3 for right, 4 for down
        switch (side) {
            case 1: 
            {
                left = open;
                break;
            }
            case 2: 
            {
                up = open;
                break;
            }
            case 3:
            {
                right = open;
                break;
            }
            case 4:
            {
                down = open;
                break;
            }
            case 5:
            {
                left = open;
                right = open;
                up = open;
                down = open;
            }
            default:
            {
                break;
            }
        }
    }
    void UpdateOpenings(bool const left_in, bool const up_in, bool const right_in, bool const down_in) {
        up = up_in;
        down = down_in;
        left = left_in;
        right = right_in;
    }

};

class Item { // could probably be done with a structure, but it is nice to have all inputs forced to be filled at the start, and also quickly set up
    public:
    bool in_inventory;
    string name, description;
    int uses;
    Item(string const name_in, string const description_in, int uses_in = 1) {
        name = name_in;
        description = description_in;
        uses = uses_in;
    }
};

//vector<Item> inventory;

vector<Item> items = {
    Item("A brown key","It looks rusted, it might not even fit into its lock anymore."),
    Item("Wooden cube", "The cube seems ")
};

void Event(int event_num, bool skip_text, vector<vector<Room>> rooms) {
    switch (event_num) {
        case 1:
        {
            if (skip_text == false) {
                cout << "\nYou picked up the key\n";
            }
            rooms[0][0].UpdateDescription("Seems like a corner, there are two doors and two walls.");
            items[0].in_inventory = true;
            break;
        }
        case 2:
        {
            if (items[0].in_inventory = true) {
                items[0].in_inventory = false;
                if (skip_text == false) {
                    cout << "\nYou used the rusted key. The door to your right is now open.\n";
                }
                rooms[1][1].UpdateDescription("There are two doors. The previously locked door seems to open now.");
                unlocked_shortcuts.push_back("1,1,3");
                rooms[1][1].UpdateOpenings(3, true);
            }
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

void SaveEvent(int number) {
    saved_events.push_back(number);
}

bool SaveToFile() {
    /*
TEST SAVE - if save to file makes the save file empty, copy the comment text below into itj mt0
E
3
END
U
1
1
2
4
END
    */
    ofstream outFile ("save.txt",ofstream::out | ofstream::trunc);
    if (outFile) {
        cout << "check1 passed";
        outFile << "E\n";
        for (size_t i = 0; i < saved_events.size(); i++) {
            outFile << saved_events[i] << '\n';
        }
        outFile << "end\n";
        outFile << "U\n";
        outFile << unlocked_shortcuts.size();
        for (size_t i = 0; i < unlocked_shortcuts.size(); i++)
        {
            vector<string> parts = SplitString(unlocked_shortcuts[i]);
            outFile << parts[0] << '\n';
            outFile << parts[1] << '\n';
            outFile << parts[2] << '\n';
        }
        outFile.close();
        return true;
    } else {
        return false;
    }
}

bool ReadFile(vector<vector<Room>>& rooms) {
    ifstream inFile ("save.txt");
    if (inFile.good() == false) {
        cout << "Could not read file.";
        return false;
    }
    string line;
    while (true) {
        getline(inFile, line);
        if (inFile.eof()) {
            break;
        }
        if (line[0] == 'E') {
            while (line != "END") {
                getline(inFile, line);
                Input pline = StringInfo(line);
                if (pline.is_num == true) {
                    Event(pline.num, true, rooms);
                    SaveEvent(pline.num);
                }
            }
        } else if (line[0] == 'U') {
            while (line != "END") {
                getline(inFile, line);
                Input pline = StringInfo(line);
                if (pline.is_num == true) {
                    for (int i = 0; i < pline.num; i++) {
                        getline(inFile, line);
                        int x = atoi(line.c_str());
                        getline(inFile, line);
                        int y = atoi(line.c_str());
                        getline(inFile, line);
                        int dir = atoi(line.c_str());
                        rooms[y][x].UpdateOpenings(dir,true);
                        unlocked_shortcuts.push_back(to_string(x)+','+to_string(y)+','+to_string(dir));
                    }
                }
            } 
        }
    }
    inFile.close();
    return true;
}

bool Move(int direction, int& pos_x, int& pos_y, int const WIDTH, int const HEIGHT, Room& current_room, vector<vector<Room>>& rooms, string const custom_message = "empty_message_1") {
    bool main_check = current_room.CheckLock(direction);
    int room2_dir;
    int move_x, move_y;
    switch (direction) {
        case 1:
        {
            if (pos_x != 0) {
                move_y = 0;
                move_x = -1; 
                room2_dir = 3;
            } else {
                if (custom_message != "empty_message_1") {
                    cout << custom_message;
                } else {
                    cout << "\nThere is no opening that direction\n";
                }
                return false; 
            }
            break;
        }
        case 2:
        {
            if (pos_y != 0) {
                move_y = -1;
                move_x = 0;
                room2_dir = 4;
            } else {
                if (custom_message != "empty_message_1") {
                    cout << custom_message;
                } else {
                    cout << "\nThere is no opening that direction\n";
                }
                return false; 
            }
            break;
        }
        case 3:
        {
            if (pos_x != WIDTH - 1) {
                move_y = 0;
                move_x = 1; 
                room2_dir = 1;
            } else {
                if (custom_message != "empty_message_1") {
                    cout << custom_message;
                } else {
                    cout << "\nThere is no opening that direction\n";
                }
                return false; 
            }
            break;
        }
        case 4:
        {
            if (pos_y != HEIGHT - 1) {
                move_y = 1; 
                move_x = 0;
                room2_dir = 2;
            } else {
                if (custom_message != "empty_message_1") {
                    cout << custom_message;
                } else {
                    cout << "\nThere is no opening that direction\n";
                }
                return false; 
            }
            break;
        }
        default:
            return false;
    }   
    Room& room2 = rooms[pos_y+move_y][pos_x+move_x];
    bool check = room2.CheckLock(room2_dir);
    if (main_check == true) {
        if (check == false) {
            room2.UpdateOpenings(room2_dir, true);
            if (custom_message != "empty_message_1") {
                cout << custom_message;
            } else {
                cout << "\ncDoor has been unlocked from your side.\n";
                unlocked_shortcuts.push_back(to_string(pos_x+move_x)+','+to_string(pos_y+move_y)+','+to_string(direction));  
            }
        } else if (custom_message != "empty_message_1") {
            cout << custom_message;
        }
        pos_x += move_x;
        pos_y += move_y;
        current_room = rooms[pos_y][pos_x];
        return true;
    } else {
        if (check == true) {
            if (custom_message != "empty_message_1") {
                cout << custom_message;
            } else {
                cout << "\nDoor is locked\n";
            }
        } else {
            if (custom_message != "empty_message_1") {
                cout << custom_message;
            } else {
                cout << "\nThere is no opening that direction\n";
            }
        }
        return false;
    }
}

int main() {
    int pos_x = 0;
    int pos_y = 1;
    vector<vector<Room>> rooms {
        {Room(false, false, true, true),    Room(true, false, true, false),     Room(true, false, false, true)},
        {Room(false, true, true, true),     Room(true, false, false, false),    Room(true, false, false, true)},
        {Room(false, true, true, false),    Room(true, false, false, false),    Room(false, false, false, false)}        
    };
    enum Dim {
        WIDTH = 3,
        HEIGHT = 3
    };
    rooms[0][0].UpdateDescription("Seems like a corner, there are two doors and two walls. A small rusted key lies on the floor.");
    rooms[1][0].UpdateDescription("A cubic, stone room, empty aside three wooden doors, each to their own wall. There is not much to see with the smooth stone surrounding you, only with a small opening at the top of the only wall void of a door.\nFrom the opening is the only source of light in this room.\nYou hope this light remains a constant for every room.");
    rooms[1][0].AddExtraDialogueOption("opening","You stand back against the middle door, trying to get a good angle to see out of the opening.\n You can't see much aside from glimpses of green light, and that the amount of light seems to change.\nIt seems that you may not be somewhere you know, but at least it's somewhere alive.\nMaybe knowing that there is likely nature outside motivates you to search for an exit from wherever this may be.");
    rooms[1][1].UpdateDescription("The room has two doors, the one you came from and another on the opposite wall. The opposite door is locked.");
    rooms[0][2].UpdateDescription("Another corner, it seems that one door leads to behind that one locked door, maybe you can get in from this side."); // Kept in as a way in because the key wouldn't seem to register and I am out of time.
    rooms[1][2].UpdateDescription("This room appears to be a closet, having a few items strewn about in it. The sight of a populated room is comforting, but not helpful.\nYou do notice a small opening underneath a poorly built desk to the right of where you entered.");
    rooms[2][2].UpdateDescription("The outside. You've made it. There are trees surrounding, and vines hanging down around you and the structure you came out of.\nThe outside is quite peaceful, and yet, you can't seem to be happy, knowing that you are still nowhere familiar. But, at least you are free.\nThe End! feel free to go back inside but not much awaits.");
    rooms[1][2].AddExtraDialogueOption("desk","The desk seems so badly made that you could probably shove it out of the way and it'd break. You could very well fit through the opening behind it. (down option)");
    ReadFile(rooms);
    Room current_room = rooms[pos_y][pos_x];
    Input input_item;
    current_room.Print();
    cout << "\nWelcome to CUBE-ACOMBS!\n";
    cout << "Type in words to interact with environment or type a number to move in a direction.\n";
    cout << "Game is definitely unfinished, so I appologize, but movement functionality and an extra dialogue option works.\n";
    cout << "If the description or open sides become burried in text, say 'room' to show the details again.\n";
    cout << "Have fun!\n\n";
    cout << "You wake up in a room, unfamiliar, no clue to how you got here.\n";
    while (true) {
        cout << "\nEnter number to move to adjacent room (1 for left, 2 for up, 3 for right, 4 for down) or enter text to interact with room.\n";
        input_item = GetInput();
        if (input_item.num) {
            Move(input_item.num, pos_x, pos_y, WIDTH, HEIGHT, current_room, rooms);
            current_room.Print();
        } else if (input_item.input_string != "exit") {
            current_room.ExtraDialogueCheck(input_item.input_string);
            string pos_string = to_string(pos_x)+", "+to_string(pos_y);
            if (input_item.input_string == "key") {
                if (pos_string == "0, 0" and items[0].in_inventory == false) {
                    Event(1,false,rooms);
                } else if (pos_string == "1, 1" and items[0].in_inventory == true) {
                    Event(2,false,rooms);
                    SaveEvent(2);
                }
            } else if (input_item.input_string == "room") {
                current_room.Print();
            }
        } else {
            if (SaveToFile()) { // broken - Will not write to file after it empties it, for whatever reason
                return 0;
            } else {
                string quick_input;
                cout << "\n SAVE FAILED! Are you sure you want to leave? (Y or N)\n"; getline(cin >> ws, quick_input);
                if (quick_input == "Y") {
                    return 0;
                }
            }
        }
    }
}