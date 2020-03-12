/*
Alice	1	deC1	1
Bob	2	deC2	2
Charlie	3	moc2	3
Oscar	4	moc3	4
		rec1	5
Fa	1	
Le	2	s1	1
PC	3	s2	2
Stu	4
TA	5
PTEm	6 */

#include <stdio.h>

int ua[5] = {23, 12, 45, 34, 35};
int pa[6] = {11, 13, 23, 54, 32, 45};
int us[6] = {11, 22, 41, 12, 42, 31};
int rs[6] = {11, 42, 31, 21, 52, 62};

int checkua(int u, int a)
{
    for(int i = 0; i<5; i++)
    {
        if (ua[i] == (u*10 + a)) return 1;
    }
    return 0;
}

int checkpa(int r, int p)
{
    for(int i = 0; i<6; i++)
    {
        if (pa[i] == (r*10 + p)) return 1;
    }
    return 0;
}
int checkus(int u, int s)
{
    for(int i = 0; i<6; i++)
    {
        if (us[i] == (u*10 + s)) return 1;
    }
    return 0;
}
int checkrs(int r, int s)
{
    for(int i = 0; i<6; i++)
    {
        if (rs[i] == (r*10 + s)) return 1;
    }
    return 0;
}
int *findrole_pa(int p)
{
    static int r[6];
    for(int i = 0; i<6; i++)
    {
        r[i] = 0;
    }
    for(int i = 0; i<6; i++)
    {
        if (((pa[i] - p)%10) == 0) {
            r[((pa[i] - p)/10) -1] = 1;
        }
    }
    return r;
}

int *getSession_U(int u){
    static int s[2];
    for (int i = 0; i<2; i++){
        if (checkus(u,i+1) == 1) {
            s[i] = 1;
        }
        else s[i] = 0;
    }
    return s;
}

int *getSession_R(int r){
    static int s[2];
    for (int i = 0; i<2; i++){
        if (checkrs(r,i+1) == 1) {
            s[i] = 1;
        }
        else s[i] = 0;
    }
    return s;
}
int main()
{
    int u, p;
    printf("Please enter u:");
    scanf("%d", &u);
    printf("Please enter p:");
    scanf("%d", &p);
    int *ar = findrole_pa(p);
    for (int i = 0; i < 6; i++){
        if (*(ar+i) == 0) continue;
        int r = i+1;
        int check_ua = checkua(u, r);
        if (check_ua == 0) {
            continue;
        }
    
        int *u_s = getSession_U(u);
        int *u_r = getSession_R(r);
    
        for (int i = 0; i < 2; i++){
            if ((*(u_s + i) == 1) & (*(u_r + i) == 1)){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
