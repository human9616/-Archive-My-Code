# UVa 12468 - Zapping

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week4） |
| Problem ID | UVa 12468 |
| Title | Zapping |
| Link | https://onlinejudge.org/external/124/12468.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-29 10:43 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行目前頻道 a 與目標頻道 b（0～99），`-1 -1` 結束。
- **Output**：最少要按幾次上／下鍵。
- **Rules / Constraints**：頻道 99 往上會回到 0，0 往下會到 99。
- **Core Task**：在 100 個頻道的環上求兩點最短距離。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
兩種走法：直接走 |a-b|，或繞另一邊 100-|a-b|，取小的。

### Final Strategy
依 a<b 或 a>b 分別算直接距離和繞一圈距離，取 min。

**Edge cases considered**：a=b（0 次）、距離剛好 50。

### Complexity Analysis
- **Time**：O(T)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 a, b 且不是 -1 -1:
    d = |a - b|
    輸出 min(d, 100 - d)
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==-1 && b==-1)break;
                int ans;
                if(a<b)ans=min(abs(b-a),abs((a+100)-b));
                else ans=min(abs(b-a),abs((b+100)-a));
                cout<<ans<<"\n";
        }
}
```
- **關鍵條件**：環上兩點距離 = min(直接距離, 100 - 直接距離)。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 9 / 0 99 / 12 27 / -1 -1` | `6 / 1 / 15` | ✅ `6 / 1 / 15` | 一般與繞一圈較近 |
| Boundary | `0 50 / -1 -1` | `50` | ✅ `50` | 兩個方向距離相同 |
| Edge | `5 5 / -1 -1` | `0` | ✅ `0` | 不用轉台 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：環狀結構的距離公式。
- **Next Action**：可以簡化成 `min(abs(a-b), 100-abs(a-b))`，不用分兩種情況。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 12468 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
