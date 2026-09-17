//Xây dựng cấu trúc dữ liệu phù hợp với các yêu cầu bài tập ở Slide 26,27,28//

//Slide 26//

#include <iostream>
#include <vector>

using namespace std;
 
class Song{
    public:
        string ID_song;
        string genre;
        string author;
        string date;
        int downloads_count;
        int likes_count;
        int views_count;
};


class User{
    public:
        string ID_user;
        string username;
        string DOB;
        string region;
        vector<Song> history;
        int listen_time;
        vector<Song> liked_list;
        vector<Song> downloaded_list;
};

vector<Song> mutual_likes(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_1.liked_list.size(); i++){
        for(int j = 0; j < user_2.liked_list.size(); j++){
            if (user_1.liked_list[i].ID_song == user_2.liked_list[j].ID_song){
                list.push_back(user_1.liked_list[i]);
                break;
            }
        }
    }
    return list;
};

vector<Song> mutual_songs(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_1.history.size(); i++){
        for(int j = 0; j < user_2.history.size(); j++){
            if (user_1.history[i].ID_song == user_2.history[j].ID_song){
                list.push_back(user_1.history[i]);
                break;
            }
        }
    }
    return list;
};

vector<Song> unmutual_songs(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_2.history.size(); i++){
        bool match = false;
        for(int j = 0; j < user_1.history.size(); j++){
            if (user_2.history[i].ID_song == user_1.history[j].ID_song){
                match = true;
                break;
            }
        }
        if (!match) list.push_back(user_2.history[i]);
    }
    return list;
};

void User_relation(const User& user_1, const User& user_2){
    float similarity_score = 0;
    vector<Song> mutual_list = mutual_songs(user_1, user_2);
    vector<Song> unmutual_list = unmutual_songs(user_1,user_2);
    vector<Song> mutual_likes_list = mutual_likes(user_1, user_2);

};

    

