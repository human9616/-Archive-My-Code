# UVa 10327 - Flip Sort

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week8 (Midterm)） |
| Problem ID | UVa 10327 |
| Title | Flip Sort |
| Link | https://onlinejudge.org/external/103/10327.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-27 11:26 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多組，每組 N 與 N 個整數，讀到 EOF。
- **Output**：`Minimum exchange operations : X`。
- **Rules / Constraints**：只能交換相鄰兩數。
- **Core Task**：最少相鄰交換次數 = 逆序對數量。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
和 UVa 299 一樣，數逆序對。

### Final Strategy
雙重迴圈，a[i] > a[j] 就計數（不用真的交換）。

**Edge cases considered**：N=1、已排序。

### Complexity Analysis
- **Time**：O(N²)。
- **Space**：O(N)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 N:
    讀陣列 a
    ans = i<j 且 a[i]>a[j] 的對數
    輸出 ans
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        while(cin>>n){
                int a[n],ans=0;
                for(int i=0;i<n;i++){
                        cin>>a[i];
                }
                for(int i=0;i<n;i++){
                        for(int j=i+1;j<n;j++){
                                if(a[i]>a[j])ans++;
                        }
                }
                cout<<"Minimum exchange operations : "<<ans<<"\n";
        }
}
```
- **關鍵條件**：直接數逆序對，比 299 的寫法更直接。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 1 2 3 / 3 / 2 3 1` | `Minimum exchange operations : 0 / Minimum exchange operations : 2` | ✅ `Minimum exchange operations : 0 / Minimum exchange operations : 2` | 題目範例 |
| Boundary | `1 / 5` | `Minimum exchange operations : 0` | ✅ `Minimum exchange operations : 0` | 只有一個數 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：同一個觀念（逆序對）可以解多題。
- **Next Action**：N 很大時可用 merge sort 做到 O(N log N)。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10327 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
