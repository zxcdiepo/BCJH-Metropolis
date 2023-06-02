#include<iostream>
#include<fstream>
#include "globalConfig.hpp"
#include "include/simpleini/SimpleIni.h"


CSimpleIniA ini;// 加载ini文件

int NUM_GUESTS;
int NUM_CHEFS;
int guestList[MAX_GUESTS];
int ITER_CHEF;
int ITER_RECIPE;
int TARGET_SCORE_APPROXIMATE;
bool AVOID_CHEF_1;
bool AVOID_CHEF_2;
bool AVOID_CHEF_3;
bool AVOID_CHEF_4;
bool AVOID_CHEF_5;

inline bool stobool(const char* s){
    if (s[0] == 'T' or s[0] == 't') return true;
    return false;
}

void stoarray(const char*s, int* a){
    int cnt = 0, k = 0;
    bool flag = false;
    for (int i = 0; s[i]; i++)
        if ('0' <= s[i] && s[i] <= '9'){
            if (!flag){
                flag = true;
                k = 0;
            }
            k = k * 10 + int(s[i]) - 48;
        }else{
            if (flag){
                a[cnt] = k;
                cnt++;
                flag = false;
            }
        }
    if (flag) a[cnt] = k;
    return;
}

void readINI(){
    SI_Error rc;
    rc = ini.LoadFile("../data/config.ini");	// 另一种方式：SI_Error LoadFile(FILE * a_fpFile);
    if (rc < 0)  std::cout << "加载 config.ini 文件失败！" << std::endl;

    ini.SetUnicode(false);
    ini.SetMultiKey(false);

    //[guestConfig]
    NUM_GUESTS = std::stoi(ini.GetValue("guestConfig", "NUM_GUESTS", "1"));
    stoarray(ini.GetValue("guestConfig", "guestList", "1"), guestList);

    //[calculator]
    ITER_CHEF = std::stoi(ini.GetValue("calculator", "ITER_CHEF", "10000"));
    ITER_RECIPE = std::stoi(ini.GetValue("calculator", "ITER_RECIPE", "10000"));
    TARGET_SCORE_APPROXIMATE = std::stoi(ini.GetValue("calculator", "TARGET_SCORE_APPROXIMATE", "2000000"));

    AVOID_CHEF_1 = stobool(ini.GetValue("calculator", "AVOID_CHEF_1", "true"));
    AVOID_CHEF_2 = stobool(ini.GetValue("calculator", "AVOID_CHEF_2", "true"));
    AVOID_CHEF_3 = stobool(ini.GetValue("calculator", "AVOID_CHEF_3", "true"));
    AVOID_CHEF_4 = stobool(ini.GetValue("calculator", "AVOID_CHEF_4", "false"));
    AVOID_CHEF_5 = stobool(ini.GetValue("calculator", "AVOID_CHEF_5", "false"));
}

void readbcjhConfig(){
    readINI();
    if (NUM_GUESTS < 1 || NUM_GUESTS > 11)
        throw "NUM_GUEST Error";
    NUM_CHEFS = NUM_GUESTS * CHEFS_PER_GUEST;
    return;
}