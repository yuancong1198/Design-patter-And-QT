#pragma once

/*

策略模式（stratety pattern）：它定义了一系列算法，并将每一个算法封装起来，而且使它们还可以相互替换。
策略模式让算法的变化不会影响到使用算法的客户。
（原文：The Strategy Pattern defines a family of algorithms,encapsulates each one,and makes them interchangeable.
Strategy lets the algorithm vary independently from clients that use it.）



优点：

　　  1、 简化了单元测试，因为每个算法都有自己的类，可以通过自己的接口单独测试。
  　　2、 避免程序中使用多重条件转移语句，使系统更灵活，并易于扩展。
	  3、 遵守大部分GRASP原则和常用设计原则，高内聚、低偶合。

	缺点：
	　1、 因为每个具体策略类都会产生一个新类，所以会增加系统需要维护的类的数量。
	  2、 在基本的策略模式中，选择所用具体实现的职责由客户端对象承担，并转给策略模式的Context对象







*/