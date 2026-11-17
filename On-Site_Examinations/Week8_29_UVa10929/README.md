# UVa 10929 - You can say 11

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week8 (Midterm)） |
| Problem ID | UVa 10929 |
| Title | You can say 11 |
| Link | https://onlinejudge.org/external/109/10929.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-27 11:21 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行一個最多 1000 位的正整數，`0` 結束。
- **Output**：`N is a multiple of 11.` 或 `N is not a multiple of 11.`。
- **Rules / Constraints**：數字太大，不能直接存成整數。
- **Core Task**：用 11 的倍數判別法：奇數位和與偶數位和的差是 11 的倍數。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
用字串讀入，交替累加到 a 與 b，再看差值。

### Final Strategy
判斷 `abs(a-b)==0 || abs(a-b)==11`。

**Edge cases considered**：差值為 22、33 等其他 11 的倍數；兩位數 11。

### Complexity Analysis
- **Time**：O(位數)。
- **Space**：O(位數)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀字串 n 且 n != "0":
    a = 奇數位和, b = 偶數位和
    if (a - b) % 11 == 0: multiple
    else: not multiple
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。但實測發現隱藏 bug：只判斷差值 0 或 11，差值是 22、33… 時會誤判為不是 11 的倍數。
- **會出錯的輸入**：`40909`（= 11 × 3719，位數差 22）：正確為 multiple，程式輸出 not a multiple。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        while(cin>>n){
                if(n=="0")break;
                bool f=0;
                int a=0,b=0;
                for(int i=0;i<n.size();i++){
                        if(f){
                                a+=n[i]-'0';
                                f=0;
                        }
                        else {
                                b+=n[i]-'0';
                                f=1;
                        }
                }
                if(abs(a-b)==0 || abs(a-b)==11)cout<<n<<" is a multiple of 11.\n";
                else cout<<n<<" is not a multiple of 11.\n";
        }
}
```
- **關鍵條件**：正確判別條件是 `(a-b)%11==0`；或直接逐位計算 `r=(r*10+digit)%11`。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `112233 / 30800 / 2937 / 323455693 / 0` | `112233 is a multiple of 11. / 30800 is a multiple of 11. / 2937 is a multiple of 11. / 323455693 is a multiple of 11.` | ✅ `112233 is a multiple of 11. / 30800 is a multiple of 11. / 2937 is a multiple of 11. / 323455693 is a multiple of 11.` | 題目範例 |
| Edge | `40909 / 0` | `40909 is a multiple of 11.` | ❌ `40909 is not a multiple of 11.` | 奇偶位數和差 22（是 11 的倍數） |
| Boundary | `11 / 0` | `11 is a multiple of 11.` | ✅ `11 is a multiple of 11.` | 最小的 11 倍數 |

**注意**：表中 ❌ 的測資代表這份程式雖然在課堂 OJ 上 AC，但實測仍有錯誤（OJ 測資沒有涵蓋），見第 7 節。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 差值 == 0 或 11 | 差值 % 11 == 0 |
| Edge Cases | 差 22 以上會錯 | 正確 |
| Output Handling | 相同 | 相同 |
| Complexity | O(位數) | O(位數) |
| Code Quality | — | — |

### Reflection
- **Root Cause**：把「是 11 的倍數」簡化成「等於 0 或 11」。
- **Lesson Learned**：判別法的條件要完整使用（mod 11），不要只測小數字。
- **Next Action**：改用 `(a-b)%11==0`，並用 1000 位的大數測試。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10929 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
