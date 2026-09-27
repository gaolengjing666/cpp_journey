#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 手写二分查找：在有序 vector 中查找 target
// 找到返回下标，找不到返回 -1
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        // 防止 (left + right) 溢出，自动截断小数部分
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;          // 找到
        } else if (arr[mid] < target) {
            left = mid + 1;      // 在右半区
        } else {
            right = mid - 1;     // 在左半区
        }
    }
    return -1;                   // 未找到
}

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // 确保有序（本题已有序，这里只是演示）
    sort(data.begin(), data.end());

    cout << "有序数组: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    // 测试存在的元素
    vector<int> tests = {1, 7, 19, 4, 20, 0};
    for (int t : tests) {
        int idx = binarySearch(data, t);
        if (idx != -1) {
            cout << "找到 " << t << "，下标为 " << idx << endl;
        } else {
            cout << "未找到 " << t << endl;
        }
    }

    return 0;
}