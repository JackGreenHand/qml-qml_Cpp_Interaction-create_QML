import QtQuick
import QtQuick.Controls 2.3
import QtQuick.Window 2.10
Window {

    width: 200
    height:200

    color: "red"
    visible:false

    Rectangle{

        id:rectangle
        objectName: "myRectangle"
        width: 50
        height: 50
        anchors.centerIn: parent
        color:"black"

    }

}
