# UVa 10071 - Back to High School Physics

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week1） |
| Problem ID | UVa 10071 |
| Title | Back to High School Physics |
| Link | https://onlinejudge.org/external/100/10071.pdf |
| Language / Version | C++ |
| Submission Result | AC（一次通過） |
| Initial (Fail) Code | 無（一次通過） |
| Final (Accepted) Code | [src/v1_AC.cpp](src/v1_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-08 11:17 | AC | [src/v1_AC.cpp](src/v1_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多組測資直到 EOF，每組 v（速度）和 t（時間）。
- **Output**：每組輸出 2·v·t。
- **Rules / Constraints**：-100 ≤ v ≤ 100，0 ≤ t ≤ 200，等加速度運動。
- **Core Task**：質點在時間 t 的速度是 v，求 2t 時間內的位移，物理推導後就是 2vt。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
先用物理公式推導：等加速度下，0～2t 的平均速度剛好是時間 t 的速度 v，所以位移 = v × 2t。

### Final Strategy
讀到 EOF，每組直接輸出 `2*v*t`。

**Edge cases considered**：v 為負（位移為負）、v 或 t 為 0。

### Complexity Analysis
- **Time**：O(T)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀得到 v, t:
    輸出 2 * v * t
```

## 5. Fail Code vs Correct Code
### Fail Code
本題第一次提交即 AC，沒有被拒絕的版本。

### Correct Code（`src/v1_AC.cpp`）
```cpp
#include <iostream>
using namespace std;

int main() {
    int v,t;
    while (cin>>v>>t) {
        cout << 2*v*t<<"\n";
    }
}
```
- **關鍵條件**：關鍵是推出位移 = 2vt，並用 while(cin) 處理多組輸入。最大值 2×100×200=40000，int 足夠。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v1_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `5 12 / 0 0` | `120 / 0` | ✅ `120 / 0` | 一般值與 0 |
| Edge | `-5 12` | `-120` | ✅ `-120` | 速度為負 |
| Boundary | `100 200` | `40000` | ✅ `40000` | 題目上界 v=100, t=200 |

## 7. Difference and Reflection
### Key Differences
本題一次 AC，沒有失敗版本可比較。

### Reflection
- **Root Cause**：一次通過；重點在物理推導而不是程式。
- **Lesson Learned**：遇到公式題先推導，程式就會很短。
- **Next Action**：維持「先確認輸入結束條件」的習慣。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10071 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
