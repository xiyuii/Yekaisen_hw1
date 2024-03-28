# algebra
硬件技术团队编程基础作业
## 预修要求｜Requirements
修读过《C程序设计基础》、《线性代数》以及X·Lab硬件技术团队第一次内训或其对应的高阶课程。
## 说明｜Explainations
本题目的难度对于初学者而言相对较高，主要考察了基础的数学能力、通过编程解决问题的能力以及工程管理、CMake、git等综合能力。该作业的最终得分仅作参考，同学们可根据自己的能力来决定实现哪些函数。
## 题目背景｜Background
《线性代数》作为浙江大学工科多数专业必修的数学基础课程，对于其掌握是至关重要的，后续各大专业的专业课程也都离不开线性代数。然而，在后续的专业课程学习中，我们往往只需要计算一些矩阵的数值解，这个过程如果用手去计算的话是十分痛苦的。秉承着“我都学编程了就不要自己做一些无意义的事情”的原则，我们决定实现一个线性代数计算库，来辅助我们进行运算。
> 当然，如MATLAB、Python等高级编程语言已经可以做到这类事情，且做得更好，但这并不妨碍我们通过这样一种方式来锻炼自己的C语言编程能力。
## 题目介绍｜Introduction
本仓库给出了我们在内训中提到的工程模板，同学们要做的任务如下：
1. 自学git，注册GitHub账号，将本仓库在自己的GitHub账户下Fork一份，并按照`yourname_hw1`的格式更改仓库名称（在仓库中的Settings处可修改，记得不要用中文，仓库权限为public，如涉及到隐私保护，可设为private，但要将`tanninrachel@yinlin.wiki`这个账户设置为协作者）。
2. 将你的仓库clone到本地。
3. 根据`inc/algebra.h`中的注释和预定义，在`src/algebra.c`中实现对应的函数。
4. 根据内训所讲，自行编写`CMakeLists.txt`文件，使你的工程能够在本地成功编译运行。
5. 自学Markdown，修改`README.md`文件，需要包含你的实现思路（大致描述即可）以及本地运行截图。
6. 将你的修改提交到远程仓库，并将仓库链接提交（提交方式待定）。
## 思路参考｜Thinking
见`doc`文件夹。
## 交互格式｜Format
在本题目中，`main.c`文件已给出，不需要同学们自己实现，也请不要更改这个文件，否则可能出现判题错误。
### 输入格式
本题目采用帧判定的思路进行，每一帧的第一行输入帧数（从0开始），第二行输入两个整数$m_1,n_1$，分别为矩阵$\bm{A}$的行数和列数，接下来的$m_1$行，每一行输入$n_1$个双精度浮点数，为矩阵$\bm{A}$的元素值$a_{ij}$。之后的一行再次输入两个整数$m_2,n_2$，分别为矩阵$\bm{B}$的行数和列数，接下来的$m_2$行，每一行输入$n_2$个双精度浮点数，为矩阵$\bm{B}$的元素值$b_{ij}$。之后重复进行上述过程，帧数依次递增，如果输入帧数为-1，则程序终止，可能的一次运行输入如下：
```
0
3 3
1 2 4
2 5.1 3.3
1.4 2.3 7.8
3 3
1.3 2.4 7.9
1.1 2.3 4.8
1.3 2.4 9.7
1
2 2
1.1 2.1 
3.1 4.2
2 2
1 2 
3 7
-1
```
### 输出格式
在每一帧中，依次根据输入运行你的函数，依次输出$\bm{A}+\bm{B}$、$\bm{A}-\bm{B}$、$\bm{AB}$、$2\bm{A}$、$\bm{A}^{\mathrm{T}}$、$|\bm{A}|$、$\bm{A}^{-1}$、$\text{rank}(\bm{A})$、$\text{tr}(\bm{A})$的值，如果出现不符合计算要求的情况（如矩阵$\bm{A}$和$\bm{B}$的规模不满足计算要求或者矩阵$\bm{A}$不可逆的情况，则会检查你的输出错误信息是否符合要求，未出现上述情况则会将你的值与标准值进行比对。可能的一帧输出如下：
```
2.30    4.40    11.90   
3.10    7.40    8.10    
2.70    4.70    17.50   
-0.30   -0.40   -3.90   
0.90    2.80    -1.50   
0.10    -0.10   -1.90   
8.70    16.60   56.30   
12.50   24.45   72.29   
14.49   27.37   97.76   
2.00    4.00    8.00    
4.00    10.20   6.60    
2.80    4.60    15.60   
1.00    2.00    1.40    
2.00    5.10    2.30    
4.00    3.30    7.80    
0.07
459.86  -91.43  -197.14 
-156.86 31.43   67.14   
-36.29  7.14    15.71   
3
13.90
```
## 评分标准｜Standard
* 成功运行：+20分
* `create_matrix`、`add_matrix`、`sub_matrix`、`scale_matrix`、`transpose_matrix`、`trace_matrix`、`print_matrix`功能正常每个+5分
* `det_matrix`、`inv_matrix`、`rank_matrix`功能正常每个+15分
> 为了保证题目难度，每个函数具体的评分标准不予公布。
## 提交方式｜Submit
待定
## 截止日期｜Deadline
待定