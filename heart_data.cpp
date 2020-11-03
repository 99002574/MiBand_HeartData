#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include "pbPlots.hpp"
#include "supportLib.hpp"
using namespace std; 
    
int main(){
    string word;
    
    
    fstream fin; 
    fin.open("heart_data_csv.csv", ios::in); 
    vector<string> row; 
    string line;
    double avgData[24]; 
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
        //cout<<"Avg of heartbeat between "<<j<<":00 and "<<j+1<<":00 is:   "<<sumAvg<<endl;
        }
        avgData[j]= sumAvg;
        //cout<<sumAvg<<endl;
        sumAvg=0;
        sum=0;
        count=0;  
                
    }
    // for(j=0;j<24;j++){
    //     cout<<avgData[j]<<endl;}
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    vector<double> x{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    vector<double> y{avgData[0],avgData[1],avgData[2],avgData[3],avgData[4],avgData[5],avgData[6],avgData[7],avgData[8],avgData[9],avgData[10],avgData[11],avgData[12],avgData[13],avgData[14],avgData[15],avgData[16],avgData[17],avgData[18],avgData[19],avgData[20],avgData[21],avgData[22],avgData[23]};
    DrawScatterPlot(imageRef, 600, 400, &x, &y);
    vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, "plot.png");
    DeleteImage(imageRef->image);
    fin.close(); 
    
    return 0;       
}
