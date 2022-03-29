# leetcode_c++
STL 是“Standard Template Library”

1. 1_two_num (hash_table `include<unsordered_map>`)
1. 2_add_two_numbers (single_linked_node)
1. 3_longest_substring_without_repeating_characters(hash_table sliding_windows two_points)

复杂度
log 2 n: 运算次数k 使得2^k=n,n是某一个数量限制


## https://github.com/changgyhub/leetcode_101
教程来了
## 贪心算法
- 455_assign_cookies
vector[i]
`#include<algorithm>` sort()  https://www.cnblogs.com/stones-dream/p/10183210.html
`#include<vector>`
`#include<functional>`
- 135_candy
max()
`#include<numeric>`accumulate https://blog.csdn.net/u011499425/article/details/52756242
- 435_non_overlapping_intervals
C++11的一大亮点就是引入了Lambda表达式
https://www.cnblogs.com/DswCnblog/p/5629165.html
for (int it : myvec)
        cout << it << ' ';
#### 练习
- 605_can_place_flower
前2可以直接判定，其他情况贪心分为三部分：前2，中间，后2

Runtime: 32 ms, faster than 79.84% of C++ online submissions for Can Place Flowers.
- 452_minimum_number_of_arrows_to_burst_balloons
和435类似，贪心区间结尾值，只要开始值小于结尾值，就只用射一箭，用一个vector表示需要射的箭数（先置1）

Runtime: 1228 ms, faster than 18.64% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
- 763_partition_labels
建三个哈希表，存第一次出现位置，最后一次，出现次数

Runtime: 20 ms, faster than 8.52% of C++ online submissions for Partition Labels.