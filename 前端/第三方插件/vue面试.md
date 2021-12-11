### Vue是什么

> 是一套渐进式框架，与其他框架不同的是，Vue可以自底向上逐层应用，vue核心只关注视图层，容易上手，方便与第三方库整合，可以完成复杂的单页面应该提供驱动

### Vue的优点

> 1. 轻量级框架：只关注视图，构建视图的集合
> 2. 简单易学，中文文档没有语言障碍
> 3. 双向数据绑定，操作数据简单
> 4. 组件化，构建单页面应该有优势
> 5. 视图数据分离，使用数据更方便
> 6. 虚拟DOM，原生dom操作很费性能

### Vue的基本原理

> 创建实例时，遍历 data 用 **Object.defineProperty()** （vue3 使用 proxy）将他们转为 getter/setter，并且在内部跟踪，每个组件实例都有 watcher 程序， 属性发生变化时，会通知 watcher 重新计算，然后更新组件

### 双向数据绑定

> vue 是采用 **数据劫持** + **发布者-订阅制模式**  的方式，通过 **Object.defineProperty** 来劫持 所有属性的 setter/getter , 在数据有变化，发布消息给订阅制，触发响应的 事件监听（watcher）回调。

### 使用 Object.defineProperty 的缺点

> 通过下标方式修改数组数据，或者给对象增加属性，不可以触发渲染，因为Object.defineProperty 拦截不到这些操作， 大部分的数组都拦截不到， vue 内部通过重写函数的方式 解决了，数组改数据 ：push，pop，shift，unshift，splice，sort，reverse
>
> vue3  使用了 proxy 对对象进行代理， 实现数据劫持，使用 proxy 的好处，可以完美监听数据的改变，并可以深度的监听数据， 唯一的缺点就是 兼容问题：**Proxy**是Es6 语法

### MVC  

> 1.  mvc 通过 model , view 和 controller 的方式组织代码结构，view负责页面显示，model负责存储业务数据和相应数据操作，并且view和model 使用了观察者模式
> 2.  当 model 改变时 通知 有关 view 更新页面，controller 是view 和 model的纽带，通过  view 来 对 model 更改，然后 model 再去通知 view 更新，过程都是单向的

### MVVM

> 1. model 代表数据模型，view 代表UI视图， view,model 负责 监听model的变化控制视图，视图变化 通知数据， 
> 2. view 和 model 没有关系，是通过viewmodel 来进行联系的
> 3. 缺点
>    - 难调试，大模块，使用方便和保证数据的一致性，但不释放内存造成很多开销
>    - 大的图形应用程序 ， 视图装太多，viewmodel构架维护成本高

### MVP

> 1. 和 MVC 唯一不同的 在于 Presenter 和 Controller ，MVC在model 发生变化的时候，通知 view ，view 和 model 偶合在一起，逻辑复杂的时候，代码可能造成混乱，并对复用造成一些问题
> 2. MVP 通过 Presenter 来实现对 view 来实现，model 的解耦，MVC 中Controller 只知道 model 的接口， 没办法控制 view 的更新，MVP 通过 View 暴露给 Presenter将model 和 view 绑定到一起，实现 view 和 model 的同步更新

### Vue 性能优化

