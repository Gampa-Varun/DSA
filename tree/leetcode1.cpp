// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// bool consistency_check(int n, int e, int i, int g, int h){
//   if( n>=e && e>=i && i>=g && g>=h){
//     return true;
//   }
//   else{
//     return false;
//   }
// }

// bool final_consistency_check(int n, int e, int i, int g, int h){
//   if( n==e && e==i && i==g && g==h && n>1){
//     return true;
//   }
//   else{
//     return false;
//   }
// }




// int main() {
//   string input;



//   int number_n=0;
//   int number_e=0;
//   int number_i=0;
//   int number_g=0;
//   int number_h=0;
  
//   int repeat_count=-1;

//   string complete_check;

//   cin>>input;
 
//   bool invalid;
//   invalid = false;
//   string:: iterator it;
      
//     // Traverse the string
//     for (it = input.begin(); it != input.end();it++) {
//         if(consistency_check(number_n,number_e,number_i,number_g, number_h)){
//           if(*it == 'n'){
//             number_n++;
//           }
//           else if (*it == 'e'){
//             number_e++;
//           }
//           else if (*it == 'i'){
//             number_i++;
//           }
//           else if (*it == 'g'){
//             number_g++;
//           }
//           else if(*it == 'h'){
//             number_h++;
//           }
//           else{
//             invalid = true;
//           }
//         }

//         else{
//           invalid = true;
//         }

//       if((number_n == number_h)){
//         repeat_count+=1;
//       }


//     }


//     if(!invalid && final_consistency_check(number_n,number_e,number_i,number_g, number_h)){
//       number_n = number_n-repeat_count;
//       cout<<number_n;
//     }
//     else{
//       cout<<"invalid";
//     }
  
//   return 0;
// }


#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<size_t> find_occs(string s2, char element, size_t init_pos)
    {
        vector<size_t> occs;

        size_t start_pos = init_pos;

        while(start_pos != std::string::npos){
            

                start_pos = s2.find(element,start_pos+1);
                
                if(start_pos != std::string::npos){
                    occs.push_back(start_pos);
                }
            
        }
        

        return occs;
    } 

    int kSimilarity(string s1, string s2) {
        if(s1.length() != s2.length()){
            return -1;
        }
       
        int len = s1.length();
        
        size_t init_pos = 0;
        int swap_count = 0;
        for(int it =0; it< len;it++){
            if(s1[it] != s2[it]){
                size_t pos = 0;
                vector<size_t> pos_occs = find_occs(s2,s1[it],init_pos);
                for(auto pos_it = pos_occs.begin();pos_it!= pos_occs.end();pos_it++){
                    if(s1[*pos_it] == s2[*pos_it]){
                        continue;
                    }
                    else if (s1[*pos_it]== s2[it]){
                        pos = *pos_it;
                        break;
                    }
                    else if(pos ==0){
                        pos = *pos_it;
                    }

                }
                cout<<" pos "<<init_pos<<" fin pos "<< pos<< endl;
                swap(s2[init_pos], s2[pos]);
                //swap(s1[init_pos], s1[pos]);
                swap_count++;
            }
            init_pos ++;
        }
        return swap_count;
    }
};