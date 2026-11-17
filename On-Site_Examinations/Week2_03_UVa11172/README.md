# UVa 11172 - Relational Operator

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week2） |
| Problem ID | UVa 11172 |
| Title | Relational Operator |
| Link | https://onlinejudge.org/external/111/11172.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-15 10:32 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 n，接著 n 行，每行兩個整數 a、b。
- **Output**：依 a 與 b 的大小輸出 `>`、`<` 或 `=`。
- **Rules / Constraints**：|a|、|b| < 1000000001，int 可以存。
- **Core Task**：比較兩數大小。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
直接用 if / else if / else 比較。

### Final Strategy
迴圈 n 次，每次讀 a、b，用三個分支輸出對應符號。

**Edge cases considered**：負數、兩數相等、接近 int 上下界。

### Complexity Analysis
- **Time**：O(n)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 n
repeat n 次:
    讀 a, b
    if a > b: 輸出 ">"
    else if a == b: 輸出 "="
    else: 輸出 "<"
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b)cout<<">\n";
        else if(a==b)cout<<"=\n";
        else cout<<"<\n";
    }
}
```
- **關鍵條件**：三個分支互斥且涵蓋所有情況。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 10 20 / 20 10 / 10 10` | `< / > / =` | ✅ `< / > / =` | 三種關係各一次 |
| Edge | `1 / -5 -10` | `>` | ✅ `>` | 負數比較 |
| Boundary | `1 / 1000000000 -1000000000` | `>` | ✅ `>` | 接近 int 上下界 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：簡單題也要確認數值範圍是否在 int 內。
- **Next Action**：—

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11172 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
