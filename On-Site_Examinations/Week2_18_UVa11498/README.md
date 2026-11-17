# UVa 11498 - Division of Nlogonia

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week2） |
| Problem ID | UVa 11498 |
| Title | Division of Nlogonia |
| Link | https://onlinejudge.org/external/114/11498.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 2 次提交） |
| Initial (Fail) Code | [src/v1_CE.cpp](src/v1_CE.cpp) |
| Final (Accepted) Code | [src/v2_AC.cpp](src/v2_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-15 10:58 | CE | [src/v1_CE.cpp](src/v1_CE.cpp) |
| 2 | 2026-09-15 11:03 | AC | [src/v2_AC.cpp](src/v2_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多組，每組先給 K，再給分界點 (N, M)，接著 K 個住址 (X, Y)；K=0 結束。
- **Output**：住址在分界點的 NE、NO、SE、SO，或在分界線上輸出 divisa。
- **Rules / Constraints**：座標可為負數。
- **Core Task**：比較 X 與 N、Y 與 M 判斷象限。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
用巢狀 if：先比 x 與 a，再比 y 與 b。

### Final Strategy
同 v1，邏輯不變；v1 是選錯語言（C）而編譯失敗，改選 C++ 後 AC。

**Edge cases considered**：在分界線上（x==a 或 y==b）、負座標。

### Complexity Analysis
- **Time**：O(ΣK)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 K 且 K != 0:
    讀 N, M
    repeat K 次:
        讀 X, Y
        if X==N 或 Y==M: divisa
        else: (Y>M ? N : S) + (X>N ? E : O)
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。程式本身沒有錯，是提交時語言選成 C，編譯器找不到 `<iostream>`，所以 CE。
- **會出錯的輸入**：（不是邏輯錯誤，任何輸入都會 CE）

### Correct Code（`src/v2_AC.cpp`）
```cpp
#include<iostream>
using namespace std;
int main(){
    int n,a,b,x,y;
    while(cin>>n){
        cin>>a>>b;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(x>a){
                if(y>b)cout<<"NE\n";
                else if(y<b) cout<<"SE\n";
                else cout<<"divisa\n";
            }
            else if(x<a){
                if(y>b)cout<<"NO\n";
                else if(y<b) cout<<"SO\n";
                else cout<<"divisa\n";
            }
            else cout<<"divisa\n";
        }
    }
    return 0;
}
```
- **關鍵條件**：提交時語言改成 C++。程式沒有判斷 K==0 就結束，但讀到 0 時迴圈不執行、之後讀不到資料自然結束，所以仍然正確。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `3 / 2 1 / 10 10 / -10 1 / 0 33 / 0` | `NE / divisa / NO` | ✅ `NE / divisa / NO` | 範例型：NE、divisa、NO |
| Edge | `2 / 0 0 / -1 -1 / 5 -3 / 0` | `SO / SE` | ✅ `SO / SE` | SO 與 SE |
| Boundary | `1 / 0 0 / 0 5 / 0` | `divisa` | ✅ `divisa` | 落在分界線上 |

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 相同 | 相同 |
| Edge Cases | 相同 | 相同 |
| Output Handling | 相同 | 相同 |
| Complexity | 相同 | 相同 |
| Code Quality | 提交語言選 C | 選 C++，加 return 0 |

### Reflection
- **Root Cause**：提交時沒有確認語言選項。
- **Lesson Learned**：CE 時先看錯誤訊息：`main.c` 代表語言選錯。
- **Next Action**：提交前確認語言是 C++。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11498 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
