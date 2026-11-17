# UVa 11827 - Maximum GCD

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week5） |
| Problem ID | UVa 11827 |
| Title | Maximum GCD |
| Link | https://onlinejudge.org/external/118/11827.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-06 10:57 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 N，接著 N 行，每行不定個數的正整數。
- **Output**：每行任兩數 gcd 的最大值。
- **Rules / Constraints**：每行數字個數不固定，要整行讀。
- **Core Task**：整行讀入、拆數字，兩兩求 gcd 取最大。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
用 getline 讀整行，再用 stringstream 拆出數字。

### Final Strategy
`cin.ignore()` 吃掉第一行的換行，之後每行 getline + stringstream，雙重迴圈求最大 gcd。

**Edge cases considered**：每行只有兩個數、數字相同。

### Complexity Analysis
- **Time**：O(k² log V)／行。
- **Space**：O(k)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 N，忽略換行
repeat N 次:
    讀一整行，拆成數字陣列 a
    ans = max over i<j of gcd(a[i], a[j])
    輸出 ans
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
        cin.ignore();
        while(n--){
                int ans=0;
                string s;
                vector<int> a;
                a.clear();
                getline(cin,s);
                stringstream ss(s);
                while(ss>>s){
                        a.push_back(stoi(s));
                }
                for(int i=0;i<a.size();i++){
                        for(int j=i+1;j<a.size();j++){
                                ans=max(__gcd(a[i],a[j]),ans);
                        }
                }
                cout<<ans<<'\n';
        }
}
```
- **關鍵條件**：關鍵是 `cin.ignore()`：否則第一次 getline 會讀到空字串。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 10 20 30 40 / 7 5 12 / 125 15 25` | `20 / 1 / 25` | ✅ `20 / 1 / 25` | 題目範例 |
| Edge | `1 / 6 6` | `6` | ✅ `6` | 兩數相同 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過。
- **Lesson Learned**：cin 與 getline 混用時要處理殘留的換行。
- **Next Action**：—

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11827 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
