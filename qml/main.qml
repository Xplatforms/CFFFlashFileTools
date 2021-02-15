import QtQuick 2.15
import QtQuick.Controls 2.15

import xplatforms.cffflashcontainer.container 1.0

ApplicationWindow {
    id: window
    width: 720
    height: 420
    visible: true
    title: qsTr("CFF Flash Files Tools")

    QtObject
    {
        id: cff_object
        //property CFFFlashContainer container: CFFFlashContainer{}
        property string selected_fname: ""
    }



    property font headerFont: Qt.font(
    {
      family: 'Segoe UI',
      weight: Font.DemiBold,
      italic: false,
      pointSize: 14
    })

    property font headerFont12: Qt.font(
    {
      family: 'Segoe UI',
      weight: Font.DemiBold,
      italic: false,
      pointSize: 12
    })





    /*
    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }
    */

    /*
    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("Page1Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
        }
    }
    */

    StackView {
        id: stackView
        initialItem: "HomeScreen.qml"
        anchors.fill: parent
    }
}