> 1. ##### 编码阶段
>
>    - 尽量减少data中数据，因为用增加 getter 和 setter, 会收集到 watcher
>    - v-if 和 v-for 不一起使用
>    - v-for 尽量使用 事件代理
>    - SPA（单页面应用）采用 keep-alive 缓存
>    - key 保证唯一
>    - 使用路由懒加载，异步组件
>    - 防抖节流
>    - 第三方模块按需导入
>    - 长列表滚动到可视区再加载
>    - 图片懒加载
>    
>2. ##### SEO 优化
> 
>   - 服务端 渲染 SSR
> 
>3. ##### 打包优化
> 
>   - 压缩代码
>    - 使用 cdn 加载第三方模块
>    - Tree Shaking/Scope Hoisting （摇树优化）/ (作用域提升)
>      - 摇树：依赖ES6导入， 直把用到的方法放到 build中，没用到的 擦除，立即执行函数无法擦除，可以装`npm i purgecss-webpack-plugin -D` 擦除无效的css(要配置)
>      - 作用域提升：将所有模块按照代码引入顺序放在一个函数作用域里，然后适当重命名防止变量冲突，减少函数声明和内存开销
>    - 多线程打包 happypack 
>      - 使用插件 happypack 
>    - splitChunks 抽离公共文件
>      - webpack 把公用的代码 单独提取成一个文件
>    - sourceMap 优化
>      - webpack 代码映射技术，通过映射可以追踪到源代码的报错
> 
>4. ##### 用户优化
> 
>   - 骨架屏
>    - PWA
>      - 首屏可以部署在服务端，响应式界面，沉浸式体验（在支持 PWA 的浏览器和手机应用上可以直接将 Web 应用添加到用户的主屏幕上）
>    - 使用 缓存优化（客户端，服务端缓存）： 协商缓存，强制缓存。 服务端开启 gzip 压缩

### 如何提升单页面(spa  single page app)应用首屏加载速度

> 1. 减小入口文件
> 2. 静态资源本地缓存
> 3. 图片资源压缩，合并（精灵图）
> 4. 开启 gzip 压缩包
> 5. 、使用服务器渲染

### Vue 初次渲染

> 1. 步骤 ：
>    1.  $mount ()  : 初始化 Vue
>    2. mountComponent :   （渲染的入口函数）
>    3. _render:（执行render函数，获得虚拟DOM）
>    4.  __update:（将虚拟DOM转真实DOM并渲染）

### Computed 和 Watch

> computed 
>
> 1. 支持缓存，依赖的数据发生变化才会重新计算
> 2. 不支持异步，当有计算属性的时候，无法监听数据变化
> 3. 默认走缓存，基于依赖的响应式进行缓存，或者 父组件传递过来的props 的数据进行计算
> 4. 可以使用 getter 和 setter 方法更灵活
>
> watch 
>
> 1. 不支持缓存，数据变化 会触发响应的操作
> 2. 支持异步监听，两个参数，一个是最新的值，第二个是旧值
> 3. 当一个属性发生变化就做像一个的操作
> 4. immediate: 立即监视， deep : 深度监视 ， handle: 监听函数
>
> 使用场景：
>
> 1.   计算 当进行计算，可以依赖缓存特性，避免每次都要计算
> 2.   当需要数据变化时 执行异步，或者 开销较大时，使用 watch , 限制执行该操作的频率，得到最终结果前，设置中间状态（防抖），计算属性不行

### watch只监听对象上的想监听属性，如何排除其他属性监听 

```js
// 可以 直接监听   "params.a":{...}

data() {
    return {
      params: {
        a: 1,
        b: 2,
      },
    };
  },
  mounted() {
      // 遍历所有的对象属性， 筛选出要监听的属性
    Object.keys(this.params)
      .filter((item) => {
        return item === "a";
      })
      // 遍历要监听的数组
      .forEach((item) => {
        // 用 vue 实例的 watch 开启监听
        // $watch 参数1 要监听的属性， 2 监听的处理函数， 3 配置项， 可以深度和立即监听
        this.$watch(
          (vm) => {
            vm.params[item];
          },
          this.watchFun,
          {
            deep: true,
          }
        );
      });
  },
  methods: {
    edit() {
      this.params.a = 10;
      this.params.b = 10;
    },
    watchFun() {
      console.log("对象单独属性更新");
    },
  },
  watch: {
    // params: {
    //   deep: true,
    //   handler() {
    //     console.log("更新了");
    //   },
    // },
  },
```

### slot

