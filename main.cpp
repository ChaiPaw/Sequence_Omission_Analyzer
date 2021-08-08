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

    //do while loop initiated to take inputs for the Primary array.
    
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
    
    //sorting function called to sort Primary array into ascending order
    arraySort();
    
    //command line interface needs a lot of user friendly C-out. Esp as I created this for my dad...
    cout<<"total number of inputs = "<<i<<endl;

    //arrStart and arrEnd were used as the compiler was glitching out in the if(condition*)
    int arrStart=0;
    int arrEnd=0;
    arrStart = seq[0];
    arrEnd = seq[i-1];
    
    if(i==0)
    {
        cout<<"No inputs were provided, the program is ready to exit, please press any key"<<endl;
        getch();
        }
    
    
    //i!=0 as in if no inputs are given, then i will be 0 and the code will skip over everything as seen above.
    if(i!=0)
    {   
        //Total number of bills are calculated because this code was programmed while keeping GSTR-1 filing in mind.
        billnos = arrEnd - arrStart + 1;
    }

    cout<<endl<<"Total Number of Bills Raised = "<<billnos<<endl<<endl;

    
    if(i!=0)
    {
    seq_calc(0,i);
    }




return 0;
}


//separated the Sequence analysis part from the main code for easier track keeping.

int seq_calc(int start, int end)
{   
    int a = 0;
    int seqMissing[billnos];
    //separate array for the variables missing, also the upper limit is set to billnos as there cannot be more number of missing numbers than the highest number....
    int temp = 0;
    //misscount keeps a track of all the omissions.
    int missCount = 0;

    //scanning every number and checking if it is in serial or not, if not then adding to the SeqMissing array.
    for (int j = start; j<end; j++ )
    {
        temp = 0;
        //first Condition to avoid checking the final numerical number, with an unknown, as the array is not limited but the numbers are entered only till 'i'.
        if(seq[j+1]==seq[end])
        {
            break;
        }
        //This condition continues with the omission check to set the temp values to verify further.
        if(seq[j+1]!=seq[end])
        {
            //temo value set to know how many numbers are omitted amidst the next value and current value.
           temp = seq[j+1] - seq[j];
        }
        if(temp<=0)
        {
            //error as this condition simply shouldn't occur unless duplicates are present.
            cout<<"duplicate values found please check the sequence"<<endl;
        }
        /*the main condition we look for is this, why not 1?
        because we increment by 1 and when we calc B-A we are actually looking for B-A-1 as we want to start from the next number.*/
        if(temp!=1)
            {
                //displays the missing number's count.
                cout<<"Missing Numbers Found: ";
                cout<<temp-1<<endl<<endl;
                //New variables to hold the temp value from where the omissions starts and increment for adding the same sequential value for the Upper For loop.
                int hold = 0;
                int incr = 0;
                hold = seq[j];
                //array value to stop at and to start at is important to stop at a set number and to start from it.
                //the var 'a' is counting the lower limit while arrMax hold the upper limit for the array seqMissing 
                int arrMax = 0;            
                arrMax = temp - 1 + missCount;
                //adding the missing numbers, separately.
                for(a; a < arrMax; a++)
                {   
                    //hold is the lower limit of our omission seq, incr is the increment and +1 is so that the seq doesn't repeat the lower number as the incr starts from 0.
                    //ik I could have started incr from 1 but this is how I did and I am lazy to change it.
                    seqMissing[a]=hold + incr + 1;
                    missCount++;
                    incr++;
                    
                }
            }
        
    }

    cout<<"New Sequence for missing number generated."<<endl;
    cout<<"Numbers missing from the sequence are:";
    
    int x=0;
    //Displaying the missing numbers is not essential but I did it so that one can see my code work T-T
    do{
        cout<<seqMissing[x]<<" ";
        x++;
    }while(x<missCount);
    cout<<endl;
    //genarating the required summary as per GST requirements... it displays it all perfectly in a command line interface.
    cout<<endl<< "Summary Genarated: "<<endl;
    cout<<endl<<"Total Number of Bills: "<<billnos<<endl;
    cout<<"Sequence Starts from: "<<seq[start]<<endl;
    cout<<"Sequence Ends At: "<<seq[i-1]<<endl;
    cout<<"Number of bills Raised: "<<end<<endl;
    cout<<"Bills Cancelled: "<<a<<endl;
    cout<<"\nVerifying: "<<"\nSequence end - Start = Total Bills = Bills Raised + Bills Cancelled"<<endl;

    //verification of data is crucial as One cannot sit and calculate the ommissions for thousands of docs.
    //if you want to, you can also verify the total number of ommissions as another parameter for checking.
    //another check can be implemented with a bit of Mathematics and sequence and series knowledge. Using that we can find the sum of sequence and match with Array sum.
    int check_i, check_ii;
    //it simply grosses over the aggregated values, obtained from all the steps.
    check_i=seq[i-1]-seq[start]+1;
    check_ii=end + a;
    //'a' is the only calculated variable here, but it is the sole crucial variable required to keep a track of every omission.
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
//thats all folks! Thank you for checking my code out.
//this is just a sorting code picked up from my school time projects.
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
