# Babel

## 安装

```shell
pnpm add babel-loader @babel/core -D 
```



### 配置

```js
// babel.config.js
module.exports = {
  presets: [
    [
        // 是一个智能预设，它可以将我们的高版本JavaScript代码进行转译根据内置的规则转译成为低版本的javascript代码。
      '@babel/preset-env', // 可以在 package.json 添加 "browserslist": "> 0.25%, not dead" 转换版本

      // 使用 polyfill 为 浏览器不支持的 新语法 来做填充
      // 安装  core-js regenerator-runtime , 或者下面 plugin @babel/plugin-transform-runtime
      // {
      //   // false 不用任何的 polyfill 相关的代码
      //   // usage 代码中需要哪些 polyfill 就引入相关 api
      //   // entry  根据 browserslistrc 目标导入所有的 polyfill,包会变大  需要在项目中引入 import 'core-js/stable'; import 'regenerator-runtime/runtime';
      //   useBuiltIns: 'usage',
      //   corejs: 3, // 指定 core-js  版本
      // },
    ],
    //   编辑 react 让jsx 转为 js
    ['@babel/preset-react'],
    // 使用 ts 转为 js
    ['@babel/preset-typescript'],
  ],

  plugins: [
    [
      '@babel/plugin-transform-runtime', // 需要 安装 babel/runtime-corejs3
      {
        corejs: 3,
      },
    ],
  ],
};
```



### [babel/preset-env](https://babeljs.io/docs/en/babel-preset-env)





### 插件

1. @babel/plugin-transform-arrow-functions 转换所有的箭头函数
2. @babel/plugin-transform-block-scoping  块级作用域转换 const let -> var
3.  @babel/preset-env 来对转换的规则做一个预设置，不然上面一个一个太烦  //  .browserslistrc  来生成
4. @babel/preset-react react 的转换 ， 需要 babel 里面 pligin -> react-refresh-babel



### 自定义插件

……
