# UVa 579 - Clock Hands

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week4） |
| Problem ID | UVa 579 |
| Title | Clock Hands |
| Link | https://onlinejudge.org/external/5/579.pdf |
| Language / Version | C++ |
| Submission Result | 課堂 OJ 上 6 次皆未通過；修正版 `v7_fix.cpp` 本地測試通過，尚未提交 OJ |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Fixed) Code | [src/v7_fix.cpp](src/v7_fix.cpp)（修正版） |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-29 11:25 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-29 11:27 | WA | [src/v2_WA.cpp](src/v2_WA.cpp) |
| 3 | 2026-09-29 11:40 | WA | [src/v3_WA.cpp](src/v3_WA.cpp) |
| 4 | 2026-09-29 11:41 | WA | [src/v4_WA.cpp](src/v4_WA.cpp) |
| 5 | 2026-09-29 11:43 | WA | [src/v5_WA.cpp](src/v5_WA.cpp) |
| 6 | 2026-09-29 11:55 | WA | [src/v6_WA.cpp](src/v6_WA.cpp) |
| 7 | 2026-11-17 | 修正版（未提交 OJ） | [src/v7_fix.cpp](src/v7_fix.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行 H:M 格式的時間，`0:00` 結束。
- **Output**：時針與分針的較小夾角，3 位小數。
- **Rules / Constraints**：1 ≤ H ≤ 12，夾角介於 0～180 度。
- **Core Task**：時針角度 30H+0.5M，分針 6M，取差的絕對值，若 > 180 改成 360 − 角度。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
自己解析字串取出 H 與 M，用公式算夾角。先寫了 `h-=12`，之後花了 5 次提交嘗試各種 >180 的修正方式。

### Final Strategy
H 為 12 時當成 0（`h%12`）；夾角 = |30H + 0.5M − 6M|，若 > 180 則 360 − 夾角（`src/v7_fix.cpp`）。

**Edge cases considered**：12 點、角度大於 180、整點。

### Complexity Analysis
- **Time**：O(T)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀 "H:M" 且不是 0:00:
    H = H % 12
    ang = |30H + 0.5M - 6M|
    if ang > 180: ang = 360 - ang
    輸出 ang（3 位小數）
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        string s;
        while(cin>>s){
                if(s=="0:00")break;
                double h=0,m=0,ans=0;
                int i=0,f=0;
                while(s[i]!=':'){
                        if(i==1){
                                h*=10;
                                h+=(s[i]-'0');
                                f=1;
                        }
                        else h+=s[i]-'0';
                        i++;
                }
                h-=12;
                for(i++;;i++){
                        if(f && i==5)break;
                        if(!f && i==4)break;
                        if((!f && i==3) || (f && i==4) )m*=10;
                        m+=s[i]-'0';
                }
                ans=abs((h*30+0.5*m)-(6*m));
                cout<<fixed<<setprecision(3)<<ans<<"\n";
        }
}
```
- **錯誤原因**：`h-=12` 讓 1～11 點變成負數，算出的角度可能超過 180 甚至到 360 附近；後續 5 版只在結果上加補丁（−180、180−ans、+180…），都不是正確的「360 − 角度」。
- **會出錯的輸入**：`3:00`：正確 90.000，v1 算出 270.000；`1:50`：正確 115.000。

### Correct Code（`src/v7_fix.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        string s;
        while(cin>>s){
                if(s=="0:00")break;
                double h=0,m=0,ans=0;
                int i=0,f=0;
                while(s[i]!=':'){
                        if(i==1){
                                h*=10;
                                h+=(s[i]-'0');
                                f=1;
                        }
                        else h+=s[i]-'0';
                        i++;
                }
                if(h==12)h=0;
                for(i++;;i++){
                        if(f && i==5)break;
                        if(!f && i==4)break;
                        if((!f && i==3) || (f && i==4) )m*=10;
                        m+=s[i]-'0';
                }
                ans=abs((h*30+0.5*m)-(6*m));
                if(ans>180)ans=360-ans;
                cout<<fixed<<setprecision(3)<<ans<<"\n";
        }
}
```
- **關鍵條件**：把 12 點對應到 0 而不是把所有小時減 12；超過 180 度時用 360 − 角度。本地測試通過，尚未提交 OJ。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v7_fix.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `12:00 / 9:00 / 8:10 / 0:00` | `0.000 / 90.000 / 175.000` | ✅ `0.000 / 90.000 / 175.000` | 題目範例 |
| Edge | `3:00 / 0:00` | `90.000` | ✅ `90.000` | 小時小於 12 |
| Edge | `1:50 / 0:00` | `115.000` | ✅ `115.000` | 角度大於 180 要取 360-角度 |
| Boundary | `12:30 / 0:00` | `165.000` | ✅ `165.000` | 12 點要當成 0 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Edge：輸入 `3:00 / 0:00`，預期 `90.000`，`v1_WA.cpp` 輸出 `270.000`。
- Edge：輸入 `1:50 / 0:00`，預期 `115.000`，`v1_WA.cpp` 輸出 `605.000`。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | h−12 + 各種補丁 | h%12 + (360−ang) |
| Edge Cases | 1～11 點錯 | 全部正確 |
| Output Handling | 3 位小數 | 3 位小數 |
| Complexity | O(1) | O(1) |
| Code Quality | 補丁越加越多 | 條件單純 |

### Reflection
- **Root Cause**：時鐘的角度模型沒想清楚，錯了之後一直對結果打補丁。
- **Lesson Learned**：幾何題先手算 2～3 個例子確認公式，再寫程式。
- **Next Action**：把 `v7_fix.cpp` 提交到 OJ 確認 AC；解析時間可直接用 `char` 讀入：`cin>>h>>c>>m`。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 579 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
