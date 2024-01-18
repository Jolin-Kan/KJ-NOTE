## JavaScript 字符串和数组操作与函数笔记

### 字符串（Strings）操作与函数：

1. **创建字符串：**
   
   - 字符串可以用单引号 (`'`) 或双引号 (`"`) 包裹。
   
   ```javascript
   let str1 = 'Hello';
   let str2 = "World";
   ```

2. **字符串拼接：**
   
   - 使用 `+` 操作符进行字符串拼接。
   
   ```javascript
   let greeting = str1 + ' ' + str2; // 'Hello World'
   ```

3. **字符串长度：**
   
   - 使用 `length` 属性获取字符串长度。
   
   ```javascript
   let length = greeting.length; // 11
   ```

4. **访问字符：**
   
   - 使用索引访问字符串中的字符，索引从0开始。
   
   ```javascript
   let firstChar = greeting[0]; // 'H'
   ```

5. **字符串切片：**
   
   - 使用 `slice(start, end)` 方法截取字符串。
   
   ```javascript
   let slicedStr = greeting.slice(0, 5); // 'Hello'
   ```

6. **查找子字符串：**
   
   - 使用 `indexOf()` 或 `includes()` 方法查找子字符串。
   
   ```javascript
   let indexOfWorld = greeting.indexOf('World'); // 6
   let includesHello = greeting.includes('Hello'); // true
   ```

7. **替换部分字符串：**
   
   - 使用 `replace(oldStr, newStr)` 方法替换部分字符串。
   
   ```javascript
   let replacedStr = greeting.replace('World', 'Universe'); // 'Hello Universe'
   ```

8. **转换为大写/小写：**
   
   - 使用 `toUpperCase()` 和 `toLowerCase()` 方法。
   
   ```javascript
   let upperCaseStr = greeting.toUpperCase(); // 'HELLO WORLD'
   let lowerCaseStr = greeting.toLowerCase(); // 'hello world'
   ```

### 数组（Arrays）操作与函数：

1. **创建数组：**
   
   - 使用方括号 (`[]`) 创建数组。
   
   ```javascript
   let fruits = ['Apple', 'Orange', 'Banana'];
   ```

2. **访问元素：**
   
   - 使用索引访问数组中的元素，索引从0开始。
   
   ```javascript
   let firstFruit = fruits[0]; // 'Apple'
   ```

3. **数组长度：**
   
   - 使用 `length` 属性获取数组长度。
   
   ```javascript
   let numOfFruits = fruits.length; // 3
   ```

4. **添加元素：**
   
   - 使用 `push()` 方法向数组末尾添加元素。
   
   ```javascript
   fruits.push('Grapes');
   ```

5. **删除元素：**
   
   - 使用 `pop()` 方法从数组末尾删除元素。
   
   ```javascript
   let removedFruit = fruits.pop(); // 'Grapes'
   ```

6. **数组切片：**
   
   - 使用 `slice(start, end)` 方法截取数组。
   
   ```javascript
   let slicedFruits = fruits.slice(1, 3); // ['Orange', 'Banana']
   ```

7. **查找元素：**
   
   - 使用 `indexOf()` 或 `includes()` 方法查找元素。
   
   ```javascript
   let indexOfBanana = fruits.indexOf('Banana'); // 2
   let includesApple = fruits.includes('Apple'); // true
   ```

8. **连接数组：**
   
   - 使用 `concat()` 方法连接两个数组。
   
   ```javascript
   let moreFruits = ['Mango', 'Pineapple'];
   let combinedFruits = fruits.concat(moreFruits); // ['Apple', 'Orange', 'Banana', 'Mango', 'Pineapple']
   ```

这是一个简要的JavaScript字符串和数组操作与函数的笔记。这两个数据类型在JavaScript中非常常用，有很多强大的方法可以操作和处理它们。
