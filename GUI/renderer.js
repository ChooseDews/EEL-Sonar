// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// No Node.js APIs are available in this process because
// `nodeIntegration` is turned off. Use `preload.js` to
// selectively enable features needed in the rendering
// process.

let proximity = new Array(360);
let currentAngle = 0;

function updatePosition(p) {
    let [s1, s2, pos] = p.replace('\r', '').split(';');
    //console.log([s1, s2, pos])
    pos = Number(pos);
    proximity[pos] = s1;
    proximity[pos + 180] = s2;
    currentAngle = pos;



}

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')
let serialPath = "/dev/ttyUSB0";

const port = new SerialPort(serialPath, {
    baudRate: 115200
})

const parser = new Readline()
port.pipe(parser)

parser.on('data', updatePosition)

var canvas = document.getElementById('paint')
var context = canvas.getContext("2d");

let origin_x = canvas.width / 2;
let origin_y = canvas.height / 2;

let maxRadius = 400;

function DrawCircle(centerX, centerY, r, color, fill) {
    var x = centerX || canvas.width / 2;
    var y = centerY || canvas.height / 2;
    var radius = r || maxRadius;
    context.beginPath();
    context.arc(x, y, radius, 0, 2 * Math.PI, false)
    context.fillStyle = fill || 'white';
    context.fill();
    context.lineWidth = 1;
    context.strokeStyle = color || '#D3D3D3';
    context.stroke();
}

function DrawLine(angle) {
    context.beginPath();
    context.moveTo(Math.cos(angle * 0.0174533) * -maxRadius + origin_x, Math.sin(angle * 0.0174533) * -maxRadius + origin_y);
    context.lineTo(Math.cos(angle * 0.0174533) * maxRadius + origin_x, Math.sin(angle * 0.0174533) * maxRadius + origin_y);

    let modified = maxRadius + 15;

    DrawText(Math.cos(angle * 0.0174533) * -modified + origin_x, Math.sin(angle * 0.0174533) * -modified + origin_y, "1", "14px Arial")
    DrawText(Math.cos(angle * 0.0174533) * modified + origin_x, Math.sin(angle * 0.0174533) * modified + origin_y, "2", "14px Arial")


    context.strokeStyle = 'red';
    context.stroke();
}

function DrawText(x, y, text, font) {
    context.font = font || "11px Arial";
    context.fillStyle = "black";
    context.strokeStyle = "black";
    context.fillText(text, x, y);
}


function DrawRadius() {

    DrawCircle(origin_x, origin_y, 800)
    DrawCircle()
    DrawCircle(origin_x, origin_y, 300)
    DrawCircle(origin_x, origin_y, 200)

    DrawCircle(origin_x, origin_y, 100)

    DrawText(origin_x + 10, origin_y - 110, '50cm')
    DrawText(origin_x + 10, origin_y - 210, '100cm')
    DrawText(origin_x + 10, origin_y - 310, '150cm')
    DrawText(origin_x + 10, origin_y - 410, '200cm')

    DrawCircle(origin_x, origin_y, 4, 'red', 'red')
    DrawText(canvas.width - 100, canvas.height - 100, currentAngle + "°", "16px Arial")


    for (let angle in proximity) {
        let value = proximity[angle] * 2;
        if (value > 10 && value < maxRadius + 20) {
            let x = Math.cos(angle * 0.0174533) * value + origin_x;
            let y = Math.sin(angle * 0.0174533) * value + origin_y;
            DrawCircle(x, y, 3, 'black');
        }
        if (angle == currentAngle) DrawLine(angle);


    }





}

DrawCircle()

setInterval(function () {

    DrawRadius()

}, 50)