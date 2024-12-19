## Tiếng Việt
Cá nhân mình thấy tuy chỉ mới là bài toán mở đầu và là bài toán dễ, nhưng nó đã làm khó những bạn nào (như mình) không kỹ càng trong việc sử dụng các giới hạn dữ liệu cũng như về việc xử lý số thực. Do đó, nếu trong phòng thi ta không biết dùng trick này, đây có thể sẽ là 1 bài gây cảm giác ức chế và có thể làm xuống tinh thần của người làm. 

Ta chỉ cần biết một chút kiến thức về diện tích tam giác cũng như định lý Pytago là xong. 

Tuy nhiên, ở bài này, nếu bạn xử lý và xuất ra đáp án bằng việc xử lý trên số thực, rất có thể bạn sẽ không AC trọn vẹn bộ test này. 

Công thức của bài toán sẽ như sau: d = sqrt(u * u + v * v), và đáp án là d * d / 4.

Tuy nhiên, ta có thể thấy, ta lấy d = sqrt(u * u + v * v), thì d sẽ là số thực, sau đó ta lại bình phương, thì việc sai số sẽ trở nên tệ gấp đôi. Nhất là khi u và v có giới hạn tối đa 2 tỷ.

Trong mọi bài toán, nếu ta xử lý bằng số thực, bao giờ cũng không tốt bằng xử lý dựa trên số nguyên, vì số nguyên có sự chính xác hoàn toàn 100%.

Vì đáp án ta cần là d * d và d = căn (u * u + v * v), do đó, ta sẽ có được d * d = u * u + v * v (d * d là một số nguyên).

Vậy còn chuyện xuất ra số thực dưới dạng 2 chữ số thập phân thì sao, mình đã dùng 1 trick đó là xuất ra d * d / 4 và đặt 1 số dư là d * d % 4.

Sau đó sẽ kiểm tra số dư, nếu là 0 thì xuất .00; là 1 thì xuất .25; là 2 thì xuất .50 và là 3 thì xuất .75.


## English
Personally, I find that although this is just an introductory problem and an easy one at that, it can be challenging for those who (like me) are not meticulous in handling data constraints and dealing with floating-point numbers. Therefore, if we don’t know how to use this trick during the exam, this problem could become frustrating and potentially dampen the solver’s morale.

We only need a bit of knowledge about triangle area and the Pythagorean theorem, and that's it!

However, in this problem, if you handle and output the result using floating-point operations, it’s very likely that you won’t achieve a full AC on the test set.

The formula for the problem is as follows: d = sqrt(u * u + v * v), and the answer is d * d / 4.

However, we can see that by taking d = sqrt(u * u + v * v), d becomes a floating-point number. Squaring it again will double the precision error, especially when u and v have a maximum limit of 2 billion.

In any problem, handling with floating-point numbers is never as good as working with integers, because integers provide complete and absolute 100% accuracy.

Since the answer we need is d * d and d = sqr(u * u + v * v), we can derive that d * d = u * u + v * v (d * d is an integer).

So what about outputting a floating-point number with two decimal places? I used a trick, which is to output d * d / 4 and set the remainder as d * d % 4.

Then, check the remainder. If it's 0, output .00; if it's 1, output .25; if it's 2, output .50; and if it's 3, output .75.

## Chinese (简体中文)

我个人认为，虽然这只是一个开头的题目，而且它是一个简单的题目，但它却让那些（像我一样）在使用数据限制和处理浮点数时不够细心的人感到困难。因此，如果在考试中我们不知道使用这个技巧，这可能会成为一个让人感到不舒服的题目，并且可能会打击解题者的士气。

我们只需要了解一点关于三角形面积的知识以及毕达哥拉斯定理就可以了。

然而，在这个题目中，如果你通过浮点数处理来计算并输出答案，很可能你无法完全通过所有测试用例。

这道题的公式如下：d = sqrt(u * u + v * v),，答案是 d * d / 4。

然而，我们可以看到，如果我们取 d = sqrt(u * u + v * v)，那么 d 将是一个浮点数，然后再对其平方，误差将会加倍。特别是当 u 和 v 的最大值为 20 亿时。

在所有的题目中，如果我们使用浮点数处理，通常都不如使用整数处理好，因为整数可以保证 100% 的精确度。

因为我们需要的答案是 d * d 和 d = sqr(u * u + v * v)，因此我们可以得到 d * d = u * u + v * v（d * d 是一个整数）。

那么输出一个保留两位小数的浮点数该怎么办呢？我使用了一个技巧，就是输出 d * d / 4，并设置一个余数为 d * d % 4

然后检查余数，如果是 0 就输出 .00；如果是 1 就输出 .25；如果是 2 就输出 .50；如果是 3 就输出 .75。

