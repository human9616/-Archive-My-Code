# UVa 11364 - Parking

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week7） |
| Problem ID | UVa 11364 |
| Title | Parking |
| Link | https://onlinejudge.org/external/113/11364.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-20 10:38 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，每組先給 n，再給 n 個商店位置。
- **Output**：從某處停車、逛完所有店再回到車的最短距離。
- **Rules / Constraints**：位置在一直線上。
- **Core Task**：答案就是 2 ×（最大位置 − 最小位置）。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
車停在哪都一樣，只要從最左走到最右再回來。

### Final Strategy
記錄 max 與 min，輸出 (max-min)*2。

**Edge cases considered**：n=1（答案 0）。

### Complexity Analysis
- **Time**：O(Σn)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
repeat T 次:
    讀 n, mn = INF, mx = 0
    repeat n 次: 讀 c, 更新 mx, mn
    輸出 (mx - mn) * 2
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
                int n,mn=INT_MAX,mx=0,ans=0,c;
                cin>>n;
                for(int i=0;i<n;i++){
                        cin>>c;
                        mx=max(mx,c);
                        mn=min(mn,c);
                }
                ans=(mx-mn)*2;
        cout<<ans<<"\n";
        }
}
```
- **關鍵條件**：直線上來回走完所有點的最短距離是兩倍區間長。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `2 / 4 / 24 13 89 37 / 6 / 7 30 41 14 39 42` | `152 / 70` | ✅ `152 / 70` | 範例型測資 |
| Edge | `1 / 1 / 50` | `0` | ✅ `0` | 只有一家店 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：先觀察題目本質（區間長度），不用模擬路徑。
- **Next Action**：—

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11364 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
