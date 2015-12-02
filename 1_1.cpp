//
// Created by Moch Xiao on 12/2/15.
//

#include "1_1.h"
#include <iostream>

/// 如果字符集是ASCII字符
bool is_unique(string str) {
    bool a[256];
    // 初始化一个数组，全部置假
    memset(a, 0, sizeof(a));
    for (int i = 0; i < str.length(); i++) {
        // 挨个取出字符串中的字符，用其ASCII值做下标找数组中对应的元素
        // 如果为假，则说明之前没出现过，值真，继续对下一个字符运算
        // 如果为真，则说明之前出现过，直接返回假
        int ch = (int)str[i];
        if (a[ch]) {
            return false;
        }
        a[ch] = true;
    }

    return true;
}

/// 使用位运算
bool is_unique_2(string str) {
#define ARRAY_LENGHT 8
    int arr[ARRAY_LENGHT];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < str.length(); i++) {
        int ch = (int)str[i];
        int index = ch / 32;
        int shift = ch % 32;
        if (arr[index] & (1 << shift)) {
            return false;
        }
        arr[index] |= (1 << shift);
    }

    return true;
}

void test_1_1() {
    string s1 = "This is a test.";
    string s2 = "abcd";
    cout << "\"" << s1 << "\"" << " is_unique: " << (is_unique(s1) ? "ture" : "false") << endl;
    cout << "\"" << s2 << "\"" << " is_unique: " << (is_unique(s2) ? "ture" : "false") << endl;
    cout << "\"" << s1 << "\"" << " is_unique_2: " << (is_unique_2(s1) ? "ture" : "false") << endl;
    cout << "\"" << s2 << "\"" << " is_unique_2: " << (is_unique_2(s2) ? "ture" : "false") << endl;
}