> 是 vue 内容分发机制，插槽是子组件的一个模板标签  ，这个标签由父组件决定，有默认插槽，具名插槽和作用域插槽
>
> 1. 默认： 匿名插槽，slot 没有 name 属性值的时候显示 默认的，一个组件只能有一个匿名
> 2. 具名：带有名字的插槽，可以有多个
> 3. 作用域: 可以有名字也可以无，不同点，在子组件渲染时，可以将子组件内部的数据传递给父组件，父组件根据子组件的数据决定如何渲染

### vue 的 hook 使用

1. 清除定时器

   ```js
    // 清除定时器
    const timer = setInterval(() => {
    console.log(1);
    }, 1000);
   // $once 监听，只触发一次 
   // 使用 hook 调用 销毁前的生命周期函数 清空定时器
    this.$once("hook:beforeDestroy", () => {
    clearInterval(timer);
    });
   ```

2. 父组件监听子组件的声明周期函数

   ```vue
   // 1. 用 $emit 监听
   	// 父组件
   	 <!-- 监听子组件的 mounted 事件 -->
       <DomeChilred @changeMount="changeMount" /> // 监听处理 changeMount
       // 子组件
       mounted() {
   		// 子组件声明周期 触发 就像父组件发信号
       	this.$emit("changeMount", "监听成功");
       },
   // 2. 使用 hook 监听 --》 缺点是不可以携带子组件的参数到父组件
   	// 父组件
       <!-- 使用 hook -->
       <DomeChilred @hook:mounted="changeMount" />
        changeMount() {
             console.log("子组件触发了 mounted");
           },
   	// 子组件 不用操作
   ```

### 保存页面（组件）当前状态

> 两种情况。组件会被卸载 和不会被卸载
>
> ###### 卸载
>
> 1. 将状态存在：LocalStorage / sessiconStorage,卸载组件 就在 beforeDestroy 存进去，进入页面的时候加一个  flag 判断是否用缓存数据，
>    - 优点：兼容好，不用库，简单，
>    - 缺点：JSON转字符串 是深拷贝，function 不会保存，Date,和正则 不是原来的值，flag不好控制，容易失效
> 2. 路由传值：通过路由传参，可以实现简单的路由传值  
>    - 优点：简单，不污染localstorage... 可以传递Date正则（弥补上面） 
>    - 缺点：跳转别的组件也带着数据
>
> ###### 不被卸载
>
> 1. 要切换的组件是子组件，父组件中正常存储页面状态 ，可以用  <keep-alive> 来缓存页面 组件在切换 调用 **activated** 和 **deactivated** 声明周期函数
>    - 优点：代码量少，不需要考虑状态传递的错误
>    - 缺点： 增加 父组件的维护成本 、 需要传递props  到子组件， 无法利用路由定位页面

### keep-alive 动态组件 缓存

> ##### 参数:
>
> - include    字符或正则，只有匹配到的缓存 - 白名单
> - exclude    字符 | 正则 ， 匹配到的不缓存 -  黑名单
> - max        number  可以缓存多少

```vue
<!-- 基本 --> 
<transition>
    <keep-alive>
<!-- 缓存 + 动态  可以 if 判断 + transiton(动画) 一起-->
      <component :is="view"></component>   
    </keep-alive>
</transition>
```

> 让组件 + 2个声明周期， activated 激活， deactevated 失活
>
> beforeDestroy 和 destroyed  不在触发

### 常用的事件修饰符

> 1.   **.stop** ==> **event.stopPropagation()**   **阻止事件冒泡**
> 2.   **.prevent**   ==>  **event.preventDefault()**  取消默认事件，不停止传播
> 3.   **.capture**     ==>  事件捕获
> 4.   **.self**    ==>   只触发自己范围内的事件， 不包含子元素
> 5.   **.once**  ==> 只会触发一次

### v-if、v-show、v-html 

> 1. v-if  懒惰的， 第一次是 false 就不加载，切换时 标签创建销毁， 在虚拟 dom 操作，开销比 v-show 大  原理： VNode 不会生成
> 2. v-show 直接创建 显示和隐藏都是用 css display 来控制的，直接生成，在用 display:none隐藏
> 3. v-html : 先移除节点下的所有节点，在 innerHTML 添加 ， **可能会导致 xss 攻击**，**里面的样式还有使用 /deep/ 穿透**
>    - 使用场景，v-show 适合频繁切换

