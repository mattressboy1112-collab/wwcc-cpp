#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Recipe {
    string name;
    vector<string> steps;
    vector<string> ingredients;
    int index;
};

void readFile(string name, vector<Recipe>& list) {
    cout << '\n' << name << '\n';
    ifstream inFile(name);
    if (!inFile) {
        cout << "\nCould not open file\n";
    } else {
        string line;
        bool loop = true;
        while (loop) {
            getline(inFile, line);
            if (inFile.eof()) break;
            Recipe read_recipe;
            read_recipe.name = line;
            while (true) {
                getline(inFile, line);
                if (inFile.eof()) {
                    loop = false;
                    break;
                }
                if (line[0] == 'I') {
                    read_recipe.ingredients.push_back(line.substr(2));
                } else if (line[0] == 'S') {
                    read_recipe.steps.push_back(line.substr(2));
                } else if (line[0] == 'N') {
                    break;
                }
            }
            read_recipe.index = list.size();
            list.push_back(read_recipe);
        }
        cout << "\nFile loaded - Recipes ready\n";
    }
    inFile.close();
}

void displayRecipe(vector<Recipe>const recipe_list, int const recipe_index) {
    Recipe current_recipe = recipe_list[recipe_index];
    cout << "\n--------------------\n";
    cout << "Recipe " << current_recipe.index + 1 << ":\n";
    cout << current_recipe.name << "\n";
    cout << "\nIngredients needed:\n";
    for (size_t ingredient_index = 0; ingredient_index < current_recipe.ingredients.size(); ingredient_index++) {
        cout << current_recipe.ingredients[ingredient_index] << "\n";
    }
    cout << "\nSteps:\n";
    size_t step_num = current_recipe.steps.size();
    for (size_t step_index = 0; step_index < step_num; step_index++) {
        cout << "Step " << step_index+1 << ": " << current_recipe.steps[step_index] << "\n";
    }
}

vector<Recipe> search(vector<Recipe>const recipe_list, string const sub) {
    vector<Recipe> search_results;
    for (size_t i = 0; i < recipe_list.size(); i++) {
        Recipe recipe = recipe_list[i];
        int index = recipe.name.find(sub);
        if (index >= 0) {
            search_results.push_back(recipe);
            cout << i << " - " << recipe.name << '\n';
        } else {                      
            for (size_t ing = 0; ing < recipe.ingredients.size(); ing++) {
                string ingredient = recipe.ingredients[ing];
                int index = ingredient.find(sub);
                if (index >= 0) {
                    search_results.push_back(recipe);
                    cout << i << " - " << recipe.name << '\n';
                    break;
                }
            }
        }
    }
    return search_results;
}

