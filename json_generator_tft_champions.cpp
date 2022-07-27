#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

//champion
int champ = 0 ;
//items
std::string item_1 = " ";
std::string item_2 = " ";
std::string item_3 = " ";
int item_num = 0;
int sub_item_num = 0;
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
int trait_num = 0 ;
std::string champ_trait_1 = " ";
std::string champ_trait_2 = " ";
std::string champ_trait_3 = " ";
//role
int role = 0;
//input
char yes_or_no = ' ';
bool answer = true;

//complete items map
std::map <int, std::string> complete_items { 
{ 1 ,"dragonmancer" }, { 2, "assassin" }, { 3, "ragewing" }, { 4, "guardian" }, { 5, "cavalier" }, { 6, "mage" }, { 7, "mirage" }, { 8, "shimmerscale" }, { 9, "archangel"}, { 10, "banshee"},
{ 11, "thirster"}, { 12, "blue" }, { 13, "bramble" }, { 14, "chalice" }, { 15, "deathblade" }, { 16, "claw" }, { 17, "edge" }, { 18, "frozenheart" },{ 19, "stoneplate" }, { 20, "slayer" },
{ 21,"rageblade" }, { 22, "hand" }, { 23, "gunblade" }, { 24, "infinity" }, { 25, "spark" }, { 26, "gauntlet" }, { 27, "whisper" }, { 28, "locket"}, { 29, "morello" }, { 30, "quicksilver"},
{ 31, "deathcap"}, { 32, "rapid"}, { 33, "redemption"}, { 34, "hurricane"}, { 35, "shroud" }, { 36, "shojin"}, { 37, "static"}, { 38, "sunfire"}, { 39, "tacticiancrown"}, { 40, "glove"},
{ 41, "titan" }, { 42, "warmogs" }, { 43, "zekes" }, { 44, "zephyr" }, { 45, "void" } };
//base items map
std::map <int, std::string> base_items { { 1, "sword" }, { 2, "vest" }, { 3, "belt" }, { 4, "rod" },
{ 5, "cloak" }, { 6, "bow" }, { 7, "crit" }, { 8, "spat" }, { 9, "tear" } };
//champions map
std::map <int, std::string> champions { { 1, "aatrox" }, { 2, "anivia" }, { 3, "aoshin" }, { 4, "ashe" }, { 5, "aurelion" }, { 6, "bard" }, { 7, "braum" }, { 8, "corki" }, { 9, "deja" }, { 10, "diana"},
{ 11, "elise" }, { 12, "ezreal" }, { 13, "gnar" }, { 14, "hecarim" }, { 15, "heimer" }, { 16, "idas" }, { 17, "illaoi" }, { 18, "jinx" }, { 19, "karma" }, { 20, "kayne" },
{ 21, "lee" }, { 22, "leona" }, { 23, "lillia" }, { 24, "lulu" }, { 25, "nami" }, { 26, "neeko" }, { 27, "nidalee" }, { 28, "nunu" }, { 29, "olaf" }, { 30, "ornn" },
{ 31, "pyke" }, { 32, "qiyanna" }, { 33, "ryze" }, { 34, "sejuani" }, { 35, "senna" }, { 36, "sett" }, { 37, "shen" }, { 38, "shiohyu" }, { 39, "shyvana" }, { 40, "skarner" },
{ 41, "sona" }, { 42, "soraka" }, { 43, "swain" }, { 44, "syfen" }, { 45, "sylas" }, { 46, "tham" }, { 47, "talon" }, { 48, "taric" }, { 49, "thresh" }, { 50, "tristana" },
{ 51, "twitch" }, { 52, "varus" }, { 53, "vladimir" }, { 54, "volibear" }, { 55, "xayah" }, { 56, "yasuo" }, { 57, "yone" }, { 58, "zoe" } };
//champions role map
std::map <int, std::string> roles { { 1, "bruiser" }, { 2, "support" }, { 3, "rangedcarry" } };
//champion traits map
std::map <int, std::string> champion_traits { { 1, "bard" }, { 2, "bruiser" }, { 3, "dragon" }, { 4, "spellthief" }, { 5, "starcaller" }, { 6, "assassin" }, { 7, "cannoneer" }, { 8, "dragonmancer" }, { 9, "evoker" }, { 10, "mage" }, { 11, "mystic" }, { 12, "shapeshifter" }, { 13, "warrior" }, { 14, "guardian" }, { 15, "legend"},
{ 16, "whispers" }, { 17, "guild" }, { 18, "jade" }, { 19, "ragewing" }, { 20, "tempest" }, { 21, "trainer" }, { 22, "revel" }, { 23, "scalescorn" }, { 24, "astral" }, { 25, "mirage"}, { 26, "shimmerscale" },
{ 0, "none"} };



