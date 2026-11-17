# UVa 11461 - Square Numbers

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week5） |
| Problem ID | UVa 11461 |
| Title | Square Numbers |
| Link | https://onlinejudge.org/external/114/11461.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 6 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v6_AC.cpp](src/v6_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-06 10:27 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-10-06 10:31 | WA | [src/v2_WA.cpp](src/v2_WA.cpp) |
| 3 | 2026-10-06 10:40 | WA | [src/v3_WA.cpp](src/v3_WA.cpp) |
| 4 | 2026-10-06 10:42 | WA | [src/v4_WA.cpp](src/v4_WA.cpp) |
| 5 | 2026-10-06 10:43 | WA | [src/v5_WA.cpp](src/v5_WA.cpp) |
| 6 | 2026-10-06 10:46 | AC | [src/v6_AC.cpp](src/v6_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行 a、b，`0 0` 結束。
- **Output**：區間 [a, b] 內完全平方數的個數。
- **Rules / Constraints**：0 < a ≤ b ≤ 100000。
- **Core Task**：數有幾個 i 使 a ≤ i² ≤ b。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
想用 i 從某個起點跑到 i² > b，數有幾個。第一版從 i=a 開始（錯把 a 當成根號的起點），後來改成 sqrt(a) 起跑，但 sqrt(a) 取整後 i² 可能小於 a。

### Final Strategy
i 從 1 跑到 i*i<=b，只在 i*i>=a 時計數。

**Edge cases considered**：a 本身不是平方數（如 5）、區間內沒有平方數、a=b=1、上界 100000。

### Complexity Analysis
- **Time**：O(√b)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 a, b 且不是 0 0:
    ans = 0
    for i = 1; i*i <= b; i++:
        if i*i >= a: ans++
    輸出 ans
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                int ans=0;
                for(int i=a;i*i<=b;i++){
                                ans++;
                }
                cout<<ans<<"\n";
        }
}
```
- **錯誤原因**：v1 從 i=a 開始，等於把 a 當成「根號」，算的是 [a², b] 而不是 [a, b]；v2 把 `i*i>=a` 放進迴圈條件，條件一不成立就整個迴圈結束；v3～v5 從 `sqrt(a)` 起跑，a 不是平方數時會多算一個；v4、v5 還多了不必要的換行格式修改。
- **會出錯的輸入**：`5 10`：正確答案 1（只有 9），v1 輸出 0。

### Correct Code（`src/v6_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        long long a,b,h=0;
        while(cin>>a>>b){
                if(a==0 || b==0)break;
                long long ans=0;
                for(int i=1;i*i<=b;i++){
                        if(i*i>=a){
                                ans++;
                        }
                }
                cout<<ans<<"\n";
        }
}
```
- **關鍵條件**：把「下界」從迴圈條件移到迴圈內的 if：迴圈只負責上界 i*i<=b，計數時再檢查 i*i>=a。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v6_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `1 4 / 1 10 / 0 0` | `2 / 3` | ✅ `2 / 3` | 從 1 開始的區間 |
| Edge | `5 10 / 0 0` | `1` | ✅ `1` | a 不是平方數 |
| Edge | `5 8 / 0 0` | `0` | ✅ `0` | 區間內沒有平方數 |
| Boundary | `1 1 / 0 0` | `1` | ✅ `1` | a=b=1 |
| Stress | `1 100000 / 0 0` | `316` | ✅ `316` | 題目上界 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Edge：輸入 `5 10 / 0 0`，預期 `1`，`v1_WA.cpp` 輸出 `0`。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 起點與條件錯誤 | 從 1 枚舉 + if 過濾 |
| Edge Cases | a 非平方數會錯 | 正確 |
| Output Handling | v4、v5 曾改成先換行 | 每行後換行 |
| Complexity | O(√b) | O(√b) |
| Code Quality | 條件混在 for 裡 | 條件分開，易讀 |

### Reflection
- **Root Cause**：把「迴圈結束條件」和「計數條件」混在一起；sqrt 取整的邊界沒想清楚。
- **Lesson Learned**：for 的條件只放「何時停」，篩選放在 if。
- **Next Action**：也可以用公式 `floor(sqrt(b)) - ceil(sqrt(a)) + 1`，但要注意浮點誤差。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11461 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
