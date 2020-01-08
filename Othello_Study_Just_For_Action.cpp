#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
//time
int main()
{
    char mal[10][10]; //[x][y], wall
    int x,y;
    int game = 0; //over = 1; ing = 0;
    int time = 1;
    int score[2] = {0,0};
    int player[2] = {0,1};
    int remaincnt = 2;
    int cnt = 0;
    int changecnt = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            mal[i][j] = '0';
            if(i==0 || i==9){
                mal[i][j] = 'W';
            }
            if(j==0 || j==9){
                mal[i][j] = 'W';
            }
        }
    }
    mal[4][4] = '1';
    mal[4][5] = '2';
    mal[5][4] = '2';
    mal[5][5] = '1';
    mal[3][4] = 'x';
    while(game<1){
        score[0] = 0;
        score[1] = 0;
        cnt = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if(mal[i][j]=='x'){
                    mal[i][j]='0';
                    cnt += 1;
                    cout << cnt << endl;
                    remaincnt = 2;
                    cout << remaincnt << endl;
                }
                if(mal[i][j] == '1'){
                    score[0]++;
                }else if(mal[i][j] == '2'){
                    score[1]++;
                }
            }
        }
        if(cnt < 1){
            if(remaincnt == 1){
                cout << "pass pass" << endl;
                remaincnt = 0;
            }else if(remaincnt == 2){
                cout << "pass" << endl;
                remaincnt = 1;
                if(player[0]==1){
                    player[0] -= 1;
                    player[1] += 1;
                }else if(player[1]==1){
                    player[1] -= 1;
                    player[0] += 1;
                }
            }
        }
        if(score[0]+score[1]==64 || remaincnt == 0){
            cout << "GAME OVER" << endl;
            if(score[0] > score[1]){
                cout << "WINNER : " << player[0] << endl;
            }else if(score[0] < score[1]){
                cout << "WINNER : " << player[1] << endl;
            }else{
                cout << "DRAW!" << endl;
            }
            game=1;
            break;
        }
        cout << "==============================" << endl;
        cout << "SCORE " << endl;
        cout << "player 1 : " << score[0] << endl;
        cout << "player 2 : " << score[1] << endl;
        cout << "==============================" << endl;
        if(player[0]==1){
            for (int i = 0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(mal[i][j]=='1'){
                        for(int s=1;mal[i+s][j] != 'x' && mal[i+s][j] != '0' && mal[i+s][j] != '1' && mal[i+s][j] != 'W';s++){
                        cout << "find i : " << i << ", j : " << j << endl;        
                        if(mal[i+s][j] == '2' && i+s < 9){
                            for(int can=1;can<9;can++){
                                if(mal[i+s+can][j] == '0'){
                                    cout << "1 done" << endl;
                                    mal[i+s+can][j] = 'x';
                                    break;
                                }else if(mal[i+s+can][j] == 'x' || mal[i+s+can][j] == '1'){
                                    cout << "1 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i][j+s] != 'x' && mal[i][j+s] != '0' && mal[i][j+s] != '1' && mal[i][j+s] != 'W';s++){
                        if(mal[i][j+s] == '2' && j+s < 9 && mal[i][j+s-1] != 'x'&& mal[i][j+s-1] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i][j+s+can] == '0'){
                                    cout << "2 done" << endl;
                                    mal[i][j+s+can] = 'x';
                                    break;
                                }else if(mal[i][j+s+can] == 'x' || mal[i][j+s+can] == '1'){
                                    cout << "2 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i+s][j+s] != 'x' && mal[i+s][j+s] != '0' && mal[i+s][j+s] != '1' && mal[i+s][j+s] != 'W';s++){
                        if(mal[i+s][j+s] == '2' && i+s < 9 && j+s < 9 && mal[i+s-1][j+s-1] != 'x'&& mal[i+s-1][j+s-1] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i+s+can][j+s+can] == '0'){
                                    cout << "3 done" << endl;
                                    mal[i+s+can][j+s+can] = 'x';
                                    break;
                                }else if(mal[i+s+can][j+s+can] == 'x' || mal[i+s+can][j+s+can] == '1'){
                                    cout << "3 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i-s][j] != 'x' && mal[i-s][j] != '0' && mal[i-s][j] != '1' && mal[i-s][j] != 'W';s++){
                        if(mal[i-s][j] == '2' && i-s > 0 && mal[i-s+1][j] != 'x'&& mal[i-s+1][j] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i-s-can][j] == '0'){
                                    cout << "4 done" << endl;
                                    mal[i-s-can][j] = 'x';
                                    break;
                                }else if(mal[i-s-can][j] == 'x' || mal[i-s-can][j] == '1'){
                                    cout << "4 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i][j-s] != 'x' && mal[i][j-s] != '0' && mal[i][j-s] != '1' && mal[i][j-s] != 'W';s++){
                        if(mal[i][j-s] == '2' && j-s > 0 && mal[i][j-s+1] != 'x'&& mal[i][j-s+1] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i][j-s-can] == '0'){
                                    cout << "5 done" << endl;
                                    mal[i][j-s-can] = 'x';
                                    break;
                                }else if(mal[i][j-s-can] == 'x' || mal[i][j-s-can] == '1'){
                                    cout << "5 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i-s][j-s] != 'x'&& mal[i-s][j-s] != '0' && mal[i-s][j-s] != '1' && mal[i-s][j-s] != 'W';s++){
                        if(mal[i-s][j-s] == '2' && i-s > 0 && j-s > 0 && mal[i-s+1][j-s+1] != 'x'&& mal[i-s+1][j-s+1] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i-s-can][j-s-can] == '0'){
                                    cout << "6 done" << endl;
                                    mal[i-s-can][j-s-can] = 'x';
                                    break;
                                }else if(mal[i-s-can][j-s-can] == 'x' || mal[i-s-can][j-s-can] == '1'){
                                    cout << "6 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i+s][j-s] != 'x'&& mal[i+s][j-s] != '0' && mal[i+s][j-s] != '1' && mal[i+s][j-s] != 'W';s++){
                        if(mal[i+s][j-s] == '2' && i+s < 9 && j+s > 0 && mal[i+s-1][j-s+1] != 'x'&& mal[i+s-1][j-s+1] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i+s+can][j-s-can] == '0'){
                                    cout << "7 done" << endl;
                                    mal[i+s+can][j-s-can] = 'x';
                                    break;
                                }else if(mal[i+s+can][j-s-can] == 'x' || mal[i+s+can][j-s-can] == '1'){
                                    cout << "7 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s=1;mal[i-s][j+s] != 'x'&& mal[i-s][j+s] != '0' && mal[i-s][j+s] != '1' && mal[i-s][j+s] != 'W';s++){
                        if(mal[i-s][j+s] == '2' && i-s > 0 && j+s < 9 && mal[i-s+1][j+s-1] != 'x'&& mal[i-s+1][j+s-1] != '0'){
                            for(int can=1;can<9;can++){
                                if(mal[i-s-can][j+s+can] == '0'){
                                    cout << "8 done" << endl;
                                    mal[i-s-can][j+s+can] = 'x';
                                    break;
                                }else if(mal[i-s-can][j+s+can] == 'x' || mal[i-s-can][j+s+can] == '1'){
                                    cout << "8 bk" << endl;
                                    break;
                                }
                            }
                        }
                        }
                    }
                }
            }
        }else if(player[1]==1){
            for (int i = 0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(mal[i][j]=='2'){
                        for(int s1=1;mal[i+s1][j] != 'x' && mal[i+s1][j] != '0' && mal[i+s1][j] != '2' && mal[i+s1][j] != 'W';s1++){
                        cout << "find i : " << i << ", j : " << j << endl;
                        if(mal[i+s1][j] == '1' && i+s1 < 9 && mal[i+s1-1][j] != 'x'&& mal[i+s1-1][j] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i+s1+can][j]!='W' && mal[i+s1+can][j] != '2';can++){
                                if(mal[i+s1+can][j] == '0'){
                                    cout << "9 done" << endl;
                                    mal[i+s1+can][j] = 'x';
                                    break;
                                }else if(mal[i+s1+can][j] == 'x' || mal[i+s1+can][j] == '2'){
                                    cout << "9 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i][j+s1] != 'x' && mal[i][j+s1] != '0' && mal[i][j+s1] != '2' && mal[i][j+s1] != 'W';s1++){
                        if(mal[i][j+s1] == '1' && j+s1 < 9 && mal[i][j+s1-1] != 'x'&& mal[i][j+s1-1] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i][j+s1+can]!='W' && mal[i][j+s1+can] != '2';can++){
                                if(mal[i][j+s1+can] == '0'){
                                    cout << "10 done" << endl;
                                    mal[i][j+s1+can] = 'x';
                                    break;
                                }else if(mal[i][j+s1+can] == 'x' || mal[i][j+s1+can] == '2'){
                                    cout << "10 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i+s1][j+s1] != 'x' && mal[i+s1][j+s1] != '0' && mal[i+s1][j+s1] != '2' && mal[i+s1][j+s1] != 'W';s1++){
                        if(mal[i+s1][j+s1] == '1' && i+s1 < 9 && j+s1 < 9 && mal[i+s1-1][j+s1-1] != 'x'&& mal[i+s1-1][j+s1-1] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i+s1+can][j+s1+can]!='W' && mal[i+s1+can][j+s1+can] != '2';can++){
                                if(mal[i+s1+can][j+s1+can] == '0'){
                                    cout << "11 done" << endl;
                                    mal[i+s1+can][j+s1+can] = 'x';
                                    break;
                                }else if(mal[i+s1+can][j+s1+can] == 'x' || mal[i+s1+can][j+s1+can] == '2'){
                                    cout << "11 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i-s1][j] != 'x' && mal[i-s1][j] != '0' && mal[i-s1][j] != '2' && mal[i-s1][j] != 'W';s1++){
                        if(mal[i-s1][j] == '1' && i-s1 > 0 && mal[i-s1+1][j] != 'x'&& mal[i-s1+1][j] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i-s1-can][j]!='W' && mal[i-s1-can][j] != '2';can++){
                                if(mal[i-s1-can][j] == '0'){
                                    cout << "12 done" << endl;
                                    mal[i-s1-can][j] = 'x';
                                    break;
                                }else if(mal[i-s1-can][j] == 'x' || mal[i-s1-can][j] == '2'){
                                    cout << "12 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i][j-s1] != 'x' && mal[i][j-s1] != '0' && mal[i][j-s1] != '2' && mal[i][j-s1] != 'W';s1++){
                        if(mal[i][j-s1] == '1' && j-s1 > 0 && mal[i][j-s1+1] != 'x'&& mal[i][j-s1+1] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i][j-s1-can]!='W' && mal[i][j-s1-can] != '2';can++){
                                if(mal[i][j-s1-can] == '0'){
                                    cout << "13 done" << endl;
                                    mal[i][j-s1-can] = 'x';
                                    break;
                                }else if(mal[i][j-s1-can] == 'x' || mal[i][j-s1-can] == '2'){
                                    cout << "13 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i-s1][j-s1] != 'x' && mal[i-s1][j-s1] != '0' && mal[i-s1][j-s1] != '2' && mal[i-s1][j-s1] != 'W';s1++){
                        if(mal[i-s1][j-s1] == '1' && i-s1 > 0 && j-s1 > 0 && mal[i-s1+1][j-s1+1] != 'x'&& mal[i-s1+1][j-s1+1] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i-s1-can][j-s1-can]!='W' && mal[i-s1-can][j-s1-can] != '2';can++){
                                if(mal[i-s1-can][j-s1-can] == '0'){
                                    cout << "14 done" << endl;
                                    mal[i-s1-can][j-s1-can] = 'x';
                                    break;
                                }else if(mal[i-s1-can][j-s1-can] == 'x' || mal[i-s1-can][j-s1-can] == '2'){
                                    cout << "14 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i+s1][j-s1] != 'x' && mal[i+s1][j-s1] != '0' && mal[i+s1][j-s1] != '2' && mal[i+s1][j-s1] != 'W';s1++){
                        if(mal[i+s1][j-s1] == '1' && i+s1 < 9 && j-s1 > 0 && mal[i+s1-s1][j-s1+1] != 'x'&& mal[i+s1-1][j-s1+1] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i+s1+can][j-s1-can]!='W' && mal[i+s1+can][j-s1-can] != '2';can++){
                                if(mal[i+s1+can][j-s1-can] == '0'){
                                    cout << "15 done" << endl;
                                    mal[i+s1+can][j-s1-can] = 'x';
                                    break;
                                }else if(mal[i+s1+can][j-s1-can] == 'x' || mal[i+s1+can][j-s1-can] == '2'){
                                    cout << "15 bk" << endl;
                                    break;
                                }
                            }
                        }}
                        for(int s1=1;mal[i-s1][j+s1] != 'x' && mal[i-s1][j+s1] != '0' && mal[i-s1][j+s1] != '2' && mal[i-s1][j+s1] != 'W';s1++){
                        if(mal[i-s1][j+s1] == '1' && i-s1 > 0 && j+s1 < 9 && mal[i-s1+1][j+s1-1] != 'x'&& mal[i-s1+1][j+s1-1] != '0'){
                            cout << "find 1" << endl;
                            for(int can=1;mal[i-s1-can][j+s1+can]!='W' && mal[i-s1-can][j+s1+can] != '2';can++){
                                if(mal[i-s1-can][j+s1+can] == '0'){
                                    cout << "16 done" << endl;
                                    mal[i-s1-can][j+s1+can] = 'x';
                                    break;
                                }else if(mal[i-s1-can][j+s1+can] == 'x' || mal[i-s1-can][j+s1+can] == '2'){
                                    cout << "16 bk" << endl;
                                    break;
                                }
                            }
                        }
                        }
                    }
                }
            }
        }
        for (int i = 0;i<10;i++){
            for(int j=0;j<10;j++){
                cout << mal[i][j];
            }
            cout << "\n";
        }

        if(player[0] == 1){
            cout << "******player 1 turn!******" << endl;
        }else if(player[1] == 1){
            cout << "******player 2 turn!******" << endl;
        }
        cout << "x(1~8) : ";
        cin >> x;
        cout << "y(1~8) : ";
        cin >> y;
        if((x>0&&x<9)&&(y>0&&y<9)&&(mal[y][x]=='x')&&time == 1){
            if(player[0] == 1){
                mal[y][x] = '1';
                for(int e=1;e<8;e++){
                    if(mal[y+e][x]=='1' && y+e<9){
                        changecnt = 0;
                        cout << "1same" << endl;
                        cout << "x = " << x << "y = " << y << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y+(e-f)][x]=='x'){
                                    break;
                                }
                                if(mal[y+(e-f)][x]!='0' && mal[y+(e-f)][x]!='x' && mal[y+(e-f)][x]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y+(e-f2)][x] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y][x+e]=='1'&& (x+e)<9){
                        changecnt = 0;
                        cout << "2same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y][x+(e-f)]=='x'){
                                    break;
                                }
                                if(mal[y][x+(e-f)]!='0' && mal[y][x+(e-f)]!='x' && mal[y][x+(e-f)]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y][x+(e-f2)] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y-e][x]=='1' && y-e > 0){
                        changecnt = 0;
                        cout << "3same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y-(e-f)][x]=='x'){
                                    break;
                                }
                                if(mal[y-(e-f)][x]!='0' && mal[y-(e-f)][x]!='x' && mal[y-(e-f)][x]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y-(e-f2)][x] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y][x-e]=='1' && x-e > 0){
                        changecnt = 0;
                        cout << "4same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y][x-(e-f)]=='x'){
                                    break;
                                }
                                if(mal[y][x-(e-f)]!='0' && mal[y][x-(e-f)]!='x' && mal[y][x-(e-f)]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y][x-(e-f2)] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y+e][x+e]=='1' && y+e < 9 && x+e < 9){
                        changecnt = 0;
                        cout << "5same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y+(e-f)][x+(e-f)]=='x'){
                                    break;
                                }
                                if(mal[y+(e-f)][x+(e-f)]!='0' && mal[y+(e-f)][x+(e-f)]!='x' && mal[y+(e-f)][x+(e-f)]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y+(e-f2)][x+(e-f2)] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y-e][x-e]=='1' && y-e > 0 && x-e > 0){
                        changecnt = 0;
                        cout << "6same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y-(e-f)][x-(e-f)]=='x'){
                                    break;
                                }
                                if(mal[y-(e-f)][x-(e-f)]!='0' && mal[y-(e-f)][x-(e-f)]!='x' && mal[y-(e-f)][x-(e-f)]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y-(e-f2)][x-(e-f2)] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y+e][x-e]=='1' && y+e < 9 && x-e > 0){
                        changecnt = 0;
                        cout << "7same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y+(e-f)][x-(e-f)]=='x'){
                                    break;
                                }
                                if(mal[y+(e-f)][x-(e-f)]!='0' && mal[y+(e-f)][x-(e-f)]!='x' && mal[y+(e-f)][x-(e-f)]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y+(e-f2)][x-(e-f2)] = '1';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y-e][x+e]=='1' && y-e > 0 && x+e < 9){
                        changecnt = 0;
                        cout << "8same" << endl;
                        cout << "e = " << e << endl;
                        if(e>1){
                            for(int f=1;f<e;f++){
                                if(mal[y-(e-f)][x+(e-f)]=='x'){
                                    break;
                                }
                                if(mal[y-(e-f)][x+(e-f)]!='0' && mal[y-(e-f)][x+(e-f)]!='x' && mal[y-(e-f)][x+(e-f)]!='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (e-1)){
                                    for(int f2=1;f2<e;f2++){
                                        mal[y-(e-f2)][x+(e-f2)] = '1';
                                    }}
                                }
                            }
                        }
                    }
                }
                player[0] -= 1;
                player[1] += 1;
            }else if(player[1] == 1){
                mal[y][x] = '2';
                for(int k=1;k<8;k++){
                    if(mal[y+k][x]=='2' && y+k < 9){
                        changecnt = 0;
                        cout << "9same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y+(k-c)][x]=='x'){
                                    break;
                                }
                                if(mal[y+(k-c)][x]!='0' && mal[y+(k-c)][x]!='x' && mal[y+(k-c)][x]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y+(k-c2)][x] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y][x+k]=='2' && x+k < 9){
                        changecnt = 0;
                        cout << "10same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y][x+(k-c)]=='x' && mal[y][x+(k-c)]=='0' && mal[y][x+(k-c)]=='2'){
                                    break;
                                }
                                if(mal[y][x+(k-c)]=='1'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y][x+(k-c2)] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y-k][x]=='2' && y-k > 0){
                        changecnt = 0;
                        cout << "11same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y-(k-c)][x]=='x'){
                                    break;
                                }
                                if(mal[y-(k-c)][x]!='0' && mal[y-(k-c)][x]!='x' && mal[y-(k-c)][x]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y-(k-c2)][x] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y][x-k]=='2' && x-k>0){
                        changecnt = 0;
                        cout << "12same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y][x-(k-c)]=='x'){
                                    break;
                                }
                                if(mal[y][x-(k-c)]!='0' && mal[y][x-(k-c)]!='x' && mal[y][x-(k-c)]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y][x-(k-c2)] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y+k][x+k]=='2' && y+k < 9 && x+k < 9){
                        changecnt = 0;
                        cout << "13same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y+(k-c)][x+(k-c)]=='x'){
                                    break;
                                }
                                if(mal[y+(k-c)][x+(k-c)]!='0' && mal[y+(k-c)][x+(k-c)]!='x' && mal[y+(k-c)][x+(k-c)]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y+(k-c2)][x+(k-c2)] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y-k][x-k]=='2' && y-k > 0 && x-k > 0){
                        changecnt = 0;
                        cout << "14same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y-(k-c)][x-(k-c)]=='x'){
                                    break;
                                }
                                if(mal[y-(k-c)][x-(k-c)]!='0' && mal[y-(k-c)][x-(k-c)]!='x' && mal[y-(k-c)][x-(k-c)]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y-(k-c2)][x-(k-c2)] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y+k][x-k]=='2' && y+k < 9 && x-k > 0){
                        changecnt = 0;
                        cout << "15same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y+(k-c)][x-(k-c)]=='x'){
                                    break;
                                }
                                if(mal[y+(k-c)][x-(k-c)]!='0' && mal[y+(k-c)][x-(k-c)]!='x' && mal[y+(k-c)][x-(k-c)]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y+(k-c2)][x-(k-c2)] = '2';
                                    }}
                                }
                            }
                        }
                    }
                    if(mal[y-k][x+k]=='2' && y-k > 0 && x+k < 9){
                        changecnt = 0;
                        cout << "16same" << endl;
                        cout << "k = " << k << endl;
                        if(k>1){
                            for(int c=1;c<k;c++){
                                if(mal[y-(k-c)][x+(k-c)]=='x'){
                                    break;
                                }
                                if(mal[y-(k-c)][x+(k-c)]!='0' && mal[y-(k-c)][x+(k-c)]!='x' && mal[y-(k-c)][x+(k-c)]!='2'){
                                    changecnt += 1;
                                    cout << "change!" << endl;
                                    if(changecnt == (k-1)){
                                    for(int c2=1;c2<k;c2++){
                                        mal[y-(k-c2)][x+(k-c2)] = '2';
                                    }}
                                }
                            }
                        }
                    }
                }
                player[1] -= 1;
                player[0] += 1;
                x = 0;
                y = 0;
            }
        }else{
            cout << "wrong way" << endl;
        }

    }
}
