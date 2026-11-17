# UVa 1225 - Digit Counting

## 1. Problem Information
| 項目 | 內容 |
|---|---|
| Platform | UVa Online Judge（課堂 OJ：CI001 week3） |
| Problem ID | UVa 1225 |
| Title | Digit Counting |
| Link | https://onlinejudge.org/external/12/1225.pdf |
| Language / Version | C++ |
| Submission Result | AC（第 3 次提交） |
| Initial (Fail) Code | [src/v1_WA.cpp](src/v1_WA.cpp) |
| Final (Accepted) Code | [src/v3_AC.cpp](src/v3_AC.cpp) |
| Review Date | 2026-11-17 |

### Submission History（課堂 OJ 提交紀錄）
| # | 時間 | 結果 | 程式碼 |
|---|---|---|---|
| 1 | 2026-09-22 10:43 | WA | [src/v1_WA.cpp](src/v1_WA.cpp) |
| 2 | 2026-09-22 10:44 | WA | [src/v2_WA.cpp](src/v2_WA.cpp) |
| 3 | 2026-09-22 10:49 | AC | [src/v3_AC.cpp](src/v3_AC.cpp) |

## 2. Problem Statement in My Own Words
- **Input**：第一行 T，每組一個 N。
- **Output**：把 1～N 連在一起寫，輸出 0～9 各出現幾次，以空白分隔。
- **Rules / Constraints**：N ≤ 10000。
- **Core Task**：統計 1～N 每個數字的各位數。

## 3. Thinking Logic and Solution Strategy
### Initial Thoughts
對每個 i 拆出每一位數並計數；一位數直接加。

### Final Strategy
同樣的計數，但輸出最後一個數字後不要多印空白。

**Edge cases considered**：N=1、N=10000、行尾空白。

### Complexity Analysis
- **Time**：O(N log N)。
- **Space**：O(1)。
- 以題目的輸入規模，這個複雜度遠低於時間限制。

## 4. Pseudocode
```
讀 T
repeat T 次:
    讀 N, cnt[0..9] = 0
    for i = 1..N: 把 i 的每一位數加到 cnt
    輸出 cnt，數字之間一個空白、行尾不加空白
```

## 5. Fail Code vs Correct Code
### Fail Code（`src/v1_WA.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int ans[10]={0};
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i<10)ans[i]++;
            else{
                    int tmp=i;
                while(tmp>=1){
                    ans[tmp%10]++;
                    tmp/=10;
                }
            }
        }
        for(int i=0;i<10;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}
```
- **錯誤原因**：v1 每個數字後面都輸出空白，行尾多了一個空白；v2 只把型別改成 long long，沒改到真正的問題。
- **會出錯的輸入**：`1 / 3`：正確 `0 1 1 1 0 0 0 0 0 0`，v1 輸出 `0 1 1 1 0 0 0 0 0 0 `（行尾多空白）。

### Correct Code（`src/v3_AC.cpp`）
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long int ans[10]={0};
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i<10)ans[i]++;
            else{
                    int tmp=i;
                while(tmp>=1){
                    ans[tmp%10]++;
                    tmp/=10;
                }
            }
        }
        for(int i=0;i<10;i++){
            cout<<ans[i];
            if(i!=9)cout<<" ";
        }
        cout<<"\n";
    }
}
```
- **關鍵條件**：`if(i!=9)` 才輸出空白，行尾不再多空白。

## 6. Test Evidence
以下 Actual 為實際編譯並執行 `src/v3_AC.cpp` 的輸出。

| Category | Input | Expected | Actual | Purpose |
|---|---|---|---|---|
| Normal | `2 / 3 / 13` | `0 1 1 1 0 0 0 0 0 0 / 1 6 2 2 1 1 1 1 1 1` | ✅ `0 1 1 1 0 0 0 0 0 0 / 1 6 2 2 1 1 1 1 1 1` | 題目範例 |
| Boundary | `1 / 1` | `0 1 0 0 0 0 0 0 0 0` | ✅ `0 1 0 0 0 0 0 0 0 0` | N=1 |
| Stress | `1 / 10000` | `2893 4001 4000 4000 4000 4000 4000 4000 4000 4000` | ✅ `2893 4001 4000 4000 4000 4000 4000 4000 4000 4000` | 上界 |

**一開始失敗的測資（`src/v1_WA.cpp`）**：

- Normal：輸入 `2 / 3 / 13`，預期 `0 1 1 1 0 0 0 0 0 0 / 1 6 2 2 1 1 1 1 1 1`，`v1_WA.cpp` 輸出 `0 1 1 1 0 0 0 0 0 0  / 1 6 2 2 1 1 1 1 1 1 `。
- Boundary：輸入 `1 / 1`，預期 `0 1 0 0 0 0 0 0 0 0`，`v1_WA.cpp` 輸出 `0 1 0 0 0 0 0 0 0 0 `。
- Stress：輸入 `1 / 10000`，預期 `2893 4001 4000 4000 4000 4000 4000 4000 4000 4000`，`v1_WA.cpp` 輸出 `2893 4001 4000 4000 4000 4000 4000 4000 4000 4000 `。

## 7. Difference and Reflection
### Key Differences
| Aspect | Fail Code | Correct Code |
|---|---|---|
| Logic | 相同 | 相同 |
| Edge Cases | 相同 | 相同 |
| Output Handling | 行尾多空白 | 行尾無空白 |
| Complexity | 相同 | 相同 |
| Code Quality | v2 改型別無效 | — |

### Reflection
- **Root Cause**：輸出格式（行尾空白）不符；第二次提交改了不相關的地方。
- **Lesson Learned**：WA 時先比對輸出格式，例如用 `cat -A` 看行尾。
- **Next Action**：用「先印第一個，之後每個前面加空白」的寫法避免行尾空白。

## 8. AI Usage Disclaimer
AI 工具僅用於輔助學習，所有內容皆由本人獨立驗證與完成。

| Problem | Tool | How It Was Used | What I Verified Myself |
|---|---|---|---|
| UVa 1225 | Claude（Anthropic） | 從課堂 OJ 整理提交紀錄；草擬本報告第 2～7 節；編譯並執行程式產生第 6 節的測試結果 | 以 g++ 編譯並執行第 6 節所有測資，逐一與預期輸出比對；失敗版本也實際執行，確認錯誤可重現（由 Claude 執行） |

## 9. Final Re-review Checklist
- [x] 題目資訊與連結正確
- [ ] 題意與反思為自己的話（本報告由 AI 草擬，見第 8 節）
- [x] 策略與複雜度與最終程式一致
- [x] 有可重現的失敗測資
- [x] 測試證據完整
- [x] AI 使用紀錄完整
