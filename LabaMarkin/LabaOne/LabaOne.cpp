#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    float PI = 3.14,x,y,S,n;
    bool get = false;
    while(!get){
        cout<<"Insert value X and Y\n";
        cin>>x>>y;
        if(((x+1)*(x+1) + (y-1)*(y-1) < 1) && (x*x+y*y>=1))
        {
        	get = true;
            S = PI/3 + 1 - PI/4;
            n = 1;
        }
        if((x>1) && (y>0) && (x > y - 1))
        {
        	get = true;
            S = 1 + 1.0/2;
            n = 2;
        }
        if((y > -1) && (x < y + 1) && (y < 0))
        {
        	get = true;
            S = 1.0/2;
            n = 3;
        }
        if((x*x + y*y < 1) && (x > y-1) && (y < 0))
        {
        	get = true;
            S = PI/4 + 0.5;
            n = 4;
        }
        if((x > 0) && (x < 1) && (y < 0) && (x*x + y*y >= 1))
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
