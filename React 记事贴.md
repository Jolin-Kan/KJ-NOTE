## React 记事贴

1. 在`JSX`中`{}`的内部是`JS表达式`不是`语句`  若要遍历数组，用`map`方法代替

2. 组件 (组件三大属性 `props` `refs` `state`)
   
   1. 函数式组件
   
   > 首字母大写 渲染时 render的参数为 <Component/> 且标签必须闭合(JSX规则)
   
   2. 类式组件 (暫時不管構造器)
      
      > 用于复杂组件（设计状态state）
      
      ```jsx
      class Mycomponent extends React.Component{
          render(){
              return{
              ......
              }
          }
      }
      ```

3. 
