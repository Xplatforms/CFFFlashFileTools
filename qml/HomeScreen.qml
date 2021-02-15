import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2

import xplatforms.cffflashcontainer.container 1.0

Page {

    title: qsTr("CFF Flash Files Tools")

    function loadCFF(fname)
    {
        cff_object.selected_fname = fname;
        console.log(cff_object.selected_fname);
        stackView.push("FlashInfoScreen.qml")
    }

    FileDialog
    {
        id: fileDialog
        title: "Please choose CFF Flash file"
        folder: shortcuts.home
        selectExisting: true
        selectMultiple: false
        nameFilters: [ "CFF Flash files (*.cff)", "All files (*)" ]
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            loadCFF(fileDialog.fileUrl);
            //Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            //Qt.quit()
        }
        //Component.onCompleted: visible = true
    }

    ColumnLayout
    {
        anchors.fill: parent
        //anchors.leftMargin: 6
        spacing: 8

        RowLayout
        {
            Layout.fillWidth: true
            Layout.margins: 20

            Label
            {
                Layout.fillWidth: true
                text: qsTr("Please select or drop CFF File: ")
                font: window.headerFont
                //anchors.centerIn: parent
            }

            Button
            {
                Layout.alignment: Qt.AlignLeft
                Layout.fillWidth: true
                implicitWidth: 200
                text: qsTr("Select")
                onClicked: fileDialog.open();
            }

        }


        Rectangle
        {
            id: drop_rect_id
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.margins: 20
            Layout.topMargin: 0
            border.color: "grey"
            border.width: 2

            Label{

                //anchors.fill: parent
                anchors.centerIn: parent
                text: qsTr("Drop CFF Flash file here.")
            }

            DropArea
            {
                anchors.fill: parent
                onDropped:
                {
                    console.log("File dropped: " + drop.text);
                    loadCFF(drop.text);
                }
            }
        }


    }




}
