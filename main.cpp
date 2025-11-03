#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
//#include"myqmlclass.h"
#include<QQmlComponent>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //方式二
   // qmlRegisterType<MyQmlClass>("com.company.myqmlclass",1,0,"MyQmlClass");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("untitled5", "Main");


    //C++创建qml对象，并交互
    QQmlComponent compont(&engine);
    compont.loadFromModule("untitled5","Window");
    QObject * qmlWindow = compont.create();
    qmlWindow->setParent(engine.rootObjects()[0]);
    //把类对象传给main.qml,main.qml即可更改和控制window.qml
    engine.rootContext()->setContextProperty("qmlWindows",qmlWindow);


    //获取window.qml 修改qmlWindow属性
    QObject *rect = qmlWindow->findChild<QObject*>("myRectangle");
    rect->setProperty("color","white");

    //
    //// 获取 main.qml 的根对象
    //QObject* rootObject = engine.rootObjects().first();
    //// 从根对象开始查找名为 "butshow" 的对象
    //QObject* text = rootObject->findChild<QObject*>("butshow");
    //if (text) {
    //    text->setProperty("color", "red");
    //} else {
    //    qDebug() << "未找到 butshow 对象";
    //}

    return app.exec();
}
