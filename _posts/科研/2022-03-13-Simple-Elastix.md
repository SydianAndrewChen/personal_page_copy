---
layout: post
title: "Simple Elastix"
date: 2022-03-12 15:00:00 +0800
---


### 入门

https://simpleelastix.readthedocs.io/Introduction.html

从SimpleElastix看几个Registration的区别

首先，关于Registration。最简单情况下的Registration应该是输入两个内容为相同对象的图片$I_{M}$$I_{F}$，判断这个对象是如何从第一个图片经历怎样的变换到了第二个图片的状态的。
$$
\min_{x \in Image} \ C(I_{F}(x),I_{M}(T(x)))
$$
> This simply means that the optimizer adjusts the parameters of the transform in a way that minimizes the difference between the two images.


将会采用梯度下降法进行优化。


从几个方面讨论了整个Registration可配置的部分。

Image Pyramids：其实没有特别看懂究竟是指什么，应该是指如果输入图片分辨率不同的话会做怎样的处理来对齐分辨率？那为什么要叫做Image Pyramid呢。

Mask：应该是指通过Mask将无用的信息去掉，只关注Substructure的对齐。

Transforms：Transform的选择很关键。常见的transform有：translation, rigid, Euler, affine, b-spline, Spline-kernel。其中B-Spline和Spline-kernel是用于Non-rigid的。对于不同的transform，我们可以简单将它们按照DOF(自由度)去划分，像是translation就有3 DOFs，affine是12 DOFs（SRT），以及B-Spline可能有数量更加庞大的自由度，以及甚至有其他不需要参数的方法，自由度更加庞大。

Metrics：同样的，挑选不同的similarity measure也会有不同的影响。

Optimizer：指的是不一定必须要用梯度下降进行优化，还有很多其他的优化策略

Samplers：在评估similarity的时候需要对两个图片进行采样，这里的采样策略也会对最终的收敛速度有影响。

Non-rigid Registration：什么是Free-form Deformation(FFD) Field？