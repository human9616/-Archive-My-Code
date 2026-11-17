# UVa 11677 - Alarm Clock

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week4） |
| Problem ID | UVa 11677 |
| Title | Alarm Clock |
| Link | https://onlinejudge.org/external/116/11677.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 2 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v2_AC.cpp](src/v2_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-29 10:32 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-29 10:34 | AC | [src/v2_AC.cpp](src/v2_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行 H1 M1 H2 M2（現在時間與鬧鐘時間），`0 0 0 0` 結束。
- **Output**：還能睡幾分鐘。
- **Rules / Constraints**：時間是 24 小時制，鬧鐘可能在隔天。
- **Core Task**：算兩個時刻的分鐘差，若鬧鐘較早就加一天。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
第一版先比較小時：若 H1>H2 就把鬧鐘小時加 24，最後取絕對值。

### Final Strategy
先全部換成分鐘 t1、t2；若 t1>t2 就 t2 += 24*60；答案 t2-t1。

**Edge cases considered**：跨午夜、同一小時但鬧鐘分鐘比較小（例如 21:33 → 21:10，要睡將近一整天）、時間相同（0 分鐘）。

### Complexity Analysis
- **Time**：O(T)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 h1 m1 h2 m2 且不是全 0:
    t1 = h1*60+m1, t2 = h2*60+m2
    if t1 > t2: t2 += 1440
    輸出 t2 - t1
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b,c,d;
        while(cin>>a>>b>>c>>d){
                if(a==0 && b==0 && c==0 && d==0)break;
                if(a>c)c+=24;
                a*=60;c*=60;
                int t1=a+b,t2=c+d,total=0;
                total=t2-t1;
                if(total<0)total*=-1;
                cout<<total<<"\n";
        }
}
```
- **錯誤原因**：只比較小時：同一小時但鬧鐘分鐘比較小時不會加 24 小時，再加上 abs 會把「要等將近一天」算成幾分鐘。
- **會出錯的輸入**：`21 33 21 10`：正確為 1417，v1 輸出 23。

### Correct Code（`src/v2_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b,c,d;
        while(cin>>a>>b>>c>>d){
                if(a==0 && b==0 && c==0 && d==0)break;
                a*=60;c*=60;
                int t1=a+b,t2=c+d,total=0;
                if(t1>t2)t2+=24*60;
                total=t2-t1;
                cout<<total<<"\n";
        }
}
```
- **關鍵條件**：判斷要用換算後的完整分鐘數 t1>t2，而不是只看小時。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `1 5 3 5 / 23 59 0 34 / 0 0 0 0` | `120 / 35` | ✅ `120 / 35` | 一般與跨午夜 |
| Edge | `21 33 21 10 / 0 0 0 0` | `1417` | ✅ `1417` | 同一小時但鬧鐘分鐘較小，需跨一天 |
| Boundary | `5 0 5 0 / 0 0 0 0` | `0` | ✅ `0` | 時間相同，答案 0 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Edge：輸入 `21 33 21 10 / 0 0 0 0`，預期 `1417`，`v1_WA.cpp` 輸出 `23`。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 比較小時 + abs | 比較總分鐘數 |
| Edge Cases | 同小時、鬧鐘分鐘較小會錯 | 正確跨天 |
| Output Handling | 相同 | 相同 |
| Complexity | O(1) | O(1) |
| Code Quality | abs 掩蓋錯誤 | 邏輯直接 |

### Reflection
- **Root Cause**：時間比較只看小時，abs 又把錯誤結果掩蓋掉。
- **Lesson Learned**：時間題先統一換成最小單位（分鐘）再比較。
- **Next Action**：遇到「循環」的量（時間、角度）時，先想清楚 mod 或加一圈的處理。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 11677 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
