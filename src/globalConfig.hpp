#ifndef CONFIG_HPP
#define CONFIG_HPP

#define MAX_CHEFS 33
#define MAX_GUESTS 11
#define DISH_PER_CHEF 3
#define CHEFS_PER_GUEST 3

extern int NUM_GUESTS;
extern int NUM_CHEFS;
extern int guestList[MAX_GUESTS]; 

#define MODE 1 // 1:宴会模式 不要动它
extern int TARGET_SCORE_APPROXIMATE;
// 预期达到的分数
// 如果是限时任务，这里输分数线
// 如果是宴会模式，不用特别准，差两倍/一半以内都可以

extern int ITER_CHEF; // 选择厨师时的迭代次数
extern int ITER_RECIPE; // 对于每一组厨师，选择菜谱时的迭代次数

extern bool AVOID_TOOL;

extern bool AVOID_CHEF_1;
extern bool AVOID_CHEF_2;
extern bool AVOID_CHEF_3;// 计算时不考虑三火厨师
extern bool AVOID_CHEF_4;// 计算时不考虑四火厨师
extern bool AVOID_CHEF_5;// 计算时不考虑五火厨师

// ************************************************** //
// ** 以下内容不建议修改，除非你清楚地知道这是什么意思 ** //
// ************************************************** //

extern int T_MAX_CHEF;
extern int T_MAX_RECIPE;

#endif