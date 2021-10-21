# jQuery项目开发--第三方包

### zepto  高级 基于jquery 的工具库  有移动端事件



1. 下载 文档   

   > 带模块的文档 https://zeptojs.bootcss.com/
   >
   > 不带模块中文的 http://www.wenshuai.cn/Manual/Zepto/#core

### 滚动条 Nicescroll

1. 下载文档

   > 配置参数文档： https://www.cnblogs.com/lucas27/p/8138216.html
   >
   > 官网地址：http://www.areaaperta.com/nicescroll/
   >
   > 下载可以去 cdn

2. 滚动时一直报错

   ```javascript
   //在源码 搜索：
   (passiveSupported && active) ? el.addEventListener(name, fn, { passive: false, capture: bubble }) : el.addEventListener(name, fn, bubble || false);
   //替换成
   (passiveSupported && (active || el == window.document || el == window.document.body || el == window)) ? el.addEventListener(name, fn, { passive: false, capture: bubble }) : el.addEventListener(name, fn, bubble || false);
   ```

### 工具插件库 superslide  11年的东西不太好用

1. 下载文档	

   >  官网地址：http://www.superslide2.com/
   >
   >   效果图：http://www.superslide2.com/demo.html
   >
   >   代码案例：http://www.superslide2.com/downLoad.html  下载完之后解压，demo文件夹里面

### 动画运动曲线库 jquery-easing

1.  下载

   > ​	// 使用方法和运动曲线： https://blog.csdn.net/xiaolongtotop/article/details/8309635
   >
   > ​    // 插件下载地址：https://www.bootcdn.cn/jquery-easing/

### 图片懒加载 jquery.lazyload  14年

1.  下载 

   > https://cdn.bootcdn.net/ajax/libs/jquery_lazyload/1.9.7/jquery.lazyload.min.js

### 获取url路径  purl

1. 文档

   > 下载： npm install purl
   >
   > gitHub: https://github.com/codematix/purl
   >
   > 浏览器： 去cdn 下载

2. 实例

   ```js
   var url = purl(location.href);
   // url 是一个对象函数组  
    url.data()  // 具体参数解析都在这个里面 ， 里面 prarm.query = {id:10}
   
   // 在 jQuery 下 
    var url = $.url(http://127.0.0.1:5500/manage-system/client/edit.html?id=10);
    url.param("id")   //10
    url.data()  // 具体参数解析都在这个里面 ， 里面 prarm.query = {id:10}
   ```

   