
### SSD Criterion

---
[Illustration of SSD criterion](https://www.researchgate.net/figure/The-illustration-of-the-SSD-criterion-for-image-registration-The-panels-A-B-show-the_fig5_312274491)

![[Pasted image 20220316172103.png]]
	本式中应该是将一个式子写了两遍：
	最开始的$(T*I)$应该是代表T所代表的Transformation对I的变换之后形成的新的Image
	
>Taking into account the fact that the image I deformed by T is I ◦ T^(-1) (and not I ◦ T )

这里我们得考虑清楚为什么是I ◦ T^(-1)，假设deformed之后的Image为I'，在deform之前，一个像素点x对应的像素应该是I(x)，那么deform之后，这个像素点对应的位置应该变成了T(x)，而对应的像素点应该是I'(T(x))，显然，我们可以列出等式：
$$
I(x) = I^{'} ◦ T (x)
$$
（这里实际上少了一部分关于函数算子T的性质论证，可以考虑在哪里找出来，T到底是不是双射呢，如果是的话显然是有逆算子的，但是这里我们先假定存在一个$T^{-1}$）
因此显然
$$
I^{'} = I ◦ T ^{-1}
$$
---
![[Pasted image 20220316173248.png]]

这里第一个式子比较显然，因为如果以I为基准register J的话，那么这里的算子就是$T^{-1}$。