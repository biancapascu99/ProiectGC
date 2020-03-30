#include <iostream>
#include<fstream>
using namespace std;
struct Punct{
float x,y;};
float mod(int a)
{
    return a>=0 ? a:-a;
}
float static arie(Punct a, Punct b, Punct c)
{
    float x=0.5 * mod((a.x*b.y + b.x*c.y + a.y*c.x - b.y*c.x - a.x*c.y - a.y*b.x));
        return x;
}
    //verifica daca punctul este in interiorul umui triunghi
bool static inter(Punct A, Punct B, Punct C, Punct M)
{
    return (arie(M,A,B) + arie(M, B, C) + arie(M,A,C)  ==  arie(A,B,C) ? true:false);
}
    //verific daca punctele sunt coliniare cu determinantul
int coliniar(Punct A, Punct B, Punct M)
{
    if(((A.x*B.y)+(B.x*M.y)+(M.x*A.y)-(M.x*B.y)-(A.x*M.y)-(B.x*A.y))==0)
        return 1;
    return 0;
}
int main()
{   fstream f("date.in");
    int n,i,j,k,nr=0,nrv=0;
    float v[100];
    Punct a[100],M;
    //cout<<"\nCiteste numarul de puncte:";
    f>>n; cout<<'\n';
    while(n<=2)
    {
         //cout<<"\nCiteste numarul de puncte:";
         f>>n; cout<<'\n';
    }
    for(i=0;i<n;i++)
    {
        //cout<<"Coordonatele punctului "<<i+1<<" sunt:";
        f>>a[i].x>>a[i].y;
    }

    f>>M.x>>M.y;

    int ok=0;

    for(i=0;i<=n-3;i++)
        if(inter(a[i],a[i+1],a[1+2],M))
            ok=1;
    if(inter(a[n-2],a[n-1],a[0],M))
        ok=1;

    if(ok==0)
        cout<<"Punctul este situat in exteriorul poligonului\n";

    else{
        for(i=0;i<=n-2;i++)
                if(coliniar(a[i],a[i+1],M))
                    ok=2;
        if(coliniar(a[n-1],a[0],M))
            ok=2;

        if(ok==2)
            cout<<"Punctul este situat pe una dintre laturi\n";
        else
            cout<<"Punctul se afla in interiorul acoperirii convexe a poligonului\n";
    }

    return 0;
}
