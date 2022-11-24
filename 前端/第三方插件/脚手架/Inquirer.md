# Inquirer 命令行交互



## 安装

```shell
npm i inquirer
```



## 使用

#### prompt  创建选项

```js
import inquirer from "inquirer";
inquirer
  .prompt([
    {
      type: "input",
      name: "name",
      message: "请输入你的名字",
      default: "liushipeng",
      validate: function (v) {
        // return v === "liushipeng";
        return true;
      },
      transformer: function (v) {
        return "前缀:" + v;
      },
    },
  ])
  .then((answers) => {
    console.log(answers);
  })
  .catch((error) => {});

// type 输入类型
// name 最后得到的 key
// message 提示信息
// default  默认值
// validate 校验函数，返回 true 才行！
// transformer 在输入提示的时候可以多家 提示符
// filter 过滤函数，返回值是最后的 value 结果
// choices: 选项数组，在特定的 type 可用
// loop:true 启动列表循环

// 循环验证
 function (input) {
    const done = this.async();

    // 一直循环吧
    setTimeout(function() {
      if (typeof input !== 'number') {
        // 失败，提示信息
        done('You need to provide a number');
        return;
      }
      // 成功结束
      done(null, true);
    }, 0);
  }

```



## 输入类型  type

1. **input 输入框**
2. **number 数字输入框**
3. **password 密码输入框 界面不会展示**
4. **confirm 单选框 value:boolean**
5. **list 列表， 开启 choices:[{name:xx,value:xx},{...},...]，**
6. **rawlist 和 list 就是交互形式不同**
7.  **expand  也是和 list 形式不同， 可以输入 h 来展开所有的选项**
8. **checkbox  可以多选 list ，空格单选，a全选，i反选**
9. **editor  打开一个 vim 编辑器，输入完成时候 :wq 退出，结果以字符串形式展示**

