工作报告
===

> ***
> 王心注 北京-都柏林国际学院 17372130
> 第二周（01.22-01.28）
> ***



+Day 1
---

1. 尝试了 marathon coding 2 ，比第一次还惨，一个都没写出来。认识到自己在基础上仍有不少暗病，在数据结构上欠缺较多。（3 h）

+Day 2
---

1. L1-007 直接对输入及时处理，预读一位判断是否输出空格。（0.3 h）

2. L1-008 忘记对数字输出完后是否输出/n进行判断，格式错误一次。（0.5 h）

3. L1-009 有侥幸心理，最后再来化简。测试数据太大溢出，浮点错误。（0.6 h）

+Day 3
---

1. L1-009 改为模拟运算，每一步都化简，AC。（0.3 h）

2. L1-010 以后注意看输出格式啊，多了个空格。（0.2 h）

3. 在sublime上搭的markdown出错，无法markup export，抢救失败。换用之前在atom上搭的markdown系统进行markup。（0.5 h）

4. sublime自动编译系统出bug，显示Finished但实际并没有编译成功（并且没有报出错误在哪），懒得弄了。（0.1 h）

+Day 4
---
1. L1-011 用了&lt;string&gt;编译无法通过，原因是缺codecvt_specializations.h（0.3h）
<br /><img src="/pic/2.png"  alt="(这里其实有张图。。。)" />

2. 调试g++，重装多次仍缺文件，直接下载该文件后编译输出一堆报错，已确认MinGW为最新版。（1 h）

3. L1-011 查明 codecvt_specializations.h 是由&lt;iostream&gt;引用的，换用&lt;cstdio&gt;。大量报错是&lt;string&gt;引起的，换用&lt;cstring&gt;和char数组。下标码值AC。（0.5 h）

4. L1-011 水题，但是我的MinGW彻底炸了，题都AC了本地编译过不了（0.1 h）

+Day 5
---

1. L1-012 水题（0.1 h）

2. L1-013 仍旧水题，还以为 long long 装不下，结果测试数据没那么大。（0.2 h）

3. ATOM 也挺废的，虽然即时编译挺好用。。。。。。
<br /><img src="/pic/3.png"  alt="(这里其实有张图。。。)" />

4. L1-014 简单题。。。（0.1 h）

5. L1-015 学到了，之前都用 Round() ，但是遇到 0.5 就看脸。原来还有 (n + 1) / 2 这种操作（0.5 h）

+Day 6
---

1. 听课听课，还想做L2呢。（1.5 h + 1 h）

+Day 7
---

1. 整理 OneNote 笔记及 ANKI 卡片（2 h）

总结
---

<br /><img src="/pic/1.png"  alt="(这里其实有张图。。。)" />

#### 又一周过去了？！！！

### 以上
