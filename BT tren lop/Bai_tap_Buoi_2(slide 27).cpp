//Xây dựng cấu trúc dữ liệu phù hợp với các yêu cầu bài tập ở Slide 26,27,28//

//Slide 27//

#include <iostream>
#include <vector>

using namespace std;

struct Coin_solution{
    int sum;                        //tong can tim
    int num_of_types;               //so luong cac loai dong xu
    int limit;                      //gioi han dai dien cho nhung tong chua co cach chia
    vector<int> coin_data;          //gia tri tung dong xu
    vector<int> coin_used;          //so luong dong xu de dc tong s
    
    Coin_solution(int sum, const vector<int>& coin_data, int num_of_types):
        sum(sum),
        num_of_types(num_of_types),
        limit(sum + 1),
        coin_data(coin_data),
        coin_used(limit, -1) {}

    vector<int> last_used;

    void find_solution(){
        for( int i = 0; i <= sum; i++){
            for( int j = 0; j < num_of_types; j++){
                if(coin_data[j] <= i && coin_used[sum- coin_data[j]] != limit){
                    if(coin_used[sum - coin_data[j]] + 1 < coin_used[i]){
                        coin_used[i] = coin_used[i - coin_data[j]] + 1;
                        last_used[i] = j;
                    }
                }
            }
        }
    }

    void output(){
        if(coin_used[sum] == limit){
            cout << "khong co cach chia nao thoa man tong S";
            return;
        }
        else{
            cout << "So xu toi thieu de duoc tong S la: " << coin_used[sum];
            
            return;
        }
    }

};