int main() {
    string temp;
    vector<Recipe> recipe_list;
    readFile("recipes.txt",recipe_list);
    while (true) {
        cin.clear();
        int choice;
        while (true) {
            cout << "\nDYNAMIC RECIPE MANAGER\n";
            cout << "----------------------\n";
            cout << "1. Add Recipe\n";
            cout << "2. Display All Recipes\n";
            cout << "3. Search Recipes\n";
            cout << "4. Remove Recipe\n";
            cout << "5. Show Statistics\n";
            cout << "6. Exit\n";
            choice = 0;
            cout << "Enter choice: "; cin >> temp;
            if (atoi(temp.c_str())>0) {
                choice = atoi(temp.c_str());
                cout << '\n';
                break;
            }
        }
        switch (choice) {
            case 1:
            {
                Recipe new_recipe;
                new_recipe.index = recipe_list.size();
                string name;
                int num_of;
                cin.ignore();
                cout << "Enter recipe name: "; getline(cin >> ws, name);
                new_recipe.name = name;
                while (true) {
                    cout << "How many ingredients? "; cin >> temp;
                    if (atoi(temp.c_str())>0) {
                        num_of = atoi(temp.c_str());
                        break;
                    }
                } 
                cin.ignore();
                for (int i = 0; i < num_of; i++) {
                    string ingredient;
                    cout << "Enter ingredient: "; getline(cin, ingredient);
                    new_recipe.ingredients.push_back(ingredient);
                }
                while (true) {
                    cout << "How many steps? "; cin >> temp;
                    if (atoi(temp.c_str())>0) {
                        num_of = atoi(temp.c_str());
                        break;
                    }
                }
                cin.ignore();
                for (int i = 0; i < num_of; i++) {
                    string step;
                    cout << "Enter step " << i+1 << ": "; getline(cin, step);
                    new_recipe.steps.push_back(step);
                }
                recipe_list.push_back(new_recipe);
                break;
            }
            case 2:
            {
                size_t size_of_list = recipe_list.size();
                for (size_t recipe_index = 0; recipe_index < size_of_list; recipe_index++) {
                    displayRecipe(recipe_list,recipe_index);
                }
                break;
            }
            case 3:
            {
                string name;
                cout << "\nType exit to exit search at any time.\n";
                cout << "\nEnter index number for recipe or enter search: "; getline(cin >> ws, name);
                if (atoi(name.c_str())>0) {
                    displayRecipe(recipe_list,atoi(name.c_str())-1);
                } else if (name != "exit") {
                    vector<Recipe> search_results = search(recipe_list, name);
                    while (true) {
                        cout << "\nEnter result number or enter new search: "; getline(cin >> ws, name);
                        if (atoi(name.c_str())>0) {
                            displayRecipe(search_results,atoi(name.c_str())-1);
                            break;
                        } else if (name != "exit") {
                            search_results = search(recipe_list, name);
                        } else {
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                int index = -1;
                cout << "Remove recipe at what index? "; getline(cin >> ws, temp);
                if (atoi(temp.c_str())>0) {
                    index = atoi(temp.c_str())-1;
                }
                if (index > 0) {
                    for (size_t i = index; i < recipe_list.size() - 1; i++)
                    {
                        recipe_list[i].index -= 1;
                        recipe_list[i] = recipe_list[i+1];
                    }
                    recipe_list.pop_back();
                } else {
                    cout << "Invalid index!\n"; 
                }
                break;
            }
            case 5:
            {
                cout << "\nCOLLECTION STATISTICS\n";
                cout << "----------------------\n";
                int const SIZE = recipe_list.size();
                cout << "Total recipes: " << SIZE << '\n';
                double total_ing;
                double total_steps;
                for (size_t i = 0; i < recipe_list.size(); i++) {
                    total_ing += recipe_list[i].ingredients.size();
                    total_steps += recipe_list[i].steps.size();
                }
                cout << "Acerage ingredients per recipe: " << total_ing / SIZE << '\n';
                cout << "Average steps per recipe: " << total_steps / SIZE << '\n';
                break;
            }
            case 6:
            {
                ofstream outFile ("recipes.txt",ofstream::out | ofstream::trunc);
                if (outFile) {
                    for (size_t recipe_index = 0; recipe_index < recipe_list.size(); recipe_index++) {
                        Recipe recipe = recipe_list[recipe_index];
                        recipe.index = recipe_list.size();
                        string name;
                        outFile << recipe.name << '\n';
                        for (size_t ingred_index = 0; ingred_index < recipe.ingredients.size(); ingred_index++) {
                            outFile << "I " << recipe.ingredients[ingred_index] << '\n';
                        }
                        for (size_t step_index = 0; step_index < recipe.steps.size(); step_index++) {
                            outFile << "S " << recipe.steps[step_index] << '\n';
                        }
                        outFile << "N\n";
                        /*
                        name 1
                        I 1/2 butter
                        I 1/2 tv
                        S mix mix mix
                        N
                        name 2
                        I 4 eggs
                        I 2 eggs
                        I 5 eggs
                        S crack eggs
                        S mix eggs
                        N
                        */
                    }
                    outFile.close();
                } else {
                    cout << "\nError saving\n";
                }
                return 0;
            }
            default:
            {
                cout << "\nInvalid input.\n";
                break;
            }
        }
    }
}