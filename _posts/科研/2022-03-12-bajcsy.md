
Bajcsy, R., & Kovačič, S. (1989). Multiresolution elastic matching. _Computer vision, graphics, and image processing_, _46_(1), 1-21.
这篇文章中将registration描述为matching，而non-rigid描述为locally variant。
> The assumption underlying elastic matching approach is that all normal brains, at least at a certain level of representation, have the same topological structure, but may differ in shape details.

> We do not try to explain deformations biologically. The measurement of biological shape and shape change can be found in [9, 10]

The author mentioned that the measurement of biological shape is provided. Then do we need to use different metrics for cloth?

> Dengler [15] developed a dynamic pyramid for solving the correspondence problem in moving image sequences, where the physical model of the elastic membrane is combined with a multilevel technique.

This reference may well explain my confusion about "pyramid" and "multi-level". Also pay attention to this paragraph as the author stated some effort form the field of computer graphics and computer vision.

> When the relative positions of particles in a continuous body are altered, we say that the body is strained and the change in the relative position of points is a deformation [22]. A nondeformable, or rigid body, is only an abstraction of the real world for which the distance between every pair of its particles remains invariant throughout the history of the body. All material bodies are to some extent deformable. Deformations maybe local or global, small or large, elastic or plastic. The elastic matching considered in this paper models small local elastic deformations. Such an elastic matching model was introduced and developed by Broit [5].

In this paragraph the author gives rather strict definitions of deformation and models. It should be noted that this kind of model was developed by Broit.

所以这篇文章中的Resolution更像是指代物体本身的大小？