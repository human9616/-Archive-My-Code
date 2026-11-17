# UVa 11559 - Event Planning

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week8 (Midterm)） |
| Problem ID | UVa 11559 |
| Title | Event Planning |
| Link | https://onlinejudge.org/external/115/11559.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-27 11:15 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多組，每組 N（人數）、B（預算）、H（飯店數）、W（週數），接著每間飯店的單價與各週空床數。
- **Output**：可行的最低總花費，沒有就輸出 stay home。
- **Rules / Constraints**：某週空床數 ≥ N 且 N×單價 ≤ B 才可行。
- **Core Task**：枚舉所有飯店與週，找符合條件的最小 N×單價。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
讀入時直接檢查每一週是否可行，取最小花費。

### Final Strategy
條件寫成 `a>n && n*p<b`。

**Edge cases considered**：床位剛好等於人數、費用剛好等於預算、全部不可行。

### Complexity Analysis
- **Time**：O(H·W)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 N, B, H, W:
    ans = INF
    for 每間飯店: 讀單價 p
        for 每週: 讀空床 a
            if a >= N 且 N*p <= B: ans = min(ans, N*p)
    輸出 ans 或 stay home
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。但實測發現隱藏 bug：條件用了嚴格不等式 `a>n`、`n*p<b`，題目是「足夠」與「不超過」預算，應該是 `>=` 與 `<=`。
- **會出錯的輸入**：`2 100 1 1 / 50 / 2`：床位剛好 2、費用剛好 100，正確答案 100，程式輸出 stay home。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,b,h,w;
        while(cin>>n>>b>>h>>w){
                int ans=INT_MAX;
                bool f=0;
                for(int i=0;i<h;i++){
                        int p,a;
                        cin>>p;
                        for(int j=0;j<w;j++){
                                cin>>a;
                                if(a>n && n*p<b){
                                        ans=min(ans,n*p);
                                        f=1;
                                }
                        }
                }
                if(f)cout<<ans<<"\n";
                else cout<<"stay home\n";
        }
}
```
- **關鍵條件**：把條件改成 `a>=n && n*p<=b` 即可；課堂 OJ 測資沒有剛好等於的情況，所以仍 AC。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 1000 2 3 / 200 / 0 2 2 / 300 / 27 3 20 / 5 2000 2 4 / 300 / 4 3 0 4 / 450 / 7 8 0 13` | `900 / stay home` | ✅ `900 / stay home` | 題目範例 |
| Boundary | `2 100 1 1 / 50 / 2` | `100` | ❌ `stay home` | 床位剛好等於人數、費用剛好等於預算 |

**注意**：表中 ❌ 的測資代表這份程式雖然在課堂 OJ 上 AC，但實測仍有錯誤（OJ 測資沒有涵蓋），見第 7 節。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | a>n、n*p<b | 應為 a>=n、n*p<=b |
| Edge Cases | 剛好相等會錯 | 正確 |
| Output Handling | 相同 | 相同 |
| Complexity | O(HW) | O(HW) |
| Code Quality | — | — |

### Reflection
- **Root Cause**：邊界條件用錯不等號。
- **Lesson Learned**：「足夠」「不超過」這類字眼要對應到 ≥、≤。
- **Next Action**：把條件改成 `>=`、`<=`。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11559 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
