## 判断是否是 windows 系统

```js
process.platform === 'win32'
```



## core/cli

#### import-local  查看是否是用的是 本地目录的

```js
const importLocal = require("import-local");

if (importLocal(__filename)) {
  // npmlog 打印信息更好看
  require("npmlog").info("cli", "正在使用 脚手架 本地版本");
} else {
  require("../lib")(process.argv.slice(2));
}

```

#### semver 比对版本号

```js
semver.gt('1.2.3', '9.8.7') // false  大于
semver.lt('1.2.3', '9.8.7') // true   小于
semver.gte('1.2.3', '9.8.7') // true   大于等于
```



#### colors 可以生成不同颜色 log

```js
const colors = require('colors');

colors.red(`需要安装 v${lowestVersion} 以上的版本的 Node.js`)
```



#### root-check  尝试降低具有 root 权限的进程

```js
 // 尝试降低具有 root 权限的进程的权限，如果失败，则阻止访问
  require('root-check')();
```



#### user-home -- 弃用 使用  os.homedir 代替

```js
const { homedir } = require('os');
console.log(homedir());
```



#### path-exists 查看文件是否存在  --》 手写一个 Promise

```js
const fs = require('fs');

function pathExists(path) {
  return new Promise((resolve, reject) => {
    fs.access(path, (err) => {
      if (err) {
        resolve(false);
      }
      resolve(true);
    });
  });
}
```



#### dotenv  用来处理环境变量



#### boxen  打印 log 加一个边框





## utils/log

#### npmlog 打印彩色好看的 log

```js
const log = require("npmlog");
log.info("cli", "test");  // info cli test
```

##### 自定义方法

```js
// 开始的模式，默认debugger  调试的 可以开启  “verbose”
log.level = process?.env?.LOG_LEVEL || "info";
// string:注册的方法  
// number:数字登记（上面level高于2000 就不能用了）
// 配置项
log.addLevel("success", 2000, { bg: "red" }); 
log.success("cli", "test"); // success cli test
```

##### 添加前缀

```js
log.heading = "liushipeng";
// 前缀样式
log.headingStyle = { fg: "black", bg: "blue" };
```

#### chalk 打印彩色信息





## utils/get-npm-info    npm-openapi



#### url-join 来拼接 url  

```js
import urlJoin from 'url-join';

const fullUrl = urlJoin('https://registry.npmjs.org', 'liushipeng-cli', );
// 在 npm 地址 加上自己的 包 名字，可以获取到 包的信息
console.log(fullUrl); // 'https://registry.npmmirror.com/liushipeng-cli'
```

#### 





## child_process  创建子进程

#### fork  创建子进程

```js
const { exec, execFile, spawn, fork } = require("child_process");
const path = require("path");
// 创建 就一个参数，路径
const child = fork(path.resolve(__dirname, "2.js"));

// 结束子进程
child.disconnect();

// 通信  父 -》 子
child.send("nihao",()=>{
    // 结束子进程
    child.disconnect();
});
// 2.js
process.on("message", (msg) => {
  console.log(msg, "子进程"); // nihao,子进程
});

// 通信  子 -》 父
// 2.js
process.send("nihao");
// 父进程
child.on("message", (msg) => {
  console.log(msg, "父进程"); // nihao, 父进程
});


```



#### exec 执行一个命令    同步的 execSync

```js
const {exec} = require("child_process");

// 配置了 {stdio:'inherit' 把log信息传给父进程 }, 就不用监听 stdout 了，只关注错误就行
const child = exec("ls -al",{stdio:'inherit'},)
// 关闭事件
child.on('close', (code) => {
  console.log(`${code}，关闭了`);
    process.exit(1); // 程序中断执行
});

exec('npm install',(err,stdout,stderr)=>{
    console.log(stdout)
})

```

#### execFile  执行一个文件       同步的 execFileSync

```js
const {execFile} = require("child_process");

execFile("ls",['-al'])
```

#### 区别

1. execFile 不能直接的使用 管道

   ```js
   const {exec，execFile} = require("child_process");
   
   exec("ls -al | grep node_modules")
   execFile("ls",['-al | grep node_modules'])  // err
   ```

2.  execFile 可以执行  .shell 文件里面的命令

```js


const {exec，execFile} = require("child_process");

exec("ls -al | grep node_modules")
execFile("ls",['-al | grep node_modules'])  // err
```







## modules/package

#### pkg-dir  向上查找第一个 package.json 文件



#### npminstall  安装 npm 模块包 cnpm使用的就是这个包

```js
const npminstall = require('npminstall');

npminstall({
    root:'', // 模块路径
    storeDir:"", // 实际存放的目录
     registry: 'https://registry.npmjs.org', // 镜像源
    // 需要 制定的 版本类型
     pkgs: [  
      { name: 'foo', version: '~1.0.0' },
    ],
})
```



#### cli-spinner 命令行 loading

```js
var Spinner = require('cli-spinner').Spinner;
 
var spinner = new Spinner('loading... %s');  
spinner.setSpinnerString('|/-\\'); // 这几个字符，循环转换
spinner.start();  // 开始

spinner.stop(true);  // 结束 传入 true 把 console.log 删除
```



#### readline 逐行读取输入内容

```shell
node 自带库 
```



#### fs-extra 增强 fs 模块

##### Async 异步

- [copy 收到](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/copy.md)
- [emptyDir 空空如也](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/emptyDir.md)
- [ensureFile 保证文件](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureFile.md)
- [ensureDir 确保长官](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureDir.md)
- [ensureLink 链接](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureLink.md)
- [ensureSymlink 保证符号链接](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureSymlink.md)
- [mkdirp](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureDir.md)
- [mkdirs](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureDir.md)
- [move 让开](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/move.md)
- [outputFile OutputFile 输出文件](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/outputFile.md)
- [outputJson 输出 Json](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/outputJson.md)
- [pathExists 路径存在者](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/pathExists.md)
- [readJson 读 Json](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/readJson.md)
- [remove 拿开](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/remove.md)
- [writeJson 写信给杰森](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/writeJson.md)

##### Sync 同步

- [copySync 同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/copy-sync.md)
- [emptyDirSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/emptyDir-sync.md)
- [ensureFileSync 确保文件同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureFile-sync.md)
- [ensureDirSync 确保同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureDir-sync.md)
- [ensureLinkSync 确保 LinkSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureLink-sync.md)
- [ensureSymlinkSync 确保 SymlinkSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureSymlink-sync.md)
- [mkdirpSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureDir-sync.md)
- [mkdirsSync 同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/ensureDir-sync.md)
- [moveSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/move-sync.md)
- [outputFileSync OutputFileSync 输出文件同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/outputFile-sync.md)
- [outputJsonSync 输出 JsonSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/outputJson-sync.md)
- [pathExistsSync 路径存在同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/pathExists-sync.md)
- [readJsonSync 读取 JsonSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/readJson-sync.md)
- [removeSync RemoveSync 移除同步](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/remove-sync.md)
- [writeJsonSync 编写 JsonSync](https://github.com/jprichardson/node-fs-extra/blob/HEAD/docs/writeJson-sync.md)
