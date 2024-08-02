//My Money My Shares

#include<bits/stdc++.h>
using namespace std;

void distribution(vector<int> &apple, vector<int> &arr, double target){
    // 8. Here we created one variable sum which stors the current sum of weight that each one get.
    int sum = 0;

    // 9. We all the weight in sum and check if the sum is less than or equal to target then add to the vector arr and update the sum variable and put -1 in that index. Otherwise continue.
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
    
    // 10. Here we print all the apples weight that Ram, Sham and Rahim gets.
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    // 1. Created one vector name apple in which we stored the weight of the apple.
    vector<int> apple;

    // 2. Then play a while loop and get the input from the user utill it gives -1.
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
    // 3. Then find the total weight of all the apples.
    int weight_sum = 0;
    for(int i = 0; i < n; i++){
        weight_sum += apple[i];
    }
    // 4. Sort the vector apple in decreasing order.
    sort(apple.rbegin(), apple.rend());
    
    // 5. Created 3 another vector in which we stored the apple of Ram, Sham and Rahim.
    vector<int> Ram;
    vector<int> Sham;
    vector<int> Rahim;
    
    // 6. Find the total weight of the apple for Ram, Sham and Rahim according to their money they paid. 
    double Ram_sum = (weight_sum * 0.5);
    double Sham_sum = (weight_sum * 0.3);
    double Rahim_sum = (weight_sum * 0.2);
    
    // 7. Call function distribution separately for Ram,Sham and Rahim. In which we pass 3 parameters one is vector apple which stored the weight of all the apples, second one is Vector which stores apple for all three of them seperately and third one is the weight of the apple they get.
    cout<<"Distribution Result :"<<endl;
    cout<<"Ram : ";
    distribution(apple, Ram, Ram_sum);
    cout<<endl;
    cout<<"Sham : ";
    distribution(apple, Sham, Sham_sum);
    cout<<endl;
    cout<<"Rahim : ";
    distribution(apple, Rahim, Rahim_sum);
    cout<<endl;
    
    return 0;
}
