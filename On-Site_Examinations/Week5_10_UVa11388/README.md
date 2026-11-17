# UVa 11388 - GCD LCM

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week5） |
| Problem ID | UVa 11388 |
| Title | GCD LCM |
| Link | https://onlinejudge.org/external/113/11388.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-06 10:37 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，接著 T 行，每行 G 與 L。
- **Output**：找最小的 a 使 gcd(a,b)=G 且 lcm(a,b)=L，輸出 a b；不存在輸出 -1。
- **Rules / Constraints**：G、L 為正整數。
- **Core Task**：有解的條件是 L 能被 G 整除，此時答案就是 G L。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
想到 a 最小就是 G，b 就是 L，只要 G 整除 L 就成立。

### Final Strategy
用 g=__gcd(G,L)：若 g==G（G 整除 L），l=(g/G)*L=L；否則 g/G=0 使 l=0，輸出 -1。

**Edge cases considered**：G=L、G 不整除 L、大數 L。

### Complexity Analysis
- **Time**：O(log L)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
repeat T 次:
    讀 G, L
    if L % G == 0: 輸出 G L
    else: 輸出 -1
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
        cin>>n;
        while(n--){
                int a,b;
                cin>>a>>b;
                int g=__gcd(a,b);
                int l=(g/a)*b;
                if(l==0)cout<<"-1\n";
                else cout<<g<<" "<<l<<"\n";
        }
}
```
- **關鍵條件**：利用整數除法 g/G 只有 g==G 時為 1，否則為 0，間接判斷 G 是否整除 L。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `2 / 1 2 / 3 4` | `1 2 / -1` | ✅ `1 2 / -1` | 有解與無解 |
| Edge | `1 / 5 5` | `5 5` | ✅ `5 5` | G 與 L 相同 |
| Boundary | `1 / 1 1000000000` | `1 1000000000` | ✅ `1 1000000000` | 大數 L |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：數論題先找出有解的條件。
- **Next Action**：寫法比較繞，可直接用 `if(L%G==0)`，可讀性較好。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11388 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
