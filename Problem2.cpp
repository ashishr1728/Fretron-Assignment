//My Money My Shares

#include<bits/stdc++.h>
using namespace std;

void distribution(vector<int> &apple, vector<int> &arr, double target){
    int sum = 0;
    for(int i = 0; i < apple.size(); i++){
        if((apple[i] != -1) && (sum + apple[i] <= target)){
            arr.push_back(apple[i]);
            sum += apple[i];
            apple[i] = -1;
        }
        else{
            continue;
        }
    }
    
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> apple;
    while(1){
        int weight;
        cout<<"Enter apple weight in gram (-1 to stop ) : ";
        cin >> weight;
        
        if(weight == -1){
            break;
        }
        else{
            apple.push_back(weight);
        }
    }
    
    int n = apple.size();
    int weight_sum = 0;
    for(int i = 0; i < n; i++){
        weight_sum += apple[i];
    }
    
    sort(apple.rbegin(), apple.rend());
    vector<int> app = apple;
    
    vector<int> Ram;
    vector<int> Sham;
    vector<int> Rahim;
    
    double Ram_sum = (weight_sum * 0.5);
    double Sham_sum = (weight_sum * 0.3);
    double Rahim_sum = (weight_sum * 0.2);
    
    cout<<"Distribution Result :"<<endl;
    cout<<"Ram : ";
    distribution(app, Ram, Ram_sum);
    cout<<endl;
    cout<<"Sham : ";
    distribution(app, Sham, Sham_sum);
    cout<<endl;
    cout<<"Rahim : ";
    distribution(app, Rahim, Rahim_sum);
    cout<<endl;
    
    return 0;
}