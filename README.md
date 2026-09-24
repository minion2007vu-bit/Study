Nop bai tap mon CTDL&GT co Hue (slide 26)
                                                                      Giải thuật:
- Đầu vào (Input):

Dữ liệu của người dùng cần gợi ý "user_1" và một người dùng khác "user_2", bao gồm các danh sách: bài hát đã nghe, bài hát đã thích, bài hát đã tải xuống
Một giá trị ngưỡng tương đồng "thresh_hold"

- Đầu ra (Output):

Danh sách (tối đa 10) bài hát gợi ý cho "user_1", được sắp xếp theo số lượng yêu thích giảm dần

Các bước của giải thuật:

- Bước 1: Tính toán độ tương đồng "Similarity Score" giữa hai người dùng:

+) Duyệt qua danh sách bài hát của "user_1" và đối chiếu với Hash Map của "user_2" để tìm các tập hợp giao nhau:
+) Tập hợp các bài hát cả hai cùng tải "mutual_downloaded"
+) Tập hợp các bài hát cả hai cùng thích "mutual_likes"
+) Tập hợp các bài hát cả hai cùng nghe "mutual_songs"
+) Tính tổng điểm tương đồng "similarity_score" theo công thức:

  Điểm = (Số bài cùng tải * 5) + (Số bài cùng thích * 3) + (Số bài cùng nghe * 0.2)

- Bước 2: Kiểm tra điều kiện ngưỡng:

+) So sánh "similarity_score" với "thresh_hold"
+) Nếu "similarity_score < thresh_hold": Hai người dùng không đủ độ tương đồng, thuật toán kết thúc và không đưa ra gợi ý
+) Nếu "similarity_score >= thresh_hold": Tiếp tục Bước 3

- Bước 3: Trích xuất danh sách bài hát tiềm năng (Lọc bài hát gợi ý):

+) Tạo một danh sách rỗng để chứa bài hát gợi ý
+) Duyệt qua toàn bộ danh sách các bài hát mà "user_2" đã nghe (lịch sử nghe):
  Điều kiện 1: Kiểm tra xem bài hát này đã tồn tại trong lịch sử nghe của "user_1" hay chưa. Nếu "user_1" chưa từng nghe, đưa bài hát vào danh sách trung gian "unmutual_songs"

+) Duyệt qua danh sách trung gian vừa tạo:
  Điều kiện 2: Kiểm tra xem "user_2" có "Thích" bài hát này không (nằm trong "liked_map" của "user_2")
+) Nếu thỏa mãn cả 2 điều kiện (User 1 chưa nghe VÀ User 2 đã thích), thêm bài hát vào danh sách gợi ý chính thức

- Bước 4: Xếp hạng và xuất kết quả:

+) Sắp xếp danh sách bài hát gợi ý chính thức theo thứ tự giảm dần dựa trên thuộc tính "likes_count" (tổng lượt thích của bài hát)
+) Cắt lấy tối đa 10 bài hát đứng đầu danh sách
+) Trích xuất và in tên (song_name) của các bài hát này ra màn hình. Kết thúc thuật toán
