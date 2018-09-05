#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int generaterandnumber()
{
    //function to create a random number between
    return rand() % 10 + 1;
}
int main()
{
  int P_Card1,D_Card1,P_Card2,D_Card2;
  int P_Total=0;
  int D_Total=0;
  char playing='N',choice;
    srand ( time(NULL) );
    while(playing=='N')
    {
        //P_Card1 & 2 are player first 2 cards and D_Card1 & 2 are dealer first 2 cards
        P_Card1=generaterandnumber();
        P_Card2=generaterandnumber();
        D_Card1=generaterandnumber();
        D_Card2=generaterandnumber();
        //2 total variables to keep track of score in player and dealer hand
        P_Total=P_Card1+P_Card2;
        D_Total=D_Card1+D_Card2;
        cout<<"Your first card is "<<P_Card1 <<" and second card is "<<P_Card2<<" with a total of "<<P_Total<<endl;
        if(P_Total>21)
          cout<<"You are bust!!";
        if(P_Total==20 && (P_Card1==1 || P_Card2==1))
        {
          cout<<"OMG!!!BLACKJACK,LUCKY YOU";
        }
        else
        {
            while(D_Total<21)
          {
              if(P_Total<21)
            {
                cout<< "Do you want to hit or stand (h for hit s for stand): ";
                cin>>choice;
                if(choice=='h'|| choice=='H')
                {
                  P_Card2=generaterandnumber();
                  P_Total += P_Card2;
                  if(P_Total==10 && P_Card2==1)
                        {
                            cout<<"YOU WON!!"<<endl<<"Your total is: 21, while Dealer's total is: "<<D_Total<<endl;
                            break;
                        }
                  cout<<"Your new total is now: "<<P_Total<<endl;
                    if(P_Total>21)
                        {
                            cout<<"You are bust!!";
                            break;
                        }
                    else if(P_Total==21)
                    {
                        cout<<"YOU WON!!"<<endl<<"Your total is: "<<P_Total<<", while Dealer's total is: "<<D_Total<<endl;
                        break;
                    }

                    else
                        continue;
                  if(D_Total<17)
                    {
                        D_Card2=generaterandnumber();
                        D_Total+=D_Card2;
                        if(D_Total==10 && D_Card2==1)
                        {
                            cout<<"YOU LOST!!"<<endl<<"Your total is: "<<P_Total<<", while Dealer's total is: 21"<<endl<<"PITY"<<endl;
                            break;
                        }
                    }
                }
                else if(choice=='s'|| choice=='S')
                {
                  if((P_Total>D_Total ||P_Total==21) && D_Total<21)
                    cout<<"YOU WON!!"<<endl<<"Your total is: "<<P_Total<<", while Dealer's total is: "<<D_Total<<endl;
                      else if(P_Total<D_Total && D_Total<=21)
                      {
                        cout<<"YOU LOST!!"<<endl<<"your total: "<<P_Total<<endl<<"Dealer total: "<<D_Total<<endl<<"PITY!!"<<endl;
                      }
                      else if(P_Total==D_Total && D_Total!=21 && P_Total!=21)
                      {
                          cout<<"DRAW??? WTF!!!";
                      }
                      break;
                }
            }
          }
        }
        cout<<"Play again? (Y/N)"<<endl;
        cin>>choice;
            if(choice=='N')
               break;
            else if(choice=='Y')
               continue;
    }
}
