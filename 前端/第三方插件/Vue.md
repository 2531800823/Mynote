# Vue

### vue.cli 完成自动注入less样式文件

> 解决问题：不用每次都要导入公用的样式到每个单独的文件中
>
> 直接使用 **vue.cli 的 style-resources-loader**  插件，完成自动注入到每个 style 标签中

1. 配置

   > 在当前项目下执行一下命令`vue add style-resources-loader`，添加一个vue.cli的插件
   >
   > 选择自己的 css 预处理器 Less
   >
   > ```js
   > // 成功后 在 成功后在 vue.config.js 自动添加配置 -》 自己修改配置
   > 
   > module.exports = {
   >   pluginOptions: {
   >     'style-resources-loader': {
   >       preProcessor: 'less',
   >       // 把要 自动注入的文件路径放到这里 ， 绝对路径
   >       patterns: [
   >         path.join(__dirname + '/src/assets/style/mixins.less'),
   >         path.join(__dirname + '/src/assets/style/variables.less')
   >       ]
   >     }
   >   }
   > }
   > ```
   >
   > 

### 官网推荐工具  ！！！

> 安装： npm i @vueuse/core
>
> 官网：https://vueuse.org/
>
> 其他阅读：！！https://blog.csdn.net/BLUESKYHOST/article/details/117082891
>
> 很厉害的工具库

实例： 还有很多好用的功能等着呢。。。。

```js
// 监听滚动事件
import { useWindowScroll } from '@vueuse/core'
setup(){
     const { x, y } = useWindowScroll()
     // 返回 y 轴滚动的距离， x轴滚动的距离
}
```

### Vue栅格栏 布局  vue-grid-layout

1. 官网

   > npm:  npm i vue-grid-layout
   >
   > 阅读：
   >
   > 1.  https://www.cnblogs.com/yasoPeng/p/9961732.html
   > 2. https://www.cnblogs.com/whoani/p/11377793.html
   >
   > 

### vue 懒加载  vue-lazyload

安装 npm i vue-lazyload

```js
import VueLazyLoad from 'vue-lazyload'  // 导入


// 注册 ， loading 添加懒加载的图片
Vue.use(VueLazyLoad, {
  loading: require("@/assets/placeholder.gif")
})
```

配置项：

| 钥匙              | 描述                      | 默认                                                         | 选项                                                         |
| :---------------- | ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `preLoad`         | 预载高度比例              | `1.3`                                                        | `Number`                                                     |
| `error`           | 加载失败时图像的 src      | `'data-src'`                                                 | `String`                                                     |
| `loading`         | 加载时图像的 src          | `'data-src'`                                                 | `String`                                                     |
| `attempt`         | 尝试次数                  | `3`                                                          | `Number`                                                     |
| `listenEvents`    | 你想让 vue 监听的事件     | `['scroll', 'wheel', 'mousewheel', 'resize', 'animationend', 'transitionend', 'touchmove']` | [所需的监听事件](https://www.npmjs.com/package/vue-lazyload#desired-listen-events) |
| `adapter`         | 动态修改元素的属性        | `{ }`                                                        | [元素适配器](https://www.npmjs.com/package/vue-lazyload#element-adapter) |
| `filter`          | 图像的侦听器过滤器        | `{ }`                                                        | [图像侦听器过滤器](https://www.npmjs.com/package/vue-lazyload#image-listener-filter) |
| `lazyComponent`   | 延迟加载组件              | `false`                                                      | [惰性组件](https://www.npmjs.com/package/vue-lazyload#lazy-component) |
| `dispatchEvent`   | 触发dom事件               | `false`                                                      | `Boolean`                                                    |
| `throttleWait`    | 油门等待                  | `200`                                                        | `Number`                                                     |
| `observer`        | 使用 IntersectionObserver | `false`                                                      | `Boolean`                                                    |
| `observerOptions` | IntersectionObserver 选项 | { rootMargin：'0px'，阈值：0.1}                              | [路口观察员](https://www.npmjs.com/package/vue-lazyload#intersectionobserver) |
| `silent`          | 不打印调试信息            | `true`                                                       | `Boolean`                                                    |