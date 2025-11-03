import QtQuick

import QtQuick.Window 2.12
import QtQuick.Controls 2.3
//import com.company.myqmlclass 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //MyQmlClass{
    //    id:myQmlImp
    //}

    Label{

        id:label
        text:""
        anchors.bottom:getBtn.top
        anchors.left: getBtn.left

    }

    Button{
        objectName: butshow
        id:getBtn
        text:"显示"
        width:120
        height:40

        anchors.centerIn:parent

        onClicked:
        {
            //label.text = myQmlImp.getValue();
            qmlWindows.visible = true;
        }
    }
    TextField{
        id:textFied
        objectName: textshow
        width:getBtn.width
        height:getBtn.height

        anchors.top: getBtn.bottom
        anchors.left: getBtn.left

        anchors.topMargin: 10
    }
    Button{
        id:setBtun
        text:"变色"
        width:getBtn.width
        height:getBtn.height

        anchors.top:textFied.bottom
        anchors.topMargin: 10
        anchors.left: textFied.left
        onClicked:{
            //var value = textFied.text
            //myQmlImp.setValue(value)

            qmlWindows.color = "blue"
            qmlWindows.visible = true
        }
    }
}
