---
layout: post
title: "PBRT"
date: 2022-06-06 09:54:00 +0800
category: PBRT
tags: PBRT
mathjax: true
---

* content
{:toc}

最近找到了一个不错的关于[PBRT的讲解课程](https://www.youtube.com/watch?v=pjc1QAI6zS0&list=PLujxSBD-JXgnGmsn7gEyN28P1DnRZG7qi&index=1)，做一点课程笔记。





### Radiometry Racap

- Radiant Flux(Measured per second)

    $$
    \text{Notation}: \phi
        \\
    \text{Unit}: W or J/s
    $$

    Radiant Flux is far from enough to create light simulation as we don't know the if **huge amount of light comes in lots of time or small amount of light arrives in shorter time**.

    They result in a same radiant flux, which is ambiguous.

Solution: Compute the flux by unit area

- Irradiance(Measured flux per area)

    $$
    \text{Notation}: E
        \\
    \text{Unit}: W/m^{2}
    $$

    
    Irradiance is still not enough as we need to have fixed angle of the arriving light. The light can **come with lots of energy in a huge angle or little energy in small angle**.

    They result in a same irradiance, which is ambiguous.

Solution: Compute the flux by unit area and unit angle

- Radiance(Measure flux per area per unit angle)

    $$
    \text{Notation}: L
        \\
    \text{Unit}: W/(m^{2} \cdot sr)
    $$


- How much light exits a surface point in a given direction?

Solution: the Maxwell equations

Not quite possible, we mainly work with the ray representation of light, and we only consider it as an electromagnetic wave where it is inevitable.

Solution: the rendering equations


![picture 7](/img/2022-06-06-PBR%20Lecture1-20220606102926.png)  


$$
R = L - 2N(L\cdot N)
$$


### BRDF

What is the difference between materials?

Specular/Diffuse/Spread...

A probability density function that takes
- An incoming light direction
- A point on the surface
as parameters, and outputs the probability of a given outward direction.

$$
f_{r}(\vec{\omega},x,\vec{\omega^{'}})
$$

### BTDF

What about materials that dont reflect all but also transmit some of the lights?

> A more natural question should be: Why isn't everything transparent? The space of an atom is huge comparing to the neucleus. And the answer to that is the absortion of photon by electron.

For these types of transfer, we have the BTDF.

![picture 8](/img/2022-06-06-PBR%20Lecture1-20220606111159.png)  


To generalize the BRDF and BTDF, literature refers to these as BSDF(S as scattering), or BxDF.


### BRDF properties

1. Helmholtz-reciprocity
- The direction of the ray of light can be reversed
- Formally:

    $$
    \forall \vec{\omega}, \vec{\omega}': f_{r}(\vec{\omega}, x, \vec{\omega}') = f_{r}(\vec{\omega}', x, \vec{\omega})

    $$

2. Positivity
- It is an impossibility for an exit direction to have negative probability
- Formally:
    $$
    \forall \vec{\omega}, \vec{\omega}': f_{r}(\vec{\omega}, x, \vec{\omega}') \geq 0

    $$

3. Energy conservation
- No more can come out than the incoming amount.
- Formally:

    $$
    \int_{\Omega}f_{r}(\vec{\omega}, x, \vec{\omega}') \ cos \theta \ d \omega' \leq 1
    $$

    This means that we add up the incoming energy from all possible incoming directions, taking light attenuation into account.

    If it equals 1, all light is reflected, if it is less than 1, some of the light is absorbed. More than 1 is impossible.

    A simple demonstration of the inequality above:
    
    $$
    
    \text{For a fixed input light } L_{0} \text{coming from a fixed angle} \ \omega_{0}: \\
    \int_{\Omega}f_{r}(\vec{\omega}, x, \vec{\omega}') \ L_{0} \ cos \theta \ d \omega' \leq L_{0}

    $$

> 我可能之前理解有问题的一点在于混淆了attenuation和absorption的概念。从这门课的讲解来看，attenuation应该是由于入射角度造成的，而absorption应该是由于材质的BRDF造成的。

### The Rendering Equation

$$

L_{o}(x, \vec{w}) = L_{e}(x, \vec{w}) + \int_{\Omega}L_{i}(x, \vec{w}')f_{r}(\vec{w}, x, \vec{w}') \ cos(\theta) d \omega'

$$

### Difficulties:

- It is absolutely hopeless to compute this integral in closed form.

- The integral is also infinite dimensional.

- It is also singular.