### data 为什么不是函数

> 使用多个组件复用时，都使用data对象中数据，形成变量污染，主要是隔离作用域，让每个组件都有自己的数据

### vue重置data或者获取data初始值

```js
// 初始值的 data
console.log(this.$options.data());
// 当前的 data
console.log(this.$data);
```

### LRU 缓存策略

> 在内存中找出 最久没有使用的数据，换新数据 ， LRU 算法根据数据的历史记录进行淘汰，最常见的是一个链表保存数据缓存 ， 详细实现：
>
> - 新数据插入到链表头部
> - 每当缓存数据被访问，则数据移到链表头部
> - 链表满了将链表尾部数据丢弃

### $nextTick 

> - 本质是对 js 执行原理  EventLoop 的一个应用，模拟对应的 宏/微  任务的实现，用 js 的异步 来执行  vue 的异步
> - 在下次渲染完成调用，可以获取最新的DOM元素

### \$set  $delete

```js
// 给对象或者数组添加一个响应式数据  
this.$set(obj , name , 'liu');  // 对象
this.$set(arr , 0 , 'liu') // 数组
// 删除一个响应式数据
this.$delete(arr , 0 ) // 数组
this.$delete( obj , name) // 对象
```

### 单页面应用和多页面

> 1. SPA单页面：只有一个主页面，一开始只用加载一次 css,js 相关资源，所有内容都在主页面，对每一个功能都模块化，跳转就是切换组件，只刷新局部资源
> 2. MAP 多页面 ：每个页面必须重复加载 js ,css 资源，多页面跳转，需要整个页面刷新

| 对比项/模式 | SPA                                    | MPA                                 |
| :---------: | -------------------------------------- | ----------------------------------- |
|    体验     | 页面多，体验好，首次加载资源多要过调整 | 页面切换慢，网速慢，体验很差        |
|    资源     | 组件公用资源加载一次                   | 每次都要加载自己的                  |
|    场景     | 不利于 SEO优化 （用 SSR 优化 SEO）     | 使用对 SEO 要求高的应该             |
|    更新     | 相关组件切换  局部更新                 | 整个 HTML切换 重复 http请求         |
|  路由跳转   | hash history                           | 超链接 跳转                         |
|  数据传递   | 各种通讯方式                           | cookie...url参数 缓存方案，接口保存 |
|  相关成本   | 前期开发成本高，易维护                 | 前期开发低，维护麻烦                |

### data 属性改变，视图不会立即渲染

> 是按照一定的策略进行 DOM的更新， 在更新是异步的，只要监听到数据变化，开启一个队列，缓存到事件循环中，发生的所有数据更改， 重复触发只放入一个队列，防止重复数据，避免不必要的计算，

### 自定义指令 directive

> 1. 使用场景
>    - 普通 DOM 元素进行底层操作，
>    - 自定义指令用来操作 DOM 可以定义任何 DOM 操作，并且可以复用
>    
> 2. 使用案例
>    - 鼠标聚焦
>    - 图片加载错误问题，懒加载
>    
> 3. 属性： 第一个参数：指令名称  ， 第二个参数：配置对象，指定指令的钩子函数
>
>    配置对象：
>
>    - bind 只调用一次，第一次绑定的时候调用
>      - 参数 ： el： 绑定的DOM元素
>      - binding 对象:
>        -  name 指令名
>        -  value : 指定传入的值  v-imgerror ='就是他'
>        - oldValue: 指令绑定的前一个值
>        - expression:  字符串形式的指令表达式 等号后面的字符串 形式
>        - arg: 传给指令的参数， 可选，v-my-directiive:foo 参数 foo
>        - modifiers: 指令修饰符，例如：v-directive.foo.bar中，修饰符对象为 { foo: true, bar: true }
>      - vnode:Vue编译生成的虚拟节点
>      - oldVnode: 上一个虚拟节点，仅在 update 和 componentUpdated 钩子中可用。
>    - inserted (el , binding , vnode):  调用的时候，元素已经插入到页面，也就是获取到父节点
>    - update (el , binding , vnode , oldVnode )：DOM重新渲染前
>    - componentUpdated ( el , binding , vnode , oldVnode  )：DOM 重新渲染后
>    - unbind ( el ) : 指令所在的元素在页面中消失，触发。
>
> 4. 简写 如果你想在 bind 和 update 时触发相同行为，而不关心其它的钩子 
>
>    - Vue.directive('自定义指令名', function( el, binding ) {})
>
> 

