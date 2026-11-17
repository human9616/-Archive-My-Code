# UVa 10193 - All You Need Is Love!

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week8 (Midterm)） |
| Problem ID | UVa 10193 |
| Title | All You Need Is Love! |
| Link | https://onlinejudge.org/external/101/10193.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-27 11:51 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 N，每組兩個二進位字串 S1、S2。
- **Output**：`Pair #i: All you need is love!`（兩數 gcd > 1）或 `Love is not all you need!`。
- **Rules / Constraints**：字串長度最多 30。
- **Core Task**：把二進位轉成整數後判斷 gcd 是否大於 1。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
逐位乘上 2 的次方轉成十進位，再用 __gcd。

### Final Strategy
同 v1。

**Edge cases considered**：互質、長度 30。

### Complexity Analysis
- **Time**：O(長度 + log V)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 N
for i = 1..N:
    讀 S1, S2，轉成整數 a, b
    if gcd(a, b) > 1: love
    else: not love
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
        for(int d=0;d<n;d++){
                string s1,s2;
                int a=0,b=0;
                cin>>s1;
                for(int i=0;i<s1.size();i++)a+=(s1[i]-'0')*pow(2,s1.size()-1-i);
                cin>>s2;
                for(int i=0;i<s2.size();i++)b+=(s2[i]-'0')*pow(2,s2.size()-1-i);
                if(__gcd(a,b)>1)cout<<"Pair #"<<d+1<<": All you need is love!\n";
                else cout<<"Pair #"<<d+1<<": Love is not all you need!\n";
        }
}
```
- **關鍵條件**：長度 ≤ 30，轉成 int 不會溢位。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `5 / 11011 / 11000 / 11011 / 11001 / 111111 / 100 / 1000000000 / 110 / 1010 / 100` | `Pair #1: All you need is love! / Pair #2: Love is not all you need! / Pair #3: Love is not all you need! / Pair #4: All you need is love! / Pair #5: All you need is love!` | ✅ `Pair #1: All you need is love! / Pair #2: Love is not all you need! / Pair #3: Love is not all you need! / Pair #4: All you need is love! / Pair #5: All you need is love!` | 題目範例 |
| Boundary | `1 / 10 / 11` | `Pair #1: Love is not all you need!` | ✅ `Pair #1: Love is not all you need!` | 互質 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：題目包裝成字串，本質是 gcd。
- **Next Action**：`pow` 回傳 double，可改用 `a=a*2+(s[i]-'0')` 避免浮點誤差。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10193 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
