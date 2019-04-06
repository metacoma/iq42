import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    property int defaultFlags:  Qt.FramelessWindowHint | Qt.Tool | Qt.Dialog | Qt.WA_TranslucentBackground
    flags: defaultFlags
    height: 80
    width: 80
    title: qsTr("iq42Button")
}