### 动态指令

```js
<button @[event]="handleEvent">动态指令</button>

data(){
	return {
		event:'click'
	}
},
mothods:{
    handleEvent(){
        console.log("事件触发");
      this.event = "contextmenu"; // 鼠标右击事件,点击之后就变成了  右击事件了
    }
}
```

### 子组件可以修改父组件的数据吗

> 不可以直接修改，因为 vue 是单项数据流，直接赋值操作，会破坏数据流，可以通过 **$emit** 派发一个自定义事件，父组件收到后，父组件自己修改

### assets 和 static

> 都是存放静态文件
>
> assets 要打包，之后放到 static里面。static 不打包

### Vue模版编译原理

> 1. 解析阶段：使用大量正则，对 template 字符串解析，将 标签，指令，属性转为抽象语法树 AST
> 2. 优化阶段： 遍历 AST 找其中的静态节点进行标记，方便在重新渲染的时候进行 diff 比较时 ，跳过一些静态节点
> 3. 生成阶段：将 AST 转为 render函数字符串

### SSR的理解

> 服务器渲染，将 vue 在客户端标签渲染成 HTML 的工作放在 服务器，然后在把 html 返回 客户端
>
> - 优势： 利于 SEO 搜索，首屏加载速度更快
> - 缺点：开发条件收到限制，只支持 beforeCreate 和 created 两个钩子，当需要外部库时要特殊处理，服务端渲染 程序，也需要在 node.js 的运行环境   也给给服务器增加负载

### vue初始化页面闪动

> 初始化之前 div 不归 vue 管，写的代码 还没有解析，容易出现花屏  如：{{msg}} 
>
> 在 css + **[v-cloak] {    display: none;}** 
>
> 或者根元素 + **style="display: none;" :style="{display: 'block'}"** 

###  Vue 子组件和父组件执行顺序

> 1. **加载渲染过程**
>    - 父组件 beforeCreate
>    - 父组件 created
>    - 父组件 beforeMount
>    - 子组件 beforeCreate
>    - 子组件 created
>    - 子组件 beforeMount
>    - 子组件 mounted
>    - 父组件 mounted
> 2. **更新过程**
>    - 父组件 beforeUpdate
>    - 子组件 beforeUpdate
>    - 子组件 updated
>    - 父组件 updated
> 3. **销毁过程：**
>    - 父组件 beforeDestroy
>    - 子组件 beforeDestroy
>    - 子组件 destroyed
>    - 父组件 destoryed

### 组件通讯

> 1. 父子组件
>    - props / \$emit 
>    - ref /refs 
>    - \$attrs / \$listeners 
> 2. 兄弟
>    -  \$parent | \$refs | \$children
> 3. 任意
>    - eventBus 事件总线
>    - .Observable 自定义一个小型的 vuex
>    - Vuex

### $attrs和$linsteners

```js
// 父组件 -》 子组件
<DomeChilred
      :dataName="dataName"
      type="text"
      v-on:updateDate="updateDate"
/>
  data() {
    return {
      dataName: "刘士朋",
    };
  },
  methods: {
    updateDate(val) {
       // 接收 子孙组件的事件
      this.dataName += val;
    },
  },      
      
      
// 子组件 -》 孙组件
<DomeSun v-bind="$attrs" v-on="$listeners" :dataName="dataName" />
props: ["dataName"],
    isShow() {
      this.$listeners.updateDate("修改");
    },
        
        
// 孙子组件
props: [ "dataName","type"],  // type -> text
  methods: {
    edit() {
      this.$emit("updateDate", "帅");
    },
  },
```



