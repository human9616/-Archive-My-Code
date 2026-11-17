# UVa 10170 - The Hotel with Infinite Rooms

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week3） |
| Problem ID | UVa 10170 |
| Title | The Hotel with Infinite Rooms |
| Link | https://onlinejudge.org/external/101/10170.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 2 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v2_AC.cpp](src/v2_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-22 11:10 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-22 11:13 | AC | [src/v2_AC.cpp](src/v2_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行 S（第一團人數）與 D（第幾天）。
- **Output**：第 D 天住在飯店的團體人數。
- **Rules / Constraints**：每團住的天數等於人數，下一團多一人；D 可達 10^15。
- **Core Task**：找最小的 k ≥ S，使 S+(S+1)+…+k ≥ D。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
從 S 開始累加天數，直到總天數 ≥ D。

### Final Strategy
同樣的模擬，但 S、D、total 改用 long long。

**Edge cases considered**：D=1、D 超過 int 範圍。

### Complexity Analysis
- **Time**：O(√D)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 S, D:
    total = S
    while total < D: S++, total += S
    輸出 S
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,d;
    while(cin>>s>>d){
        int total=s;
        while(total<d){
            s++;
            total+=s;
        }
        cout<<s<<"\n";
    }
}
```
- **錯誤原因**：v1 用 int，D 最大到 10^15 會溢位，讀入就失敗。
- **會出錯的輸入**：`10000 1000000000000000`：v1 用 int 讀不到正確的 D（輸出錯誤或沒有輸出）。

### Correct Code（`src/v2_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long  s,d;
    while(cin>>s>>d){
        long long  total=s;
        while(total<d){
            s++;
            total+=s;
        }
        cout<<s<<"\n";
    }
}
```
- **關鍵條件**：改用 long long，累加的 total 也不會溢位。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `1 6 / 3 10 / 3 14` | `3 / 5 / 6` | ✅ `3 / 5 / 6` | 題目範例 |
| Boundary | `10 1` | `10` | ✅ `10` | 第一天 |
| Stress | `10000 1000000000000000` | `44721361` | ✅ `44721361` | D 超過 int 範圍 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Stress：輸入 `10000 1000000000000000`，預期 `44721361`，`v1_WA.cpp` 輸出 （無輸出）。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 相同 | 相同 |
| Edge Cases | 大數溢位 | long long 正確 |
| Output Handling | 相同 | 相同 |
| Complexity | O(√D) | O(√D) |
| Code Quality | — | — |

### Reflection
- **Root Cause**：沒注意 D 的範圍超過 int。
- **Lesson Learned**：先看資料範圍再決定型別。
- **Next Action**：也可以用等差級數公式加二分搜尋做到 O(log D)。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10170 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
