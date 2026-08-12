# LeetCode C++ 刷题项目

这个仓库用于 LeetCode 题目练习与验证。

项目目标：
用注册中心集中管理题目，启动后可直接查找并执行。扩展成本低。
- 题解代码和测试校验放在同一工程里，方便持续积累。
- 每道题独立实现，统一注册、统一运行。
- 通过修改一处字符串即可切换当前要运行的题目。


## Problem注册：ProblemRegistry

项目通过 `ProblemRegistry` 管理“题目名 -> 校验函数”的映射关系。

核心接口在 `src/ProblemRegistry.h`：
- `RegisterProblem(name, verify)`：注册题目。
- `GetProblems()`：获取所有已注册题目。
- `FindProblemByName(name)`：按名称查找题目。
- `ProblemRegistrar`：用于静态注册的辅助类。

工作流程：
1. 每个题目文件里实现算法和 `RunChecks` 校验函数。
2. 在该文件中定义一个全局 `ProblemRegistrar` 对象完成自动注册。
3. 程序启动时，所有已编译且已注册的题目进入注册表。
4. `main` 根据题目字符串查找并执行对应 `RunChecks`。

说明：
- 名称匹配对大小写和空白不敏感（内部会做规范化）。
- 只有“注册过”的题目才会出现在可运行列表中。

## 如何切换要运行的题目

在 `src/main.cpp` 中修改这一行：

```cpp
const std::string problem = "49.Group Anagrams";
```

把字符串改成已注册题目的名字即可，例如：
- `1. TwoSum`
- `2. AddTwoNumbers`
- `13.romanToInt`
- `49.Group Anagrams`

如果名称写错，程序会提示 `Problem not found` 并输出当前可用题目列表。

## 构建与运行
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\leetcode_app.exe
```


## 如何新增一道题

建议流程：
1. 在 `src/problem/` 新建文件，命名可参考 `题号.题名.cpp`。
2. 编写算法实现。
3. 编写 `RunChecks(std::string& message)`，返回 `true/false` 并写入结果信息。
4. 在文件末尾添加注册语句：

```cpp
ProblemRegistrar registrar("题号. 题目名", RunChecks);
```

5. 回到 `src/main.cpp` 修改 `problem` 字符串，运行验证。

说明：`CMakeLists.txt` 会自动收集 `src/problem/[0-9]*.cpp`，一般不需要手动改 CMake。

## Helper 说明

- `src/helper/VerifyHelper.h`：向量比较与差异输出辅助。
- `src/helper/ListNode.h`、`src/helper/ListNodeHelper.h`：链表题构造、转换、释放工具。
- `src/helper/TreeNode.h`：二叉树题可复用节点定义。

## 后续可迭代方向

- 给每道题补齐更强的测试用例（边界值、空输入、大数据量）。
- 为所有已实现题目补齐注册与统一输出格式。
- 增加 CI（例如 GitHub Actions）做自动构建检查。
- 按专题整理题目（哈希、双指针、链表、树、DP 等）。
