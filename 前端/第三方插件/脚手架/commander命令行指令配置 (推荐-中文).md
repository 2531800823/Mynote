# commander —— 命令行指令配置 (推荐-中文)

```js
const program = require("commander");
// 解析用户执行时输入的参数
// process.argv 是 nodejs 提供的属性
// npm run server --port 3000
// 后面的 --port 3000 就是用户输入的参数
program.parse(process.argv);
```

## 添加获取版本号命令

```js
program.version('1.0.0');
```

## 帮助文档提示信息

```js
program.usage("nihoa"); // 在每个命令前可以添加

// 添加全局
program.addHelpText("beforeAll", "请阅读下面的命令！！！");
// beforeAll：作为全局标头栏展示
// before：在内建帮助信息之前展示
// after：在内建帮助信息之后展示
// afterAll：作为全局末尾栏展示
// 参数2 函数，返回一个字符串， 
// error：boolean 值，代表该帮助信息是否由于不当使用而展示
// command：代表展示该帮助信息的Command对象

// 没有命令的时候 输出帮助文档
if (process.argv.length < 3) {
    program.outputHelp();
} else {
    program.parse(process.argv);
}
```

## 在出错后展示帮助信息

```js
// 所有错误
program.showHelpAfterError('出错了哦');

// 遇到未知命令和拼写错误后，建议正确拼写
program.showSuggestionAfterError(true);

// 处理错误
program.showHelpAfterError(colors.yellow('(使用 --help 查看帮助文档)'));
program.exitOverride();
try {
    program.parse(process.argv);
} catch (e) {
    console.log();
    const obj = program.args;
    console.error(colors.red('出错了！未知的命令：', obj[0]));
    const commands = program.commands.map((cmd) => cmd.name());
    if (commands.lengtn > 0) {
        console.log(colors.green('可用命令：', commands.join(', ')));
    }
}
```

## 添加自己的 option    [官网文档](https://github.com/tj/commander.js/blob/master/Readme_zh-CN.md#%e9%80%89%e9%a1%b9)

```js
program.option('-c, clear', '删除 node_modules ',"函数","没有函数：默认参数 有函数：函数的参数")

// 最后一个 默认参数的， 直接 liu 也会有参数，但是 -c 没有参数不行

// 特殊指令可以自定义 Option
const { Option } = program;
program
  .addOption(new Option('-t, --timeout <delay>', 'timeout in seconds').default(60, 'one minute'))
// 参数只可以取一个 ，在 timerout 上
// .default() 默认参数 ,
// .env("PORT") 环境变量 使用： PORT=80 liu
// ....
```

## 处理 option 指令

```js
// 在这个下面
program.parse(process.argv);
// 获取到参数
const opt = program.opts();

// 一个一个的判断，然后处理对应的指令
if (opt.clear) {
  //  -c 的命令 ， 可以 全部指令放到 obj 上  obj[opt.clear]()
  console.log(opt.clear, "clear");
}
// ...
else {
  console.log("其他命令");
}
```

## 监听事件

```js
// 监听事件
program.on('--help', function () {
  console.log('监听到了');
})
// 监听所有的 未知 命令, 会把命令放入到 参数里
program.on('command:*', function (obj) {
  	console.log('监听到了',obj);
    console.error('未知的命令：', obj[0])
    const commands = program.commands.map(cmd=>cmd.name())
    console.log('可用命令：',commands.join(', '))
})
```

## 自定义指令

```js
// 参数 create 指令名字
// <fileName>  必选参数
// [others]  可选参数
// [others...]  <fileName...> 多个可选参数
// 配置对象： noHelp： 不显示在 帮助文档
//   		isDefault: 没有其他命令，默认执行这个命令
//          executableFile: 可以手动修改可执行文件 可以使用别的脚手架
			// 例：.command("install ", { executableFile: '../cli' }) 要拼接路径到其他的脚手架命令（或者其他js文件，也会调用） 就可以执行别的脚手架命令 也可以相对路径
program
  .command("create <fileName> [others...]", { noHelp: true })
  .description("这里是描述！！")
  .option("-p,--port <port_number>", "web port")
  .action(async (fileName, others, option) => {
    console.log("开始执行了");
    console.log(fileName, others, option?.port);
    try {
      // direct: 要克隆的地址 , 下载到的文件路径,  不填就是下载, clone 可以初始化 git 的操作
      await download("direct:下载路径", "保存到文件的路径", { clone: true });
    } catch (error) {
      console.log("出错误：", err);
    }
  });
// .description 描述信息
// .alias('i') 添加别名
// .option 可以为指令添加参数 如: liu create -p 8080
// .action 处理指令参数， 传入一个函数，函数接收 的是指令传入的参数，最后一个参数 指向该命令自身
// .argument('<first>', 'integer argument', 1000) 可以匹配所有命令，可以单独把参数提出来配置 	.argument('[second]', 'integer argument', 1000, 2000) 在description 第二参数可以用 {first:'第一个'} 来描述 命令
// .name('create')  单独把 name 提出来配置


```

## 添加子命令

```js
const service = new commander.Command('service');
service.command('start [port]')
.description('在 service 下创建的子命令')
.action((port)=>{
    console.log('执行命令',port)
})

// 注册到全局
program.addCommand(service)
// cli service -h  // 显示的就只有 service 创建的命令
// cli service start 8888 --> '执行命令',8888
```

