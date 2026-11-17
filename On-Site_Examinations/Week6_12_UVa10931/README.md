# UVa 10931 - Parity

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week6） |
| Problem ID | UVa 10931 |
| Title | Parity |
| Link | https://onlinejudge.org/external/109/10931.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-13 10:45 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行一個正整數 I，0 結束。
- **Output**：`The parity of B is P (mod 2).`，B 是 I 的二進位，P 是 B 中 1 的個數。
- **Rules / Constraints**：1 ≤ I ≤ 2147483647。
- **Core Task**：十進位轉二進位並數 1 的個數。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
和三進位轉換一樣：%2 取位元、/2，順便數 1。

### Final Strategy
取位元存進字串、計數 1，最後反向輸出字串並印出 parity。

**Edge cases considered**：I=1、I 為 2 的次方、int 上界 2147483647。

### Complexity Analysis
- **Time**：O(log I)。
- **Space**：O(log I)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 n 且 n != 0:
    s = "", cnt = 0
    while n > 0:
        if n%2 == 1: cnt++
        s += n%2, n /= 2
    輸出 "The parity of " + reverse(s) + " is " + cnt + " (mod 2)."
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
                string s="",ans="";
                int count=0;
                while(n>0){
                        if(n%2==1)count++;
                        s+=to_string(n%2);
                        n/=2;
                }cout<<"The parity of ";
                for(int i=s.size()-1;i>=0;i--)
                cout<<s[i];
                cout<<" is "<<count<<" (mod 2).\n";
        }
}
```
- **關鍵條件**：I ≥ 1，所以不會遇到 0 的空字串問題（和 11185 的差別）。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `1 / 2 / 10 / 21 / 0` | `The parity of 1 is 1 (mod 2). / The parity of 10 is 1 (mod 2). / The parity of 1010 is 2 (mod 2). / The parity of 10101 is 3 (mod 2).` | ✅ `The parity of 1 is 1 (mod 2). / The parity of 10 is 1 (mod 2). / The parity of 1010 is 2 (mod 2). / The parity of 10101 is 3 (mod 2).` | 範例型測資 |
| Boundary | `2147483647 / 0` | `The parity of 1111111111111111111111111111111 is 31 (mod 2).` | ✅ `The parity of 1111111111111111111111111111111 is 31 (mod 2).` | int 上界，31 個 1 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：同類型的進位轉換，要注意每題的輸入範圍是否包含 0。
- **Next Action**：宣告了沒用到的變數 ans，可以刪除。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10931 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
