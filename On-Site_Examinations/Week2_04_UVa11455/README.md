# UVa 11455 - Behold my quadrangle

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week2） |
| Problem ID | UVa 11455 |
| Title | Behold my quadrangle |
| Link | https://onlinejudge.org/external/114/11455.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 2 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v2_AC.cpp](src/v2_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-15 11:28 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-15 11:33 | AC | [src/v2_AC.cpp](src/v2_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 n，接著 n 行，每行四個邊長。
- **Output**：正方形輸出 square、長方形輸出 rectangle、能圍成一般四邊形輸出 quadrangle，否則輸出 banana。
- **Rules / Constraints**：四個邊可以任意順序給。
- **Core Task**：依邊長判斷形狀；能圍成四邊形的條件是「最長邊 < 其他三邊和」。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
先排序，再依序判斷正方形、長方形、四邊形。第一版判斷四邊形時拿「最短邊」去和其他三邊比較。

### Final Strategy
排序後 side[3] 是最長邊；四邊相等 → square；side[0]==side[1] 且 side[2]==side[3] → rectangle；side[3] < 其他三邊和 → quadrangle；否則 banana。

**Edge cases considered**：最長邊太長、最長邊剛好等於其他三邊和（退化，不算四邊形）、極大邊長相加溢位。

### Complexity Analysis
- **Time**：O(n)（每組排序 4 個數是常數）。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 n
repeat n 次:
    讀四邊並排序成 s[0..3]
    if 四邊相等: square
    else if s[0]==s[1] 且 s[2]==s[3]: rectangle
    else if s[3] < s[0]+s[1]+s[2]: quadrangle
    else: banana
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        int side[4] = {a, b, c, d};
        sort(side, side + 4);
        if(side[1]==side[2] && side[1]==side[3] && side[1]==side[0])cout<<"square\n";
        else if (side[0]==side[1] && side[2]==side[3])cout<<"rectangle\n";
        else if(side[0]<(side[1]+side[2]+side[3]))cout<<"quadrangle\n";
        else cout<<"banana\n";
    }
}
```
- **錯誤原因**：四邊形條件寫成 `side[0] < side[1]+side[2]+side[3]`。最短邊幾乎一定小於其他三邊和，所以永遠不會輸出 banana。
- **會出錯的輸入**：`1 1 1 5`：正確答案 banana（5 ≥ 1+1+1），v1 輸出 quadrangle。

### Correct Code（`src/v2_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        int side[4] = {a, b, c, d};
        sort(side, side + 4);
        if(side[1]==side[2] && side[1]==side[3] && side[1]==side[0])cout<<"square\n";
        else if (side[0]==side[1] && side[2]==side[3])cout<<"rectangle\n";
        else if(side[3]<(side[1]+side[2]+side[0]))cout<<"quadrangle\n";
        else cout<<"banana\n";
    }
}
```
- **關鍵條件**：多邊形不等式要看「最長邊」：只要最長邊 < 其他三邊和，四邊就能圍起來。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `4 / 10 8 7 6 / 9 1 9 1 / 29 29 29 29 / 5 12 30 7` | `quadrangle / rectangle / square / banana` | ✅ `quadrangle / rectangle / square / banana` | 四種輸出各一次 |
| Edge | `1 / 1 1 1 5` | `banana` | ✅ `banana` | 最長邊太長，無法圍成四邊形 |
| Boundary | `1 / 1 2 3 6` | `banana` | ✅ `banana` | 最長邊剛好等於其他三邊和（退化） |
| Stress | `1 / 1000000000 1000000000 1000000000 1` | `quadrangle` | ✅ `quadrangle` | 三邊相加超過 int 範圍 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `4 / 10 8 7 6 / 9 1 9 1 / 29 29 29 29 / 5 12 30 7`，預期 `quadrangle / rectangle / square / banana`，`v1_WA.cpp` 輸出 `quadrangle / rectangle / square / quadrangle`。
- Edge：輸入 `1 / 1 1 1 5`，預期 `banana`，`v1_WA.cpp` 輸出 `quadrangle`。
- Boundary：輸入 `1 / 1 2 3 6`，預期 `banana`，`v1_WA.cpp` 輸出 `quadrangle`。
- Stress：輸入 `1 / 1000000000 1000000000 1000000000 1`，預期 `quadrangle`，`v1_WA.cpp` 輸出 `banana`。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 用最短邊判斷 | 用最長邊判斷 |
| Edge Cases | banana 永遠不會出現 | 正確分辨 banana |
| Output Handling | 相同 | 相同 |
| Complexity | O(1)/組 | O(1)/組 |
| Code Quality | 相同 | 相同 |

### Reflection
- **Root Cause**：多邊形不等式的條件記錯對象。
- **Lesson Learned**：幾何條件寫之前先用一組反例檢查（例如 1 1 1 5）。
- **Next Action**：邊長最大可到 2^30，三邊相加可能超過 int；建議把加總改用 long long（目前課堂 OJ 測資沒有測到）。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11455 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
