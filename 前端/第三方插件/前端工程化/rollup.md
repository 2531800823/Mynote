# Rollup



## config

```js
// rollup.config.js
const commonjs = require('@rollup/plugin-commonjs');
const nodeResolve = require('@rollup/plugin-node-resolve');

module.exports = {
  input: './src/index.js', // 入口
  // 数组 可以打包多个格式
  output: [
    {
      format: 'cjs', // 打包格式
      name: 'liu', // name, 立即执行函数 打包完 最后给挂在到 window 上
      file: './dist/liu.cjs.js', // 出口
      globals: {
        lodash: '_', // 告诉 库对应的在项目中使用的变量
      },
    },
    {
      format: 'iife',
      name: 'liu',
      file: './dist/liu.iife.js',
    },
    {
      format: 'es',
      name: 'liu', // name
      file: './dist/liu.es.js',
    },
  ],
  
   //   排除哪些库打包。 和output 的 globals 对应
  	external: ['lodash'],
   plugins: [commonjs(), nodeResolve()],
};
```



### 插件

1. @rollup/plugin-node-resolve   打包第三方库 node_modules 下的 。

2. babel

   ```js
   // rollup.config.js
   // 依赖 @babel/core  @babel/preset-env
   const babel = require('@rollup/plugin-babel');
   module.exports={
       plugins: [babel(),terser()],
   }
   
   // bable.config.js
   module.exports = {
     presets: ['@bable/preset-env'],
   };
   ```

3. rollup-plugin-terser -- js代码压缩--- 直接使用

4. 处理css  rollup-plugin-postcss

   ```js
   // rollup.config.js
   // 处理css
   const postcss = require('rollup-plugin-postcss');
   const autoprefixer = require('autoprefixer'); // 给css添加前缀
   
   module.exports = {
       plugins: [ 
         postcss({
         	plugins: [autoprefixer()],
       	})
       ],
   }
   ```

5. typescript 支持ts  ts.config.ts自己设置

   ```js
   const typescript = require("@rollup/plugin-typescript");
   typescript({
           outDir: "es",
           declaration: true,  // 导出声明文件
           declarationDir: "es",
   }),
   ```

6. rollup-plugin-replace 配置环境变量

   ```js
   // 注入环境变量
   const replaceENV = require('rollup-plugin-replace');
   replaceENV({
         'process.env.NODE_ENV': JSON.stringify('development'),
   });
   ```

7. rollup-plugin-vue  打包 vue

   ```js
   const vue = require('rollup-plugin-vue')
    vue({
           // 处理 <style>
           css: true, 
           // 把 template 转成 function
           compileTemplate: true
    })
   ```

8. serve 开启一个服务

   ```js
   const serve = require('rollup-plugin-serve');
   serve({
         open: true, // 打开浏览器
         port: '8888',
         //   服务的文件夹
         contentBase: '.',
   }),
   ```

   



##### 打包格式

1. cjs commonjs
2. iife  立即执行函数
3. amd amd 格式
4. es es6 格式









### 打包

### 命令行

```shell
// -f 是打包成什么格式的。 -o 输出到文件下
npx rollup ./src/index.js -f cjs -o dist/bundle.js  
// 有配置文件
npx rollup -c
```

### 设置模块入口

```json
// package.json
{
  "main": "dist/cjs/index.js", // 打包后的文件
  "module": "dist/es/index.js",
  "types": "es/index.d.ts",
}
```





### 自定义插件

……
