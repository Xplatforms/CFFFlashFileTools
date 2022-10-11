import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.platform

import xplatforms.cffflashcontainer.flashblock 1.0
import xplatforms.cffflashcontainer.flashsegment 1.0
import xplatforms.cffflashcontainer.flashsegmentmodel 1.0


ColumnLayout
{
    property string flash_name;
    property string idk;
    property CFFFlashSegment segment;

    width: parent.width
    RowLayout
    {
        spacing: 20
        Layout.fillWidth: true
        Label
        {
            font.weight: Font.DemiBold
            text: segment.SegmentName
        }
        Label
        {
            text: "Address: "
        }
        Label
        {
            text: segment.FromAdress
        }
        Label
        {
            text: "Length (byte): "
        }
        Label
        {
            text: segment.SegmentLength
        }

        Rectangle
        {
            height: 1
            Layout.fillWidth: true
        }

        Button
        {
            //text: "Save segment to file"
            icon.source: "qrc:/images/save_btn.svg"
            flat: true
            onClicked:
            {
                file_save_dialog.open()
            }
        }
    }

    FolderDialog
    {
        id: file_save_dialog
        title: "Please choose where to save flash segment"
        //fileMode: FolderDialog.OpenFolder
        //folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)

        //nameFilters: [FlashSegment.SegmentName+".segment"]

        onAccepted: {
            console.log("You chose: " + file_save_dialog.folder)
            ttip_id.show("Segment saved to: " +segment.saveToFile(file_save_dialog.folder+"/"+flash_name+"_"+idk+"_"+segment.SegmentName+".segment"), 2500);
            //loadCFF(fileDialog.currentFile);
            //Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            //Qt.quit()
        }
        //Component.onCompleted: visible = true
    }

    ToolTip
    {
        id: ttip_id
        //parent: parent//btn_export_all
        anchors.centerIn: parent
        margins: 20
    }

}


