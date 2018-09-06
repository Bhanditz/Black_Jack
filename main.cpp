#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
int generaterandnumber()
{
    //A function to create a random number between 1 and 10 as...
    //score of the cards
    return rand() % 10 + 1;
}
int generaterandnumber2()
{
    //A function to create a random number between 1 and 4
    //to get random card shape ♥ ♦ ♣ ♠
    return rand() % 4 + 1;
}
string cardChecker(int pc1,int pc2)
{
  //♥ ♦ ♣ ♠
   switch( pc1)
  {
     case 1:
  {
    if(pc2==1)
    {
      return"♥";
    }
    else if(pc2==2)
    {
      return"♦";
      
    }
    else if(pc2==3)
    {
      return"♣";
      
    }
    else if(pc2==4)
    { 
      return"♠";      
    }
    break;
  }
  //♥ ♦ ♣ ♠
  case 2:
  { 
    if(pc2==1)
    {
      return"♥";
      
    }
    else if(pc2==2)
    {
      return"♦";
      
    }
    else if(pc2==3)
    {
      return"♣";
   
    }
    else if(pc2==4)
    { 
      return"♠";
      
    }
    break;
  }
  //♥ ♦ ♣ ♠
  case 3:
  {

    if(pc2==1)
    {
      return"♥";
    }
    else if(pc2==2)
    {
      return"♦";
    }
    else if(pc2==3)
    {
      return"♣";
      
    }
    else if(pc2==4)
    { 
      return"♠";
      
    }
    break;
  }
  //♥ ♦ ♣ ♠
  case 4:
  {
    if(pc2==1)
    {
      return"♥";
    
    }
    else if(pc2==2)
    {
      return"♦";
      
    }
    else if(pc2==3)
    {
      return "♣";
      
    }
    else if(pc2==4)
    { 
      return"♠";
      
    }
    break;
  }
  }
}
int main()
{
/*this is a blackjack(aka 21) simple version your goal is to get 21 or anything closer to it but higher than the dealer's hand
you can either hit(ask for another card) or stand(dont ask for another card)
if you stand with x score if x is bigger than dealer score you win otherwise you lose
if you get 21 automatically you will win and also if the dealer got 21 he wins*/
  int P_Card1,D_Card1,P_Card2,D_Card2;
  int P_Total=0;
  int D_Total=0;
  //variables to store the number of the shape ...
  // of the card
  int pc1,pc2,dc1,dc2;
  //variables to store the shape of the card
  //♥ ♦ ♣ ♠
  string PC1="",PC2="",DC1="";
  char playing='N',choice;
    srand ( time(NULL) );
    while(playing=='N')
    {
      cout<<"_________♥ ♦ ♣ ♠ WELCOME TO BLACKJACK ♥ ♦ ♣ ♠_________"<<endl;
        //P_Card1 & 2 are player first 2 cards and D_Card1 & 2 are dealer first 2 cards
        P_Card1=generaterandnumber();
        P_Card2=generaterandnumber();
        D_Card1=generaterandnumber();
        D_Card2=generaterandnumber();
        //2 total variables to keep track of score in player and dealer hand
        P_Total=P_Card1+P_Card2;
        D_Total=D_Card1+D_Card2;
        pc1=generaterandnumber2();
        pc2=generaterandnumber2();
        dc1=generaterandnumber2();
        dc2=generaterandnumber2();
        PC1=cardChecker(pc1,pc2);
        PC2=cardChecker(pc1,pc2);
        DC1=cardChecker(dc1,dc2);
        cout<<"Your first card  is "<<P_Card1 <<" "<<PC1<<" and second card is "<<P_Card2<<" "<<PC2<<" with a total of "<<P_Total<<endl;
        cout<<"One of the dealer's cards is  "<<D_Card1<<" "<<DC1<<endl;
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
            if(choice=='N'||choice=='n')
               break;
            else if(choice=='Y'||choice=='y')
               continue;
    }
}