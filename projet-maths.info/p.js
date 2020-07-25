var CANVAS_WIDTH;
var CANVAS_HEIGHT;
var CENTER_X;
var CENTER_Y;
var RADIUS;
var ROTATE;
var drawing;

setup(); // démarre tout, banzaï

///////////////////////////////////////////////////////////////////////////////

function setup() {
	var wrapper = document.getElementById("wrapper");
	CANVAS_WIDTH = wrapper.offsetWidth;
	CANVAS_HEIGHT = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
	CENTER_X = CANVAS_WIDTH / 2;
	CENTER_Y = CANVAS_HEIGHT / 2;
	RADIUS = .9 * Math.min(CANVAS_WIDTH, CANVAS_HEIGHT);
	ROTATE = localStorage.getItem("ROTATE") == "-90" ? "-90" : "90";
	if (ROTATE == "-90") {
		document.getElementById("rotate").textContent = "rotate -90°";
	}
	if (SVG.supported) {
		drawing = SVG("wrapper").size(CANVAS_WIDTH, CANVAS_HEIGHT);
	} else {
		alert("Votre navigateur ne supporte pas SVG, navré. Vous pouvez toutefois utiliser une version antérieure du site (« previous version », sur le menu de gauche).");
	}
	init();
	coloredButtons();
	draw();
}

// function windowResized() {
// 	CANVAS_WIDTH = document.getElementById("wrapper").offsetWidth;
// 	CANVAS_HEIGHT = windowHeight;
// 	resizeCanvas(CANVAS_WIDTH, CANVAS_HEIGHT);
//   CANVAS_CENTER_X = CANVAS_WIDTH / 2;
//   CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;
// 	RADIUS = .9 * Math.min(CANVAS_WIDTH, CANVAS_HEIGHT);
// }

///////////////////////////////////////////////////////////////////////////////

function coloredButtons() {
	var buttons = document.querySelectorAll("button");
	// console.log(buttons);
	buttons.forEach(function(button) {
		var color = randomColor({
			luminosity: 'light',
		});
		button.style.background = color;
	});
}

function init() {
	var hash = window.location.hash;
	if (hash) {
		var m = hash.substr(1).split(";")[0];
		var mod = hash.substr(1).split(";")[1];
		setConf(
			parseInt(m),
			parseInt(mod)
		);
	} else {
		setRandomConf();
	}
}

function setURL(m, mod) {
	if (history.pushState) {
		window.history.pushState(null, null, "#" + m + ";" + mod);
	}
}

function setTitle(m, mod) {
	document.title = m + ";" + mod;
}

function setConf(m, mod) {
	document.getElementById("m").value = m;
	document.getElementById("mod").value = mod;
	setURL(m, mod);
	setTitle(m, mod);
}

function setRandomConf() {
	setConf(
		Math.round(Math.random() * 1000),
		Math.round(Math.random() * 1000)
	);
}

///////////////////////////////////////////////////////////////////////////////

function updateConf() {
	var m = document.getElementById("m").value;
	var mod = document.getElementById("mod").value;
	setConf(m, mod);
	draw();
}

// input: `m`
document.getElementById("m").addEventListener("input", function() {
	updateConf();
}, true);

// input: `mod`
document.getElementById("mod").addEventListener("input", function() {
	updateConf();
}, true);

// button: `random values`
document.getElementById("random").addEventListener("click", function() {
	setRandomConf();
	draw();
}, true);

// button: `rotate`
document.getElementById("rotate").addEventListener("click", function() {
	var rotate = document.getElementById("rotate");
	if (ROTATE == "-90") {
		rotate.textContent = "rotate 90°";
		localStorage.setItem("ROTATE", "90");
		ROTATE = "90";
	} else {
		rotate.textContent = "rotate -90°";
		localStorage.setItem("ROTATE", "-90");
		ROTATE = "-90";
	}
	console.log(ROTATE);
	draw();
}, true);

// button: `save`
document.getElementById("save").addEventListener("click", function() {
	var link = document.createElement("a");
	var m = document.getElementById("m").value;
	var mod = document.getElementById("mod").value;
	link.setAttribute("download", m + "_" + mod + ".svg");
	document.body.appendChild(link);
	link.setAttribute("href", "data:image/svg+xml;utf8," + encodeURIComponent(drawing.svg()));
	link.click();
	link.remove();
}, true);

///////////////////////////////////////////////////////////////////////////////

function getPairs(m, mod) {
	var pairs = [0];
	for (i = 1 ; i < mod ; i++) {
		var result = i * m % mod;
		if (result == i) {
			pairs.push(null);
		} else {
			pairs.push(result);
		}
	}
	return pairs;
}

function getPoint(n, mod) {
	if (ROTATE == "-90") {
		return {
			x: CENTER_X + (RADIUS / 2) * Math.cos(2 * Math.PI * (n / mod)),
			y: CENTER_Y + (RADIUS / 2) * Math.sin(2 * Math.PI * (n / mod)),
		};
	} else {
		return {
			x: CENTER_X + (RADIUS / 2) * Math.sin(2 * Math.PI * (n / mod)),
			y: CENTER_Y - (RADIUS / 2) * Math.cos(2 * Math.PI * (n / mod)),
		};
	}
}

// function setRandomColor() {
// 	var color = randomColor({
// 		// luminosity: 'light',
// 		format: 'rgbArray'
// 	});
// 	stroke(color[0], color[1], color[2]);
// }

function draw() {
	drawing.clear();
  drawing.circle(RADIUS).attr({cx: CENTER_X, cy: CENTER_Y, stroke: "black", fill: "transparent"});
  //
	var m = document.getElementById("m").value;
	var mod = document.getElementById("mod").value;
  var pairs = getPairs(m, mod);
  //
	// setRandomColor();
  for (i = 0 ; i < pairs.length ; i++) {
  	if (i != pairs[i]) {
			var p1 = getPoint(i, mod);
			var p2 = getPoint(pairs[i], mod);
			drawing.line(
				p1.x, p1.y,
				p2.x, p2.y
			).attr({stroke: "black"});
  	}
	}
}
