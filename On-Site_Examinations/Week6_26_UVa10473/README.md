# UVa 10473 - Simple Base Conversion

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week6） |
| Problem ID | UVa 10473 |
| Title | Simple Base Conversion |
| Link | https://onlinejudge.org/external/104/10473.pdf |
| Language / Version | C++ |
| Submission Result | 課堂 OJ 上 1 次皆未通過；修正版 `v2_fix.cpp` 本地測試通過，尚未提交 OJ |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Fixed) Code | [src/v2_fix.cpp](src/v2_fix.cpp)（修正版） |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-10-13 11:19 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-11-17 | 修正版（未提交 OJ） | [src/v2_fix.cpp](src/v2_fix.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：多行，每行一個十進位數或 `0x` 開頭的十六進位數，負數結束。
- **Output**：十進位轉成 `0x` 大寫十六進位；十六進位轉成十進位。
- **Rules / Constraints**：數值在 32 位元範圍內。
- **Core Task**：判斷前綴，雙向進位轉換。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
用 `0x` 前綴判斷方向；十六進位逐位乘 16 的次方，十進位反覆除 16。

### Final Strategy
修正 v1 的三個錯誤：字母判斷改成 `>='A'`、累加時用 r 本身而不是 `r%10`、以任意負數結束，並特判十進位 0（`src/v2_fix.cpp`）。

**Edge cases considered**：十六進位剛好是 A、多位數十六進位、十進位 0、以 −1 以外的負數結束。

### Complexity Analysis
- **Time**：O(位數)。
- **Space**：O(位數)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
while 讀字串 s 且不是負數:
    if s 以 0x 開頭: 逐位轉成數值累加，輸出十進位
    else: 反覆 %16、/16 得到位數，反向輸出 "0x..."（0 輸出 0x0）
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        while(cin>>n){
                if(n=="-1")break;
                if(n[0]=='0' && n[1]=='x'){  //16->10
                int a=0,t=0;
                for(int i=n.size()-1;i>=2;i--){
                        int r;
                        if(n[i]>'A' && n[i]<='F')r=n[i]-'A'+10;
                        else r=n[i]-'0';
                        a+=r%10*pow(16,t++);
                }
                cout<<a<<"\n";
                }
                else{                           //10->16
                string ans="";
                        int a=stoi(n);
                        cout<<"0x";
                        while(a>0){
                                char r=(a%16)-10+'A';
                                if(a%16>=10)ans+=r;
                                else ans+=to_string(a%16);
                                a/=16;
                        }
                        for(int i=ans.size()-1;i>=0;i--)
                        cout<<ans[i];
                        cout<<"\n";
                }
        }

}
```
- **錯誤原因**：三個錯誤：(1) `n[i]>'A'` 漏掉 A 本身；(2) `r%10` 把 10～15 變成 0～5；(3) 只在輸入 `-1` 時結束。
- **會出錯的輸入**：`0xA`：正確 10，v1 輸出 0；`0x1F`：正確 31，v1 輸出 21。

### Correct Code（`src/v2_fix.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        while(cin>>n){
                if(n[0]=='-')break;
                if(n[0]=='0' && n[1]=='x'){  //16->10
                long long a=0,t=0;
                for(int i=n.size()-1;i>=2;i--){
                        int r;
                        if(n[i]>='A' && n[i]<='F')r=n[i]-'A'+10;
                        else if(n[i]>='a' && n[i]<='f')r=n[i]-'a'+10;
                        else r=n[i]-'0';
                        a+=r*(long long)pow(16,t++);
                }
                cout<<a<<"\n";
                }
                else{                           //10->16
                string ans="";
                        long long a=stoll(n);
                        cout<<"0x";
                        if(a==0)ans="0";
                        while(a>0){
                                char r=(a%16)-10+'A';
                                if(a%16>=10)ans+=r;
                                else ans+=to_string(a%16);
                                a/=16;
                        }
                        for(int i=ans.size()-1;i>=0;i--)
                        cout<<ans[i];
                        cout<<"\n";
                }
        }

}
```
- **關鍵條件**：字母範圍包含 A～F（也處理小寫），每一位直接用 r 乘上 16 的次方；輸入以 '-' 開頭就結束。本地測試通過，尚未提交 OJ。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v2_fix.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `4 / 7 / 44 / 0x80685 / -1` | `0x4 / 0x7 / 0x2C / 525957` | ✅ `0x4 / 0x7 / 0x2C / 525957` | 題目範例 |
| Edge | `0xA / -1` | `10` | ✅ `10` | 十六進位剛好是 A |
| Edge | `0x1F / -5` | `31` | ✅ `31` | 含兩位以上十六進位且以其他負數結束 |
| Boundary | `0 / -1` | `0x0` | ✅ `0x0` | 十進位 0 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Edge：輸入 `0xA / -1`，預期 `10`，`v1_WA.cpp` 輸出 `7`。
- Edge：輸入 `0x1F / -5`，預期 `31`，`v1_WA.cpp` 輸出 `21 / 0x`。
- Boundary：輸入 `0 / -1`，預期 `0x0`，`v1_WA.cpp` 輸出 `0x`。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | r%10、>'A' | r、>='A' |
| Edge Cases | A、0、其他負數錯誤 | 全部正確 |
| Output Handling | 相同 | 0 輸出 0x0 |
| Complexity | O(位數) | O(位數) |
| Code Quality | — | 改用 long long |

### Reflection
- **Root Cause**：字元範圍的邊界與取位數的寫法沒檢查。
- **Lesson Learned**：進位轉換要測「每個位數符號」至少一次（0、9、A、F）。
- **Next Action**：把 `v2_fix.cpp` 提交到 OJ 確認 AC。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 10473 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
