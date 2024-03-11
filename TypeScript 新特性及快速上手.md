# TypeScript 新特性及快速上手



## 数据类型

- 类型标注`:` 

- ```ts
  let num:any = 6;
  let name:string = 'johb';
  ```

> ts新增了一些數據類型

- #### Any
  
  - 不需要类型检查器对这些值进行检查而是直接让它们通过编译阶段的检查

- #### Void
  
  - 表示不是任何一种类型；只能赋值`Null`和`undefined` 

- #### Never
  
  - 表示永不存在的类型，可以赋值给任何类型，但任何类型都不能赋值给`Never`，即便是`any`

##### 类型断言

> ‘强制类型转换‘ 无需编译器检查白娘的类型，可自由改变

##### 使用方式 (推荐用as语法)

- 尖括号语法

```ts
let someValue: any = "this is a string";

let strLength: number = (<string>someValue).length;
```

- as 语法

```ts
let someValue: any = "this is a string";

let strLength: number = (someValue as string).length;
```

---

### TS中的模版语法 `${ }`  计算属性

```ts
class Student {
    fullName: string;
    constructor(public firstName, public middleInitial, public lastName) {
        this.fullName = firstName + " " + middleInitial + " " + lastName;
    }
}

interface Person {
    firstName: string;
    lastName: string;
}

function greeter(person : Person) {
    return "Hello, " + person.firstName + " " + person.lastName;
    //`hello,${person.firstName} ${person.lastName}`
}

let user = new Student("Jane", "M.", "User");

document.body.innerHTML = greeter(user);
```

### 接口

#### 通俗理解

- 为`object`类型建立一个对象，使该对象能够快捷地复用于程序中

#### 属性

- 必须属性：`label:string` 

- 可选属性：`attribute_name?:attribute`

- 只读属性：`readonly`

---

## 类





`public`修饰符是使得类中的成员（对象、方法）可以在类的内部和外部使用，但不是像全局定义那样任何地方都能使用。



# 
