#include <bits/stdc++.h>

using namespace std;

class BankAcc
{
   public:
   long rupees ;
   string name ;
   string account_no ;
};

int main() {
   
   string str ;
   vector<BankAcc> vec ;
   while(getline(cin, str)){
      
      string s = "" , ss = "" , pname = "";
      int i ;
      for(i=0;str[i]!=' ';i++){
         s += str[i] ;   
      }
     
      int j ;
      for(j=i+1;str[j]!=' ';j++){
         ss += str[j] ;
      }
      for(int k=j+1 ;k<str.size();k++){
         pname += str[k] ;
      }
      if(s=="CREATE")
      {
         BankAcc obj ;
         obj.account_no = ss ;
         obj.name =  pname ; 
         obj.rupees = 0 ; 
         vec.push_back(obj);
      }else if(s=="DEPOSIT"){
         int found = 0;
         for(int i=0;i<vec.size();i++){
            if(vec[i].account_no==ss){
               found = 1 ;
               vec[i].rupees += stol(pname);
            }
         }
         if(found==0){
            cout<<"DEPOSIT : account number is invalid\n";
         }
      }else if(s=="WITHDRAW"){
         int found = 0;
         for(int i=0;i<vec.size();i++){
            if(vec[i].account_no==ss){
               found = 1 ;
               long l = stol(pname); 
               if(vec[i].rupees >= l){
               vec[i].rupees -= l ;
               }else{
                  cout<<"Money is Not present that much\n";
               }
            }
         }
         if(found==0){
            cout<<"WITHDRAW : account number is invalid\n";
         }
      }else if(s=="BALANCE"){
         int found =0 ;
         for(int i=0;i<vec.size();i++){
            string st = vec[i].account_no ;
            int flage =0 ;
            for(int i=0;i<st.size();i++){
               if(st[i]==ss[i]){
                  flage++ ;
               }
            }
            if(flage==ss.size()-1){
               found = 1 ;
               cout<<vec[i].name<<" "<<vec[i].rupees<<endl ;
            }
         }
         if(found==0){
            cout<<"BALANCE : account number is invalid\n";
         }
      }else{
         cout<<"Command Invalid\n";
      }      
   }
   return 0;
}
