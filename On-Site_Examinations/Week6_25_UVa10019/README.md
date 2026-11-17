# UVa 10019 - Funny Encryption Method

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week6） |
| Problem ID | UVa 10019 |
| Title | Funny Encryption Method |
| Link | https://onlinejudge.org/external/100/10019.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-13 10:58 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 N，接著 N 個整數 M。
- **Output**：b1：M 的二進位中 1 的個數；b2：把 M 的十進位字面當成十六進位後，二進位中 1 的個數。
- **Rules / Constraints**：0 < M ≤ 9999。
- **Core Task**：兩種解讀方式各數一次 1 的個數。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
把 M 的每一位數乘上 16 的次方得到十六進位解讀的值，再分別數 1。

### Final Strategy
同 v1。

**Edge cases considered**：M=1、M=9999。

### Complexity Analysis
- **Time**：O(log M)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 N
repeat N 次:
    讀 M
    a = 把 M 的每一位當十六進位位數組合
    輸出 popcount(M), popcount(a)
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,m;
        cin>>n;
        while(n--){
                int ct1=0,ct2=0;
                cin>>m;
                int tmp=m,a=0,i=0;
                while(m>0){
                        a+=m%10*pow(16,i++);
                        m/=10;
                }
                m=tmp;
                while(m>0){
                        if(m%2==1)ct1++;
                        m/=2;
                }

                while(a>0){
                        if(a%2==1)ct2++;
                        a/=2;
                }
                cout<<ct1<<" "<<ct2<<"\n";
        }
}
```
- **關鍵條件**：每一位數 ≤ 9，所以「十進位字面當十六進位」就是逐位乘 16^i。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 265 / 111 / 1234` | `3 5 / 6 3 / 5 5` | ✅ `3 5 / 6 3 / 5 5` | 題目範例 |
| Boundary | `1 / 1` | `1 1` | ✅ `1 1` | M=1 |
| Boundary | `1 / 9999` | `8 8` | ✅ `8 8` | 上界 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：進位轉換題可以拆成「取位數」與「重組」兩步。
- **Next Action**：可用 `__builtin_popcount` 簡化數 1 的部分；`pow` 回傳 double，整數運算建議自己累乘。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10019 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