void set_values_with_input(){

    std::cout << "Enter champion name: " << std::endl;
    std::cin >> champ;
    std::cout << "Champion name: " << champions[champ] << std::endl;

    std::cout << "Enter the champion's role: " << std::endl;
    std::cin >> role;
    std::cout << "The role given to the champ: " << roles[role] << std::endl;

    std::cout << "Enter champion priority score(PS) - numbers 1-5" << std::endl;
    std::cin >> prio_score; 
    std::cout << "PS entered: " << prio_score << std::endl;
    
    for(int i = 0; i < 3; i++)
    {
        std::cout << "Enter the trait (" << i + 1 << "): "<< std::endl;
        if(i == 0)
        {
            std::cin >> trait_num;
            std::cout << "Trait entered: " << champion_traits[trait_num] << std::endl;
            champ_trait_1 = champion_traits[trait_num];
        }
        else if(i == 1)
        {
            std::cin >> trait_num;
            std::cout << "Trait entered: " << champion_traits[trait_num] << std::endl;
            champ_trait_2 = champion_traits[trait_num];
        }
        else
        {
            std::cin >> trait_num;
            std::cout << "Trait entered: " << champion_traits[trait_num] << std::endl;
            champ_trait_3 = champion_traits[trait_num];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        std::cout << "Enter the item (" << i + 1 << "): "<< std::endl;
        if(i == 0)
        {
            std::cin >> item_num;
            std::cout << "Item entered: " << complete_items[item_num] << std::endl;
            item_1 = complete_items[item_num];
        }
        else if(i == 1)
        {
            std::cin >> item_num;
            std::cout << "Item entered: " << complete_items[item_num] << std::endl;
            item_2 = complete_items[item_num];
        }
        else
        {
            std::cin >> item_num;
            std::cout << "Item entered: " << complete_items[item_num] << std::endl;
            item_3 = complete_items[item_num];
        }
    }
      for(int i = 0; i < 6; i++)
    {
        std::cout << "Enter the sub item (" << i + 1 << "): "<< std::endl;
        if(i == 0)
        {
            std::cin >> sub_item_num;
            std::cout << "Sub item entered: " << base_items[sub_item_num] << std::endl;
            sub_item_1 = base_items[sub_item_num];
        }
        else if(i == 1)
        {
            std::cin >> sub_item_num;
            std::cout << "Sub item entered: " << base_items[sub_item_num] << std::endl;
            sub_item_2 = base_items[sub_item_num];
        }
        else if(i == 2)
        {
            std::cin >> sub_item_num;
            std::cout << "Sub item entered: " << sub_item_3 << std::endl;
            sub_item_3 = base_items[sub_item_num];
        }
        else if (i == 3)
        {
            std::cin >> sub_item_num;
            std::cout << "Sub item entered: " << base_items[sub_item_num] << std::endl;
            sub_item_4 = base_items[sub_item_num];
        }
        else if (i == 4)
        {
            std::cin >> sub_item_num;
            std::cout << "Sub item entered: " << base_items[sub_item_num] << std::endl;
            sub_item_5 = base_items[sub_item_num];
        }
        else if (i == 5)
        {
            std::cin >> sub_item_num;
            std::cout << "Sub item entered: " << base_items[sub_item_num] << std::endl;
            sub_item_6 = base_items[sub_item_num];
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

    champ_json << "{ \"" << champions[champ] << "\" : {\n  \"items\" : [\"" 
    << item_1 << "\" , \""<< item_2 << "\" , \"" << item_3 
    << "\"],\n  \"sub_items\" : [\"" << sub_item_1 <<"\" , \"" 
    << sub_item_2 << "\" , \"" << sub_item_3 << "\" , \"" << sub_item_4 
    << "\" , \"" << sub_item_5 <<"\" , \""<< sub_item_6 <<"\"], \n  \"prio_score\" : \"" 
    << prio_score << "\",\n  \"traits\" : [\""<< champ_trait_1 <<"\" ,\""<< champ_trait_2 
    << "\" ,\"" << champ_trait_3 << "\"],\n  \"role\" : \"" << roles[role] << "\"\n}\n}";

    champ_json.close();

    return 0;
}