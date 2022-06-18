#include <iostream>
using namespace std;
struct DATA
{
    float prob;
    char symb;
    double range_from,range_to;
};

void encoding( DATA Table[], string s, int T)
{
    cout<<"\nEncoding\n"<<endl;
    DATA Tab[T];
     for(int i=0 ; i<T ;i++)
    {
        Tab[i]=Table[i];
    }
    double Lc=0.0, Hc=0.0, Taille=1.0;
    int i=0,l=1;
    while (i<s.size())
    {
        for(int j=0;j<T;j++)
        {
          if(s[i]==Table[j].symb)
          {
              Lc=Tab[j].range_from;
              Hc=Tab[j].range_to;
              Taille= Hc-Lc;
              cout<<"Level ("<<l<<")\t"<<"["<< Lc <<"," << Hc <<"]"<<"\tdifference="<<Taille<< endl;
          }
        }
            cout<<"\nSymbol\t      Range_from\tRange_to\n";
            cout<<"_____________________________________________"<<endl;
          for(int k=0; k<T;k++)
          {
              Tab[k].range_from=Lc+Taille*Table[k].range_from;
              Tab[k].range_to  =Lc+Taille*Table[k].range_to;
              cout<<Tab[k].symb<<"\t\t"<<Tab[k].range_from<<"\t\t"<<Tab[k].range_to<<endl;

          }
          cout<<endl;
        i++;l++;
    }
    cout<<endl;
    cout<<"this sequence can be coded with any value from this interval ["<<Lc<<","<<Hc<<"]"<<endl;;
}
int main()
{
    int T;
    cout<<"precise the number of symboles "; cin >> T;
    DATA Table[T];
    double temp=0;
    for (int i=0; i<T ; i++)
    {
        cout<<"enter the symbol"<< "\t" ; cin>>Table[i].symb;
        cout<<"enter its probability "<< "\t" ; cin>>Table[i].prob;
        Table[i].range_from=temp;
        Table[i].range_to=Table[i].range_from+Table[i].prob;
        temp=Table[i].range_to;

    }
    cout<<"Symbol\tProbability\tRange_from\tRange_to\n";
    cout<<"______________________________________________"<<endl;
    for (int i=0; i<T ; i++)
    {
        cout<<Table[i].symb<<"\t"<<Table[i].prob<<"\t\t"<<Table[i].range_from<<"\t\t"<<Table[i].range_to<<endl;
    }
    cout<<endl;
    string s;
    cout<<"enter your sequence:  "; cin>> s;
    encoding(Table,s,T);
    return 0;
}
