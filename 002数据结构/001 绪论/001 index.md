> 45分
>
> - 11个选择题 22分
> - 2个应用题 13+10 23分



数据结构三要素

- 逻辑结构
  - 集合
  - 线性结构
  - 树形结构
  - 网状结构
- 存储结构
  - 顺序存储
  - 链式存储
  - 索引存储
  - 散列存储
- 数据运算
  - 运算的定义是针对逻辑结构的
  - 运算的实现是针对存储结构的





## 时间复杂度

### 0 补充

等差数列求和公式
$$
S_n = \frac{n * (a_1 + a_n)}{2}
$$
等比数列求和公式



### 1. 单层循环



#### 1.1 线性复杂度

while循环

```cpp
int i =1; 
while(i<n)
    i++;
```

for循环

```cpp
int m = 0;
for(int i=0; i<n;i++)
{
    m++;
}
```

时间复杂度 $O(n)$

#### 1.2 对数复杂度

```cpp
int m = 0;
for(int i=0; i<n; i*=2){
    m++;
}
```

假设需要执行 t 次结束循环.则$2^t = n $ $\Rightarrow t = \log_2 n$

所以时间复杂度是 $O(\log n)$



#### 1.3 方根时间复杂度

```cpp
int m = 0;
for(int i=0; i*i<n; i++){
    m++;
}
```

假设需要执行 t 次结束循环.则$t^2 = n $ $\Rightarrow t = \sqrt{n}$

所以时间复杂度是 $O(\sqrt n)$​



```cpp
int m = 0;
for(int i=0; i*i*i<n; i++){
    m++;
}
```



假设需要执行 t 次结束循环.则$t^3 = n $ $\Rightarrow t = \sqrt[3]{n}$

所以时间复杂度是 $O(\sqrt[3] n)$



### 2. 多层循环

#### 2.1 嵌套指针无关

j指针和i指针无关：

```cpp
for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
        // other code
}
```

时间复杂度 $O(n) * O(n) = O(n^2)$



```cpp
for(int i=0; i*i<n; i++)
{
    for(int j=0; j*j<n; j++)
        // other code 
}
```

时间复杂度 $O(\sqrt{n}) * O(\sqrt{n}) = O(n)$



#### 2.2 嵌套指针相关



```cpp
for(int i=0; i<n; i++)
{
    for(int j=0; j<i; j++)
        //other code
}
```

时间复杂度$O(n) * O(n) = O(n^2)$

严格计算如下:
$$
\sum_{i=0}^{n-1}\sum_{j=0}^{i-1} 1= \sum_{i=0}^{n-1}i = \frac{n(n-1)}{2} = O(n^2)
$$




```cpp
for(int i=0; i*i<=n; i++)
{
    for(int j=0; j<=i; j++)
        // other code
}
```

时间复杂度$O(n)$

严格计算如下:
$$
\sum_{i=0}^{\sqrt{n}} \sum_{j=0}^{i}1 = \sum_{i=0}^{\sqrt{n}}i = \frac{\sqrt{n}*(0+\sqrt{n})}{2} = O(n)
$$









