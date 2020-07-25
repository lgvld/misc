var CANVAS_WIDTH;
var CANVAS_HEIGHT;
var CENTER_X;
var CENTER_Y;
var RADIUS;
var ROTATE;

///////////////////////////////////////////////////////////////////////////////

function setup() {
	var wrapper = document.getElementById("wrapper");
	CANVAS_WIDTH = wrapper.offsetWidth;
	CANVAS_HEIGHT = windowHeight;
	CENTER_X = CANVAS_WIDTH / 2;
	CENTER_Y = CANVAS_HEIGHT / 2;
	RADIUS = .9 * Math.min(CANVAS_WIDTH, CANVAS_HEIGHT);
	ROTATE = true;
	var canvas = createCanvas(CANVAS_WIDTH, CANVAS_HEIGHT);
	canvas.parent("wrapper");
	init();
	coloredButtons();
}

function windowResized() {
	CANVAS_WIDTH = document.getElementById("wrapper").offsetWidth;
	CANVAS_HEIGHT = windowHeight;
	resizeCanvas(CANVAS_WIDTH, CANVAS_HEIGHT);
  CANVAS_CENTER_X = CANVAS_WIDTH / 2;
  CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;
	RADIUS = .9 * Math.min(CANVAS_WIDTH, CANVAS_HEIGHT);
}

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
}

// input: `m`
document.getElementById("m").addEventListener("click", function() {
	updateConf();
}, true);

// input: `mod`
document.getElementById("mod").addEventListener("click", function() {
	updateConf();
}, true);

// button: `random values`
document.getElementById("random").addEventListener("click", function() {
	setRandomConf();
}, true);

// button: `rotate`
document.getElementById("rotate").addEventListener("click", function() {
	var rotate = document.getElementById("rotate");
	if (ROTATE) {
		rotate.textContent = "rotate -90°";
	} else {
		rotate.textContent = "rotate 90°";
	}
	ROTATE = !ROTATE;
	draw();
}, true);

// button: `take screenshot`
document.getElementById("screenshot").addEventListener("click", function() {
	var img = canvas.toDataURL("image/png").replace("image/png", "image/octet-stream");
	var link = document.createElement("a");
	var m = document.getElementById("m").value;
	var mod = document.getElementById("mod").value;
	link.setAttribute("download", m + "_" + mod + ".png");
	document.body.appendChild(link);
	link.setAttribute("href", img);
	link.click();
	link.remove();
	// window.location.href = img;
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
	if (ROTATE) {
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

function setRandomColor() {
	var color = randomColor({
		// luminosity: 'light',
		format: 'rgbArray'
	});
	stroke(color[0], color[1], color[2]);
}

function draw() {
	clear();
  stroke(0, 0, 0);
  fill(0, 0, 0, 0);
  ellipse(CENTER_X, CENTER_Y, RADIUS, RADIUS);
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
			line(
				p1.x, p1.y,
				p2.x, p2.y
			);
  	}
	}
}
