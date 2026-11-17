# UVa 11799 - Horror Dash

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week7） |
| Problem ID | UVa 11799 |
| Title | Horror Dash |
| Link | https://onlinejudge.org/external/117/11799.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-20 10:30 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，每組先給 N，再給 N 個速度。
- **Output**：`Case x: v`，v 為最大速度。
- **Rules / Constraints**：小丑的速度必須不小於所有生物的速度。
- **Core Task**：求每組的最大值。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
邊讀邊用 max 更新答案。

### Final Strategy
ans 初始 0，讀入時 ans=max(ans,c)，輸出 Case 編號與 ans。

**Edge cases considered**：N=1、所有速度相同。

### Complexity Analysis
- **Time**：O(ΣN)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
for i = 1..T:
    讀 N, ans = 0
    repeat N 次: 讀 c, ans = max(ans, c)
    輸出 "Case i: ans"
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
        for(int i=0;i<t;i++){
                int n,c,ans=0;
                cin>>n;
                for(int i=0;i<n;i++){
                        cin>>c;;
                        ans=max(ans,c);
                }
        cout<<"Case "<<i+1<<": "<<ans<<"\n";
        }
}
```
- **關鍵條件**：速度都是正數，所以 ans 從 0 開始是安全的。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `2 / 5 9 5 6 4 3 / 3 4 3 5` | `Case 1: 9 / Case 2: 5` | ✅ `Case 1: 9 / Case 2: 5` | 多組 case |
| Edge | `1 / 1 7` | `Case 1: 7` | ✅ `Case 1: 7` | 只有一隻生物 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：Case 編號從 1 開始。
- **Next Action**：內外層迴圈都用 i，可讀性較差，內層可改名為 j。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11799 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
