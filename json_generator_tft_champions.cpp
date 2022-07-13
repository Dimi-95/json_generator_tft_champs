#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

//champion
std::string champ = " " ;
//items
std::string item_1 = " ";
std::string item_2 = " ";
std::string item_3 = " ";
//sub items
std::string sub_item_1 = " ";
std::string sub_item_2 = " ";
std::string sub_item_3 = " ";
std::string sub_item_4 = " ";
std::string sub_item_5 = " ";
std::string sub_item_6 = " ";
//champion priority
int prio_score = 0;
//champion traits
std::string trait_1 = " ";
std::string trait_2 = " ";
std::string trait_3 = " ";
//input
char yes_or_no = ' ';
bool answer = true;


void set_values_with_input(){

    std::cout << "Enter champion name: " << std::endl;
    std::cin >> champ;
    std::transform(champ.begin(), champ.end(), champ.begin(), ::tolower);
    std::cout << "Champion name: " << champ << std::endl;

    std::cout << "Enter champion priority score(PS) - numbers 1-5" << std::endl;
    std::cin >> prio_score;
    std::cout << "PS entered: " << prio_score << std::endl;
    
    for(int i = 0; i < 3; i++)
    {
        std::cout << "Enter the trait (" << i + 1 << "): "<< std::endl;
        if(i == 0)
        {
            std::cin >> trait_1;
            std::transform(trait_1.begin(), trait_1.end(), trait_1.begin(), ::tolower);
            std::cout << "Trait entered: " << trait_1 << std::endl;
        }
        else if(i == 1)
        {
            std::cin >> trait_2;
            std::transform(trait_2.begin(), trait_2.end(), trait_2.begin(), ::tolower);
            std::cout << "Trait entered: " << trait_2 << std::endl;
        }
        else
        {
            std::cin >> trait_3;
            std::transform(trait_3.begin(), trait_3.end(), trait_3.begin(), ::tolower);
            std::cout << "Trait entered: " << trait_3 << std::endl;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        std::cout << "Enter the item (" << i + 1 << "): "<< std::endl;
        if(i == 0)
        {
            std::cin >> item_1;
            std::transform(item_1.begin(), item_1.end(), item_1.begin(), ::tolower);
            std::cout << "Item entered: " << item_1 << std::endl;
        }
        else if(i == 1)
        {
            std::cin >> item_2;
            std::transform(item_2.begin(), item_2.end(), item_2.begin(), ::tolower);
            std::cout << "Item entered: " << item_2 << std::endl;
        }
        else
        {
            std::cin >> item_3;
            std::transform(item_3.begin(), item_3.end(), item_3.begin(), ::tolower);
            std::cout << "Item entered: " << item_3 << std::endl;
        }
    }
      for(int i = 0; i < 6; i++)
    {
        std::cout << "Enter the sub item (" << i + 1 << "): "<< std::endl;
        if(i == 0)
        {
            std::cin >> sub_item_1;
            std::transform(sub_item_1.begin(), sub_item_1.end(), sub_item_1.begin(), ::tolower);
            std::cout << "Sub item entered: " << sub_item_1 << std::endl;
        }
        else if(i == 1)
        {
            std::cin >> sub_item_2;
            std::transform(sub_item_2.begin(), sub_item_2.end(), sub_item_2.begin(), ::tolower);
            std::cout << "Sub item entered: " << sub_item_2 << std::endl;
        }
        else if(i == 2)
        {
            std::cin >> sub_item_3;
            std::transform(sub_item_3.begin(), sub_item_3.end(), sub_item_3.begin(), ::tolower);
            std::cout << "Sub item entered: " << sub_item_3 << std::endl;
        }
        else if (i == 3)
        {
            std::cin >> sub_item_4;
            std::transform(sub_item_4.begin(), sub_item_4.end(), sub_item_4.begin(), ::tolower);
            std::cout << "Sub item entered: " << sub_item_4 << std::endl;
        }
        else if (i == 4)
        {
            std::cin >> sub_item_5;
            std::transform(sub_item_5.begin(), sub_item_5.end(), sub_item_5.begin(), ::tolower);
            std::cout << "Sub item entered: " << sub_item_5 << std::endl;
        }
        else if (i == 5)
        {
            std::cin >> sub_item_6;
            std::transform(sub_item_6.begin(), sub_item_6.end(), sub_item_6.begin(), ::tolower);
            std::cout << "Sub item entered: " << sub_item_6 << std::endl;
        }
    }   


    
}




int main(){

    while(answer){
        std::cout << "Do you want to create a champion .json file ? [y/n]" << std::endl;
        std::cin >> yes_or_no;
        if(yes_or_no == 'y')
        {
            answer = false;
        }
        else if(yes_or_no == 'n')
        {
            std::cout << "Ok, programming is closing now" << std::endl;
            exit(0);
        }
        else{
            std::cout << "Wrong input, try again" << std::endl;
        }
    }

    set_values_with_input();

    std::ofstream champ_json("champions.json");

    champ_json << "{ \"" << champ << "\" : {\n  \"items\" : [\"" 
    << item_1 << "\" , \""<< item_2 << "\" , \"" << item_3 
    << "\"],\n  \"sub_items\" : [\"" << sub_item_1 <<"\" , \"" 
    << sub_item_2 << "\" , \"" << sub_item_3 << "\" , \"" << sub_item_4 
    << "\" , \"" << sub_item_5 <<"\" , \""<< sub_item_6 <<"\"], \n  \"prio_score\" : \"" 
    << prio_score << "\",\n  \"traits\" : [\""<< trait_1 <<"\" ,\""<< trait_2 
    << "\" ,\"" << trait_3 << "\"]\n}\n}";

    champ_json.close();

    return 0;
}