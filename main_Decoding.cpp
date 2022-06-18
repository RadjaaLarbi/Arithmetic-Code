#include <iostream>
using namespace std;

struct DATA
{
    char symb;
    float prob;
    double range_from, range_to;
};

void decode( DATA Table[] , double code_word , int N, int T)
{
    double Lc=0.0, Hc=1.0 , Taille=1.0,X,temp;
    string s="";
    //cout<< "[Lc,Hc]=[" <<Lc <<","<< Hc << "]."<<"\tdifference = "<< Taille <<endl;
    //cout<<endl;
    for(int i=0 ; i<N ;i++)
    {
        X=(code_word-Lc)/Taille;
        for(int j=0; j<T ;j++)
        {
            if (Table[j].range_from<= X && X<Table[j].range_to)
            {
               temp=Lc;
               s=s+Table[j].symb;
               Lc=temp+Taille*Table[j].range_from;
               Hc=temp+Taille*Table[j].range_to;
               Taille=Hc-Lc;
               cout<< "[Lc,Hc]=[" <<Lc <<","<< Hc << "]."<<"\tdifference = "<< Taille <<endl;
               cout<<endl;
            }
        }
    }
    cout << "the coded sequence is :"<< s << endl;
}
int main()
{
    //double Lc=0.0, Hc=1.0 , Taille=1.0;
    int T,N;
    //cout<< "[Lc,Hc]=[" <<Lc <<","<< Hc << "]."<<"\tdifference = "<< Taille <<endl;
    cout<< "Precise the number of symbols used ="; cin>>T;
    DATA Table [T];
    double temp=0;
    for(int i=0; i<T; i++)
    {
        cout<<"enter the symbol"<< "\t" ; cin>>Table[i].symb;
        cout<<"enter its probability "<< "\t" ; cin>>Table[i].prob;
        Table[i].range_from=temp;
        Table[i].range_to=Table[i].range_from+Table[i].prob;
        temp=Table[i].range_to;
    }

    cout<<"Symbole\tProbability\tRange_from\tRange_to\n";
    cout<<"______________________________________________"<<endl;
    for(int i=0; i<T; i++)
    {
        cout<<Table[i].symb<<"\t"<<Table[i].prob<<"\t\t"<<Table[i].range_from<<"\t\t"<<Table[i].range_to<<endl;
    }

    double code_word;
    cout<<"\nenter the code word = "; cin>>code_word;
    cout<<"precise how many symbols are used in the coding of this word "; cin>>N;
    cout<<endl;
    decode(Table,code_word,N,T);

    return 0;
}
