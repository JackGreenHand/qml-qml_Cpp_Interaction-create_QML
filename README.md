环境：
	window环境+QT6+VS2022+cmake编译方式
说明：
	主要是为了实现qml语言如何和底层C++语言进行交互，数据处理
	这里例子是：C++创建qml对象，并对qml对象内的子对象进行交互
	主要用到的思路是：
		1、创建一个Window.qml文件
		2、在main.cpp里，用C++接口创建Window.qml对象
		3、在main.cpp里，用C++接口修改Window.qml对象里的子对象属性
		
	实现大体伪代码：
		1)创建一个qml 
			Window.qml=>objectName: "myRectangle"
				Window {
					...
					color: "red"
					visible:false
					Rectangle{
						id:rectangle
						objectName: "myRectangle"
						width: 50
						height: 50
						anchors.centerIn: parent
						color:"black"
					}}

		2)在main.cpp里面创建qml对象
			//C++创建qml对象，并交互
			QQmlComponent compont(&engine);
			compont.loadFromModule("untitled5","Window");
			QObject * qmlWindow = compont.create();
			qmlWindow->setParent(engine.rootObjects()[0]);
			
		3)在C++创建的对象注入到main.qml里
			//把类对象传给main.qml,main.qml即可更改和控制window.qml
			engine.rootContext()->setContextProperty("qmlWindows",qmlWindow);
		
		4)在C++中修改qml对象的属性
			//修改qmlWindow属性
			QObject *rect = qmlWindow->findChild<QObject*>("myRectangle");
			rect->setProperty("color","white");
		
打开方式：
	把源文件下载，打开qt6，点击右上角的打开项目，把里面的内容都框进去即可