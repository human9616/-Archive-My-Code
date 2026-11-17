# UVa 11727 - Cost Cutting

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week2） |
| Problem ID | UVa 11727 |
| Title | Cost Cutting |
| Link | https://onlinejudge.org/external/117/11727.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 2 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v2_AC.cpp](src/v2_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-15 10:40 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-15 10:44 | AC | [src/v2_AC.cpp](src/v2_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，每組三個薪水。
- **Output**：`Case i: x`，x 為中間值。
- **Rules / Constraints**：三個數字不保證互不相同。
- **Core Task**：求三個數的中位數。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
用 if 判斷誰在中間；第一版只考慮了兩種排列。

### Final Strategy
v2 列出更多 if 條件；但最簡單可靠的方法是排序後取中間。

**Edge cases considered**：中位數在各個位置、有相同的值。

### Complexity Analysis
- **Time**：O(T)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
for i = 1..T:
    讀 a, b, c，排序
    輸出 "Case i: " + 中間那個
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<iostream>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        cout<<"Case "<<i+1<<": ";
        if(a>b && c>a)cout<<a<<"\n";
        else if(b>a && c>b)cout<<b<<"\n";
        else cout<<c<<"\n";
    }
}
```
- **錯誤原因**：v1 只判斷了 a<... 與 b<... 兩種排列，其他排列都落到 else 輸出 c。
- **會出錯的輸入**：`2 3 1`：正確答案 2，v1 輸出 1。

### Correct Code（`src/v2_AC.cpp`）
```cpp
#include<iostream>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        cout<<"Case "<<i+1<<": ";
        if(a>b && c>a)cout<<a<<"\n";
        else if(b>a && c>b)cout<<b<<"\n";
        else if(b>c && a>b)cout<<b<<"\n";
        else if(a>c && b>a)cout<<a<<"\n";
        else cout<<c<<"\n";
    }
}
```
- **關鍵條件**：v2 補上 b>c 且 a>b、a>c 且 b>a 兩種情況而 AC。但實測發現仍有隱藏 bug：有相同值時嚴格不等式都不成立，`5 5 1` 會輸出 1（正確 5）。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 1000 2000 3000 / 3000 2500 1500 / 1500 1200 1800` | `Case 1: 2000 / Case 2: 2500 / Case 3: 1500` | ✅ `Case 1: 2000 / Case 2: 2500 / Case 3: 1500` | 題目範例 |
| Edge | `2 / 3 1 2 / 2 3 1` | `Case 1: 2 / Case 2: 2` | ✅ `Case 1: 2 / Case 2: 2` | 中位數在不同位置 |
| Boundary | `1 / 5 5 1` | `Case 1: 5` | ❌ `Case 1: 1` | 有相同值 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `3 / 1000 2000 3000 / 3000 2500 1500 / 1500 1200 1800`，預期 `Case 1: 2000 / Case 2: 2500 / Case 3: 1500`，`v1_WA.cpp` 輸出 `Case 1: 2000 / Case 2: 1500 / Case 3: 1500`。
- Edge：輸入 `2 / 3 1 2 / 2 3 1`，預期 `Case 1: 2 / Case 2: 2`，`v1_WA.cpp` 輸出 `Case 1: 2 / Case 2: 1`。
- Boundary：輸入 `1 / 5 5 1`，預期 `Case 1: 5`，`v1_WA.cpp` 輸出 `Case 1: 1`。

**注意**：表中 ❌ 的測資代表這份程式雖然在課堂 OJ 上 AC，但實測仍有錯誤（OJ 測資沒有涵蓋），見第 7 節。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 只處理 2 種排列 | 處理 4 種排列 + else |
| Edge Cases | 多數排列錯誤 | 相同值仍會錯 |
| Output Handling | 相同 | 相同 |
| Complexity | O(1) | O(1) |
| Code Quality | — | 條件多，容易漏 |

### Reflection
- **Root Cause**：用 if 窮舉排列容易漏，嚴格不等式也沒考慮相等。
- **Lesson Learned**：三個數求中位數直接排序最安全。
- **Next Action**：改寫成 `sort` 後取 `x[1]`，可同時解決相同值的問題。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11727 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
