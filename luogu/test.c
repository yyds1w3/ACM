#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <conio.h>  <-- Linux下删掉这个，没有这个文件

#define MAX_HERO 15
#define MAX_USER 100

// 定义英雄结构体
typedef struct {
    int id;
    char name[20];
    int jq, st, bu; // 剪刀、石头、布
    int s_jq, s_st, s_bu; // 剩余数量
    int win; 
    int total; 
} Hero;

// 玩家
typedef struct {
    char name[30];
    char pwd[30];
    int score; 
} User;

Hero heros[MAX_HERO]; 
User users[MAX_USER];
int user_count = 0;
int login_index = -1; 

// 函数声明
void init();
void load();
void save();
int check_move(int id);

// --- Linux 特供辅助函数 ---

// 模拟 Windows 的 system("pause")
void wait_enter() {
    printf("\n请按回车键继续...");
    // 循环读取直到读到换行符，既能清空缓冲区，又能等待输入
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

// 专门用来清空输入缓冲区并等待回车（防止scanf留下的坑）
void pause_game() {
    printf("\n请按回车键继续...");
    getchar(); // 这是一个简单的等待，前面代码里我会处理掉scanf留下的回车
}

// 模拟 system("cls")
void clear_screen() {
    system("clear"); // Linux下用clear
}

// ------------------------

void init() {
    Hero temp[MAX_HERO] = {
        {0, "赵云", 2, 2, 2}, {1, "宫本武藏", 4, 1, 1}, {2, "凯", 2, 3, 1},
        {3, "白起", 5, 0, 1}, {4, "韩信", 1, 2, 3}, {5, "诸葛亮", 2, 1, 3},
        {6, "刘邦", 2, 0, 4}, {7, "后羿", 0, 3, 3}, {8, "王昭君", 1, 1, 4},
        {9, "妲己", 4, 1, 1}, {10, "安琪拉", 1, 4, 1}, {11, "貂蝉", 3, 2, 1},
        {12, "露娜", 1, 3, 2}, {13, "不知火舞", 4, 2, 0}, {14, "蔡文姬", 0, 5, 1}
    };
    
    for(int i=0; i<MAX_HERO; i++) {
        heros[i] = temp[i];
        heros[i].win = 0;
        heros[i].total = 0;
        heros[i].s_jq = heros[i].jq;
        heros[i].s_st = heros[i].st;
        heros[i].s_bu = heros[i].bu;
    }
}

void load() {
    FILE *fp = fopen("players.txt", "r");
    if(fp == NULL) return; 
    
    user_count = 0;
    while(fscanf(fp, "%s %s %d", users[user_count].name, users[user_count].pwd, &users[user_count].score) != EOF) {
        user_count++;
    }
    fclose(fp);
}

void save() {
    FILE *fp = fopen("players.txt", "w");
    if(fp == NULL) {
        printf("保存失败！\n");
        return;
    }
    for(int i=0; i<user_count; i++) {
        fprintf(fp, "%s %s %d\n", users[i].name, users[i].pwd, users[i].score);
    }
    fclose(fp);
}

void login_sys() {
    int op;
    char n[30], p[30];
    while(1) {
        clear_screen(); 
        printf("*********************************\n");
        printf("       欢迎来到王者农药 (Linux版) \n");
        printf("*********************************\n");
        printf("1. 登录\n");
        printf("2. 注册\n");
        printf("3. 退出\n");
        printf("请选择: ");
        scanf("%d", &op);
        getchar(); // 吃掉scanf留下的回车符
        
        if(op == 1) {
            printf("用户名: "); scanf("%s", n);
            printf("密码: "); scanf("%s", p);
            getchar(); // 吃掉回车
            
            int flag = 0;
            for(int i=0; i<user_count; i++) {
                if(strcmp(users[i].name, n) == 0 && strcmp(users[i].pwd, p) == 0) {
                    login_index = i;
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                printf("登录成功！\n");
                pause_game();
                return;
            } else {
                printf("账号或密码错误！\n");
                pause_game();
            }
        }
        else if(op == 2) {
            printf("请输入新用户名: "); scanf("%s", n);
            int exist = 0;
            for(int i=0; i<user_count; i++) {
                if(strcmp(users[i].name, n) == 0) exist = 1;
            }
            if(exist) {
                printf("用户名已存在！\n");
                getchar(); // 吃掉回车
                pause_game();
                continue;
            }
            printf("请输入密码: "); scanf("%s", p);
            getchar(); // 吃掉回车
            
            strcpy(users[user_count].name, n);
            strcpy(users[user_count].pwd, p);
            users[user_count].score = 0;
            user_count++;
            save();
            printf("注册成功，请去登录！\n");
            pause_game();
        }
        else if(op == 3) {
            exit(0);
        }
    }
}

int check_move(int id) {
    if(heros[id].s_jq > 0 || heros[id].s_st > 0 || heros[id].s_bu > 0)
        return 1;
    return 0;
}

void play() {
    for(int i=0; i<MAX_HERO; i++) {
        heros[i].s_jq = heros[i].jq;
        heros[i].s_st = heros[i].st;
        heros[i].s_bu = heros[i].bu;
    }
    
    int my_h[3]; 
    int cpu_h[3]; 
    
    clear_screen();
    // --- 修改开始 ---
    // %-5s 表示左对齐占5格，%-14s 给名字留出足够的空间（容纳4个汉字）
    printf("%-5s %-14s %-6s %-6s %-6s\n", "ID", "名字", "剪刀", "石头", "布");
    printf("--------------------------------------------------\n"); 
    
    for(int i=0; i<MAX_HERO; i++) {
        printf("%-5d %-14s %-6d %-6d %-6d\n", 
               heros[i].id, heros[i].name, heros[i].jq, heros[i].st, heros[i].bu);
    }
    // --- 修改结束 ---
    printf("\n请输入3个英雄的ID(用空格隔开): ");
    for(int i=0; i<3; i++) {
        scanf("%d", &my_h[i]);
    }
    getchar(); // 吃掉回车
    
    printf("电脑正在选人...\n");
    for(int i=0; i<3; i++) {
        cpu_h[i] = rand() % 15;
        printf("电脑选择了: %s\n", heros[cpu_h[i]].name);
    }
    pause_game();
    
    int my_win = 0, cpu_win = 0;
    FILE *log = fopen("battle_log.txt", "a");
    fprintf(log, "--- 新对局: %s VS 电脑 ---\n", users[login_index].name);
    
    for(int r=1; r<=9; r++) {
        clear_screen();
        printf(">>> 第 %d 回合 <<<\n", r);
        printf("比分 我 %d : %d 电脑\n\n", my_win, cpu_win);
        
        int c_who, c_act; 
        while(1) {
            c_who = rand() % 3;
            if(check_move(cpu_h[c_who])) break; 
        }
        while(1) {
            c_act = rand() % 3;
            if(c_act == 0 && heros[cpu_h[c_who]].s_jq > 0) { heros[cpu_h[c_who]].s_jq--; break; }
            if(c_act == 1 && heros[cpu_h[c_who]].s_st > 0) { heros[cpu_h[c_who]].s_st--; break; }
            if(c_act == 2 && heros[cpu_h[c_who]].s_bu > 0) { heros[cpu_h[c_who]].s_bu--; break; }
        }
        printf("电脑派出了 [%s]，招数未知！\n", heros[cpu_h[c_who]].name);
        
        printf("\n我方阵容:\n");
        for(int i=0; i<3; i++) {
            printf("%d. %s (剪%d 石%d 布%d)\n", i, heros[my_h[i]].name, 
                   heros[my_h[i]].s_jq, heros[my_h[i]].s_st, heros[my_h[i]].s_bu);
        }
        int m_who;
        printf("请选择英雄序号(0-2): ");
        scanf("%d", &m_who);
        getchar(); // 吃掉回车，关键！
        
        if(m_who < 0 || m_who > 2 || check_move(my_h[m_who]) == 0) {
            printf("输入错误或者该英雄没招了，系统随便给你选一个！\n");
            for(int k=0; k<3; k++) if(check_move(my_h[k])) m_who = k;
        }
        
        int m_act;
        while(1) {
            m_act = rand() % 3;
            if(m_act == 0 && heros[my_h[m_who]].s_jq > 0) { heros[my_h[m_who]].s_jq--; break; }
            if(m_act == 1 && heros[my_h[m_who]].s_st > 0) { heros[my_h[m_who]].s_st--; break; }
            if(m_act == 2 && heros[my_h[m_who]].s_bu > 0) { heros[my_h[m_who]].s_bu--; break; }
        }
        
        char *str[] = {"剪刀", "石头", "布"};
        printf("我方 [%s] 出: %s\n", heros[my_h[m_who]].name, str[m_act]);
        printf("电脑 [%s] 出: %s\n", heros[cpu_h[c_who]].name, str[c_act]);
        
        int res = 0; 
        if(m_act == c_act) res = 0;
        else if((m_act==0 && c_act==2) || (m_act==1 && c_act==0) || (m_act==2 && c_act==1)) res = 1;
        else res = 2;
        
        if(res == 1) {
            printf("赢了！\n");
            my_win++;
            heros[my_h[m_who]].win++;
        } else if(res == 2) {
            printf("输了...\n");
            cpu_win++;
        } else {
            printf("平局\n");
        }
        heros[my_h[m_who]].total++; 
        
        fprintf(log, "R%d: 我(%s %s) VS 敌(%s %s) -> %d\n", r, heros[my_h[m_who]].name, str[m_act], 
                heros[cpu_h[c_who]].name, str[c_act], res);
        
        pause_game();
    }
    
    fclose(log);
    clear_screen();
    if(my_win > cpu_win) {
        printf("恭喜你，最终胜利！\n");
        users[login_index].score++;
        save();
    } else if(my_win < cpu_win) {
        printf("遗憾败北...\n");
    } else {
        printf("最终平局\n");
    }
    pause_game();
}

void rank_user() {
    User temp_u[MAX_USER];
    for(int i=0; i<user_count; i++) temp_u[i] = users[i];
    
    for(int i=0; i<user_count-1; i++) {
        for(int j=0; j<user_count-1-i; j++) {
            if(temp_u[j].score < temp_u[j+1].score) {
                User t = temp_u[j];
                temp_u[j] = temp_u[j+1];
                temp_u[j+1] = t;
            }
        }
    }
    
    clear_screen();
    printf("=== 玩家排行榜 ===\n");
    printf("名次\t姓名\t胜场\n");
    for(int i=0; i<user_count; i++) {
        printf("%d\t%s\t%d\n", i+1, temp_u[i].name, temp_u[i].score);
    }
    pause_game();
}

void rank_hero() {
    Hero temp_h[MAX_HERO];
    for(int i=0; i<MAX_HERO; i++) temp_h[i] = heros[i];
    
    for(int i=0; i<MAX_HERO-1; i++) {
        for(int j=0; j<MAX_HERO-1-i; j++) {
            double r1 = (temp_h[j].total == 0) ? 0 : (double)temp_h[j].win / temp_h[j].total;
            double r2 = (temp_h[j+1].total == 0) ? 0 : (double)temp_h[j+1].win / temp_h[j+1].total;
            
            if(r1 < r2) {
                Hero t = temp_h[j];
                temp_h[j] = temp_h[j+1];
                temp_h[j+1] = t;
            }
        }
    }
    
    clear_screen();
    printf("=== 英雄胜率榜 ===\n");
    printf("英雄\t胜场\t总场\t胜率\n");
    for(int i=0; i<MAX_HERO; i++) {
        double rate = (temp_h[i].total == 0) ? 0 : (double)temp_h[i].win / temp_h[i].total * 100;
        printf("%s\t%d\t%d\t%.1f%%\n", temp_h[i].name, temp_h[i].win, temp_h[i].total, rate);
    }
    pause_game();
}

int main() {
    srand(time(0));
    init();
    load();
    
    login_sys(); 
    
    while(1) {
        clear_screen();
        printf("1. 开始游戏\n");
        printf("2. 玩家排行\n");
        printf("3. 英雄排行\n");
        printf("4. 退出\n");
        printf("请选择: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // 关键：scanf后吃掉回车，不然会跳过下一次输入
        
        switch(choice) {
            case 1: play(); break;
            case 2: rank_user(); break;
            case 3: rank_hero(); break;
            case 4: save(); return 0;
            default: printf("输入错了！\n"); pause_game();
        }
    }
    return 0;
}