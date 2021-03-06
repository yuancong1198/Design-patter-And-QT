#pragma once

/*
迭代器模式（Iterator）: 提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露该对象的内部表示。

背景：
	一个聚合对象，就是所谓的对象容器了；作为一个容器，都应该提供一种方法来让别人可以访问它的元素；但是，有的时候，
我是不希望遍历容器的人知道我的容器是如何实现的；那该怎么办？就像我在大学那样实现的链表，只提供了从头到尾的遍历，
如果我需要从尾到头的遍历呢？是不是我又要添加对应的方法了呢！！！
	容器的遍历方式千变万化，我们不知道需求是如何的，如果需求变了，那么我们的代码就会发生很大的改动，所以，我们需要去改变；
对于上面的代码，当我对同一个链表对象进行多次遍历时，是不是就出现了m_pCurrent对象混乱的局面呢？是的，这一切的一切，都说明，
我们必须去将一个容器的内部结构与它的遍历进行解耦，要是出现上面的情况时，我们就无法面对。就好比STL中的容器，
它将容器中对象的实现和遍历很好的解耦了，所以，我们就无法知道它的内部是如何组织对象数据的，同时，我们也可以按照我们自己的想法去遍历容器，
而不会出现任何差错。在我们的项目中使用迭代器模式就能很好的将容器对象的内部表示与对它的遍历进行解耦。

使用场合:
	访问一个聚合对象的内容而无需暴露它的内部表示；
	支持对聚合对象的多种遍历（从前到后，从后到前）；
	为遍历不同的聚合结构提供一个统一的接口，即支持多态迭代。

作用:
	它支持以不同的方式遍历一个聚合，甚至都可以自己定义迭代器的子类以支持新的遍历；
	迭代器简化了聚合的接口，有了迭代器的遍历接口，聚合本身就不再需要类似的遍历接口了。这样就简化了聚合的接口；
	在同一个聚合上可以有多个遍历，每个迭代器保持它自己的遍历状态；因此，我们可以同时进行多个遍历。

总的来说: 迭代器模式就是分离了聚集对象的遍历行为，抽象出一个迭代器来负责，这样既可以做到不暴露集合的内部结构，又可以让外部代码透明的访问
集合内部的数据。
*/