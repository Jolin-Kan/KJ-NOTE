# Java学习指南

## 1. Java基础

### 1.1 变量和数据类型

- Java中有不同类型的变量，如整型、浮点型、布尔型和字符型。
- 示例代码：
  
  ```java
  int num = 10;
  double pi = 3.14;
  boolean isTrue = true;
  char ch = 'A';
  ```

### 1.2 运算符

- Java中有多种运算符，包括算术运算符、关系运算符和逻辑运算符。
- 示例代码：
  
  ```java
  int a = 5;
  int b = 3;
  int sum = a + b; // 算术运算符
  boolean result = (a > b) && (a != b); // 关系运算符和逻辑运算符
  ```

### 1.3 流程控制

- Java提供了if语句、switch语句、for循环和while循环等控制语句。
- 示例代码：
  
  ```java
  int num = 10;
  if (num > 0) {
      System.out.println("Positive number");
  } else {
      System.out.println("Negative number or zero");
  }
  ```

### 1.4 方法

- Java中的方法可以用来封装一段代码，并且可以接受参数并返回值。
- 示例代码：
  
  ```java
  public class Calculator {
      public int add(int a, int b) {
          return a + b;
      }
  }
  ```

## 2. 面向对象编程（OOP）

### 2.1 类和对象

- 类是Java程序的基本单元，它定义了对象的属性和行为。
- 示例代码：
  
  ```java
  public class Person {
      String name;
      int age;
  }
  ```

### 2.2 封装、继承和多态

- 封装：通过使用访问修饰符来限制对类的访问，提高代码的安全性。
- 示例代码：
  
  ```java
  public class Car {
      private String color;
      public String getColor() {
          return color;
      }
      public void setColor(String newColor) {
          color = newColor;
      }
  }
  ```

在Java中，`public` 是一种访问修饰符（Access Modifier），用于修饰类、方法、变量等，表示被修饰的成员可以被任何其他类访问。具体来说：

1. **对于类：** 使用 `public` 修饰的类可以被任何其他类访问，无论这些类是否在同一个包中。

```java
public class MyClass {
    // 类的成员和方法
}
```

2. **对于方法：** 使用 `public` 修饰的方法可以被任何其他类调用，无论这些类是否在同一个包中。

```java
public void myMethod() {
    // 方法体
}
```

3. **对于变量：** 使用 `public` 修饰的变量可以被任何其他类访问，无论这些类是否在同一个包中。

```java
public int myVariable;
```

需要注意的是，当一个Java源文件中只能包含一个 `public` 类，并且该类的名称必须与文件名相同。其他非 `public` 的类可以有多个，但是它们的名称不能与文件名相同。

例如，如果有一个名为 `MyClass.java` 的Java文件，其中包含一个 `public` 类 `MyClass`，那么只能有一个 `MyClass` 类，并且该类的名称必须是 `MyClass`。但是可以有其他非 `public` 的类，其名称可以是不同的。



除了 `public` 外，Java 还有三种访问修饰符，分别是 `private`、`protected` 和默认访问修饰符（package-private）。

1. **private：** 使用 `private` 修饰的成员只能在声明它们的类内部访问。其他类无法直接访问 `private` 成员。

```java
public class MyClass {
    private int myPrivateVariable;
    private void myPrivateMethod() {
        // 方法体
    }
}
```

2. **protected：** 使用 `protected` 修饰的成员可以被同一个包中的其他类访问，也可以被子类访问，无论子类是否在同一个包中。

```java
public class MyClass {
    protected int myProtectedVariable;
    protected void myProtectedMethod() {
        // 方法体
    }
}
```

3. **默认访问修饰符（package-private）：** 如果不使用任何访问修饰符，默认情况下，成员具有包范围（package scope），即只能被同一个包中的其他类访问，而不能被不同包中的类访问。

```java
class MyClass {
    int myPackagePrivateVariable;
    void myPackagePrivateMethod() {
        // 方法体
    }
}
```

