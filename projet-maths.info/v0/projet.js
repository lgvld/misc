var CANVAS_WIDTH;
var CANVAS_HEIGHT;
var CENTER_X;
var CENTER_Y;
var RADIUS;

//--

var canvas;
var saved = localStorage.getItem("savedConfigs") ? JSON.parse(localStorage.getItem("savedConfigs")) : ["839-481"];
var AXIS = false;

//--

// window.onload = function(e) {
// 	if(performance.navigation.type == 2) {
//   	location.reload(true);
// 	}
// }

//--

function initConfig() {
	var config = window.location.hash.substr(1).split("-");
	if (config[0] > 0 && config[1] > 0) {
		document.getElementById("mod").value = config[0];
		document.getElementById("n").value = config[1];
		updateTitle();
	} else {
		document.getElementById("random").click();
	}
	var savedConfigs = document.getElementById("saved-configs");
	if (saved[0] != get_config()) {
		saved.reverse().forEach(function(element) {
			var link = document.createElement("a");
			link.setAttribute("href", "/#" + element);
			// link.setAttribute("href", "#");
			link.innerText = element;
			savedConfigs.appendChild(link);
			link.addEventListener("click", function(e) {
				document.getElementById("mod").value = element.split("-")[0];
				document.getElementById("n").value = element.split("-")[1];
				updateURL();
				e.preventDefault();
				// return false;
			}, true);
		});
	}
}

function setup() {
	var wrapper = document.getElementById("wrapper");
	CANVAS_WIDTH = wrapper.offsetWidth;
	// CANVAS_HEIGHT = wrapper.offsetHeight;
	CANVAS_HEIGHT = windowHeight;
	var canvas = createCanvas(CANVAS_WIDTH, CANVAS_HEIGHT);
	canvas.parent('wrapper');
  CENTER_X = CANVAS_WIDTH / 2;
  CENTER_Y = CANVAS_HEIGHT / 2;
  // alert(CANVAS_HEIGHT);
	RADIUS = .9 * Math.min(CANVAS_WIDTH, CANVAS_HEIGHT);
	initConfig();
}

function nth_point(mod, n) {
	return {
		x: CENTER_X + (RADIUS / 2) * Math.cos(2 * Math.PI * (n / mod)),
		y: CENTER_Y + (RADIUS / 2) * Math.sin(2 * Math.PI * (n / mod)),
	};
}

function get_mod() {
	return document.getElementById("mod").value;
}

function get_n() {
	return document.getElementById("n").value;
}

function get_config() {
	return get_mod() + "-" + get_n();
}

function draw() {
	var mod = get_mod();
	var n = get_n();
	clear();
  if (AXIS) {
	  // stroke(200, 200, 200);
	  line(CENTER_X, 0, CENTER_X, CANVAS_HEIGHT);
	  line(0, CENTER_Y, CANVAS_WIDTH, CENTER_Y);
  }
  stroke(0, 0, 0);
  fill(0, 0, 0, 0);
  ellipse(CENTER_X, CENTER_Y, RADIUS, RADIUS);
  for (i = 0 ; i < mod ; i++) {
		var p1 = nth_point(mod, i);
		var p2 = nth_point(mod, Math.round(i * n % mod));
		// alert(p2.x);
		line(p1.x, p1.y, p2.x, p2.y);
	}
}

function windowResized() {
	CANVAS_WIDTH = document.getElementById("wrapper").offsetWidth;
	resizeCanvas(CANVAS_WIDTH, CANVAS_HEIGHT);
  CANVAS_CENTER_X = CANVAS_WIDTH / 2;
  CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;
	RADIUS = .9 * Math.min(CANVAS_WIDTH, CANVAS_HEIGHT);
}

// update URL
function updateTitle() {
	var params = get_config();
	document.title = params;
}

function updateURL() {
	var params = get_config();
	window.history.pushState("", "", "#" + params);
	updateTitle();
}

// mod, n
document.getElementById("mod").addEventListener("click", function() {
	updateTitle();
	updateURL();
}, true);

document.getElementById("n").addEventListener("click", function() {
	updateTitle();
	updateURL();
}, true);

// `random values`
document.getElementById("random").addEventListener("click", function() {
	document.getElementById("mod").value = Math.floor(Math.random() * 1000);
	document.getElementById("n").value = Math.floor(Math.random() * 1000);
	updateURL();
}, true);

// `steps are enabled/disabled`
var steps = document.getElementById("steps");
steps.addEventListener("click", function() {
	var n = document.getElementById("n");
	if (n.step == .1) {
		steps.textContent = "steps are disabled";
		steps.style.background = "#85144b";
		n.value = Math.round(n.value);
		n.step = 1;
	} else {
		steps.textContent = "steps are enabled";
		steps.style.background = "#3d9970";
		n.step = .1;
	}
}, true);

// `show/hide axis`
var axis = document.getElementById("axis");
axis.addEventListener("click", function() {
	if (axis.value == "show") {
		AXIS = false;
		axis.value = "hide";
		axis.style.background = "#85144b";
	} else {
		AXIS = true;
		axis.value = "show";
		axis.style.background = "#7fdbff";
	}
}, true);

// `take screenshot`
function saveCanvasScreenShot() {
	var img = canvas.toDataURL("image/png").replace("image/png", "image/octet-stream");
	var link = document.createElement("a");
	link.setAttribute("download", get_config() + ".png");
	document.body.appendChild(link);
	link.setAttribute("href", img);
	link.click();
	link.remove();
	// window.location.href = img;
}

document.getElementById("screenshot").addEventListener("click", function() {
	saveCanvasScreenShot();
}, true);

// `save configuration`
function saveConfiguration() {
	var config = get_config();
	if (saved && saved[0] == config) {
		return;
	}
	saved.unshift(config);
	var savedConfigs = document.getElementById("saved-configs");
	var link = document.createElement("a");
	link.setAttribute("href", "/#" + config);
	link.innerText = config;
	savedConfigs.appendChild(link);
	localStorage.setItem("savedConfigs", JSON.stringify(saved));
	// console.log(saved);
	// console.log(localStorage.getItem("savedConfigs"));
}

document.getElementById("save").addEventListener("click", function() {
	saveConfiguration();
}, true);
