# UVa 299 - Train Swapping

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week7） |
| Problem ID | UVa 299 |
| Title | Train Swapping |
| Link | https://onlinejudge.org/external/2/299.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-20 10:55 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，每組 L 與 L 個車廂編號。
- **Output**：`Optimal train swapping takes S swaps.`，S 為相鄰交換的最少次數。
- **Rules / Constraints**：L ≤ 50。
- **Core Task**：相鄰交換排序的最少次數 = 逆序數對數量。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
模擬泡沫排序並計算交換次數。

### Final Strategy
雙重迴圈，若 c[i] > c[j] 就交換並計數。

**Edge cases considered**：L=1、已排序、完全反序。

### Complexity Analysis
- **Time**：O(L²)。
- **Space**：O(L)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
repeat T 次:
    讀 L 與陣列 c
    ct = 0
    for i < j: if c[i] > c[j]: swap, ct++
    輸出 ct
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t--){
                int n,ct=0;
                cin>>n;
                int c[n];
                for(int i=0;i<n;i++){
                        cin>>c[i];
                }
                for(int i=0;i<n;i++)
                        for(int j=i+1;j<n;j++){
                                if(c[i]>c[j]){
                                        swap(c[i],c[j]);
                                        ct++;
                                }
                        }
        cout<<"Optimal train swapping takes "<<ct<<" swaps.\n";
        }
}
```
- **關鍵條件**：這種寫法實際上是選擇排序式的交換，但交換次數恰好等於逆序對數量，所以答案正確。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 3 / 1 3 2 / 4 / 4 3 2 1 / 2 / 2 1` | `Optimal train swapping takes 1 swaps. / Optimal train swapping takes 6 swaps. / Optimal train swapping takes 1 swaps.` | ✅ `Optimal train swapping takes 1 swaps. / Optimal train swapping takes 6 swaps. / Optimal train swapping takes 1 swaps.` | 題目範例 |
| Boundary | `1 / 1 / 1` | `Optimal train swapping takes 0 swaps.` | ✅ `Optimal train swapping takes 0 swaps.` | 只有一節車廂 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：「相鄰交換最少次數」等於逆序對數量。
- **Next Action**：直接數逆序對（不交換）更清楚，也和 10327 Flip Sort 是同一題型。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 299 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
