#include <iostream>
#include<string>
#include<vector>
#include<iterator>
#include<type_traits>
#include<iterator>
#include<algorithm>
#include<utility>
#include<fstream>
#include <cmath> 

using namespace std;

bool isPrime(int num) {  
    if (num <= 1) return false;  // 0 and 1 are not prime numbers  
    if (num <= 3) return true;   // 2 and 3 are prime numbers  

    // Check for factors from 2 to sqrt(num)  
    for (int i = 2; i <= sqrt(num); ++i) {  
        if (num % i == 0) {  
            return false;  // Found a factor, num is not prime  
        }  
    }  
    return true;  // No factors found, num is prime  
}  

int main(int argc,char **argv)
{
    //Argument amount check
    if(argc!=3){
    	cerr<<string("Your program ")+argv[0]+" were not given enough arguments .";
    	return 1;
    }
    
    //File name
    string fileName="worker_";
    fileName=fileName+argv[1]+"_"+argv[2]+".txt";
    ofstream MyFile(fileName);
    
    int start=stoi(string(argv[1]));//The starting number
    int ending=stoi(string(argv[2]));//The ending number
    
    //Write the prime numbers into the file
    for(int i=start;i<=ending;++i){
    	if(isPrime(i)){
    	    MyFile<<i<<endl;
    	}
    }
    
    
    //Close the file
    MyFile.close();
    
    return 0;
}






