# UVa 11332 - Summing Digits

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week3） |
| Problem ID | UVa 11332 |
| Title | Summing Digits |
| Link | https://onlinejudge.org/external/113/11332.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-22 10:37 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行一個正整數 n，輸入 0 結束。
- **Output**：輸出 g(n)：把 n 的各位數相加，重複到只剩一位數為止。
- **Rules / Constraints**：n ≤ 2,000,000,000。
- **Core Task**：重複求位數和直到 < 10。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
用兩層迴圈：外層「還不是一位數就繼續」，內層用 %10、/10 把每一位加起來。

### Final Strategy
外層 `while(n>10)`、內層求位數和後令 n=tmp。

**Edge cases considered**：本來就是一位數、n 剛好是 10、相加後剛好得到 10（例如 19→10）。

### Complexity Analysis
- **Time**：O(log n)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 n 且 n > 0:
    while n 不是一位數:   # 應為 n >= 10
        n = n 的各位數和
    輸出 n
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。但實測發現隱藏 bug：外層條件寫成 `n>10`，所以 n=10 不會再算一次，會直接輸出 10。
- **會出錯的輸入**：`19`：19→10，條件 10>10 不成立就停下，輸出 `10`，正確答案是 `1`。輸入 `10` 也一樣。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    while(cin>>n && n>0){
        while(n>10){
            long long tmp=0;
            while(n>=1){
                tmp+=n%10;
                n/=10;
            }
            n=tmp;
        }
        cout<<n<<"\n";
    }
}
```
- **關鍵條件**：正確條件應為 `while(n>=10)`（或 `n>9`），「一位數」的定義是 n < 10。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `11 / 47 / 1234567892 / 0` | `2 / 2 / 2` | ✅ `2 / 2 / 2` | 範例型測資 |
| Edge | `7 / 0` | `7` | ✅ `7` | 本來就是一位數 |
| Boundary | `10 / 0` | `1` | ❌ `10` | n=10，迴圈條件邊界 |
| Edge | `19 / 0` | `1` | ❌ `10` | 第一次相加後得到 10 |

**注意**：表中 ❌ 的測資代表這份程式雖然在課堂 OJ 上 AC，但實測仍有錯誤（OJ 測資沒有涵蓋），見第 7 節。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | n>10 | 應改為 n>=10 |
| Edge Cases | n=10 與相加得 10 會錯 | 全部正確 |
| Output Handling | 相同 | 相同 |
| Complexity | O(log n) | O(log n) |
| Code Quality | — | — |

### Reflection
- **Root Cause**：迴圈邊界差一（off-by-one），課堂 OJ 測資剛好沒測到。
- **Lesson Learned**：AC 不代表完全正確，要自己測邊界值（10、19、99…）。
- **Next Action**：把 `while(n>10)` 改成 `while(n>=10)`，並養成邊界值自測的習慣。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11332 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
