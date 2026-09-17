//Xây dựng cấu trúc dữ liệu phù hợp với các yêu cầu bài tập ở Slide 26,27,28//

//Slide 26//

#include <iostream>
#include <vector>
#include <unordered_map>

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
        int listen_time;
        
        vector<Song> liked_list;
        unordered_map<string, Song> liked_map;

        vector<Song> downloaded_list;
        unordered_map<string, Song> downloaded_map;

        vector<Song> history_list;
        unordered_map<string, Song> history_map;

        void listen_to_song(const Song& song){
            history_map.insert({song.ID_song, song});
        }

};

vector<Song> mutual_likes(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_1.liked_list.size(); i++){
        if(user_2.liked_map.find(user_1.liked_list[i].ID_song) != user_2.liked_map.end())
            list.push_back(user_1.liked_list[i]);
    }
    return list;
};

vector<Song> mutual_downloaded(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_1.downloaded_list.size(); i++){
        if(user_2.downloaded_map.find(user_1.downloaded_list[i].ID_song) != user_2.downloaded_map.end())
            list.push_back(user_1.downloaded_list[i]);
    }
    return list;
};

vector<Song> mutual_songs(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_1.history_list.size(); i++){
        if(user_2.history_map.find(user_1.history_list[i].ID_song) != user_2.history_map.end())
            list.push_back(user_1.history_list[i]);
    }
    return list;
};

vector<Song> unmutual_songs(const User& user_1, const User& user_2){
    vector<Song> list;
    for(int i = 0; i < user_2.history_list.size(); i++){
        if(user_1.history_map.find(user_2.history_list[i].ID_song) == user_1.history_map.end())
            list.push_back(user_2.history_list[i]);
    }
    return list;
};

void User_relation(const User& user_1, const User& user_2){
    float similarity_score = 0;
    vector<Song> mutual_list = mutual_songs(user_1, user_2);
    vector<Song> unmutual_list = unmutual_songs(user_1,user_2);
    vector<Song> mutual_likes_list = mutual_likes(user_1, user_2);
    vector<Song> mutual_downloaded_list = mutual_downloaded(user_1, user_2);

    similarity_score = sizeof(mutual_downloaded_list)*5 + sizeof(mutual_likes_list)*3;

};

    

