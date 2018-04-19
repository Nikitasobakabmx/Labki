#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    float PI = 3.14,x,y,S,n;
    bool get = false;
    while(!get){
        cout<<"Insert value X and Y\n";
        cin>>x>>y;
        if((x>-1)&&(x<0)&&(y>1)&&(y<2)&&((x+1)*(x+1) + (y-1)*(y-1)>=1))
        {
        	get = true;
            S = 1 - PI/4;
            n = 1;
        }
        if((x > -2) && (x < -1) && (y > 0) && (y < 1) && ((x+1)*(x+1) + (y-1)*(y-1)>=1) )
        {
        	get = true;
            S = 1 - PI/4;
            n = 2;
        }
        if((x > 0) && (y > 0) && (x*x +y*y < 1))
        {
        	get = true;
            S = PI/4;
            n = 3;
        }
        if((x > 1) && (x < 2) && (y > 0) && (y < x + 1))
        {
        	get = true;
            S = 0.5;
            n = 4;
        }
        if((y < 0) && (x > 0) && (x < 1) && (x*x +y*y >= 1))
        {
        	get = true;
            S = 2 - PI/4;
            n = 5;
        }
        if(get)
            cout<<"You get figur number "<<n<<" it square is "<<S<<"\n";
        else 
            cout<<"you dont get a figure, tru again"<<"\n";
        cout<<"Out? 1/0 \n";
        cin >> get;
        }        
        getch();
    return 0;
}
