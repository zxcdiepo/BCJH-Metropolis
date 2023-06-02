#include<iostream>
#include<fstream>
#include "globalConfig.hpp"

int NUM_GUESTS = 2;
int NUM_CHEFS = 6;
int guestList[MAX_GUESTS] = {0};
int ITER_CHEF = 1000;
int ITER_RECIPE = 1000;

void readbcjhConfig(){
    std::ifstream getcomb("../data/comb.txt");
    getcomb >> NUM_GUESTS;
    if (NUM_GUESTS < 1 || NUM_GUESTS > 11)
        throw "NUM_GUEST Error";
    for (int i = 0; i < NUM_GUESTS; i++) 
        getcomb >> guestList[i];
    NUM_CHEFS = NUM_GUESTS * CHEFS_PER_GUEST;
    getcomb >> ITER_CHEF >> ITER_RECIPE;
    return;
}