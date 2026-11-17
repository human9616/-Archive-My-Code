# UVa 10035 - Primary Arithmetic

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week3） |
| Problem ID | UVa 10035 |
| Title | Primary Arithmetic |
| Link | https://onlinejudge.org/external/100/10035.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 2 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v2_AC.cpp](src/v2_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-22 10:59 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-22 11:00 | AC | [src/v2_AC.cpp](src/v2_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行兩個非負整數，`0 0` 結束。
- **Output**：輸出直式加法的進位次數：0 次輸出 `No carry operation.`、1 次輸出 `1 carry operation.`、多次輸出 `N carry operations.`。
- **Rules / Constraints**：數字小於 10 位。
- **Core Task**：模擬直式加法，數進位次數，並注意單複數。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
從個位數開始，每次取 a%10、b%10 相加，若 ≥10 就算一次進位並把進位加回去。

### Final Strategy
同樣的模擬，但輸出分成 ans==1（單數 operation）與 ans>1（複數 operations）。

**Edge cases considered**：完全沒進位、剛好 1 次、多次、其中一數為 0、進位一路傳到較長的數（9999+1）。

### Complexity Analysis
- **Time**：O(位數)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 a, b 且不是 0 0:
    ans = 0, carry = 0
    while a > 0 或 b > 0:
        carry = (a%10 + b%10 + carry) / 10
        ans += carry
        a /= 10, b /= 10
    依 ans 輸出 No / 1 operation / N operations
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0)break;
        int ans=0;
        while(a>=1 && b>=1){
            int tmp1=a%10,tmp2=b%10;
            if((tmp1+tmp2)/10){
                ans++;
                a+=(tmp1+tmp2)/10;
            }
            a/=10;b/=10;
        }
        if(ans)cout<<ans<<" carry operation.\n";
        else cout<<"No carry operation.\n";
    }
}
```
- **錯誤原因**：輸出沒有區分單複數：v1 對任何 ans>0 都輸出 `carry operation.`。
- **會出錯的輸入**：`555 555`：正確為 `3 carry operations.`，v1 輸出 `3 carry operation.`。

### Correct Code（`src/v2_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0)break;
        int ans=0;
        while(a>=1 && b>=1){
            int tmp1=a%10,tmp2=b%10;
            if((tmp1+tmp2)/10){
                ans++;
                a+=(tmp1+tmp2)/10;
            }
            a/=10;b/=10;
        }
        if(ans==1)cout<<ans<<" carry operation.\n";
        else if(ans>1)cout<<ans<<" carry operations.\n";
        else cout<<"No carry operation.\n";
    }
}
```
- **關鍵條件**：輸出依 ans 分三種情況。另外實測發現 AC 版仍有隱藏 bug：迴圈條件 `a>=1 && b>=1` 在短的數字用完時就停止，`9999 1` 只算到 1 次（正確是 4 次）。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `123 456 / 555 555 / 123 594 / 0 0` | `No carry operation. / 3 carry operations. / 1 carry operation.` | ✅ `No carry operation. / 3 carry operations. / 1 carry operation.` | 0 次、多次、1 次進位 |
| Edge | `9999 1 / 0 0` | `4 carry operations.` | ❌ `1 carry operation.` | 進位一路傳到較長的數 |
| Boundary | `0 5 / 0 0` | `No carry operation.` | ✅ `No carry operation.` | 其中一數為 0 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `123 456 / 555 555 / 123 594 / 0 0`，預期 `No carry operation. / 3 carry operations. / 1 carry operation.`，`v1_WA.cpp` 輸出 `No carry operation. / 3 carry operation. / 1 carry operation.`。
- Edge：輸入 `9999 1 / 0 0`，預期 `4 carry operations.`，`v1_WA.cpp` 輸出 `1 carry operation.`。

**注意**：表中 ❌ 的測資代表這份程式雖然在課堂 OJ 上 AC，但實測仍有錯誤（OJ 測資沒有涵蓋），見第 7 節。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 進位模擬相同 | 進位模擬相同 |
| Edge Cases | — | 9999+1 仍會少算 |
| Output Handling | 不分單複數 | 分 operation / operations |
| Complexity | O(位數) | O(位數) |
| Code Quality | 相同 | 相同 |

### Reflection
- **Root Cause**：沒注意題目輸出的英文單複數；迴圈條件應該用 `||` 而不是 `&&`。
- **Lesson Learned**：輸出字串要逐字對照題目範例。
- **Next Action**：把迴圈改成 `while(a>0 || b>0)`，並另外保留一個 carry 變數，避免短數字用完就停止。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10035 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
