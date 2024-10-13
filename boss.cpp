#include <iostream>
#include<string>
#include<vector>
#include<type_traits>
#include<iterator>
#include<algorithm>
#include<utility>
#include<fstream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


using namespace std;


int main(int argc,char **argv)
{
    int processNumber=stoi(string(argv[1]));
    int upperBound=stoi(string(argv[2]));
    
    int start=1;
    int ending=0;
    int base=upperBound/processNumber;
    
    int status;
    
    
    
    for(int i=0;i<processNumber;++i)
    {
     int pid = fork();
    
     //Determine the ending number for "this" separate interval
     ending=start+(base-1);
     if( i==(processNumber-1)    ){
     	ending=upperBound;//Handle the unaverage division for the last one
     } 
     
    
    if(pid<0){
    	cout<<"Fork fails";
    }
    else if ( pid == 0 )
        {         //Convert the start and ending number to the corresponding C-stype strings
           execl("./worker","./worker",to_string(start).c_str(),to_string(ending).c_str(),(char*)NULL);
        }
        
        start=++ending;//Determine the start number for "next" separate interval
    }
    
    
    
    for(int i=0;i<processNumber;++i){
    	int pidTerminated=wait(&status);
    	if(pidTerminated>0){
    	    cout<<"Child process with PID "<<pidTerminated<<" returned status code "<<status<<endl;
    	}
    }
    return 0;
}  