### 路由的 hash 和 history ，abstract-- 抽象模式 服务器的

> 1. hash 
>    - 在url 有 # ， http 请求没有，对后端没影响，改变 hash 不会重新加载页面，对浏览器支持友好，成为 SPA（单页面）标配
>    - 原理 : 监听 onhashchange() 事件
> 2. history
>    - 没有 # 更好看，需要后端配置支持，不配置好 404 
>    - 分两状态 ： 
>      - 修改历史状态： H5新增，pushState 和 replaceState
>      - 切换历史状态 : forward, back, go 

### \$router 和 $route

> $route 是 路由信息对象， path hash fullpath matched name 
>
> $router 是 路由实例对象 包含了 跳转方法钩子函数，push back go

### 路由声明周期

> 1. 完成路由导航（没有其他声明周期）
>    - 触发进入其他路由。
>    - 调用要离开路由的组件守卫beforeRouteLeave
>    - 调用局前置守卫∶ beforeEach
>    - 在重用的组件里调用 beforeRouteUpdate
>    - 调用路由独享守卫 beforeEnter。
>    - 解析异步路由组件。
>    - 在将要进入的路由组件中调用 beforeRouteEnter
>    - 调用全局解析守卫 beforeResolve
>    - 导航被确认。
>    - 调用全局后置钩子的 afterEach 钩子。
>    - 触发DOM更新（mounted）。
>    - 执行beforeRouteEnter 守卫中传给 next 的回调函数
> 2. 触发钩子的完整顺序
>    - 路由导航、keep-alive、和组件生命周期钩子结合起来的，触发顺序，假设是从a组件离开，第一次进入b组件∶
>    - beforeRouteLeave：路由组件的组件离开路由前钩子，可取消路由离开。
>    - beforeEach：路由全局前置守卫，可用于登录验证、全局路由loading等。
>    - beforeEnter：路由独享守卫
>    - beforeRouteEnter：路由组件的组件进入路由前钩子。
>    - beforeResolve：路由全局解析守卫
>    - afterEach：路由全局后置钩子
>    - beforeCreate：组件生命周期，不能访问tAis。
>    - created;组件生命周期，可以访问tAis，不能访问dom。
>    - beforeMount：组件生命周期
>    - deactivated：离开缓存组件a，或者触发a的beforeDestroy和destroyed组件销毁钩子。
>    - mounted：访问/操作dom。
>    - activated：进入缓存组件，进入a的嵌套子组件（如果有的话）。
>    - 执行beforeRouteEnter回调函数next。
> 3. 导航行为被触发到导航完成的整个过程
>    - 导航行为被触发，此时导航未被确认。
>    - 在失活的组件里调用离开守卫 beforeRouteLeave。
>    - 调用全局的 beforeEach守卫。
>    - 在重用的组件里调用 beforeRouteUpdate 守卫(2.2+)。
>    - 在路由配置里调用 beforeEnter。
>    - 解析异步路由组件（如果有）。
>    - 在被激活的组件里调用 beforeRouteEnter。
>    - 调用全局的 beforeResolve 守卫（2.5+），标示解析阶段完成。
>    - 导航被确认。
>    - 调用全局的 afterEach 钩子。
>    - 非重用组件，开始组件实例的生命周期：beforeCreate&created、beforeMount&mounted
>    - 触发 DOM 更新。
>    - 用创建好的实例调用 beforeRouteEnter守卫中传给 next 的回调函数。
>    - 导航完成

### vuex 和 localStorage

> vuex 存在 内存中, localStorage 以文件的方式存储在本地，只能存储字符串
>
> vuex 刷新页面会丢失  localStorage 不会

