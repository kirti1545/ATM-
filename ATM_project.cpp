#include<iostream>
#include<cstring>
using namespace std;
void print_ATM(char input[]){
    int n = strlen(input);
    //check size:
    if(n != 16 && n!= 19){
        cout<<"invalid"<<endl;
        return;
    }
    //1 index only 4 , 5 and 6:
    if(input[0] != '4'){
        if(input[0] != '5'){
            if(input[0] != '6'){
                cout<<"invalid"<<endl;
                return;
            }
        }
    }
    //only '-' 3:
    int county = 0;
    for(int i = 0 ; i<n ; i++){
        if(input[i] == '-'){
            county++;
        }
    }
    if(county > 3){
        cout<<"invalid"<<endl;
        return;
    }
    //check number and '-';
    for(int i = 0 ; i<n ; i++){
        char j = input[i];
        if(isdigit(j) || j == '-'){
            continue;
        }
        else{
            cout<<"invalid"<<endl;
            return;
        }
    }
     //check '-' is original place or not:
    if(input[4] != '-'){
        if(!isdigit(input[4])){
            cout<<"invalid"<<endl;
            return;
        }
    }
    if(input[9] != '-'){
        if(!isdigit(input[9])){
            cout<<"invalid"<<endl;
            return;
        }
    }
    if(input[14] != '-'){
        if(!isdigit(input[14])){
            cout<<"invalid"<<endl;
            return;
        }
    }
    //check consecutive reapaetaion number with '-:
    for(int i = 0 ; i<n ; i++){
        int count = 0;
     for(int j = i ; j<i+5 && j<n ; j++){
         char ch = input[j];
         if(ch == '-'){
             continue;
         }
         else if(isdigit(ch)){
             if(ch == input[i]){
                 count++;
             }
         }
         else{
             break;
         }
      }
      if(count >= 4){
          cout<<"invalid"<<endl;
          return;
      }
    }
    //my atm number is correct:
    cout<<"valid"<<endl;
    return;
}
int main(){
    char input[100];
    cin>>input;
    print_ATM(input);
    return 0;
}
