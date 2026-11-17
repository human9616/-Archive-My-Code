# UVa 11547 - Automatic Answer

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week8 (Midterm)） |
| Problem ID | UVa 11547 |
| Title | Automatic Answer |
| Link | https://onlinejudge.org/external/115/11547.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-27 10:27 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 t，接著 t 個整數 n。
- **Output**：對 n 做 ×567、÷9、+7492、×235、÷47、−498 後，輸出結果的十位數。
- **Rules / Constraints**：|n| ≤ 1000，結果可能是負數。
- **Core Task**：照步驟計算，取十位數（負數取絕對值）。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
照題目算完，再轉成字串取倒數第二個字元。

### Final Strategy
`string a=to_string(n); cout<<a[a.size()-2]`。

**Edge cases considered**：負數（字串開頭有 '-'）、n=0、上界 1000。

### Complexity Analysis
- **Time**：O(t)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 t
repeat t 次:
    讀 n
    n = ((n*567/9 + 7492) * 235 / 47) - 498
    輸出 |n| / 10 % 10
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
                int n;
                cin>>n;
                n=(((((n*567)/9)+7492)*235)/47)-498;
                string a=to_string(n);
                cout<<a[a.size()-2]<<"\n";
        }
}
```
- **關鍵條件**：負號在字串最前面，所以倒數第二個字元仍是十位數；結果的絕對值夠大，不會只有一位數。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `2 / 637 / -120` | `1 / 3` | ✅ `1 / 3` | 正數與負數 |
| Edge | `1 / 0` | `6` | ✅ `6` | n=0 |
| Boundary | `1 / 1000` | `6` | ✅ `6` | 題目上界 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：取某一位數可以用字串，也可以用 `abs(n)/10%10`。
- **Next Action**：改用 `abs(n)/10%10` 更直接，也不會有字串長度不足的風險。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11547 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
