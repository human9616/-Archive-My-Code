# UVa 10055 - Hashmat the Brave Warrior

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week1） |
| Problem ID | UVa 10055 |
| Title | Hashmat the Brave Warrior |
| Link | https://onlinejudge.org/external/100/10055.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 4 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v4_AC.cpp](src/v4_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-08 11:03 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-08 11:06 | WA | [src/v2_WA.cpp](src/v2_WA.cpp) |
| 3 | 2026-09-08 11:09 | WA | [src/v3_WA.cpp](src/v3_WA.cpp) |
| 4 | 2026-09-08 11:13 | AC | [src/v4_AC.cpp](src/v4_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多組測資直到 EOF，每組兩個整數，分別是 Hashmat 與敵方的兵力。
- **Output**：每組輸出兩數差的絕對值，一行一個。
- **Rules / Constraints**：數值可到 2^32，不保證哪個數比較大。
- **Core Task**：讀到檔案結尾為止，對每組算 |a-b|。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
一開始以為只有一組輸入，所以只讀一次 a、b 就輸出。也有想到大小順序不固定，所以用 abs 或 if 比較。

### Final Strategy
用 `while(cin>>a>>b)` 一直讀到 EOF，每組輸出較大減較小。

**Edge cases considered**：多組輸入、a<b 與 a>b 都要處理、兩數相同、極大值。

### Complexity Analysis
- **Time**：O(T)，T 為測資組數；每組 O(1)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀得到 a, b:
    if a > b: 輸出 a - b
    else:     輸出 b - a
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<abs(a-b)<<"\n";
}
```
- **錯誤原因**：v1～v3 都只讀一組 `cin>>a>>b` 就結束，忽略「多組測資直到 EOF」。v2、v3 只是把 abs 改成 if，沒有改到真正的錯誤。
- **會出錯的輸入**：`10 12` / `10 14` / `100 200`：v1 只輸出 `2`，後面兩組沒有處理。

### Correct Code（`src/v4_AC.cpp`）
```cpp
#include<iostream>
using namespace std;
int main(){
    int a,b;
    while (cin>>a>>b) {
     if(a>b)cout<<a-b<<"\n";
    else cout<<b-a<<"\n";   
    }
}
```
- **關鍵條件**：把讀取放進 `while(cin>>a>>b)`，cin 讀失敗（EOF）時迴圈自然結束。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v4_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `10 12 / 10 14 / 100 200` | `2 / 4 / 100` | ✅ `2 / 4 / 100` | 多組測資讀到 EOF |
| Boundary | `0 0` | `0` | ✅ `0` | 兩數皆為 0 |
| Edge | `20 5` | `15` | ✅ `15` | 第一個數比較大 |
| Stress | `4294967295 0` | `4294967295` | ❌ （無輸出） | 接近 2^32 的大數（int 會溢位） |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `10 12 / 10 14 / 100 200`，預期 `2 / 4 / 100`，`v1_WA.cpp` 輸出 `2`。
- Stress：輸入 `4294967295 0`，預期 `4294967295`，`v1_WA.cpp` 輸出 `2147483647`。

**注意**：表中 ❌ 的測資代表這份程式雖然在課堂 OJ 上 AC，但實測仍有錯誤（OJ 測資沒有涵蓋），見第 7 節。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 只處理一組 | 迴圈處理到 EOF |
| Edge Cases | 忽略多組輸入 | 處理多組輸入 |
| Output Handling | 相同 | 相同 |
| Complexity | O(1) | O(T) |
| Code Quality | 用 bits/stdc++ + abs，最簡潔 | iostream + if/else |

### Reflection
- **Root Cause**：沒讀清楚輸入格式，以為只有一組測資。
- **Lesson Learned**：UVa 題目大多是多組輸入，先確認結束條件（EOF、0 0、給定組數）。
- **Next Action**：寫題前先標出「輸入怎麼結束」。另外題目數值到 2^32，課堂 OJ 用 int 雖然 AC，但上 UVa 原站應改用 long long（Stress 測資中 int 版本讀不進 4294967295）。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10055 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
