import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import xplatforms.cffflashcontainer.flashblock 1.0

Component
{

    ColumnLayout
    {
        RowLayout
        {
            Label{
                font.bold: true
                text: "Qualifier: "
            }
            Label{text: FlashDataBlock.Qualifier}
            //Label{text: "test"}
        }

        RowLayout
        {
            Label{
                font.bold: true
                text: "FlashDataInfo_Idk: "
            }
            Label{text: FlashDataBlock.FlashDataInfo_Idk}
            //Label{text: "test"}
        }
    }
}
