//signIn
var enemy=0;
var count = 0;
//creat game
function setupBoard(){
	
	
	var N = document.getElementById("txtNum");
	var divoutput = document.getElementById("board");
	
	var output ="<h1>Click Any Cell to gun</h1> \n";
	output += '<div id="notice">Thong bao tu trung tam : load...</div> \n';
	output += '<table id="gameScreen"> \n';
	for(var i=0;i<N.value;i++){
		output += "<tr> \n"
		for(var j=0;j<N.value;j++){
			output += "<td></td>";
		}
		output += "\n </tr> \n";
	}
	output += "</table> \n";
	divoutput.innerHTML= output;
	
	setupPlayer(N.value);
	setupAI(N.value);
	setupSetting();
	enemy = N.value;
	count = 0;
}

function setupPlayer(N){
	var mapgame = document.getElementsByTagName("td");
	var x=Math.floor(Math.random() * N);
	var y=Math.floor(Math.random() * N);
	mapgame[x*N + y].innerHTML = '<img src="images/myship.png" alt="ship" width="100%" height="100%" /><br/>';	
}

function setupAI(N){
	
	var mapgame = document.getElementsByTagName("td");
	var x=0,y=0;
	for(var i=0;i<N;i++){
		x=Math.floor(Math.random() * N);
		y=Math.floor(Math.random() * N);
		if(mapgame[x*N + y].innerHTML == ""){
			mapgame[x*N + y].innerHTML = '<img class="obj-hidden" src="images/enemyship.png" alt="enemyship" width="100%" height="100%" />';
		}
		else i--;
	}
}
function setupSetting(){
	var mapgame = document.getElementsByTagName("td");
	for(var i=0; i<mapgame.length;i++){
		mapgame[i].addEventListener("click",gun);
	}
}
