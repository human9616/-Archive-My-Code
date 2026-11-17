# UVa 11185 - Ternary

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week6） |
| Problem ID | UVa 11185 |
| Title | Ternary |
| Link | https://onlinejudge.org/external/111/11185.pdf |
| Language / Version | C++ |
| Submission Result | 課堂 OJ 上 9 次皆 WA；修正版 `v10_fix.cpp` 本地測試通過，尚未提交 OJ |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Fixed) Code | [src/v10_fix.cpp](src/v10_fix.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-13 10:28 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-10-13 10:32 | WA | [src/v2_WA.cpp](src/v2_WA.cpp) |
| 3 | 2026-10-13 10:42 | WA | [src/v3_WA.cpp](src/v3_WA.cpp) |
| 4 | 2026-10-13 10:48 | WA | [src/v4_WA.cpp](src/v4_WA.cpp) |
| 5 | 2026-10-13 11:33 | WA | [src/v5_WA.cpp](src/v5_WA.cpp) |
| 6 | 2026-10-13 11:38 | WA | [src/v6_WA.cpp](src/v6_WA.cpp) |
| 7 | 2026-10-13 11:47 | WA | [src/v7_WA.cpp](src/v7_WA.cpp) |
| 8 | 2026-10-13 11:48 | WA | [src/v8_WA.cpp](src/v8_WA.cpp) |
| 9 | 2026-10-13 11:48 | WA | [src/v9_WA.cpp](src/v9_WA.cpp) |
| 10 | 2026-11-17 | 修正版（未提交 OJ） | [src/v10_fix.cpp](src/v10_fix.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行一個非負整數 N，遇到負數結束。
- **Output**：輸出 N 的三進位表示。
- **Rules / Constraints**：N 為十進位非負整數。
- **Core Task**：十進位轉三進位。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
不斷 %3 取餘數、/3，最後把餘數反過來。第一版用了 `s.reserve()`（保留容量）而不是反轉字串。

### Final Strategy
以 `n<0` 結束；n==0 時直接輸出 0；其餘不斷 %3 取餘數存進字串，再由後往前輸出並換行（`src/v10_fix.cpp`）。

**Edge cases considered**：N=0（應輸出 0）、以任意負數結束、大數。

### Complexity Analysis
- **Time**：O(log₃N)。
- **Space**：O(log₃N)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 n 且 n >= 0:
    if n == 0: 輸出 "0"，換行，continue
    s = ""
    while n > 0: s += n%3, n /= 3
    反向輸出 s，換行
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        while(cin>>n && n!=-1){
                string s;
                while(n>0){
                        s+=to_string(n%3);
                        n/=3;
                }
                s.reserve();
                cout<<s<<"\n";
        }
}
```
- **錯誤原因**：v1 用 `s.reserve()` 沒有反轉，數字順序相反；v2～v9 修正了順序與結束條件，但**輸入 0 時 while(n>0) 一次都不執行，輸出空行**；v4、v8、v9 嘗試改換行位置，反而造成輸出格式錯誤。
- **會出錯的輸入**：`0`：正確輸出 `0`，v2～v9 都輸出空行（v6 實測輸出 `\n`）。

### Correct Code（`src/v10_fix.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        long long n;
        while(cin>>n){
                if(n<0)break;
                if(n==0){
                        cout<<"0\n";
                        continue;
                }
                string s="";
                while(n>0){
                        s+=to_string(n%3);
                        n/=3;
                }
                for(int i=s.size()-1;i>=0;i--)
                cout<<s[i];
                cout<<"\n";
        }
}
```
- **關鍵條件**：在轉換前加上 `if(n==0)` 特判輸出 0，其他部分與 v6 相同。本地測試全部通過，尚未提交到課堂 OJ。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v10_fix.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `5 / 100 / -1` | `12 / 10201` | ✅ `12 / 10201` | 一般轉換 |
| Edge | `0 / -1` | `0` | ✅ `0` | N=0，應輸出 0 |
| Boundary | `1000000000 / -1` | `2120200200021010001` | ✅ `2120200200021010001` | 大數 |
| Edge | `3 / -5` | `10` | ✅ `10` | 以任意負數結束 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `5 / 100 / -1`，預期 `12 / 10201`，`v1_WA.cpp` 輸出 `21 / 10201`。
- Edge：輸入 `0 / -1`，預期 `0`，`v1_WA.cpp` 輸出 `（空行）`。
- Boundary：輸入 `1000000000 / -1`，預期 `2120200200021010001`，`v1_WA.cpp` 輸出 `1000101200020020212`。
- Edge：輸入 `3 / -5`，預期 `10`，`v1_WA.cpp` 輸出 `01 / （空行）`。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | reserve 誤當 reverse | 正確反向輸出 |
| Edge Cases | N=0 輸出空行 | 特判 N=0 輸出 0 |
| Output Handling | — | 每行換行 |
| Complexity | O(log N) | O(log N) |
| Code Quality | — | — |

### Reflection
- **Root Cause**：進位轉換沒考慮 N=0；連續 WA 時一直改換行格式，沒有回頭找邊界輸入。
- **Lesson Learned**：WA 很多次時，先列出邊界輸入（0、最大值、結束條件）逐一測，而不是猜格式。
- **Next Action**：把 `v10_fix.cpp` 提交到 OJ 確認 AC；之後做進位轉換題都先測 0。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11185 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
