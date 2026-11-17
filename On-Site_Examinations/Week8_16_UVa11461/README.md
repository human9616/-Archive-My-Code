# UVa 11461 - Square Numbers

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week8 (Midterm)） |
| Problem ID | UVa 11461 |
| Title | Square Numbers |
| Link | https://onlinejudge.org/external/114/11461.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 4 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v4_AC.cpp](src/v4_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-27 10:32 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-10-27 10:33 | WA | [src/v2_WA.cpp](src/v2_WA.cpp) |
| 3 | 2026-10-27 10:39 | WA | [src/v3_WA.cpp](src/v3_WA.cpp) |
| 4 | 2026-10-27 10:50 | AC | [src/v4_AC.cpp](src/v4_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行 a、b，`0 0` 結束。
- **Output**：區間 [a, b] 內完全平方數的個數。
- **Rules / Constraints**：0 < a ≤ b ≤ 100000。
- **Core Task**：數有幾個 i 使 a ≤ i² ≤ b（與 Week5 同一題）。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
想用公式 sqrt(b) - sqrt(a) + 1 一步算完。

### Final Strategy
i 從 (int)sqrt(a) 跑到 sqrt(b)，若 i < sqrt(a)（i² < a）就跳過，其餘計數。

**Edge cases considered**：a 不是平方數、a=b 為平方數、a=b 不是平方數。

### Complexity Analysis
- **Time**：O(√b)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 a, b 且不是 0 0:
    ans = 0
    for i = floor(sqrt(a)); i <= sqrt(b); i++:
        if i < sqrt(a): continue   # i*i < a
        ans++
    輸出 ans
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                a=sqrt(a);
                b=sqrt(b);
                cout<<b-a+1;
        }
}
```
- **錯誤原因**：v1、v2 用 `sqrt(b)-sqrt(a)+1`，但 a 不是平方數時 floor(sqrt(a)) 的平方小於 a，會多算一個（v1 還少了換行）；v3 只特判 a==b，沒解決一般情況。
- **會出錯的輸入**：`5 10`：正確答案 1，v1 輸出 2（把 4 也算進去）。

### Correct Code（`src/v4_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                int ans=0;
                for(int i=sqrt(a);i<=sqrt(b);i++){
                        if(i<sqrt(a))continue;
                        ans++;
                }
                cout<<ans<<"\n";
        }
}
```
- **關鍵條件**：下界用 ceil(sqrt(a)) 的概念：從 floor(sqrt(a)) 開始，但跳過平方小於 a 的那一個。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v4_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `1 4 / 1 10 / 0 0` | `2 / 3` | ✅ `2 / 3` | 從 1 開始的區間 |
| Edge | `5 10 / 0 0` | `1` | ✅ `1` | a 不是平方數 |
| Boundary | `4 4 / 0 0` | `1` | ✅ `1` | a=b 且為平方數 |
| Edge | `5 5 / 0 0` | `0` | ✅ `0` | a=b 但不是平方數 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `1 4 / 1 10 / 0 0`，預期 `2 / 3`，`v1_WA.cpp` 輸出 `23` （缺少換行）。
- Edge：輸入 `5 10 / 0 0`，預期 `1`，`v1_WA.cpp` 輸出 `2` （缺少換行）。
- Boundary：輸入 `4 4 / 0 0`，預期 `1`，`v1_WA.cpp` 輸出 `1` （缺少換行）。
- Edge：輸入 `5 5 / 0 0`，預期 `0`，`v1_WA.cpp` 輸出 `1` （缺少換行）。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | floor(√b)-floor(√a)+1 | 枚舉並跳過 i² < a |
| Edge Cases | a 非平方數多算 1 | 正確 |
| Output Handling | v1 缺換行 | 每行換行 |
| Complexity | O(1) | O(√b) |
| Code Quality | 公式簡潔但錯 | 正確但混用 int 與 double 比較 |

### Reflection
- **Root Cause**：Week5 就錯過的同一個邊界（sqrt 取整），期中考再犯一次。
- **Lesson Learned**：同一題錯兩次，代表觀念沒弄懂：下界應該是 ceil(√a)，不是 floor(√a)。
- **Next Action**：正確公式為 `floor(sqrt(b)) - ceil(sqrt(a)) + 1`；複習時把錯過的題目重寫一次。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11461 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
