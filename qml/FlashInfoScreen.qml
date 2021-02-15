import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2

import xplatforms.cffflashcontainer.container 1.0
import xplatforms.cffflashcontainer.flashheader 1.0
import xplatforms.cffflashcontainer.flashblock 1.0

Page {

    title: qsTr("CFF Flash Files Tools")
    padding: 5

    property CFFFlashContainer cff: CFFFlashContainer{}
    property CFFFlashHeader flash_header: null
    property int cff_checksum: 0
    property int cff_calculated_checksum: 0

    Component.onCompleted:
    {
        cff = cff.openCaesarFlashContainer(cff_object.selected_fname)
        cff_checksum = cff.readChecksum();
        cff_calculated_checksum = cff.genChecksum();

        flash_header = cff.readFlashCFF();

        console.log(flash_header.FlashName)
    }

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 8

        RowLayout
        {
            Label
            {
                text: qsTr("Flash Name:")
                font: window.headerFont12
            }
            Label
            {
                text: flash_header.FlashName
            }
        }

        RowLayout
        {
            Label
            {
                text: qsTr("Flash Author:")
                font: window.headerFont12

            }
            Label
            {
                text: flash_header.FileAuthor
            }
        }

        ListView
        {
            model: flash_header.FlashDataBlocks
            delegate: ColumnLayout
            {
                RowLayout
                {
                    Label{text: ItemDelegate.data}
                }
            }
        }

        Rectangle
        {
            Layout.fillHeight: true
            width: 1
        }
    }

}