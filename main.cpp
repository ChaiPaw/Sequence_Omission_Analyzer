#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>

using namespace std;

int i= 0;
int seq[1024];

int seq_calc(int start, int end);
int arraySort();
int billnos=0;

int main()
{   
    
    int input= 1;

    cout<<endl;
    cout<<"Being by pasting the number sequence from Excel followed by 0 to stop accepting Inputs"<<endl<<endl;
    cout<<"Please give an input for the number sequence:"<<endl;

    do
    {
        cin >> input;
        cout<<endl;
        if(input == 0)
        {
            break;
        }
        else
        {

        seq[i]=input;
        i++;
        }
    }while(input != 0);

    arraySort();

    cout<<"total number of inputs = "<<i<<endl;

    
    int arrStart=0;
    int arrEnd=0;
    arrStart = seq[0];
    arrEnd = seq[i-1];
    if(i!=0)
    {   
        
        billnos = arrEnd - arrStart + 1;
    }

    cout<<endl<<"Total Number of Bills Raised = "<<billnos<<endl<<endl;

    
    if(i!=0)
    {
    seq_calc(0,i);
    }




return 0;
}

int seq_calc(int start, int end)
{   
    int a = 0;
    int seqMissing[billnos];
    int seqCal[billnos];
    int temp = 0;
    int missCount = 0;


    for (int j = start; j<end; j++ )
    {
        temp = 0;
        if(seq[j+1]==seq[end])
        {
            break;
        }
        if(seq[j+1]!=seq[end])
        {
           temp = seq[j+1] - seq[j];
        }
        if(temp<=0)
        {
            cout<<"duplicate values found please check the sequence"<<endl;
        }
        if(temp!=1)
            {
                cout<<"Missing Numbers Found: ";
                cout<<temp-1<<endl<<endl;
                int hold = 0;
                int incr = 0;
                hold = seq[j];
                int arrMax = 0;
                arrMax = temp - 1 + missCount;
                for(a; a < arrMax; a++)
                {   
                    
                    seqMissing[a]=hold + incr + 1;
                    missCount++;
                    incr++;
                    
                }
            }
        
    }

    cout<<"New Sequence for missing number generated."<<endl;
    cout<<"Numbers missing from the sequence are:";
    
    int x=0;

    do{
        cout<<seqMissing[x]<<" ";
        x++;
    }while(x<missCount);
    cout<<endl;

    cout<<endl<< "Summary Genarated: "<<endl;
    cout<<endl<<"Total Number of Bills: "<<billnos<<endl;
    cout<<"Sequence Starts from: "<<seq[start]<<endl;
    cout<<"Sequence Ends At: "<<seq[i-1]<<endl;
    cout<<"Number of bills Raised: "<<end<<endl;
    cout<<"Bills Cancelled: "<<a<<endl;
    cout<<"\nVerifying: "<<"\nSequence end - Start = Total Bills = Bills Raised + Bills Cancelled"<<endl;


    int check_i, check_ii;

    check_i=seq[i-1]-seq[start]+1;
    check_ii=end + a;

    if(check_i == check_ii && check_i == billnos && check_ii == billnos)
    {
        cout<<"\nVerification Complete. Pausing Program"<<endl;
        cout<<"\n The Program Stopped. Close the window by pressing any key....";
        getch();
    }

    else{
        cout<<endl<<"There seems to be an error somewhere...."<<endl; 
    }
}

int arraySort()
{   
    int tempSort;
    for(int a=0; a<i; a++)
    {
        for(int b=a+1; b<i; b++)
        {
            
            if(seq[b] < seq[a])
            {
                tempSort = seq[b];
                seq[b] = seq[a];
                seq[a] = tempSort;
            }
        }
    }
}