需要注意的是，当类的访问修饰符为默认（package-private）时，类只能被同一个包中的其他类访问，不能被不同包中的类访问。

## 3. 异常处理

### 3.1 异常的类型

- Java中的异常分为编译时异常和运行时异常。
- 示例代码：
  
  ```java
  try {
      int result = 10 / 0;
  } catch (ArithmeticException e) {
      System.out.println("Error: " + e.getMessage());
  }
  ```

### 3.2 异常处理机制

- 使用try-catch块来处理异常，可以捕获并处理程序运行时可能发生的异常。
- 示例代码：
  
  ```java
  try {
      // 可能发生异常的代码
  } catch (Exception e) {
      // 异常处理代码
  } finally {
      // 无论是否发生异常都会执行的代码
  }
  ```

## 4. Java标准库

### 4.1 字符串处理

- Java提供了丰富的字符串处理方法，如获取字符串长度、提取子串等。
- 示例代码：
  
  ```java
  String str = "Hello, World!";
  int length = str.length(); // 获取字符串长度
  String substr = str.substring(0, 5); // 提取子串
  ```

### 4.2 集合框架

- Java中的集合框架提供了一组类来实现各种类型的数据结构，如列表、集合和映射等。
- 示例代码：
  
  ```java
  ArrayList<String> list = new ArrayList<>();
  list.add("Java");
  list.add("Python");
  list.add("C++");
  ```

### 4.3 文件操作

- Java提供了一系列的类来处理文件操作，如读取文件、写入文件等。
- 示例代码：
  
  ```java
  try {
      FileInputStream fis = new FileInputStream("input.txt");
      int data;
      while ((data = fis.read()) != -1) {
          System.out.print((char) data);
      }
      fis.close();
  } catch (IOException e) {
      e.printStackTrace();
  }
  ```

### 4.4 网络编程

- Java中的网络编程可以实现客户端和服务器之间的通信连接，使用Socket类来实现。
- 示例代码：
  
  ```java
  try {
      Socket socket = new Socket("localhost", 8080);
      // 连接到服务器后的操作
      socket.close();
  } catch (IOException e) {
      e.printStackTrace();
  }
  ```

## 5. 多线程编程

### 5.1 线程的创建和启动

- Java中的线程可以通过继承Thread类或实现Runnable接口来创建。
- 示例代码：
  
  ```java
  class MyThread extends Thread {
      public void run() {
          System.out.println("Thread running...");
      }
  }
  ```

### 5.2 线程同步和互斥

- 多线程编程中需要注意线程同步和互斥的问题，可以使用synchronized关键字来实现。
- 示例代码：
  
  ```java
  class Counter {
      private int count = 0;
      public synchronized void increment() {
          count++;
      }
      public synchronized int getCount() {
          return count;
      }
  }
  ```

---





## 6. Java编程实践

### 6.1 项目实战

- 通过完成小型项目来应用所学知识，如学生信息管理系统、图书馆管理系统等。
- 示例代码：略

### 6.2 练习题目

- 完成一些编程练习题目，提升编程能力和解决问题的能力。
- 1. 编写一个Java程序，计算两个整数的和、差、积和商。
  
  2. 编写一个Java程序，判断一个数是否为素数。
  
  3. 编写一个Java程序，找出一个整数数组中的最大值和最小值。
  
  4. 编写一个Java程序，统计一个字符串中各个字符出现的次数。
  
  5. 编写一个Java程序，实现冒泡排序算法对一个整数数组进行排序。
  
  6. 编写一个Java程序，将一个字符串反转。
  
  7. 编写一个Java程序，实现斐波那契数列的计算。
  
  8. 编写一个Java程序，实现一个简单的学生信息管理系统，包括添加学生、删除学生、查询学生信息等功能。
  
  9. 编写一个Java程序，实现一个简单的图书馆管理系统，包括添加图书、借阅图书、归还图书等功能。
  
  10. 编写一个Java程序，模拟实现一个简单的计算器，包括加法、减法、乘法和除法等功能。
