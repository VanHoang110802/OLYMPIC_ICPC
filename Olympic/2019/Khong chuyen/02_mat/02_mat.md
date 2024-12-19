## Tiếng Việt

Theo đề bài, ta có: C[𝑖,𝑗] = 𝑎[𝑖,1] × 𝑏[1,𝑗] + 𝑎[𝑖,2] × 𝑏[2,𝑗] +..+ 𝑎[𝑖,𝑛] × [𝑏𝑛,𝑗] 

Đầu tiên, nếu k = 1, tức là chỉ có một ma trận, ta sẽ lấy số hàng mod cho s luôn rồi lưu kết quả vào mảng tạm thời (ans). Lưu ý rằng khi nhập phần tử cho ma
trận thì phải luôn để phần tử là phần tử dương thì mới chia dư được cho s. Tại sao phải cộng thêm s mà không phải cộng số khác hay dùng abs() thì là do đặc
điểm của phép toán modulo. Điều này liên quan đến việc đảm bảo rằng giá trị của phần tử luôn nằm trong phạm vi hợp lệ của modulo s, vì:

- Lý do không dùng abs()
    - Hàm abs() trả về giá trị tuyệt đối của một số: abs(-5) = 5.
- Tuy nhiên, trong bối cảnh modulo, chúng ta không chỉ cần giá trị dương mà còn cần giá trị nằm trong phạm vi từ 0 đến s - 1.
  - Ví dụ:
    - Nếu s = 7, thì các số hợp lệ trong phép modulo là 0, 1, 2,..., 6.
    - Nếu a[i][j] = -3, dùng abs() sẽ cho kết quả 3, nhưng -3 mod 7 = 4 (kết quả khác nhau).

- Tại sao lại cộng thêm s?
- Trong phép toán modulo:
  - Nếu số x là số âm, khi tính x mod s, bạn cần "chuyển" số đó thành dương để nằm trong phạm vi [0, s - 1].
  - Ví dụ:
    - -3 mod 7: Thêm s nhiều lần cho đến khi số không âm: -3 + 7 = 4.
      - Kết quả: 4 (vì 4 mod 7 = 4).

- Quy trình cộng s đảm bảo rằng mọi số âm sẽ được điều chỉnh về dương mà không làm thay đổi giá trị modulo:
  - Nếu a[i][j] < 0: Thêm s cho đến khi a[i][j] >= 0.
  - Nếu a[i][j] >= 0, không cần cộng thêm.

-> Modulo s xác định các số hợp lệ trong phạm vi [0, s - 1]. 
-> Do đó, việc cộng một số khác s sẽ làm thay đổi kết quả modulo và gây sai lệch trong tính toán.

Với k tiếp theo, duyệt từng cột của ma trận, lấy từng phần tử trong mảng ans (tức là lấy từng hàng trong ma trận đầu) nhân với cột tương ứng của mảng a. Lưu ý rằng khi nhân các phần tử với nhau sẽ ra các số rất lớn, kể cả nếu có mod như bình thường cũng sẽ bị tràn số, vì vậy, ta cần viết một hàm mod nhân tối ưu hơn đó là nhân nhanh bằng cách chia nhỏ số một số cần nhân. Sau đó đem đi cộng dồn lại, cộng dồn nhớ mod thêm lần nữa đến tránh sai do tràn số.

Sau khi tính xong một tổng, cần thêm 1 mảng phụ để lưu các tổng đã tính đó lại. Sau khi tính xong xuôi hết các ma trận thì lấy mảng phụ đó gán cập nhật lại cho mảng ans. Cuối cùng in ra phần tử thứ hàng i cột j là xong.

## English



## Chinese (简体中文)

