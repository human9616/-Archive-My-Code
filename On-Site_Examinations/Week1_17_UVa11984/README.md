# UVa 11984 - A Change in Thermal Unit

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week1） |
| Problem ID | UVa 11984 |
| Title | A Change in Thermal Unit |
| Link | https://onlinejudge.org/external/119/11984.pdf |
| Language / Version | C++ |
| Submission Result | 課堂 OJ 上 10 次皆未通過；修正版 `v11_fix.cpp` 本地測試通過，尚未提交 OJ |
| Initial (Fail) Code | [src/v1_CE.cpp](src/v1_CE.cpp) |
| Final (Fixed) Code | [src/v11_fix.cpp](src/v11_fix.cpp)（修正版） |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-08 11:35 | CE | [src/v1_CE.cpp](src/v1_CE.cpp) |
| 2 | 2026-09-08 11:35 | CE | [src/v2_CE.cpp](src/v2_CE.cpp) |
| 3 | 2026-09-08 11:36 | WA | [src/v3_WA.cpp](src/v3_WA.cpp) |
| 4 | 2026-09-08 11:39 | WA | [src/v4_WA.cpp](src/v4_WA.cpp) |
| 5 | 2026-09-08 11:40 | WA | [src/v5_WA.cpp](src/v5_WA.cpp) |
| 6 | 2026-09-08 11:41 | WA | [src/v6_WA.cpp](src/v6_WA.cpp) |
| 7 | 2026-09-08 11:45 | WA | [src/v7_WA.cpp](src/v7_WA.cpp) |
| 8 | 2026-09-08 11:48 | WA | [src/v8_WA.cpp](src/v8_WA.cpp) |
| 9 | 2026-09-08 11:55 | WA | [src/v9_WA.cpp](src/v9_WA.cpp) |
| 10 | 2026-09-08 11:59 | WA | [src/v10_WA.cpp](src/v10_WA.cpp) |
| 11 | 2026-11-17 | 修正版（未提交 OJ） | [src/v11_fix.cpp](src/v11_fix.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，接著每行 C（攝氏溫度）與 d（華氏「增加量」）。
- **Output**：`Case i: x`，x 為上升後的攝氏溫度，取到小數點後 2 位。
- **Rules / Constraints**：d 是溫度「差」，不是絕對的華氏溫度。
- **Core Task**：把華氏增量換成攝氏增量再加上 C：C + d×5/9。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
一開始把 d 當成華氏溫度，用 (d−32)×5/9 轉換；前兩次連 for 迴圈的分號都寫錯（`time<t<time++`）造成 CE，之後又忘了讀入 t。

### Final Strategy
華氏「增量」換成攝氏增量不需要減 32：答案 = C + d×5/9，用 double 計算並輸出 2 位小數（`src/v11_fix.cpp`）。

**Edge cases considered**：d=0、C 為負、四捨五入到 2 位。

### Complexity Analysis
- **Time**：O(T)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
for i = 1..T:
    讀 C, d
    輸出 "Case i: " + (C + d*5/9) 取 2 位小數
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v3_WA.cpp`）
```cpp
#include <iostream>
using namespace std;
int main(){
    int t,c,d;
    for(int time=0;time<t;time++){
       cin >>c>>d;
       cout<<"Case "<<time+1<<": "<<c+((d-32)*5/9)<<"\n";
    }
}
```
- **錯誤原因**：v1、v2 for 迴圈寫成 `time<t<time++` 編譯錯誤；v3、v4 沒有 `cin>>t`，t 未初始化；v5、v6 用 `(d-32)*5/9`，把溫差當成溫度（v6 還把 `d==0` 寫成 `d=0` 指派）；v7～v10 繞一圈先轉華氏再轉回攝氏，數學上正確但多次浮點運算造成四捨五入誤差，且 v9、v10 改用精度更低的 float。
- **會出錯的輸入**：`1 / 0 1`：正確 `Case 1: 0.56`；v5 會算成 0 + (1−32)×5/9 = −17.22。

### Correct Code（`src/v11_fix.cpp`）
```cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    double c,d;
    cin>>t;
    for(int time=0;time<t;time++){
       cin >>c>>d;
       double ans=c+d*5.0/9;
       cout<<"Case "<<time+1<<": "<< fixed << setprecision(2)<<ans<<"\n";
    }
}
```
- **關鍵條件**：溫度「差」轉換只要乘 5/9，不用減 32；直接一次算出來，避免來回轉換的浮點誤差。本地測試通過，尚未提交 OJ。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v11_fix.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `2 / 100 0 / 0 100` | `Case 1: 100.00 / Case 2: 55.56` | ✅ `Case 1: 100.00 / Case 2: 55.56` | 題目範例 |
| Edge | `1 / -10 9` | `Case 1: -5.00` | ✅ `Case 1: -5.00` | 攝氏為負 |
| Boundary | `1 / 0 1` | `Case 1: 0.56` | ✅ `Case 1: 0.56` | 最小的華氏增量，四捨五入 |

**一開始失敗的測資（`src/v3_WA.cpp`）**：

- Normal：輸入 `2 / 100 0 / 0 100`，預期 `Case 1: 100.00 / Case 2: 55.56`，`v3_WA.cpp` 輸出 （無輸出）。
- Edge：輸入 `1 / -10 9`，預期 `Case 1: -5.00`，`v3_WA.cpp` 輸出 （無輸出）。
- Boundary：輸入 `1 / 0 1`，預期 `Case 1: 0.56`，`v3_WA.cpp` 輸出 （無輸出）。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | (d−32)×5/9 或來回轉換 | C + d×5/9 |
| Edge Cases | d 當成溫度 | d 當成溫差 |
| Output Handling | fixed 2 位 | fixed 2 位 |
| Complexity | O(T) | O(T) |
| Code Quality | CE、未讀 t、= 與 == 混用 | 簡潔 |

### Reflection
- **Root Cause**：沒有讀懂題目中 d 是「增量」；連續 WA 時改了很多無關的地方（float、換行）。
- **Lesson Learned**：溫度、時間這種「差值」與「絕對值」要分清楚；WA 時先回頭確認公式。
- **Next Action**：把 `v11_fix.cpp` 提交到 OJ 確認 AC。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11984 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
