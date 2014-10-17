#常见皮肤QSS代码

******

##QTabWidget

> * 淡蓝色效果TabWidget(属性值lightblue)

```css
QTabWidget[lightblue = "true"] QTabBar::tab{    	
	border-top:1px solid rgb(249,249,249);
	border-top-left-radius: 4px;
    border-top-right-radius: 4px;
	max-height:20px;
	min-height:20px;
	min-width:95px;
	font-family:microsoft yahei;
	color:rgb(50,50,50);
	font-size:13px;
	padding:0px 0px 0px 0px;
	border-image:url();
	margin: 0px;
	padding-bottom:15px;
}

QTabWidget[lightblue = "true"] QTabBar::tab:selected{
	border-left:1px solid rgb(192,215,250);
	border-right:1px solid rgb(192,215,250);
	border-top:1px solid rgb(192,215,250);
	color:rgb(50,50,50);
	background-color:rgb(249,249,249);
	font-size:13px;
	border-image:url();
	margin: 0px;
}

QTabWidget[lightblue = "true"]::pane { 
 border-top: 1px solid rgb(192,215,250);
 position: absolute;
 top: -1px;
}
```
效果如下图所示：
![QTableWidget](./皮肤模块说明文档的资源文件/QTabWidget.png)

##QLabel 

> * 蓝色标题Label(属性值blueTitle)

```css
QLabel[blueTitle="true"]
{
	font-size:18px;
	font-family:Microsoft YaHei;
	color:rgb(255,255,255);
	background-color:rgb(5 ,112, 183 );
	padding-left:25px;
}
```

效果图如下所示：

![blueTitleLabel](./皮肤模块说明文档的资源文件/blueTitle.png)

> * 淡灰色标题Label(属性值lightgrayTitle)

```css
QLabel[lightgrayTitle="true"]
{
	font-family:Microsoft YaHei;
	font-size:16px;
	background-color: rgb(207, 207, 207);
	padding-left: 25px;
}
```

效果图如下所示：

![lightGrayTitleLabel](./皮肤模块说明文档的资源文件/lightGrayTitle.png)

##QPushbutton

> * 蓝色按钮(属性值blueButton)

```css
QPushButton[blueButton="true"]
{
	color:rgb(255,255,255);
	border-radius:3px;
	background-color:rgb(0,109,204);
	font-family:Arial;
}
QPushButton[blueButton="true"]:hover
{
	background-color:rgb(0 ,119, 224 );
}
QPushButton[blueButton="true"]:pressed
{
	background-color:rgb(0 ,149 ,255  );
}
```

效果图如下所示：

![blueButton](./皮肤模块说明文档的资源文件/blueButton.png)