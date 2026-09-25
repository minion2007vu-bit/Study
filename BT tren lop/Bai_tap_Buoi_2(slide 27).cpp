//Xây dựng cấu trúc dữ liệu phù hợp với các yêu cầu bài tập ở Slide 26,27,28//

//Slide 27//

#include <iostream>
#include <vector>

using namespace std;

struct Coin_solution{
    int sum;
    vector<int> coin_data;
    int num_of_types;


    vector<int> coin_used;
    vector<int> last_used;
};