### vue.Observable ()进行状态管理

> vue 2.6.0 版本， vuex 如果应用不够大，最好不要使用，可以使用跟这个 来进行一个简单的跨组件的 状态管理

```js
// 创建一个 store.js
import Vue from 'vue'
// 导出数据模块
export const store = Vue.observable({
    data: {
        name: 'liu'
    }
})
// 导出 修改数据函数 模块
export const mutations = {
    updata(val) {
        store.data.name = val
    }
} 
// …… 也可以定义 ations  getters module
   
// 使用  在别的文件中使用 操作一样
<button @click="editName">修改数据</button>
<button @click="edit('刘士朋')">修改数据</button>
import { store, mutations } from "@/utils/store.js";
editName() {
      // 调用 修改
      mutations.updata("刘");
},
//  或者
edit: mutations.updata,
```



### 虚拟DOM的理解

> 1. 是对 DOM 的抽象，无需手动操作 DOM ，多次修改DOM修改的结果 一次性的更新到页面上,减少页面渲染次数，减少修改DOM的重绘重排(回流), 提高渲染性能
> 2. 解析过程：
>    - 把要插入 DOM 的结构进行分析，使用 js 对象表示出来。然后将 js 对象树 保存下来，最后将 DOM片段插入到文档
>    - 页面发生改变 对页面重新进行调整 ，首先根据变更状态 重新构建一棵树，和旧树进行比较 ，记录两个树的差异
>    - 最后将有差异的地方应用到 DOM 树上，视图就更新了
> 3. 为什么使用虚拟DOM ：
>    - 避免不必要的更新，不是立即更新，通过 diff 算法 来找出不同 只修改不同的部分

### diff算法原理

> 1. 对比节点本身，是否为同一节点，
>    - 不同：删除重新创建，替换
>    - 相同：进行判断，有无子节点，没有就移除旧的，有就 判断如何对老节点的子节点操作
> 2. 匹配时，找到相同的子节点，递归比较子节点，放弃跨节点比较 时间复杂度从 O(n^3)~O(n) 只有当新旧节点为多个子节点时需要进行同层比较

### Vue3 有什么更新

> 1. 检测机制
>    - 基于 Proxy 的 ObServer 实现，提供了 全语言覆盖，接触了 Vue2 的 Object.defineProperty的很多限制，
> 2. 对象只能检测属性不能检测对象
>    - 对象属性 添加和删除
>    - 数组 索引和长度修改
>    - vue3支持了 Set Map WeakSet WeakMap
> 3. 模板
>    - 作用域插槽变成了函数方式
>    - 可以有多个根节点
> 4. 对象的组件声明方式
>    - 生命方式改成了 类式的写法 setup()   和  ts 结合更容易
> 5. 过滤器删除，可以用计算属性来代替

### 处理错误（和警告）的更好方法

```js
// Vue 3
const app = createApp(App);
app.config.errorHandler = (err) => {
  alert(err);
};

// Vue 2
Vue.config.errorHandler = (err) => {
  alert(err);
};
```

### Es6

> 1. 默认参数
> 2. 剩余参数
> 3. 箭头函数
> 4. 字符串模板
> 5. symbol

### 前后端API交互如何保证数据安全性

> 1. 使用https通讯
> 2. 请求签名，防止参数被篡改
> 3. 身份确认机制，每次请求都要验证合法
> 4. app中使用 ssl , 防止抓包操作
> 5. 对所有请求响应都加密

### 常见浏览器兼容性问题

> 1. *{margin:0;padding:0;}
>
> 2. 添加浏览器前缀 
>
>    - 谷歌，苹果 webkit
>    - ie -ms-
>    - 火狐 -moz-
>    - 欧朋 -o-
>
> 3. 使用 hock 技术
>
>    ```css
>    <!--[if gte IE 9]>  只有 ie9 可以检测到
>     	<link rel="stylesheet" href="style9.css">
>    <![endif]-->
>    ```
>
>    