#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std; 
    
int main(){
    string word;
    
    
    fstream fin; 
    fin.open("heart_data_csv.csv", ios::in); 
    vector<string> row; 
    string line;
    int hour; 
    int count=0;
    int sum=0;
    int sumAvg;
    int j;
    
    while(!fin.eof()){
    getline(fin, line); 
    stringstream s(line);
    
    while (getline(s, word, ',')) { 
        row.push_back(word); 
    }}
        
    for(j=0;j<24;j++){
        for (int i = 0; i < row.size(); i++){  
            if(i%3==0){        
            if(stoi(row[i+2])==j){
                count++;
            sum+=stoi(row[i]);
            }
            }
        }
        
        if(count!=0){
        sumAvg =sum/count;
        cout<<"Avg of heartbeat between "<<j<<":00 and "<<j+1<<":00 is:   "<<sumAvg<<endl;}
        sumAvg=0;
        sum=0;
        count=0;           
    }
    
    fin.close(); 
    
    return 0;       
}
