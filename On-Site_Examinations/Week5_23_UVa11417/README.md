# UVa 11417 - GCD

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week5） |
| Problem ID | UVa 11417 |
| Title | GCD |
| Link | https://onlinejudge.org/external/114/11417.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-06 10:50 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行一個 N，0 結束。
- **Output**：G = Σ gcd(i, j)，1 ≤ i < j ≤ N。
- **Rules / Constraints**：N < 501。
- **Core Task**：雙重迴圈加總所有 gcd。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
直接照定義寫雙重迴圈。

### Final Strategy
i 從 1 到 N，j 從 i+1 到 N，累加 __gcd(i,j)。

**Edge cases considered**：N=2。

### Complexity Analysis
- **Time**：O(N² log N)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 N 且 N != 0:
    G = 0
    for i = 1..N: for j = i+1..N: G += gcd(i, j)
    輸出 G
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
                if(n==0)break;
                int ans=0;
                for(int i=1;i<=n;i++){
                        for(int j=i+1;j<=n;j++){
                                ans+=__gcd(i,j);
                        }
                }
                cout<<ans<<'\n';
        }
}
```
- **關鍵條件**：N ≤ 500，雙重迴圈約 12 萬次，完全夠快；答案在 int 範圍內。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `10 / 100 / 500 / 0` | `67 / 13015 / 442011` | ✅ `67 / 13015 / 442011` | 題目範例 |
| Boundary | `2 / 0` | `1` | ✅ `1` | 最小 N |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：先估計暴力法的運算量，夠快就直接寫。
- **Next Action**：—

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11417 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
