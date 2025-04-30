#include <iostream>
#include <windows.h>
using namespace std;

const int WIDTH=40;
const int HEIGHT=20;

int main() {
    int x=WIDTH/2;
    int y=HEIGHT/2;
    int dx=1;
    int dy=1;
    while(true){
        system("cls");
        for(int i=0; i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(i==y && j==x)
                    cout << 'O';
                else{
                    cout << ' ';
                }
            }
            cout << endl;
        }
        x+=dx;
        y+=dy;
        if(x<=0 || x>=WIDTH-1){
            dx=-dx;
        }
        if(y<=0 || y >=HEIGHT-1){
            dy=-dy;
        }
        Sleep(50);
    }
    return 0;
}

